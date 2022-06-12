#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QPainter>
#include <QPixmap>
#include <QImage>
#include <QFile>
#include <QPicture>
#include <QMap>
#include "WatchComponentsWidget.h"
#include "readexcel.h"
#include "CodeJson.h"
#include "Utils.h"
#pragma execution_character_set("UTF-8")

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setAcceptDrops(true);
    pxcp = new pxcpJson();
    watch_view = new WatchView(this);

 
	ui->label_display->installEventFilter(this); 
  
   
    language = Language::GetInstance();
    current_lan = (Language_e)ui->CB_language->currentIndex();

    QStandardItemModel  *components_model = new QStandardItemModel(this);
    imageSelectWidget = new ImageSelectWidget();
    imageSelectWidget->OpenPath("./watchImage");
    int count = watch_view->component_list.size();
    for (int i = 0; i < count; i++)
    {
        components_model->appendRow(new QStandardItem(watch_view->component_list.at(i)));
    }

    ui->listView_componnets->setModel(components_model);
   
    selected_items_model  = new QStandardItemModel(this);
    selected_items_model->setHorizontalHeaderItem(0, new QStandardItem("ID"));
    selected_items_model->setHorizontalHeaderItem(1, new QStandardItem("属性"));
    //文本选择界面
     languageTextSelect = new LanguageTextSelect();
     languageTextSelect->SetSelectedText(&select_element_list);
     QObject::connect(languageTextSelect, SIGNAL(updata_text()), this, SLOT(on_updata_select_content_list()));
     QObject::connect(imageSelectWidget, SIGNAL(updata_image()), this, SLOT(on_updata_select_content_list()));
     QObject::connect(imageSelectWidget, SIGNAL(create_image()), this, SLOT(on_creat_item()));
     
    vpWatchCode = VpWatchCode::getInstance();
   
    /* 界面 */
    page_model = new QStandardItemModel(this);
	
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    event->acceptProposedAction();
}
//bool MainWindow::eventFilter(QObject *watched, QEvent *event)   //用过滤器eventFilter（）拦截QLabel中的QEvent::Paint事件
//{
//	//if (watched == ui->label_display && event->type() == QEvent::Paint)
//		//paint();
//	//this->update();
//   
//
//	return QWidget::eventFilter(watched, event);
//}
void MainWindow::mousePressEvent(QMouseEvent* event)
{
    qDebug() << "Press";
    //直接点击效果图进行坐标的设置
    QPoint label_dipaly_point = ui->label_display->mapFromGlobal(QCursor::pos());
    oldPoint = label_dipaly_point;
    int lable_width  = ui->label_display->width();
    int lable_height = ui->label_display->height();
    int touch_x = label_dipaly_point.x();
    int touch_y = label_dipaly_point.y();
    if (touch_x > lable_width || touch_y > lable_height || touch_x < 0 || touch_y <0)
    {
        //不在显示范围，不处理
        return;
    }

    item_is_drop = CheckPointText(label_dipaly_point); //当前点击的控件id
    if (!item_is_drop)
    {
        //没有点击到
        current_item_id.clear();
    }

  
}
void MainWindow::mouseReleaseEvent(QMouseEvent* event)
{
 
    qDebug() << "Release";
    item_is_drop = false;
 
   
}
void MainWindow::mouseMoveEvent(QMouseEvent* event)
{
    qDebug() << "Move";
    QPoint point = ui->label_display->mapFromGlobal(QCursor::pos()); //鼠标相对控件的位置;
    int move_x = point.x() - oldPoint.x(); //x移动的距离
    int move_y = point.y() - oldPoint.y(); //y移动的距离
    int current_x = ui->spinBox_cood_x->value();
    int current_y = ui->spinBox_cood_y->value();
    int change_x = current_x + move_x;
    int change_y = current_y + move_y;
    oldPoint = point;
    if (item_is_drop)
    {
        ui->spinBox_cood_x->setValue(change_x);
        ui->spinBox_cood_y->setValue(change_y);
        on_updata_item_param();
    }
 
}
//显示合成的效果图
void MainWindow::paintEvent(QPaintEvent * event)
{

	//QPainter paint(this);   
    
    QPainter painter;
   // qDebug() << "paintEvent";
    int label_h = ui->label_display->height(); //  current_select_text.param.font_size;
    int label_w =  ui->label_display->width();//rec.width(); 

    QPixmap pix(label_w, label_h);
    pix.fill(QColor(Qt::black));
    painter.begin(&pix);
    /*进行预览图的绘画*/
    if (!priview_path.isEmpty())
    {    
        QImage Image;
        Image.load(priview_path);
        QPixmap pixmap = QPixmap::fromImage(Image);
       // QPixmap fitpixmap(priview_path);
            QPixmap fitpixmap = pixmap.scaled(label_w, label_h, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        painter.drawPixmap(QPoint(0, 0), fitpixmap);
     
    }
  
  
    DislayView(&painter); //画控件

    painter.end();
 
    ui->label_display->setPixmap(pix);
}

void MainWindow::dropEvent(QDropEvent *event)
{
    qDebug() << event->mimeData()->formats();
 
    QList formats = event->mimeData()->formats();
    for each (QString format in formats)
    {
        if (format == ("application/x-qabstractitemmodeldatalist"))
        {
          
        }
        else if (format ==  "application/x-qstandarditemmodeldatalist")
        {
           // qDebug() << event->
            if (event->source() == ui->listView_componnets)
            {
                /*  控件的拖拽添加*/          
                 creat_componnet_type =  ui->listView_componnets->currentIndex().data().toString();
                 creat_point = ui->label_display->mapFromGlobal(QCursor::pos()); //鼠标相对控件的位置
        
                CreatItem(creat_componnet_type, creat_point);
              

                
            }
        }
        else if (format == "text/uri-list")
        {
            QString filePath = event->mimeData()->urls().first().toLocalFile();
        
            QFileInfo info(filePath);

            if (filePath.isEmpty())
            {
                QMessageBox::warning(this, "Error", tr("The Path is Error!"));
                return;
            }

            if (info.isFile())
            {
                if (info.suffix() == "pxcp")
                {
                    
                    //对pxcp 文件进行分析 得到json文件和图片
                    if (pxcp->GetJsonAndImage(info.filePath()))
                    {
                        ui->textBrowser->setText("Read pxcp File succeed!");
                    }
                    else {
                        ui->textBrowser->setText("Read pxcp File failed!");

                    }
                    //多国语言处理
                    LanguageProcess();
                    return;
                    if (ui->tabWidget->currentIndex() == 4)
                    {
                       
                    }
                    else
                    {
                        //对pxcp 文件进行分析 得到json文件
                        if (pxcp->getJson(info.filePath()))
                        {
                            ui->textBrowser->setText("Read pxcp File succeed!");
                        }
                        else {
                            ui->textBrowser->setText("Read pxcp File failed!");

                        }
                    }
                }
                else if (info.suffix() == "xlsx")
                {
                    language->SetLanguageFileExcel(filePath);
                    languageTextSelect->SetTextList(language->text_id_list);

                }

                return;
            }           
   
        }

    }
    return;
   
}

void MainWindow::LanguageProcess()
{
    //pxcp->GetJsonAndImage("./1.pxcp");

   int index = 0;
   //显示图片
   QStringList page_list = pxcp->GetPages();

   QStandardItemModel* page_item_model = new QStandardItemModel(this);
   index = 0;
   for each (QString  page in page_list)
   {
       QString priview = pxcp->GetPriview(page);
       QStandardItem* item = new QStandardItem(QIcon(priview), page);
       page_item_model->setItem(index, 0, item);
       index++;

   }
   ui->listView_page->setModel(page_item_model);

   
}









int MainWindow::GetX()
{
    return ui->spinBox_cood_x->value();
}

int MainWindow::GetY()
{
    return ui->spinBox_cood_y->value();;
}





//int text_index = 0;
#define SAVE_TEXT_TO_IMAGE 0
void MainWindow::on_display_text(const QModelIndex index)
{
    //显示文字项
    QStandardItemModel* text_model = new QStandardItemModel(this);
    QString key = index.data().toString();
    QJsonArray textarray =  text_object.value(key).toArray();
    int font_size = ui->spinBox_font->value();
    QString font_family = ui->fontComboBox->currentText();
    int array_size = textarray.size();
  
    for (int i = 0; i < array_size; i++)
    {
#if SAVE_TEXT_TO_IMAGE
        QString file_name = "./TextImage/key_text";
        file_name.append(QString::number(text_index));
        file_name.append("_");
    
        file_name.append(QString::number(i));
        file_name.append(".bmp");
        language->TextGenerateImage(text, font_size, font_family, file_name);
#endif
        QString text = textarray.at(i).toString();
        QStandardItem* item = new QStandardItem(text);
        text_model->appendRow(item);
    }
//    text_index++;
    //ui->listView_text_select->setModel(text_model);


}

void MainWindow::on_display_page(const QModelIndex index)
{
   QString key =  index.data().toString();
   //font_page.Page = key;
   QString path = pxcp->GetPageImage(key);
   priview_path = path;
   ui->label_display->setScaledContents(true);
   ui->label_display->setPixmap(priview_path);
   this->update();
 
}

void MainWindow::on_select_language_file(int select)
{
    /* 语言切换*/
  
    current_lan = (Language_e)select;
   // qDebug() << "select language " << current_lan;
    language->SetLanguage(current_lan);
    ui->comboBox_texts->clear();
    if (!select_element_list.isEmpty())
    {
        QStringList text_list = language->GetText(select_element_list);
        ui->comboBox_texts->addItems(text_list);
    }
    return;
    if (language != nullptr)
    {
        text_object =   language->GetLanuageFile((Language_e)select);
        QStringList text_item_list = text_object.keys();
        //显示文字项
        QStandardItemModel* text_item_model = new QStandardItemModel(this);
        int index = 0;
        for each (QString  icontitel in text_item_list)
        {
            QStandardItem* item = new QStandardItem(icontitel);
            text_item_model->setItem(index, 0, item);
            index++;
        }
        //ui->listView_Text->setModel(text_item_model);

    }
}
void MainWindow::on_updata_select_content_list()
{
    ui->comboBox_texts->clear();
    
    if (!select_element_list.isEmpty())
    {
        if (watch_view->Fomat(current_item_id) == COMPONNET_FORMAT_TEXT)
        {
            QStringList text_list = language->GetText(select_element_list);
            ui->comboBox_texts->addItems(text_list);
        }
        else
        {
            int count = select_element_list.count();
            for (int i = 0; i < count; i++)
            {
               QString path = select_element_list.at(i);
               QString name = Utils::GetBaseName(path);
               
               QString current = watch_view->GetPriview(current_item_id);
              
               ui->comboBox_texts->addItem(QIcon(path), name);
            }
           
            
        }
        
    }   
   
   // qDebug() << "on_updata_select_content_list" << select_element_list;
    on_updata_item_param(); //更新参数
  
    
}
void MainWindow::on_updata_item_param()
{
    if (watch_view->contains(current_item_id))
    {
     
        ComponnetsItem current_item = watch_view->GetCurrentItem(current_item_id);
        /*尺寸*/
        int width = ui->spinBox_width->value();
        int height = ui->spinBox_height->value();
        int interval = ui->spinBox_spacing->value();
        current_item.interval = interval;
        current_item.size.setWidth(width);
        current_item.size.setHeight(height);
        if (current_item.fomat == COMPONNET_FORMAT_TEXT)
        {
            int font_size = ui->spinBox_font->value();
            QString font_family = ui->fontComboBox->currentText();
            int lineHeight = ui->spinBox_LineHeight->value();
            int spacing = ui->spinBox_spacing->value();
            /*位置*/
            language_offset text_point;
            if (current_item.text_point.contains(current_lan))
            {
                //如果当前的语言有对应的坐标
                text_point = current_item.text_point.value(current_lan);
            }    
             /*更新当前语言的信息*/
            text_point.x = GetX();
            text_point.y = GetY();
            text_point.lineHeight = lineHeight;
            text_point.spacing = spacing;
          
            current_item.text_point.insert(current_lan, text_point);

            current_item.font.param.font_size = font_size;
            current_item.font.param.family = font_family;
            current_item.element_list.clear();
            current_item.element_list.append(select_element_list);
            //qDebug() << "id"<< current_item_id << "updata" << text_point.x << current_lan;
            QString text = ui->comboBox_texts->currentText();
            if (!text.isEmpty())
            {
                current_item.current_element = text;
            }
            
        
        }
        else
        {
            current_item.point.setX(GetX());
            current_item.point.setY(GetY());
            current_item.element_list.clear();
            current_item.element_list.append(select_element_list);
            int index  = ui->comboBox_texts->currentIndex();
            QString cur_digit = ui->comboBox_number->currentData().toString(); //当前的位数
            if (!select_element_list.isEmpty() && (index != -1))
            {
                QString current_element = select_element_list.at(index);
               // qDebug() << "current_element" << current_element;
                if (!current_element.isEmpty())
                {
                    current_item.current_element = current_element;
                }
                if (current_item.size.height() == 0)
                {
                    //如果显示的图片没有设置高度则用第一张作为高度的设置
                    QImage image(current_element);
                   
                    if (!image.isNull())
                    {
                        current_item.size = image.size();
                       
                    }                                     
                }
                if (watch_view->Type(current_item_id) == COMPONNET_TYPE_NUMBER)
                {
                    //数字的要进行坐标的初步计算
                    int digit = watch_view->Digit(current_item.fomat); //获取对应数字的位数
                   
                    Utils::CalcNumberPoints(current_item.size, current_item.point, &current_item.points, digit, current_item.interval);
                  
                   
                    if (current_item.element_lists.count() == 0)
                    {
                        int width = current_item.size.width();
                        current_item.size.setWidth((current_item.interval + width) * digit);
                        qDebug() << "size" << current_item.size;
                        //如果完全没有切图,则按位数保存选择的同样切图
                        for (int i = digit - 1; i >= 0 ; i--)
                        {
                            current_item.element_lists.insert(i, select_element_list);//根据万，千，百，十，个，的顺序保存
                            
                        }           

                    }
                    else
                    {
                        //如果有切图,则按对应的位数保存
                        if (!cur_digit.isEmpty())
                        {
                            int int_digit = watch_view->DigitToInt(cur_digit);
                            current_item.element_lists.insert(int_digit, select_element_list);//根据万，千，百，十，个，的顺序保存
                        }
                        
                        
                    }
                }
                else
                {
                    //不是数字的，只保持一位
                    current_item.points.insert(0, current_item.point);
                }
            }   

        }
        watch_view->AppendItem(current_item_id, current_item);
      
        
    }
   CodeJson* josn1 = new CodeJson(this);
    josn1->FontParamToJson(watch_view->GetPage(current_page_id));
    ui->textBrowser->setText(josn1->GetCode());
    ui->TB_Positon->setText(josn1->GetCodeAddrArry());
    this->update();
}
void MainWindow::on_selected_item(QModelIndex index)
{
      int row =  index.row();
      QModelIndex row_index = ui->treeView_slelect_items->model()->index(row, 0);
      QString select_id = row_index.data().toString();
      SelectingItem(select_id);
}
void MainWindow::on_creat_item()
{
    CreatItem(creat_componnet_type, &creat_point);
    SaveSelectedItem(creat_componnet_type, current_item_id); //保存当前的控件ID
    on_updata_select_content_list(); 
}
void MainWindow::on_create_page()
{
    watch_view->AppendPage();
    QString page_id = watch_view->CurrentPageId();
    page_model->appendRow(new QStandardItem(page_id));
    ui->lv_Page_Select->setModel(page_model);
}
void MainWindow::on_lond_language_file()
{
    if (watch_view->Fomat(current_item_id) == COMPONNET_FORMAT_TEXT)
    {
        /* 文字选中窗口显示*/
        languageTextSelect->SetSelectedText(&select_element_list);
        languageTextSelect->show();
    }
    else
    {
        imageSelectWidget->setSelectedImage(&select_element_list);
        imageSelectWidget->SetMode(SELECT_MODE_APPEND);
        imageSelectWidget->show();
    }
    


   
    return;

    QString	path = QFileDialog::getExistingDirectory(this, "选择字库路径", "./");
    QFileInfo lan_path(path);
    if (lan_path.isDir())
    {
        QDir dir(path);
    
        foreach(QFileInfo fileInfo, dir.entryInfoList(QDir::Dirs | QDir::Files, QDir::DirsFirst))
        {
            if (fileInfo.isFile())
            {
                QString suffix = fileInfo.suffix();
                if (suffix == "c" && fileInfo.fileName().contains("param"))
                {
                    // 翻译文件
                    language->SetLanguageFile(fileInfo.filePath());
                    on_select_language_file(ui->CB_language->currentIndex());
                }
                else  if (suffix == "json" && fileInfo.fileName().contains("param"))
                {
                    language->SetParamJsonFile(fileInfo.filePath());

                }
                else if (suffix == "xlsx")
                {
                    language->SetLanguageFileExcel(fileInfo.filePath());
                    //languageTextSelect->SetTextList(test);
                    //languageTextSelect->show();
                }
               


           
            }
        }
    }
    else
    {
        qDebug() << "拖错文件啦!";
    }

}
bool MainWindow::CheckPointText(QPoint touch)
{
    /*  只用在文本上的*/
     /* 根据文字的位置和大小判断是否点击在此位置*/
   
    QStringList *view_id_list = watch_view->GetViewId(current_page_id);
    if (view_id_list == nullptr)
    {
        return false;
    }
    int id_count = view_id_list->count();
    //for each(QString id in view_id_list)
    for(int i = id_count - 1; i >= 0; i--)
    {   
        QString id = view_id_list->at(i);
        int height = watch_view->Height(id);
        int width = watch_view->Width(id);
        QPoint point = watch_view->GetPoint(id, current_lan);
        int x = point.x();
        int y = point.y();     
        int end_x = x + width;
        int end_y = y + height;
        
        if (touch.x() > end_x || touch.x() < x || touch.y() > end_y || touch.y() < y)
        {
          
        }
        else
        {
            
            SelectingItem(id);
            return true;
        }
    }
    return false;
}



void MainWindow::CreatTextItem(QPoint *point)
{
    ComponnetsItem item;
   // current_item = item;
    item.id = watch_view->Count() + 1;//items_map.count() + 1;
    QString id_str = QString::number(item.id);
    current_item_id = id_str;
    select_element_list.clear(); //清除当前的文字列表
    ui->comboBox_texts->clear();
    languageTextSelect->SetSelectedText(&select_element_list);
 
    languageTextSelect->show();// 显示文本选择框
    
    item.current_element = "Text";
    item.fomat = COMPONNET_FORMAT_TEXT;

    int font_size = ui->spinBox_font->value();
    int lineHeight = ui->spinBox_LineHeight->value();
    int spacing = ui->spinBox_spacing->value();
    //获取文本的范围
    QString font_family = ui->fontComboBox->currentText();
    QRect rect = language->GetTextRect(item.current_element, font_size, font_family);
    int width = rect.width();
    int height = rect.height();

    int x = point->x();
    int y = point->y();
    item.size.setWidth(width);
    item.size.setHeight(height);
    /*  这里要添加推荐的坐标*/
    language_offset text_point;
    text_point.x = x;
    text_point.y = y;
    text_point.lineHeight = lineHeight;
    text_point.spacing = spacing;
    item.point = QPoint(x , y);
    item.text_point.insert(current_lan, text_point);
   
    watch_view->AppendItem(current_item_id, item); //添加新的控件
    watch_view->SetCurrentItem(current_item_id);

   
    ui->spinBox_width->setValue(width);
    ui->spinBox_height->setValue(height);

    ui->spinBox_cood_x->setValue(x);
    ui->spinBox_cood_y->setValue(y);


}

void MainWindow::CreatItem(QString componnet_type, QPoint point)
{  
    if (componnet_type == "文本")
    { 
        CreatTextItem(&point);

    }
    else
    {
        select_element_list.clear(); //清除当前的文字列表
        imageSelectWidget->setSelectedImage(&select_element_list);
        imageSelectWidget->SetMode(SELECT_MODE_CREAT);
        imageSelectWidget->show();
       //CreatItem(componnet_type , &point);
    }
   
}

void MainWindow::CreatNumber(QString componnet_type, QPoint *point)
{
    ComponnetsItem item;
    //添加id
    item.id = watch_view->Count() + 1;
    QString id = QString::number(item.id);
    current_item_id = id;

    item.fomat = watch_view->GetComponnetType(componnet_type);// COMPONNET_FORMAT_BETTARY;
    //选择图片
    select_element_list.clear(); //清除当前的文字列表
    ui->comboBox_texts->clear();
    imageSelectWidget->setSelectedImage(&select_element_list);
    imageSelectWidget->show();
    //设置默认参数
    int x = point->x();
    int y = point->y();
    int width = 0;
    int height = 0;

    //item.point = QPoint(x, y);
    //item.size.setWidth(width);
    //item.size.setHeight(height);


    select_element_list.clear(); //清除当前的文字列表
    ui->comboBox_texts->clear();

    watch_view->AppendItem(current_item_id, item); //添加新的控件
    watch_view->SetCurrentItem(current_item_id);


    ui->spinBox_width->setValue(width);
    ui->spinBox_height->setValue(height);

    ui->spinBox_cood_x->setValue(x);
    ui->spinBox_cood_y->setValue(y);


}

void MainWindow::CreatItem(QString componnet_type, QPoint* point)
{
    ComponnetsItem item;
    //添加id
    qDebug() << "CreatItem" << watch_view->Count();
    item.id = watch_view->Count() + 1;
    QString id = QString::number(item.id);
    current_item_id = id;
    item.count = 1;
    item.fomat = watch_view->GetComponnetType(componnet_type);// COMPONNET_FORMAT_BETTARY;
    //选择图片
    //select_element_list.clear(); //清除当前的文字列表
    //ui->comboBox_texts->clear();
    //imageSelectWidget->setSelectedImage(&select_element_list);
    //imageSelectWidget->SetMode(SELECT_MODE_CREAT);
    //imageSelectWidget->show();

    if (!select_element_list.isEmpty())
    {
        QString current_element = select_element_list.at(0);
        QImage image(current_element);
        item.size =  image.size();
    }
     
    //设置默认参数
    int x = point->x();
    int y = point->y();
    int interval = 0;
    item.interval = interval;
    item.point = QPoint(x, y);
  
    watch_view->AppendItem(current_item_id, item); //添加新的控件
    watch_view->SetCurrentItem(current_item_id);
    ui->comboBox_number->clear();
    if (watch_view->Type(id) == COMPONNET_TYPE_NUMBER)
    {
        item.count = watch_view->Digit(item.fomat);
        //数字的话，还得显示位数选择
        for (int i = item.count - 1; i >= 0; i --)
        {
            ui->comboBox_number->addItem(watch_view->DigitToString(i));//根据万，千，百，十，个，的显示
        }
        
    }
    
    ui->comboBox_texts->clear();
    ui->spinBox_spacing->setValue(interval);
    ui->spinBox_width->setValue(item.size.width());
    ui->spinBox_height->setValue(item.size.height());

    ui->spinBox_cood_x->setValue(x);
    ui->spinBox_cood_y->setValue(y);



}

void MainWindow::SelectingItem(QString id)
{
    current_item_id = id;
    QString format = watch_view->Fomat(id);
    
     //if (format == COMPONNET_FORMAT_BETTARY)
    {
        QPoint point = watch_view->GetPoint(id, current_lan);
        int x = point.x();
        int y = point.y();
        int width = watch_view->Width(id);
        int height = watch_view->Height(id);
        int interval = watch_view->interval(id);
        select_element_list.clear();
        QStringList element_list = watch_view->GetElementList(id);
        select_element_list.append(element_list);
        if (format == COMPONNET_FORMAT_TEXT)
        {
            int font_size = watch_view->FontSize(id);
            ui->spinBox_font->setValue(font_size);
        }
        ui->spinBox_cood_x->setValue(x);
        ui->spinBox_cood_y->setValue(y);
        ui->spinBox_width->setValue(width);
        ui->spinBox_height->setValue(height);
        ui->spinBox_spacing->setValue(interval);
        //ui->comboBox_texts->clear();

        on_updata_select_content_list();
    }
}

void MainWindow::DislayView(QPainter* painter)
{
   // QStringList view_id_list = watch_view->GetViewId();
    QStringList* view_id_list = watch_view->GetViewId(current_page_id);
    if (view_id_list == nullptr)
    {
        return ;
    }
    for each (QString id in *view_id_list)
    {
        int draw_x = watch_view->X(id);
        int draw_y = watch_view->Y(id);
        int width = watch_view->Width(id);
        int height = watch_view->Height(id);
        QString fomat = watch_view->Fomat(id);
        QPoint point(draw_x, draw_y);
        QRect rect(draw_x, draw_y, width, height);
        if (fomat == COMPONNET_FORMAT_TEXT)
        {
            font_t font_text;
            font_text.title = watch_view->GetPriview(id);
            font_text.param.font_size = watch_view->FontSize(id);
            font_text.param.family = watch_view->Family(id);

            QPoint point = watch_view->GetPoint(id, current_lan);
            font_text.param.x = point.x();
            font_text.param.y = point.y();

            draw_x = font_text.param.x;
            draw_y = font_text.param.y;
            language->DarwText(painter, &font_text);
        }
        else //if (fomat == COMPONNET_FORMAT_BETTARY)
        {
           
            if (watch_view->Type(id) == COMPONNET_TYPE_NUMBER)
            {
               //拿每个位数的第一张进行显示
                QMap<int, QStringList>* elem_lists =  watch_view->GetElementLists(id);
                QMap<int, QPoint>* elem_points = watch_view->GetPoints(id);
                int digit_count = elem_lists->count(); //多少位数
                int digit = 0;
                int interval = watch_view->interval(id);
                //rect.setWidth((width + interval) * digit_count); //设置这个数字的宽度
                for each (QStringList element in elem_lists->values())
                {
                    QPoint point = elem_points->value(digit);
                 
                    QRect rect(point.x(), point.y(), width, height);
                    QString image_path = element.at(0); //只拿第一张
                    if (image_path.isEmpty())
                    {
                        painter->setPen(QColor(255, 100, 255));
                        painter->drawRoundedRect(rect, 10, 10);
                    }
                    else
                    {
                        painter->drawImage(point, QImage(image_path));
                    }
                    digit++;
                }
                
            }
            else
            {
                QString image_path = watch_view->GetPriview(id);
                if (image_path.isEmpty())
                {
                    painter->setPen(QColor(255, 100, 255));
                    painter->drawRoundedRect(rect, 10, 10);
                }
                else
                {
                    painter->drawImage(point, QImage(image_path));
                }
            }

           
           
        }

        if (id == current_item_id)
        {
            //点击到当前的id，进行矩形的绘画
            painter->setPen(QColor(50, 100, 50));
            painter->drawRect(rect);
        }
    }
}

void MainWindow::SaveSelectedItem(QString type, QString id)
{
    //添加到已选择的控件列表中  
    QStandardItem* item_type = new QStandardItem(type);
    int row_count = selected_items_model->rowCount();
    selected_items_model->setItem(row_count, 1, item_type);
    selected_items_model->setItem(row_count, 0, new QStandardItem(id));
    ui->treeView_slelect_items->setModel(selected_items_model);
}
