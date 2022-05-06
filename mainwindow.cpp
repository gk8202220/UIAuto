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

#pragma execution_character_set("UTF-8")

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setAcceptDrops(true);
    json = new pxcpJson();
    ui->CB_old->setChecked(false);
	ui->label_display->installEventFilter(this); //这行不能省
    language = Language::GetInstance();
    current_lan = (Language_e)ui->CB_language->currentIndex();
   // WatchComponentsWidget  watchComponentsWidget = new WatchComponentsWidget(this);
    QStandardItemModel  *components_model = new QStandardItemModel(this);
    QStandardItem* item = new QStandardItem("文本");
    QStandardItem* item1= new QStandardItem("电池");
    components_model->setItem(0,0,item);
    components_model->setItem(1, 0, item1);
    ui->listView_componnets->setModel(components_model);
    selected_items_model  = new QStandardItemModel(this);
    selected_items_model->setHorizontalHeaderItem(0, new QStandardItem("ID"));
    selected_items_model->setHorizontalHeaderItem(1, new QStandardItem("属性"));
    //文本选择界面
    //  QStringList test = { "nihao","zhong" };
     languageTextSelect = new LanguageTextSelect();
     languageTextSelect->SetSelectedText(&select_text_list);
     QObject::connect(languageTextSelect, SIGNAL(updata_text()), this, SLOT(on_updata_select_text_list()));


   // watchComponentsWidget.setGeometry(0, 0, 100, 100);
   // watchComponentsWidget.show();
    if(ui->CB_FunSelect->currentIndex() == 2)
    {
        setPostionFun = "LCD_SetPosition(icon_16_";
        WriteDataFun ="LCD_DriverWriteDataFromExtFlash(icon_16_";

    }
    else if(ui->CB_FunSelect->currentIndex() == 1){
        setPostionFun = "LCD_SetPositionType2(index,icon_16_";
        WriteDataFun ="LCD_DriverWriteDataFromExtFlashType2(index,icon_16_";
    }
    else if(ui->CB_FunSelect->currentIndex() == 3){
        setPostionFun = "Gui_PageClearBackgroundType2(index,icon_16_";
        WriteDataFun ="LCD_DriverWriteDataFromExtFlashType2(index,icon_16_";
    }
    else if(ui->CB_FunSelect->currentIndex() == 0){
        setPostionFun = "LCD_SetXY(icon_16_";
        WriteDataFun ="LCD_SetImage(icon_16_";
    }
    else {
        setPostionFun = "Gui_PageClearBackground(icon_16_";
        WriteDataFun ="LCD_DriverWriteDataFromExtFlash(icon_16_";
    }
    if (ui->tabWidget->currentIndex() == 4)
    {

        //多国语言处理
        LanguageProcess();
    }
	
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    event->acceptProposedAction();
}
bool MainWindow::eventFilter(QObject *watched, QEvent *event)   //用过滤器eventFilter（）拦截QLabel中的QEvent::Paint事件
{
	//if (watched == ui->label_display && event->type() == QEvent::Paint)
		//paint();
//		this->update();
   


	return QWidget::eventFilter(watched, event);
}
void MainWindow::mousePressEvent(QMouseEvent* event)
{
    qDebug() << "Press";
    //直接点击效果图进行坐标的设置
    //点击是选中
    QPoint point = event->pos();
    int label_x = ui->label_display->x();
    int label_y = ui->label_display->y();
    int lan = ui->CB_language->currentIndex();
    /*
     check_text_index = CheckPointText(point.x()- label_x, point.y() - label_y);
    if (check_text_index != -1)
    {
        SelectedText(check_text_index); //选中已有的文字
        item_is_drop = true;
    }
    else
    {
        item_is_drop = false;
    }
   */
    item_is_drop = CheckPointText(point.x() - label_x, point.y() - label_y); //当前点击的控件id
    if (!item_is_drop)
    {
        //没有点击到
        current_item_id.clear();
    }
                                                                             // qDebug() << "Press" << check_text_index;

    //if (point.x() >= label_x && point.x() < label_x + ui->label_display->width()
    //    && point.y() >= label_y && point.y() < label_y + ui->label_display->height()
    //    )
    //{
    //    int touch_x = point.x() - label_x;
    //    int touch_y = point.y() - label_y;
    //    


    //}
  
}
void MainWindow::mouseReleaseEvent(QMouseEvent* event)
{
 
    qDebug() << "Release";
    item_is_drop = false;
    /*
    if (item_is_drop)
    {
        language->FontParamToJson(&item_text_list.value(check_text_index), &font_page); //保存所有选中的文字
    }
    */
   
}
void MainWindow::mouseMoveEvent(QMouseEvent* event)
{
    qDebug() << "Move";
    QPoint point = event->pos();
    int label_x = ui->label_display->x();
    int label_y = ui->label_display->y();
    int touch_x = point.x() - label_x;
    int touch_y = point.y() - label_y;
    if (item_is_drop)
    {
        /*
        QMap<Language_e, font_t> font_map = item_text_list.value(check_text_index);
        font_t  font_text= font_map.value(current_lan);
        if (current_select_text != nullptr)
        {
            ui->spinBox_cood_x->setValue(touch_x);
            ui->spinBox_cood_y->setValue(touch_y);
            font_text.param.x = touch_x;
            font_text.param.y = touch_y;
            current_select_text = &font_text;
           // qDebug() << "move" << current_select_text->title;
            font_map.insert(current_lan, font_text);
            item_text_list.insert(check_text_index, font_map);

        }
        */
        ui->spinBox_cood_x->setValue(touch_x);
        ui->spinBox_cood_y->setValue(touch_y);
        on_updata_item_param();
    }
 
}
//显示合成的效果图
void MainWindow::paintEvent(QPaintEvent * event)
{

	QPainter paint(this);
 
   
    // 大小
   
    // 设置字符间距
  //  font.setLetterSpacing(QFont::AbsoluteSpacing, 20);

    // 使用字体
    
    
    int label_x = ui->label_display->x();
    int label_y = ui->label_display->y();
	pxcpJson json;
    QPainter painter;


 /*   current_select_text.param.x = ui->spinBox_cood_x->value();
    current_select_text.param.y = ui->spinBox_cood_y->value();
    current_select_text.param.font_size = ui->spinBox_font->value();
    QFontMetrics me(font);
    QRect rec = me.boundingRect(current_select_text.title);*/

    int label_h = ui->label_display->height(); //  current_select_text.param.font_size;
    int label_w =  ui->label_display->width();//rec.width();
   


    QPixmap pix(label_w, label_h);
    pix.fill(QColor(Qt::black));
    painter.begin(&pix);
    /*进行预览图的绘画*/
    if (!priview_path.isEmpty())
    {
        //ui->label_display->setPixmap(priview_path);            
        painter.drawImage(QPoint(0, 0), QImage(priview_path));
     /*   QImage image(priview_path);
        qDebug() << image.width() << image.height();
        image.scaled(ui->label_display->width(), ui->label_display->height(),Qt::KeepAspectRatio);
        ui->label_display->setPixmap(priview_path);
        paint.drawImage(label_x, label_y, image);*/
     
    }
    /*进行文字的绘画*/
    for each (int i  in item_text_list.keys())
    {
        font_t font_text = item_text_list.value(i).value(current_lan);
     
        language->DarwText(&painter, &font_text);
    
    }
    //for each (ComponnetsItem var in items_map.values())
    for each(QString id in items_map.keys())
    {
        ComponnetsItem var = items_map.value(id);
        if (var.fomat == "Text")
        {
            font_t font_text;
            font_text = var.font;
            font_text.title = var.text;
            font_text.param.x = var.point.x();
            font_text.param.y = var.point.y();
            language->DarwText(&painter, &font_text);
           // painter.drawText(var.point, var.text);
        }
        if (id == current_item_id)
        {
            //点击到当前的id，进行矩形的绘画
            painter.drawRect(var.point.x(), var.point.y(), var.size.width(), var.size.height());

        }
    }

    painter.end();
    ui->label_display->setPixmap(pix);
    
	if (!iconArray.isEmpty())
	{
		for (int i = 0; i< iconArray.size(); i++)
		{
			//qDebug() << "aaa";

			QJsonObject  rectInfo = iconArray.at(i).toObject();
			int x = rectInfo.value("x").toInt() + ui->label_display->x();
			int y = rectInfo.value("y").toInt() + ui->label_display->y();
			//显示大背景
			if (x == 0 && y == 0)
			{
				QString filePath1 = rectInfo.value("path").toString();
				if (!filePath1.isEmpty())
				{
					
					//QImage *image = new QImage(filePath1);
					//paint.drawImage(x, y, *image);
					if (x == 240 && y == 240)
					{
						continue;
					}
					paint.drawPixmap(x, y, QPixmap(filePath1));
					break;

				}
			}

		}
		for (int i = 0; i< iconArray.size(); i++)
		{


			QJsonObject  rectInfo = iconArray.at(i).toObject();
			int x = rectInfo.value("x").toInt() + ui->label_display->x();;
			int y = rectInfo.value("y").toInt() + ui->label_display->y();;
			if (x == ui->label_display->x() && y == ui->label_display->y())
			{
				continue;
			}
			// int height =rectInfo.value("height").toInt();
			// int width = rectInfo.value("width").toInt();
			QString filePath1 = rectInfo.value("path").toString();
			//qDebug() << "*********显示切图*********";
			//qDebug()<<"x = "<< x << ",y =  " << y  << ",parh = " << filePath1;
			/*QImage *image = new QImage(filePath1);
			if (!image->isNull())
			{
				paint.drawImage(x, y, *image);
			}*/
			
			paint.drawPixmap(x, y, QPixmap(filePath1));
				
		}

	}
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
                /*  控件的拖拽*/
                qDebug() << "listView_componnets";
                QString componnet_type =  ui->listView_componnets->currentIndex().data().toString();
                if (componnet_type == "文本")
                {
                    QPoint point = event->pos();
                    CreatTextItem(&point);
                    
                }
                
              

                
            }
        }
        else if (format == "text/uri-list")
        {
            QString file_path = event->mimeData()->urls().first().toLocalFile();
           // readexcel *excel = new readexcel(this);
            //excel->read(file_path); 
            language->SetLanguageFileExcel(file_path);
            languageTextSelect->SetTextList(language->text_id_list);
           
            languageTextSelect->show();


        }

    }
    return;
    this->filePath =  event->mimeData()->urls().first().toLocalFile();
    QFileInfo info(filePath);

    if(filePath.isEmpty())
    {
        QMessageBox::warning(this, "Error",tr("The Path is Error!"));
        return;
    }
  
    if(info.isFile() &&   info.suffix() == "pxcp")
    {
        if (ui->tabWidget->currentIndex() == 4)
        {        
            //对pxcp 文件进行分析 得到json文件和图片
            if (json->GetJsonAndImage(info.filePath()))
            {
                ui->textBrowser->setText("Read pxcp File succeed!");
            }
            else {
                ui->textBrowser->setText("Read pxcp File failed!");

            }
            //多国语言处理
            LanguageProcess();
        }
        else
        {
            //对pxcp 文件进行分析 得到json文件
            if (json->getJson(info.filePath()))
            {
                ui->textBrowser->setText("Read pxcp File succeed!");
            }
            else {
                ui->textBrowser->setText("Read pxcp File failed!");

            }
        }
     
        return;
    }
   
    if(!info.isDir())
    {
        QMessageBox::warning(this,"Error",tr("The Path is Error!"));
        return;
    }
	if (ui->tabWidget->currentIndex() == 3)
	{
		//专门获取地址
		getBmpAddr(filePath);
	}
  
	else
	{
       
		if (ui->CB_old->isChecked())
		{
			file = new QFile(filePath + "/gui_flash_param.h");
			file_c = new QFile(filePath + "/gui_flash_param.c");
		}

		ui->lineEdit->setText(filePath);
		if (ui->CB_old->isChecked())
		{
			//if (!file->open(QIODevice::WriteOnly))
				//QMessageBox::warning(this, "警告", "请检测gui_flash_param.h路径!");
			//if (!file_c->open(QIODevice::WriteOnly))
				//QMessageBox::warning(this, "警告", "请检测gui_flash_param.h路径!");
		}
		// json->getBmpPaths(filePath);
		jsonPaths.clear();
		AllJsonAnalysis(filePath);
		foreach(QString path, jsonPaths)
		{
			//pxcpJson *json = new pxcpJson();
			 //json->setPath(path);
			json->jsonAnalysis(path);
		}
		iconArray = json->geticonArray(filePath);
		initDisplay();

		//mainDisplay(filePath);
        //getBmpPaths(filePath);
        saveBmpPaths(filePath);
     
		display();
		if (ui->CB_old->isChecked())
		{
			file->close();
			file_c->close();
		}

	}
}
void MainWindow::DislayAddrParm(QString Image_title, QJsonArray image_arry)
{
  
    /***Write file "gui_flash_param.c"***/
    QString tiles1 = "const uint32_t icon_16_" + Image_title + "_addr";
    tiles1.append("[" + QString::number(image_arry.count()) + "] = " + "\n{");
    ui->TB_Positon->append(tiles1);
    QByteArray data;
    for (int i = 0; i < image_arry.count(); i++)
    {
        QString icon_name;// = image_arry.at(i).toString();
        QStringList iconList = image_arry.at(i).toString().split("_");
        //指针
        if (iconList.at(0) == "zz" || iconList.at(0) == "zzz")
        {
            for (int i = 1; i < iconList.count(); i++)
            {
                icon_name += iconList.at(i);
            }          
        }
        else
        {
            icon_name = image_arry.at(i).toString();
        }
        qDebug() << icon_name;
        //获取坐标并写入
        QString addr_str = "   ICON_" + icon_name.toUpper() + "_ADDR,";
        data.append(addr_str.toLocal8Bit());
        if (i % 3== 0 || i == image_arry.count() - 1)
        {
            ui->TB_Positon->append(data);
            data.clear();
        }        
      
    }   
    qDebug() << "***" << Image_title << image_arry;
    ui->TB_Positon->append("};"); //写参数表
    ui->TB_head->append("extern const uint32_t icon_16_" + Image_title + "_addr[" + QString::number(image_arry.count()) + "];");  //写头文件声明
   

    //显示地址
    QList<int> position_x;
    QList<int> position_y;
    if (!iconArray.isEmpty())
    {   
        for (int i = iconArray.size() - 1; i >= 0; i--)
        {
            QJsonObject  rectInfo = iconArray.at(i).toObject();
            int x = rectInfo.value("x").toInt();
            int y = rectInfo.value("y").toInt();
            //根据高度和宽度匹配到对应的切图路径
            QString path = rectInfo.value("path").toString();
             //根据高度和宽度匹配到对应的切图路径           
            if (path.toLower().contains(Image_title))
            {
                  if (position_x.count() == 0)
                  {
                      position_x.append(x);
                      position_y.append(y);
                  }
                  else
                  {
                      bool HasSave = true; //是否保存
                      for (int index = 0; index < position_x.count(); index++)
                      {
                          //排除重复的
                          if (abs(position_x.at(index)- x) < 2 && abs(position_y.at(index) - y) < 2)
                          {
                              HasSave = false;
                          }
                      }
                      if (HasSave)
                      {
                          position_x.append(x);
                          position_y.append(y);
                      }
                  }
                }
            }
        }
        //显示对应坐标
        int last_y = 0;
        QString position_all;
        QList<int> position_temp_x;
        QList<int> position_temp_y;
        position_all.append("const uint16_t icon_16_" + Image_title + "_coord["+ QString::number(position_x.count())+"][2] = \n{\n");
        for (int index = 0; index < position_x.count(); index++)
        {
            int x = position_x.at(index);
            int y = position_y.at(index);
            position_temp_x.append(x);
            position_temp_y.append(y);
           //按y坐标分组
            if (last_y != y)
            {
                last_y = y;
                //按x大小排序
				//在QT6中找不到这个函数
                //qSort(position_temp_x.begin(), position_temp_x.end());
                for (int i = 0; i < position_temp_x.count(); i++)
                {
                   // qDebug() << "x = " << QString::number(position_temp_x.at(i), 10) << "y = " << position_temp_y.at(i);
                   
                    position_temp_x.clear();
                    position_temp_y.clear();
                }
                position_all.append("\n");
               
            }
            position_all.append("\t{" + QString::number(x) + "," + QString::number(y) + "}," );
          
        }
        position_all.append("\n};\n");
        ui->TB_Positon->append(position_all);
        ui->TB_head->append("extern const uint16_t icon_16_"+ Image_title + "_coord["+ QString::number(position_x.count())+"][2];\n");

    

    
}
void MainWindow::LanguageProcess()
{
    //json->GetJsonAndImage("./1.pxcp");

   int index = 0;
   //显示图片
   QStringList page_list = json->GetPages();

   QStandardItemModel* page_item_model = new QStandardItemModel(this);
   index = 0;
   for each (QString  page in page_list)
   {
       QString priview = json->GetPriview(page);
       QStandardItem* item = new QStandardItem(QIcon(priview), page);
       page_item_model->setItem(index, 0, item);
       index++;

   }
   ui->listView_page->setModel(page_item_model);

   
}
void MainWindow::saveBmpPaths(QString path)
{
    Image_Path_Map.clear();
    titleList.clear();  
   //bmpbin.clear();
    ui->TB_Positon->append("\n/**********" + QFileInfo(path).fileName() + "**********/\n");
    ui->TB_head->append("\n/**********" + QFileInfo(path).fileName() + "**********/\n");
    getBmpPaths(filePath);
   // qDebug() << "saveBmpPaths" << QFileInfo(path).fileName();
    if (Image_Path_Map.isEmpty())
    {
        qDebug() << "get image error !";
    }
    else
    {
        QString last_image_title; //相同大小类型的切图以前下划线的前两个作为区分
        QStringList imageList;
        foreach(QString key, Image_Path_Map.keys())
        {
            QStringList imageNameList = key.split("_");  //切分图片命名
            QString image_title;
            if (imageNameList.at(0).contains("zz"))
            {
                //指针图片
                image_title = imageNameList.at(1) + "_" + imageNameList.at(2); //去掉zz字母
            }
            else
            {
                //正常图片
                image_title = imageNameList.at(0) + "_" + imageNameList.at(1);
            }

            if (last_image_title != image_title)
            {

                if (!last_image_title.isEmpty() && !imageList.isEmpty())
                {

                    //保存前两位的标题（035main_data4）和对应的所有切图（s035main_data4_mlg_00","s035main_data4_mlg_01","s035main_data4_mlg_02","s035main_data4_mlg_03","s035main_data4_mlg_04"）
                    QJsonArray iconArray;
                    foreach(QString name, imageList)
                    {
                        iconArray.append(QJsonValue(name));
                    }

                    titleList.append(last_image_title);
                    Title_Image_json.insert(last_image_title, iconArray); //保存title 对应所有image 的json
                    imageList.clear();

                }
                last_image_title = image_title;
            
            }
            imageList.append(key);
            //qDebug() << Image_Path_Map.value(key);
        }
        //最后一次也要添加
        if (!last_image_title.isEmpty() && !imageList.isEmpty())
        {

            //保存前两位的标题（035main_data4）和对应的所有切图（s035main_data4_mlg_00","s035main_data4_mlg_01","s035main_data4_mlg_02","s035main_data4_mlg_03","s035main_data4_mlg_04"）
            QJsonArray iconArray;
            foreach(QString name, imageList)
            {
                iconArray.append(QJsonValue(name));

            }           
            titleList.append(last_image_title);
           // qDebug() << last_image_title << iconArray;
            Title_Image_json.insert(last_image_title, iconArray); //保存title image 的json
            imageList.clear();

        }
        // 保存json完成
        QJsonDocument doc;
        doc.setObject(Title_Image_json);
        iconModel = new QStandardItemModel(this);
        //qDebug() << doc.toJson(QJsonDocument::Compact);

        //设置切图类型的选择
        //取每个类型第一个切图进行坐标的获取
        int index = 0;
        for each (QString  icontitel in titleList)
        {

            QString iconfilepath = Image_Path_Map.value(Title_Image_json.value(icontitel).toArray().at(0).toString());
            DislayAddrParm(icontitel, Title_Image_json.value(icontitel).toArray());
            QStandardItem* item = new QStandardItem(QIcon(iconfilepath), icontitel);
            iconModel->setItem(index, 0, item);
            index++;

        }
    }
}
int addr_count = 0;


void MainWindow::UI_time(QString title)
{
    ui->textBrowser->append("\n//***** 时间 ****//");
    ui->textBrowser->append( setPostionFun+title.toLower()+"_coord[0][0],icon_16_"+title.toLower()+"_coord[0][1],");
    ui->textBrowser->append("\t\tICON_"+title.toUpper()+"_WIDE,"+ "ICON_"+title.toUpper()+"_HIGH);");
    ui->textBrowser->append( WriteDataFun+title.toLower()+"_addr[hour / 10 % 10 % 3],ICON_"+title.toUpper()+"_SIZE);");
    ui->textBrowser->append("");
    ui->textBrowser->append( setPostionFun+title.toLower()+"_coord[1][0],icon_16_"+title.toLower()+"_coord[1][1],");
    ui->textBrowser->append("\t\tICON_"+title.toUpper()+"_WIDE,"+ "ICON_"+title.toUpper()+"_HIGH);");
    ui->textBrowser->append( WriteDataFun+title.toLower()+"_addr[hour % 10],ICON_"+title.toUpper()+"_SIZE);");
    ui->textBrowser->append("");
    ui->textBrowser->append( setPostionFun+title.toLower()+"_coord[2][0],icon_16_"+title.toLower()+"_coord[2][1],");
    ui->textBrowser->append("\t\tICON_"+title.toUpper()+"_WIDE,"+ "ICON_"+title.toUpper()+"_HIGH);");
    ui->textBrowser->append( WriteDataFun+title.toLower()+"_addr[minute / 10 % 6],ICON_"+title.toUpper()+"_SIZE);");
    ui->textBrowser->append("");
    ui->textBrowser->append( setPostionFun+title.toLower()+"_coord[3][0],icon_16_"+title.toLower()+"_coord[3][1],");
    ui->textBrowser->append("\t\tICON_"+title.toUpper()+"_WIDE,"+ "ICON_"+title.toUpper()+"_HIGH);");
    ui->textBrowser->append( WriteDataFun+title.toLower()+"_addr[minute % 10],ICON_"+title.toUpper()+"_SIZE);");
    ui->textBrowser->append("");
}

void MainWindow::UI_week(QString title,QString title_en)
{
    ui->textBrowser->append("\n//***** 星期 ****//");
    ui->textBrowser->append("if(language == 0)\n{");
    ui->textBrowser->append( "\t"+setPostionFun+title.toLower()+"_coord[0][0],icon_16_"+title.toLower()+"_coord[0][1],");
    ui->textBrowser->append("\t\tICON_"+title.toUpper()+"_WIDE,"+ "ICON_"+title.toUpper()+"_HIGH);");
    ui->textBrowser->append( "\t"+WriteDataFun+title.toLower()+"_addr[((week >= 1)?(week-1):week) % 7],ICON_"+title.toUpper()+"_SIZE);");
    ui->textBrowser->append("");
    ui->textBrowser->append("}\nelse\n{");
    ui->textBrowser->append( "\t"+setPostionFun+title_en.toLower()+"_coord[0][0],icon_16_"+title_en.toLower()+"_coord[0][1],");
    ui->textBrowser->append("\t\tICON_"+title_en.toUpper()+"_WIDE,"+ "ICON_"+title_en.toUpper()+"_HIGH);");
    ui->textBrowser->append( "\t"+WriteDataFun+title_en.toLower()+"_addr[((week >= 1)?(week-1):week) % 7],ICON_"+title.toUpper()+"_SIZE);");
    ui->textBrowser->append("}");

}
//计步数
void MainWindow::UI_Step(QString title)
{

      ui->textBrowser->append("\n//***** 计步 ****//");
      if (ui->CB_old->isChecked())
      {
          ui->textBrowser->append("uint32_t step_temp = step_cnt;");
          ui->textBrowser->append("if(step_temp > 99999)");
          ui->textBrowser->append("{");
          ui->textBrowser->append("   step_temp = 99999;");
          ui->textBrowser->append("}");
          ui->textBrowser->append("uint8_t step_data[5]= {0};");
          ui->textBrowser->append("step_data[0] = (step_temp / 10000) %10;");
          ui->textBrowser->append("step_data[1] = (step_temp / 1000) %10;");
          ui->textBrowser->append("step_data[2] = (step_temp / 100) %10;");
          ui->textBrowser->append("step_data[3] = (step_temp / 10) %10;");
          ui->textBrowser->append("step_data[4] = step_temp  %10;");
      }

      ui->textBrowser->append("for(uint8_t i = 0;i < 5; i++)");
      ui->textBrowser->append("{");

      ui->textBrowser->append("\t"+setPostionFun+title.toLower()+"_coord[i][0],icon_16_"+title.toLower()+"_coord[i][1],");
      ui->textBrowser->append("\t\tICON_"+title.toUpper()+"_WIDE,"+ "ICON_"+title.toUpper()+"_HIGH);");
      ui->textBrowser->append( "\t"+WriteDataFun+title.toLower()+"_addr[step_data[i]],ICON_"+title.toUpper()+"_SIZE);");
      ui->textBrowser->append("}");


}

void MainWindow::UI_blue(QString title)
{
    ui->textBrowser->append("\n//***** 蓝牙 ****//");
    ui->textBrowser->append( setPostionFun+title.toLower()+"_coord[0][0],icon_16_"+title.toLower()+"_coord[0][1],");
    ui->textBrowser->append("\t\t\t\t\tICON_"+title.toUpper()+"_WIDE,"+ "ICON_"+title.toUpper()+"_HIGH);");
    ui->textBrowser->append( WriteDataFun+title.toLower()+"_addr[ble_status % 2],ICON_"+title.toUpper()+"_SIZE);");

}

void MainWindow::UI_heart(QString title)
{

    QString dot;
    for(int i = 0;i<iconTitleList.count();i++)
    {

        QString name = iconTitleList.value(i);
        if(name.contains(title) && name.contains("DOT"))
        {
            dot = name;
        }
    }
     ui->textBrowser->append("\n//***** 心率 ****//");
    
     ui->textBrowser->append("uint8_t heart_tmp = heart;\n");
     ui->textBrowser->append("if(heart_tmp == 0)\n{");
     ui->textBrowser->append("\tfor(uint8_t i = 0;i<3;i++)");
     ui->textBrowser->append("\t{");

     if(!dot.isEmpty())
     {
         //显示 ---
         ui->textBrowser->append( "\t\t"+setPostionFun+title.toLower()+"_coord[i][0],icon_16_"+title.toLower()+"_coord[i][1],");
         ui->textBrowser->append("\t\t\tICON_"+dot.toUpper()+"_WIDE,"+ "ICON_"+dot.toUpper()+"_HIGH);");
         ui->textBrowser->append( "\t\t"+WriteDataFun+dot.toLower()+"_addr[0],ICON_"+dot.toUpper()+"_SIZE);");

     }else {
         ui->textBrowser->append( "\t\t"+setPostionFun+title.toLower()+"_coord[i][0],icon_16_"+title.toLower()+"_coord[i][1],");
         ui->textBrowser->append("\t\t\tICON_"+title.toUpper()+"_WIDE,"+ "ICON_"+title.toUpper()+"_HIGH);");
         ui->textBrowser->append( "\t\t"+WriteDataFun+title.toLower()+"_addr[0],ICON_"+title.toUpper()+"_SIZE);");


    }
     ui->textBrowser->append("\t}");
     ui->textBrowser->append("}");

     ui->textBrowser->append("else\n{");
     if (ui->CB_old->isChecked())
     {
         ui->textBrowser->append("\tif(heart_tmp > 255)\n\t{\n\t\theart_tmp = 255;\n");
         ui->textBrowser->append("\t}");

         ui->textBrowser->append("\t\tuint8_t heart_data[3]= {0};");
         ui->textBrowser->append("\t\theart_data[0] = (heart_tmp / 100) %10;");
         ui->textBrowser->append("\t\theart_data[1] = (heart_tmp / 10) %10;");
         ui->textBrowser->append("\t\theart_data[2] = heart_tmp %10;");
     }

     ui->textBrowser->append("\tfor(uint8_t i = 0;i<3;i++)");
     ui->textBrowser->append("\t{");
     ui->textBrowser->append( "\t\t"+setPostionFun+title.toLower()+"_coord[i][0],icon_16_"+title.toLower()+"_coord[i][1],");
     ui->textBrowser->append("\t\t\tICON_"+title.toUpper()+"_WIDE,"+ "ICON_"+title.toUpper()+"_HIGH);");
     ui->textBrowser->append( "\t\t"+WriteDataFun+title.toLower()+"_addr[heart_data[i]],ICON_"+title.toUpper()+"_SIZE);");
     ui->textBrowser->append("\t}");
     ui->textBrowser->append("}");


}

void MainWindow::UI_data(QString title)
{
    ui->textBrowser->append("\n//***** 月份 ****//");
    ui->textBrowser->append( setPostionFun+title.toLower()+"_coord[0][0],icon_16_"+title.toLower()+"_coord[0][1],");
    ui->textBrowser->append("\t\t\t\tICON_"+title.toUpper()+"_WIDE,"+ "ICON_"+title.toUpper()+"_HIGH);");
    ui->textBrowser->append( WriteDataFun+title.toLower()+"_addr[month / 10 % 10],ICON_"+title.toUpper()+"_SIZE);");
    ui->textBrowser->append("");
    ui->textBrowser->append( setPostionFun+title.toLower()+"_coord[1][0],icon_16_"+title.toLower()+"_coord[1][1],");
    ui->textBrowser->append("\t\t\t\tICON_"+title.toUpper()+"_WIDE,"+ "ICON_"+title.toUpper()+"_HIGH);");
    ui->textBrowser->append( WriteDataFun+title.toLower()+"_addr[month % 10],ICON_"+title.toUpper()+"_SIZE);");
    ui->textBrowser->append("\n//*****day****//");
    ui->textBrowser->append( setPostionFun+title.toLower()+"_coord[2][0],icon_16_"+title.toLower()+"_coord[2][1],");
    ui->textBrowser->append("\t\t\t\tICON_"+title.toUpper()+"_WIDE,"+ "ICON_"+title.toUpper()+"_HIGH);");
    ui->textBrowser->append( WriteDataFun+title.toLower()+"_addr[day / 10 % 10],ICON_"+title.toUpper()+"_SIZE);");
    ui->textBrowser->append("");
    ui->textBrowser->append( setPostionFun+title.toLower()+"_coord[3][0],icon_16_"+title.toLower()+"_coord[3][1],");
    ui->textBrowser->append("\t\t\t\tICON_"+title.toUpper()+"_WIDE,"+ "ICON_"+title.toUpper()+"_HIGH);");
    ui->textBrowser->append( WriteDataFun+title.toLower()+"_addr[day % 10],ICON_"+title.toUpper()+"_SIZE);");
    ui->textBrowser->append("");
}
//卡路里
void MainWindow::UI_calories(QString title)
{
    ui->textBrowser->append("\n/***** 卡路里 ****/");
    if (ui->CB_old->isChecked())
    {

        ui->textBrowser->append("uint32_t calories_temp = calories_cnt;");
        ui->textBrowser->append("if(calories_temp > 9999)");
        ui->textBrowser->append("{");
        ui->textBrowser->append("   calories_temp = 9999;");
        ui->textBrowser->append("}");
        ui->textBrowser->append("uint8_t calories_data[4]= {0};");
        ui->textBrowser->append("calories_data[0] = (calories_temp / 1000) %10;");
        ui->textBrowser->append("calories_data[1] = (calories_temp / 100) %10;");
        ui->textBrowser->append("calories_data[2] = (calories_temp / 10) %10;");
        ui->textBrowser->append("calories_data[3] = calories_temp  %10;");
    }
    ui->textBrowser->append("for(uint8_t i = 0;i < 4; i++)");
    ui->textBrowser->append("{");
    ui->textBrowser->append("\t"+setPostionFun+title.toLower()+"_coord[i][0],icon_16_"+title.toLower()+"_coord[i][1],");
    ui->textBrowser->append("\t\tICON_"+title.toUpper()+"_WIDE,"+ "ICON_"+title.toUpper()+"_HIGH);");
    ui->textBrowser->append( "\t"+WriteDataFun+title.toLower()+"_addr[calories_data[i] ],ICON_"+title.toUpper()+"_SIZE);");
    ui->textBrowser->append("}");
}
//里程
void MainWindow::UI_distance(QString title)
{
    ui->textBrowser->append("\n/***** 里程 ****/");
    if (ui->CB_old->isChecked())
    {
        ui->textBrowser->append("uint32_t distance_temp = 0;");
        ui->textBrowser->append("\tif(distance_cnt >= 99.9f)\n\t{\n\tdistance_temp = 999;\n");
        ui->textBrowser->append("\t}");
        ui->textBrowser->append("\telse ");
        ui->textBrowser->append("\t{");
        ui->textBrowser->append("\t     distance_temp = (uint32_t)(distance_cnt* 10);");
        ui->textBrowser->append("\t}");
        ui->textBrowser->append("\tuint8_t distance_data[3]= {0};");
        ui->textBrowser->append("\tdistance_data[0] = (distance_temp / 100) %10;");
        ui->textBrowser->append("\tdistance_data[1] = (distance_temp / 10) %10;");
        ui->textBrowser->append("\tdistance_data[2] = distance_temp %10;");
    }

    ui->textBrowser->append("\tfor(uint8_t i = 0;i<3;i++)");
    ui->textBrowser->append("\t{");
    ui->textBrowser->append( "\t\t"+setPostionFun+title.toLower()+"_coord[i][0],icon_16_"+title.toLower()+"_coord[i][1],");
    ui->textBrowser->append("\t\t\t\t\t\tICON_"+title.toUpper()+"_WIDE,"+ "ICON_"+title.toUpper()+"_HIGH);");
    ui->textBrowser->append( "\t\t"+WriteDataFun+title.toLower()+"_addr[distance_data[i]],ICON_"+title.toUpper()+"_SIZE);");
    ui->textBrowser->append("\t}");

}

void MainWindow::write_param_head(QStringList list)
{



}

void MainWindow::UI_AMPM(QString title)
{
   ui->textBrowser->append("\n/***** 上下午 ****/");
   ui->textBrowser->append( "if(language == 0)");
   ui->textBrowser->append( "{");
   ui->textBrowser->append( "\t"+setPostionFun+title.toLower()+"_coord[0][0],icon_16_"+title.toLower()+"_coord[0][1],");
   ui->textBrowser->append("\t\t\tICON_"+title.toUpper()+"_WIDE,"+ "ICON_"+title.toUpper()+"_HIGH);");

   ui->textBrowser->append("\tif(am_pm == GUI_TIME_FORMAT_AM)");
   ui->textBrowser->append( "\t{");
   ui->textBrowser->append( "\t\t"+WriteDataFun+title.toLower()+"_addr[0],ICON_"+title.toUpper()+"_SIZE);");
   ui->textBrowser->append( "\t}");
   ui->textBrowser->append( "\telse if(am_pm == GUI_TIME_FORMAT_PM)");
   ui->textBrowser->append( "\t{");
   ui->textBrowser->append( "\t\t"+WriteDataFun+title.toLower()+"_addr[1],ICON_"+title.toUpper()+"_SIZE);");
   ui->textBrowser->append("\t}");
   ui->textBrowser->append("\telse if(am_pm == GUI_TIME_FORMAT_STANDARD)");
   ui->textBrowser->append("\t{");
   ui->textBrowser->append( "\t\t"+WriteDataFun+title.toLower()+"_addr[4],ICON_"+title.toUpper()+"_SIZE);");
   ui->textBrowser->append("\t}");
   ui->textBrowser->append("}");
   ui->textBrowser->append("else");
   ui->textBrowser->append("{");
   ui->textBrowser->append( "\t\t"+setPostionFun+title.toLower()+"_coord[0][0],icon_16_"+title.toLower()+"_coord[0][1],");
   ui->textBrowser->append("\t\t\t\t\tICON_"+title.toUpper()+"_WIDE,"+ "ICON_"+title.toUpper()+"_HIGH);");
   ui->textBrowser->append("\tif(am_pm == GUI_TIME_FORMAT_AM)");
   ui->textBrowser->append("\t{");
   ui->textBrowser->append( "\t\t\t"+WriteDataFun+title.toLower()+"_addr[2],ICON_"+title.toUpper()+"_SIZE);");
   ui->textBrowser->append("\t}");
   ui->textBrowser->append("\telse if(am_pm == GUI_TIME_FORMAT_PM)");
   ui->textBrowser->append("\t{");
   ui->textBrowser->append( "\t\t\t"+WriteDataFun+title.toLower()+"_addr[3],ICON_"+title.toUpper()+"_SIZE);");
   ui->textBrowser->append("\t}");
   ui->textBrowser->append("\telse if(am_pm == GUI_TIME_FORMAT_STANDARD)");
   ui->textBrowser->append("\t{");
   ui->textBrowser->append( "\t\t\t"+WriteDataFun+title.toLower()+"_addr[4],ICON_"+title.toUpper()+"_SIZE);");
   ui->textBrowser->append("\t}");
   ui->textBrowser->append("}");

}

void MainWindow::UI_one(QString title)
{

    ui->textBrowser->append("\n\t\t/*****" +title+" ****/");
    ui->textBrowser->append( "\t\t"+setPostionFun+title.toLower()+"_coord[0][0],icon_16_"+title.toLower()+"_coord[0][1],");
    ui->textBrowser->append("\t\t\t\t  ICON_"+title.toUpper()+"_WIDE,"+ "ICON_"+title.toUpper()+"_HIGH);");
    if(iconListnum.value(title) >1 )
    {
        //动图
       QString num1 = QString::number(iconListnum.value(title));
       ui->textBrowser->append( "\t\t"+WriteDataFun+title.toLower()+"_addr[index % " +num1 +"],ICON_"+title.toUpper()+"_SIZE);\n");
    }else
    {
        ui->textBrowser->append( "\t\t"+WriteDataFun+title.toLower()+"_addr[0],ICON_"+title.toUpper()+"_SIZE);\n");

    }



}


void MainWindow::UI_charge(QString title)
{
    ui->textBrowser->append("\n/***** 充电 ****/");
    ui->textBrowser->append( "    if(charge == BATTERRY_IS_CHARGING)");
    ui->textBrowser->append( "    {");
    ui->textBrowser->append( "\t\t"+setPostionFun+title.toLower()+"_coord[0][0],icon_16_"+title.toLower()+"_coord[0][1],");
    ui->textBrowser->append("\t\t\tICON_"+title.toUpper()+"_WIDE,"+ "ICON_"+title.toUpper()+"_HIGH);");
    ui->textBrowser->append( "\t\t"+WriteDataFun+title.toLower()+"_addr[index % 5],ICON_"+title.toUpper()+"_SIZE);\n");
    ui->textBrowser->append( "    }");
    ui->textBrowser->append( "    else");
    ui->textBrowser->append( "    {");
    ui->textBrowser->append( "        if(battery_level == 0)");
    ui->textBrowser->append( "        {");
    ui->textBrowser->append( "            if(index % 4 == 1)");
    ui->textBrowser->append( "            {");
    ui->textBrowser->append( "\t\t\t"+setPostionFun+title.toLower()+"_coord[0][0],icon_16_"+title.toLower()+"_coord[0][1],");
    ui->textBrowser->append("\t\t\t\t\tICON_"+title.toUpper()+"_WIDE,"+ "ICON_"+title.toUpper()+"_HIGH);");
    ui->textBrowser->append( "\t\t\t"+WriteDataFun+title.toLower()+"_addr[0],ICON_"+title.toUpper()+"_SIZE);\n");
    ui->textBrowser->append( "            }");
    ui->textBrowser->append( "            else if(index % 4 == 3)");
    ui->textBrowser->append( "            {");
    ui->textBrowser->append( "\t\t\t"+setPostionFun+title.toLower()+"_coord[0][0],icon_16_"+title.toLower()+"_coord[0][1],");
    ui->textBrowser->append("\t\t\t\t\tICON_"+title.toUpper()+"_WIDE,"+ "ICON_"+title.toUpper()+"_HIGH);");
    ui->textBrowser->append( "\t\t\t"+WriteDataFun+title.toLower()+"_addr[5],ICON_"+title.toUpper()+"_SIZE);\n");

    ui->textBrowser->append( "            }");
    ui->textBrowser->append( "        }");
    ui->textBrowser->append( "        else");
    ui->textBrowser->append( "        {");

    ui->textBrowser->append( "\t\t\t"+setPostionFun+title.toLower()+"_coord[0][0],icon_16_"+title.toLower()+"_coord[0][1],");
    ui->textBrowser->append("\t\t\t\t\tICON_"+title.toUpper()+"_WIDE,"+ "ICON_"+title.toUpper()+"_HIGH);");
    ui->textBrowser->append( "\t\t\t"+WriteDataFun+title.toLower()+"_addr[battery_level],ICON_"+title.toUpper()+"_SIZE);\n");

    ui->textBrowser->append( "        }");
    ui->textBrowser->append( "    }");


}

void MainWindow::UI_uint(QString title)
{
     ui->textBrowser->append("\n\t\t/***** 单位 ****/");
    ui->textBrowser->append( "\t\t"+setPostionFun+title.toLower()+"_coord[0][0],icon_16_"+title.toLower()+"_coord[0][1],");
    ui->textBrowser->append("\t\t\t\t  ICON_"+title.toUpper()+"_WIDE,"+ "ICON_"+title.toUpper()+"_HIGH);");
    ui->textBrowser->append( "\t\t"+WriteDataFun+title.toLower()+"_addr[language % 2],ICON_"+title.toUpper()+"_SIZE);\n");

}
void MainWindow::UI_Women(QString title)
{
     ui->textBrowser->append("\n\t\t/***** 女性 ****/");
    ui->textBrowser->append( "\t\t"+setPostionFun+title.toLower()+"_coord[0][0],icon_16_"+title.toLower()+"_coord[0][1],");
    ui->textBrowser->append("\t\t\t\t  ICON_"+title.toUpper()+"_WIDE,"+ "ICON_"+title.toUpper()+"_HIGH);");
    ui->textBrowser->append( "\t\t"+WriteDataFun+title.toLower()+"_addr[menstrual % 5],ICON_"+title.toUpper()+"_SIZE);\n");

}
//血压
void MainWindow::UI_BP(QString title)
{
    ui->textBrowser->append("\n//***** 血压 ****//");
    ui->textBrowser->append("uint8_t bp_data[6]= {0};");
    ui->textBrowser->append("bp_data[0] = (bp_sp / 100)% 10;");
    ui->textBrowser->append("bp_data[1] = (bp_sp / 10)% 10;");
    ui->textBrowser->append("bp_data[2] =  bp_sp % 10;");

    ui->textBrowser->append("bp_data[3] = (bp_dp / 100)% 10;");
    ui->textBrowser->append("bp_data[4] = (bp_dp / 10)% 10;");
    ui->textBrowser->append("bp_data[5] = bp_dp % 10;");

    ui->textBrowser->append("for(uint8_t i = 0;i < 6; i++)");
    ui->textBrowser->append("{");

    ui->textBrowser->append("\t"+setPostionFun+title.toLower()+"_coord[i][0],icon_16_"+title.toLower()+"_coord[i][1],");
    ui->textBrowser->append("\t\tICON_"+title.toUpper()+"_WIDE,"+ "ICON_"+title.toUpper()+"_HIGH);");
    ui->textBrowser->append( "\t"+WriteDataFun+title.toLower()+"_addr[bp_data[i]],ICON_"+title.toUpper()+"_SIZE);");
    ui->textBrowser->append("}");

}
//显示三位的睡眠
void MainWindow::UI_Sleep(QString title)
{


    ui->textBrowser->append("\n//***** 睡眠三位  ****//");
    ui->textBrowser->append("uint8_t sleep_hours = time / 60;");
    ui->textBrowser->append("uint8_t sleep_minutes = 10 * (time % 60 / 60.0f);");
    ui->textBrowser->append("uint32_t disp_sleep_buf1 = sleep_hours*10 + sleep_minutes;");




    ui->textBrowser->append("uint8_t light_sleep_hours = light_time / 60;");
    ui->textBrowser->append("uint8_t light_sleep_minutes = 10 * (light_time % 60 / 60.0f);");
    ui->textBrowser->append("uint32_t disp_light_sleep_buf1 = light_sleep_hours*10 + light_sleep_minutes;");


    ui->textBrowser->append("uint8_t deep_sleep_hours = deep_time / 60;");
    ui->textBrowser->append("uint8_t deep_sleep_minutes = 10 * (deep_time % 60 / 60.0f);");
    ui->textBrowser->append("uint32_t disp_deep_sleep_buf1 = deep_sleep_hours*10 + deep_sleep_minutes;");

    ui->textBrowser->append("if((disp_sleep_buf1 - disp_light_sleep_buf1 - disp_deep_sleep_buf1) != 0)");
    ui->textBrowser->append("{");
    ui->textBrowser->append("    disp_deep_sleep_buf1 = disp_sleep_buf1 - disp_light_sleep_buf1;");
    ui->textBrowser->append("}");
    ui->textBrowser->append("\n//***** Sleep ****//");
    ui->textBrowser->append("uint8_t sleep_data[3]= {0};");
    ui->textBrowser->append("sleep_data[0] = (disp_sleep_buf1 / 100)% 10;");
    ui->textBrowser->append("sleep_data[1] = (disp_sleep_buf1 /10 )% 10;");

    ui->textBrowser->append("sleep_data[2] = disp_sleep_buf1 % 10;");

    ui->textBrowser->append("for(uint8_t i = 0;i < 3; i++)");
    ui->textBrowser->append("{");

    ui->textBrowser->append("\t"+setPostionFun+title.toLower()+"_coord[i][0],icon_16_"+title.toLower()+"_coord[i][1],");
    ui->textBrowser->append("\t\tICON_"+title.toUpper()+"_WIDE,"+ "ICON_"+title.toUpper()+"_HIGH);");
    ui->textBrowser->append( "\t"+WriteDataFun+title.toLower()+"_addr[sleep_data[i]],ICON_"+title.toUpper()+"_SIZE);");
    ui->textBrowser->append("}");

    ui->textBrowser->append("\n//***** deep Sleep ****//");
    ui->textBrowser->append("uint8_t deep_sleep_data[3]= {0};");
    ui->textBrowser->append("deep_sleep_data[0] = (disp_deep_sleep_buf1 / 100)% 10;");
    ui->textBrowser->append("deep_sleep_data[1] = (disp_deep_sleep_buf1 / 10) % 10;");

    ui->textBrowser->append("deep_sleep_data[2] = disp_deep_sleep_buf1 % 10;");

    ui->textBrowser->append("for(uint8_t i = 0;i < 3; i++)");
    ui->textBrowser->append("{");

    ui->textBrowser->append("\t"+setPostionFun+title.toLower()+"_coord[i][0],icon_16_"+title.toLower()+"_coord[i][1],");
    ui->textBrowser->append("\t\tICON_"+title.toUpper()+"_WIDE,"+ "ICON_"+title.toUpper()+"_HIGH);");
    ui->textBrowser->append( "\t"+WriteDataFun+title.toLower()+"_addr[deep_sleep_data[i]],ICON_"+title.toUpper()+"_SIZE);");
    ui->textBrowser->append("}");
     ui->textBrowser->append("\n//***** light Sleep ****//");
    ui->textBrowser->append("uint8_t light_sleep_data[3]= {0};");
    ui->textBrowser->append("light_sleep_data[0] = (disp_light_sleep_buf1 / 100)% 10;");
    ui->textBrowser->append("light_sleep_data[1] = (disp_light_sleep_buf1 / 10) % 10;");

    ui->textBrowser->append("light_sleep_data[2] = disp_light_sleep_buf1  % 10;");

    ui->textBrowser->append("for(uint8_t i = 0;i < 3; i++)");
    ui->textBrowser->append("{");

    ui->textBrowser->append("\t"+setPostionFun+title.toLower()+"_coord[i][0],icon_16_"+title.toLower()+"_coord[i][1],");
    ui->textBrowser->append("\t\tICON_"+title.toUpper()+"_WIDE,"+ "ICON_"+title.toUpper()+"_HIGH);");
    ui->textBrowser->append( "\t"+WriteDataFun+title.toLower()+"_addr[light_sleep_data[i]],ICON_"+title.toUpper()+"_SIZE);");
    ui->textBrowser->append("}");
}
//显示4位的睡眠
void MainWindow::UI_Sleep_4(QString title)
{
    ui->textBrowser->append("\n//***** 睡眠 4位 ****//");
    if (ui->CB_old->isChecked())
    {
      
        ui->textBrowser->append("uint8_t sleep_hours = time / 60;");
        ui->textBrowser->append("uint8_t sleep_minutes = time % 60;");
        ui->textBrowser->append("uint8_t deep_sleep_hours = deep_time / 60;");
        ui->textBrowser->append("uint8_t deep_sleep_minutes = deep_time % 60;");
        ui->textBrowser->append("uint8_t light_sleep_hours = light_time / 60;");
        ui->textBrowser->append("uint8_t light_sleep_minutes = light_time % 60;");


        ui->textBrowser->append("uint8_t sleep_data[4]= {0};");
        ui->textBrowser->append("sleep_data[0] = (sleep_hours / 10)% 10;");
        ui->textBrowser->append("sleep_data[1] =  sleep_hours % 10;");
        ui->textBrowser->append("sleep_data[2] = (sleep_minutes / 10)% 10;");
        ui->textBrowser->append("sleep_data[3] = sleep_minutes % 10;");
    }

    ui->textBrowser->append("for(uint8_t i = 0;i < 4; i++)");
    ui->textBrowser->append("{");

    ui->textBrowser->append("\t"+setPostionFun+title.toLower()+"_coord[i][0],icon_16_"+title.toLower()+"_coord[i][1],");
    ui->textBrowser->append("\t\tICON_"+title.toUpper()+"_WIDE,"+ "ICON_"+title.toUpper()+"_HIGH);");
    ui->textBrowser->append( "\t"+WriteDataFun+title.toLower()+"_addr[sleep_data[i]],ICON_"+title.toUpper()+"_SIZE);");
    ui->textBrowser->append("}");
    if (ui->CB_old->isChecked())
    {
        ui->textBrowser->append("\n//***** deep Sleep ****//");
        ui->textBrowser->append("uint8_t deep_sleep_data[4]= {0};");
        ui->textBrowser->append("deep_sleep_data[0] = (deep_sleep_hours / 10)% 10;");
        ui->textBrowser->append("deep_sleep_data[1] =  deep_sleep_hours % 10;");
        ui->textBrowser->append("deep_sleep_data[2] = (deep_sleep_minutes / 10)% 10;");
        ui->textBrowser->append("deep_sleep_data[3] = deep_sleep_minutes % 10;");
    }
    ui->textBrowser->append("for(uint8_t i = 0;i < 4; i++)");
    ui->textBrowser->append("{");

    ui->textBrowser->append("\t"+setPostionFun+title.toLower()+"_coord[i][0],icon_16_"+title.toLower()+"_coord[i][1],");
    ui->textBrowser->append("\t\tICON_"+title.toUpper()+"_WIDE,"+ "ICON_"+title.toUpper()+"_HIGH);");
    ui->textBrowser->append( "\t"+WriteDataFun+title.toLower()+"_addr[deep_sleep_data[i]],ICON_"+title.toUpper()+"_SIZE);");
    ui->textBrowser->append("}");

    if (ui->CB_old->isChecked())
    {
        ui->textBrowser->append("\n//***** light Sleep ****//");
        ui->textBrowser->append("uint8_t light_sleep_data[4]= {0};");
        ui->textBrowser->append("light_sleep_data[0] = (light_sleep_hours / 10)% 10;");
        ui->textBrowser->append("light_sleep_data[1] =  light_sleep_hours % 10;");
        ui->textBrowser->append("light_sleep_data[2] = (light_sleep_minutes / 10)% 10;");
        ui->textBrowser->append("light_sleep_data[3] = light_sleep_minutes % 10;");
    }
     ui->textBrowser->append("for(uint8_t i = 0;i < 4; i++)");
     ui->textBrowser->append("{");

     ui->textBrowser->append("\t"+setPostionFun+title.toLower()+"_coord[i][0],icon_16_"+title.toLower()+"_coord[i][1],");
     ui->textBrowser->append("\t\tICON_"+title.toUpper()+"_WIDE,"+ "ICON_"+title.toUpper()+"_HIGH);");
     ui->textBrowser->append( "\t"+WriteDataFun+title.toLower()+"_addr[light_sleep_data[i]],ICON_"+title.toUpper()+"_SIZE);");
     ui->textBrowser->append("}");

}

void MainWindow::UI_position(QString title)
{
    ui->textBrowser->append("\n/***** position coord ****/");
    QString X = ui->LE_X->text();
    QString Y = ui->LE_Y->text();
    QString title1 ="ICON_"+ title+"_WIDE";
    int p = ui->LE_distance->text().toInt();
    ui->textBrowser->append("const uint16_t icon_16_" +title.toLower() +"_coord[4][2] =  \n{ ");
    if(p != 0)
    {

        int x0 = ui->LE_X->text().toInt();
        QString x1 = QString::number(x0+p);
        QString x2 = QString::number(x0+p*2);
        QString x3 = QString::number(x0+p*3);
        QString x4 = QString::number(x0+p*4);

        ui->textBrowser->append("\t{" + X + "," + Y +"}," +"{" + x1+ "+" + title1 + ","+ Y  +" },");
        ui->textBrowser->append( "\t{" +x2+ "+ " + title1 + "* 2," + Y +"}," + "{" + x3+ "+ " + title1 + "* 3," + Y +"},"+ "{" + x4+ "+ " + title1 + "* 4," + Y +"},"  );

    }else {
        ui->textBrowser->append("\t{" + X + "," + Y +"}," +"{" + X+ "+" + title1 + ","+ Y  +" },");
        ui->textBrowser->append( "\t{" + X+ "+ " + title1 + "* 2," + Y +"}," + "{" + X+ "+ " + title1 + "* 3," + Y +"},"+ "{" + X+ "+ " + title1 + "* 4," + Y +"},"  );

    }
     ui->textBrowser->append(" \n};\n");

}

void MainWindow::display()
{
    //添加到界面列表
    QStringList iconlistnumkeys = iconListnum.keys();
    //ui->CB_Time->addItems(iconlistnumkeys);
    //ui->CB_week->addItems(iconlistnumkeys);
    //ui->CB_week_en->addItems(iconlistnumkeys);
    //ui->CB_step->addItems(iconlistnumkeys);
    //ui->CB_blu->addItems(iconlistnumkeys);
    //ui->CB_heart->addItems(iconlistnumkeys);
    //ui->CB_data->addItems(iconlistnumkeys);
    //ui->CB_ampm->addItems(iconlistnumkeys);
    //ui->CB_one->addItems(iconlistnumkeys);
    //ui->CB_charge->addItems(iconlistnumkeys);
    //ui->CB_calories->addItems(iconlistnumkeys);
    //ui->CB_unit->addItems(iconlistnumkeys);
    //ui->CB_distant->addItems(iconlistnumkeys);
    //ui->CB_sleep->addItems(iconlistnumkeys);
    //ui->CB_sleep_2->addItems(iconlistnumkeys);
    //ui->CB_postion->addItems(iconlistnumkeys);
    //ui->CB_BP->addItems(iconlistnumkeys);
    //ui->CB_women->addItems(iconlistnumkeys);
   
    ui->CB_Time->setModel(iconModel);
    ui->CB_week->setModel(iconModel);
   
   ui->CB_week_en->setModel(iconModel);
   ui->CB_step->setModel(iconModel);
   ui->CB_blu->setModel(iconModel);
   ui->CB_heart->setModel(iconModel);
   ui->CB_data->setModel(iconModel);
   ui->CB_ampm->setModel(iconModel);
   ui->CB_one->setModel(iconModel);
   ui->CB_charge->setModel(iconModel);
   ui->CB_calories->setModel(iconModel);
   ui->CB_unit->setModel(iconModel);
   ui->CB_distant->setModel(iconModel);
   ui->CB_sleep->setModel(iconModel);
   ui->CB_sleep_2->setModel(iconModel);
   ui->CB_postion->setModel(iconModel);
   ui->CB_BP->setModel(iconModel);
    ui->CB_women->setModel(iconModel);
    //显示单独的代码
    foreach(QString iconName,iconlistnumkeys)
    {

        if(iconName.contains("ICON") ||iconName.contains("DOT") )
        {
            UI_one(iconName);
        }
        if(iconName.contains("DATA")  )
        {

             ui->CB_Time->setCurrentText(iconName);
             ui->CB_step->setCurrentText(iconName);
             ui->CB_data->setCurrentText(iconName);
             ui->CB_calories->setCurrentText(iconName);
             ui->CB_sleep->setCurrentText(iconName);
             ui->CB_postion->setCurrentText(iconName);
             ui->CB_BP->setCurrentText(iconName);
        }
         if(iconName.contains("WEEK"))
         {

              ui->CB_week->setCurrentText(iconName);
              ui->CB_week_en->setCurrentText(iconName);
              UI_week(iconName,iconName);
         }
         if(iconName.contains("UNIT"))
         {
            ui->CB_unit->setCurrentText(iconName);
            UI_uint(iconName);

         }
         if(iconName.contains("AM"))
         {
              ui->CB_ampm->setCurrentText(iconName);
              UI_AMPM(iconName);
         }

    }


}

void MainWindow::initDisplay()
{
    ui->textBrowser->clear();
    ui->TB_head->clear();
    ui->TB_Positon->clear();
    ui->CB_Time->clear();
    ui->CB_week->clear();
    ui->CB_week_en->clear();
    ui->CB_step->clear();
    ui->CB_blu->clear();
    ui->CB_heart->clear();
    ui->CB_data->clear();
    ui->CB_ampm->clear();
    ui->CB_one->clear();
    ui->CB_charge->clear();
    ui->CB_calories->clear();
    ui->CB_distant->clear();
    ui->CB_unit->clear();
    ui->CB_postion->clear();
    ui->CB_sleep->clear();
    ui->CB_sleep_2->clear();
    ui->CB_women->clear();
    ui->CB_BP->clear();
    iconListnum.clear();
    iconTitleList.clear();
    iconTitleList.append("NULL");

}

void MainWindow::AllJsonAnalysis(QString jsonPath)
{
    /*先对json进行解析获取坐标 */
    QDir dir(jsonPath);
    foreach(QFileInfo fileInfo ,dir.entryInfoList(QDir::Dirs|QDir::Files,QDir::DirsFirst))
    {
        if(fileInfo.isDir())
        {
            //目录遍历
            if(fileInfo.fileName()  == "." || fileInfo.fileName()  == ".."  )continue;
             AllJsonAnalysis(fileInfo.absoluteFilePath());
        }else {

            if(fileInfo.suffix() == "json")
            {
                //对位置json文件进行分析 获取到x y 高度 宽度的 icontmp.txt 文件

                jsonPaths.append(fileInfo.filePath());
                break;
            }
        }

    }



}

void MainWindow::dispaly_BP(QString icon_data, QString icon_person, QString icon_no, QString icon_error)
{
     write_code("if(test_mode == 1){");
     writePosiAndData(icon_person);
     write_code("}");

}

void MainWindow::write_code(QString data)
{
      ui->textBrowser->append(data);

}

void MainWindow::writePosiAndData(QString tile)
{
    write_code( "\t\t\t"+setPostionFun+title.toLower()+"_coord[0][0],icon_16_"+title.toLower()+"_coord[0][1],");
    write_code("\t\t\t\t\tICON_"+title.toUpper()+"_WIDE,"+ "ICON_"+title.toUpper()+"_HIGH);");
    write_code( "\t\t\t"+WriteDataFun+title.toLower()+"_addr[0],ICON_"+title.toUpper()+"_SIZE);\n");


}

int MainWindow::GetX()
{
    return ui->spinBox_cood_x->value();
}

int MainWindow::GetY()
{
    return ui->spinBox_cood_y->value();;
}

void MainWindow::getBmpAddr(QString path)
{

	QDir dir(path);
	QString last_icon;

	foreach(QFileInfo fileInfo, dir.entryInfoList(QDir::Dirs | QDir::Files, QDir::DirsFirst))
	{

		if (fileInfo.isDir())
		{
			//目录遍历
			if (fileInfo.fileName() == "." || fileInfo.fileName() == "..")continue;
			getBmpAddr(fileInfo.absoluteFilePath());

		}
		else
		{
			QImage image(fileInfo.filePath());
			if (fileInfo.suffix() == "bmp" || fileInfo.suffix() == "png")
			{
				QString icon_src = fileInfo.baseName().toUpper();
				QString icon = "ICON_" + fileInfo.baseName().toUpper() + "_ADDR";
				QStringList icon_split = icon_src.split("_");
				if (icon_split.size() < 2)continue;
				QByteArray data;
				QString addr;
				QString name1 = icon_split.at(0);
				QString name2;
				//qDebug() << "SSSSSS "<<name1;
				if (name1 == "ZZ" || name1 == "ZZZ")
				{
					name2 = icon_split.at(1) + "_" + icon_split.at(2);
				}
				else
				{
					name2 = icon_split.at(0) + "_" + icon_split.at(1);
				}
				if ((name2) != last_icon)
				{
					qint16 size = 1;
					last_icon = name2;
					addr += "\n#define ";
					addr += "ICON_";
					addr += last_icon;
					addr += "_SIZE ";
					addr += QString::number(image.width() * image
						.height() * 2);
					addr += "\n";

					addr += "#define ";
					addr += "ICON_";
					addr += last_icon;
					addr += "_WIDE ";
					addr += QString::number(image.width()); ;
					addr += "\n";

					addr += "#define ";
					addr += "ICON_";
					addr += last_icon;
					addr += "_HIGH ";
					addr += QString::number(image.height()); ;
					addr += "\n\n";
					qDebug() << last_icon;
				}

				addr += "#define ";
				addr += icon;
				addr += " ";
				//addr += icon;
				//addr += "\"\n";
				addr.append(QString::number(addr_count++));
				addr += "\n";


				data.append(addr.toLocal8Bit());
		/*		if (flashaddrfile.isOpen())
				{
					flashaddrfile.write(data);
				}*/
				ui->TB_addr->append(data);
				qDebug() << icon;
				qDebug() << fileInfo.filePath();
				//bmpPathsMap.insert(icon, fileInfo.filePath());
				//bmpPathsMap.append(); //添加切图的路径
			}

		}
	}
}

void MainWindow::getBmpPaths(QString path)
{
    QDir dir(path);
    QString last_icon;
    QImage image;

    foreach(QFileInfo fileInfo, dir.entryInfoList(QDir::Dirs | QDir::Files, QDir::DirsFirst))
    {
        if (fileInfo.isDir())
        {
            //目录遍历
            if (fileInfo.fileName() == "." || fileInfo.fileName() == "..")continue;
            //qDebug() << fileInfo.absolutePath(); //"F:/Work/汇顶/h18T_f/设备UI文件/H18T_UI_1.2.6/切图/音乐"
            //qDebug() << fileInfo.filePath(); //"F:/Work/汇顶/h18T_f/设备UI文件/H18T_UI_1.2.6/切图/音乐/音乐音量"
            //qDebug() << fileInfo.fileName(); //"音乐音量"
            //qDebug() << fileInfo.baseName(); //"音乐音量"
            //qDebug() << fileInfo.absoluteFilePath();// "F:/Work/汇顶/h18T_f/设备UI文件/H18T_UI_1.2.6/切图/音乐/音乐音量"
            //qDebug() << fileInfo.path();// "F:/Work/汇顶/h18T_f/设备UI文件/H18T_UI_1.2.6/切图/音乐"
            getBmpPaths(fileInfo.absoluteFilePath());

        }
        else {
            //qDebug() << fileInfo.filePath();
            //QImage image(fileInfo.filePath());
            if (fileInfo.suffix() == "bmp" || fileInfo.suffix() == "png")
            {
                QString icon_src = fileInfo.baseName();// .toUpper();q
                //qDebug() << fileInfo.absolutePath(); //"F:/Work/汇顶/h18T_f/设备UI文件/H18T_UI_1.2.6/切图/音乐/音乐音量"
                //qDebug() << fileInfo.filePath(); //"F:/Work/汇顶/h18T_f/设备UI文件/H18T_UI_1.2.6/切图/音乐/音乐音量/musicvu_icon1_mute.bmp"
                //qDebug() << fileInfo.fileName(); //"musicvu_icon1_mute.bmp"
                //qDebug() << fileInfo.baseName(); //"musicvu_icon1_mute"
                //qDebug() << fileInfo.absoluteFilePath(); //"F:/Work/汇顶/h18T_f/设备UI文件/H18T_UI_1.2.6/切图/音乐/音乐音量/musicvu_icon1_mute.bmp
            	//qDebug() << icon_src << " " << fileInfo.filePath(); //"F:/Work/汇顶/h18T_f/设备UI文件/H18T_UI_1.2.6/切图/音乐/音乐音量"
            //	qDebug() << "\n";
               
                Image_Path_Map.insert(icon_src, fileInfo.filePath());
            }    

        }
    }
      
}

void MainWindow::on_pushButton_clicked()
{

//    UI_time( ui->CB_Time->currentText());
//    UI_Step( ui->CB_step->currentText());
//    UI_blue( ui->CB_blu->currentText());
//    UI_week( ui->CB_week->currentText(),ui->CB_week_en->currentText());
//    UI_heart(ui->CB_heart->currentText());
//    UI_data(ui->CB_data->currentText());
//    UI_AMPM(ui->CB_ampm->currentText());
//    UI_one(ui->CB_one->currentText());
//    UI_charge(ui->CB_charge->currentText());
//if(json->isOk())
{
   //显示效果图
    //FormDraw *draw ;
   // draw = new FormDraw();
   // draw->setPath(json->geticonArray(filePath));
   // draw->show();
}
    //draw->show();
this->update();


}

void MainWindow::on_CB_one_activated(const QString &arg1)
{
    ui->textBrowser->clear();
    UI_one(arg1);
}

void MainWindow::on_CB_Time_activated(const QString &arg1)
{
    ui->textBrowser->clear();
    UI_time(arg1);
}

void MainWindow::on_CB_heart_activated(const QString &arg1)
{
    ui->textBrowser->clear();
    UI_heart(arg1);
}

void MainWindow::on_CB_step_activated(const QString &arg1)
{
   ui->textBrowser->clear();
    UI_Step(arg1);
}

void MainWindow::on_CB_blu_activated(const QString &arg1)
{
    ui->textBrowser->clear();
    UI_blue(arg1);
}

void MainWindow::on_CB_data_activated(const QString &arg1)
{
    ui->textBrowser->clear();
    UI_data(arg1);
}

void MainWindow::on_CB_ampm_activated(const QString &arg1)
{
    ui->textBrowser->clear();
    UI_AMPM(arg1);
}

void MainWindow::on_CB_charge_activated(const QString &arg1)
{
    ui->textBrowser->clear();
    UI_charge(arg1);
}

void MainWindow::on_CB_week_activated(const QString &arg1)
{
    ui->textBrowser->clear();
    UI_week(arg1,arg1);
}

void MainWindow::on_CB_calories_activated(const QString &arg1)
{
    ui->textBrowser->clear();
    UI_calories(arg1);
}

void MainWindow::on_CB_unit_activated(const QString &arg1)
{
    ui->textBrowser->clear();
    UI_uint(arg1);
}

void MainWindow::on_CB_distant_activated(const QString &arg1)
{
   ui->textBrowser->clear();
    UI_distance(arg1);
}

void MainWindow::on_CB_sleep_activated(const QString &arg1)
{
   ui->textBrowser->clear();
    UI_Sleep(arg1);
}

void MainWindow::on_CB_postion_activated(const QString &arg1)
{
    ui->textBrowser->clear();
    UI_position(arg1);
}

void MainWindow::on_CB_BP_activated(const QString &arg1)
{
    ui->textBrowser->clear();
    UI_BP(arg1);
}

void MainWindow::on_CB_FunSelect_activated(const QString &arg1)
{

	if (ui->CB_FunSelect->currentIndex() == 2)
	{
		setPostionFun = "LCD_SetPosition(icon_16_";
		WriteDataFun = "LCD_DriverWriteDataFromExtFlash(icon_16_";

	}
	else if (ui->CB_FunSelect->currentIndex() == 1) {
		setPostionFun = "LCD_SetPositionType2(index,icon_16_";
		WriteDataFun = "LCD_DriverWriteDataFromExtFlashType2(index,icon_16_";
	}
	else if (ui->CB_FunSelect->currentIndex() == 3) {
		setPostionFun = "Gui_PageClearBackgroundType2(index,icon_16_";
		WriteDataFun = "LCD_DriverWriteDataFromExtFlashType2(index,icon_16_";
	}
	else if (ui->CB_FunSelect->currentIndex() == 0) {
		setPostionFun = "LCD_SetXY(icon_16_";
		WriteDataFun = "LCD_SetImage(icon_16_";
	}
	else {
		setPostionFun = "Gui_PageClearBackground(icon_16_";
		WriteDataFun = "LCD_DriverWriteDataFromExtFlash(icon_16_";
	}



}

void MainWindow::on_CB_women_activated(const QString &arg1)
{
    ui->textBrowser->clear();
    UI_Women(arg1);
}

void MainWindow::on_CB_sleep_2_activated(const QString &arg1)
{
    ui->textBrowser->clear();
    UI_Sleep_4(arg1);

}
//int text_index = 0;
#define SAVE_TEXT_TO_IMAGE 0
void MainWindow::on_display_text(const QModelIndex index)
{
    //显示文字项
    QStandardItemModel* text_model = new QStandardItemModel(this);
    QString key = index.data().toString();
    font_page.title = key;
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
    ui->listView_text_select->setModel(text_model);


}

void MainWindow::on_display_page(const QModelIndex index)
{
   QString key =  index.data().toString();
   font_page.Page = key;
   QString path = json->GetPageImage(key);
   priview_path = path;
   ui->label_display->setScaledContents(true);
   ui->label_display->setPixmap(priview_path);
   this->update();
 
}

void MainWindow::on_select_text(const QModelIndex index)
{
    /* 根据列表中选中的第几个，创建一个font_t*/
    QString text = index.data().toString();
    font_page.text = text;
    int select_index = index.row(); //选中的当前的第几个
    if (!item_text_list.contains(select_index))
    {
        font_t font_new;
    
        /* 填充一个推荐值*/
        font_new.title = text;
        font_new.param.x =  0;
        font_new.param.y =  20;
        font_new.param.font_size = ui->spinBox_font->value();
        font_new.param.family = ui->fontComboBox->currentText();
        QMap<Language_e, font_t> font_map;
        language->CalculatePoint(font_new, &font_map); //自动计算其他语言的位置
        item_text_list.insert(select_index, font_map);
      
    }
     check_text_index = select_index;
    // SelectedText(select_index); //选中已有的文字
     //for each (int index in item_text_list.keys())
     {
         language->FontParamToJson(&item_text_list.value(select_index), &font_page); //保存所有选中的文字
     }
   

 
   // current_select_text.param.font_size = ui->
   
}
void MainWindow::on_select_language_file(int select)
{
    /* 语言切换*/
    current_lan = (Language_e)select;
    language->SetLanguage(current_lan);
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
        ui->listView_Text->setModel(text_item_model);

    }
}
void MainWindow::on_updata_select_text_list()
{
    ui->comboBox_texts->clear();
    if (!select_text_list.isEmpty())
    {
        QStringList text_list = language->GetText(select_text_list);
        ui->comboBox_texts->addItems(text_list);
    }
   
   
    qDebug() << "on_updata_select_text_list" << select_text_list;
    on_updata_item_param(); //更新参数
  
    
}
void MainWindow::on_updata_item_param()
{
    if (items_map.contains(current_item_id))
    {
        current_item = items_map.value(current_item_id);
        /*位置*/
        current_item.point.setX(GetX());
        current_item.point.setY(GetY());
        /*尺寸*/
        int width = ui->spinBox_width->value();
        int height = ui->spinBox_height->value();

        current_item.size.setWidth(width);
        current_item.size.setHeight(height);
        if (current_item.fomat == "Text")
        {
            int font_size = ui->spinBox_font->value();
            QString font_family = ui->fontComboBox->currentText();
            current_item.font.param.font_size = font_size;
            current_item.font.param.family = font_family;
            current_item.texts.clear();
            current_item.texts.append( select_text_list);
            qDebug() << "id"<< current_item_id << "updata" << select_text_list;
            QString text = ui->comboBox_texts->currentText();
            if (!text.isEmpty())
            {
                current_item.text = text;
            }
            
        
        }
        items_map.insert(current_item_id, current_item); 
    }         
}
void MainWindow::on_selected_item(QModelIndex index)
{
      int row =   index.row();
      QModelIndex row_index = ui->treeView_slelect_items->model()->index(row, 0);
      QString select_id = row_index.data().toString();
      SelectedText(select_id);
}
void MainWindow::on_lond_language_file()
{
    /* 文字选中窗口显示*/
    languageTextSelect->SetSelectedText(&select_text_list);
    languageTextSelect->show();
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
bool MainWindow::CheckPointText(int touch_x, int touch_y)
{
    /*  只用在文本上的*/
     /* 根据文字的位置和大小判断是否点击在此位置*/
    /*
    for each (int i in item_text_list.keys())
    {
       
     
        font_t font_text = item_text_list.value(i).value(lan);
        QFont font;
        font.setPixelSize(font_text.param.font_size);
        font.setFamily(font_text.param.family);
        QFontMetrics me(font);
        QRect rec = me.boundingRect(font_text.title);
        int text_h = rec.height();
        int text_w = rec.width();
        int x = font_text.param.x;
        int y = font_text.param.y;
        int end_x = x + text_w;
        int end_y = y + text_h;
        
        if (touch_x > end_x || touch_x < x || touch_y > end_y || touch_y < y)
        {
            continue;
        }
        else
        {
            return i;
        }

    }
    return -1;
    */
  
    //for each (ComponnetsItem item in items_map)
    for each(QString key in items_map.keys())
    {
        ComponnetsItem item = items_map.value(key);
        int height = item.size.height();
        int width = item.size.width();
        int x = item.point.x();
        int y = item.point.y();
        int end_x = x + width;
        int end_y = y + height;
        if (touch_x > end_x || touch_x < x || touch_y > end_y || touch_y < y)
        {
          
        }
        else
        {
            
            SelectedText(key);
            return true;
        }
    }
    return false;
}

void MainWindow::SelectedText(QString id)
{
    /* 点击选中某个控件后,对界面的参数进行更新*/
    /*
    current_select_text = &item_text_list.value(index).value(current_lan);
    int x = current_select_text->param.x;
    int y = current_select_text->param.y;
    int font_size = current_select_text->param.font_size;

    ui->spinBox_cood_x->setValue(x);
    ui->spinBox_cood_y->setValue(y);
    ui->spinBox_font->setValue(font_size);
    qDebug() << "SelectedText" << current_select_text->title;
    font_page.text = current_select_text->title;
    */
    current_item_id = id;
    ComponnetsItem item = items_map.value(id);
    int x = 0;
    int y = 0;
    if (item.text_point.contains(current_lan))
    {
        //对应的语言有位置
        language_offset text_point = item.text_point.value(current_lan);
        x = text_point.x;
        y = text_point.y;
    }
    else
    {
        x = item.point.x();
        y = item.point.y();
    }
   
    int font_size = item.font.param.font_size;
    int width = item.size.width();
    int height = item.size.height();
    select_text_list.clear();
    QStringList texts = item.texts;
    select_text_list.append(texts);
    ui->spinBox_cood_x->setValue(x);
    ui->spinBox_cood_y->setValue(y);
    ui->spinBox_font->setValue(font_size);
    ui->spinBox_width->setValue(width);
    ui->spinBox_height->setValue(height);
    ui->comboBox_texts->clear(); 
    QStringList text_list = language->GetText(select_text_list);
    ui->comboBox_texts->addItems(text_list);
    
    qDebug()<< "id" << id << "chick" << texts;

}

void MainWindow::CreatTextItem(QPoint *point)
{
    ComponnetsItem item;
    current_item = item;
    item.id = items_map.count() + 1;
    QString id_str = QString::number(item.id);
    current_item_id = id_str;
    select_text_list.clear(); //清除当前的文字列表
    ui->comboBox_texts->clear();
    languageTextSelect->SetSelectedText(&select_text_list);
    languageTextSelect->show();// 显示文本选择框
    
    item.text = "Text";
    item.fomat = "Text";
    
    int label_x = ui->label_display->x();
    int label_y = ui->label_display->y();
    int font_size = ui->spinBox_font->value();
    int lineHeight = ui->spinBox_LineHeight->value();
    int spacing = ui->spinBox_spacing->value();
    //获取文本的范围
    QString font_family = ui->fontComboBox->currentText();
    QRect rect = language->GetTextRect(item.text, font_size, font_family);
    int width = rect.width();
    int height = rect.height();
    int x = point->x() - label_x;
    int y = point->y() - label_y;
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
   
    
    items_map.insert(id_str, item); //添加新的控件
   
    ui->spinBox_width->setValue(width);
    ui->spinBox_height->setValue(height);

    ui->spinBox_cood_x->setValue(x);
    ui->spinBox_cood_y->setValue(y);

    //添加到已选择的控件  
    QString type = "文本";
    //type.append("(" + id_str + ")");
    QStandardItem* item_type = new QStandardItem(type);   
    int row_count = selected_items_model->rowCount();
    //selected_items_model->appendRow(item_type);
    selected_items_model->setItem(row_count, 1, item_type);
    selected_items_model->setItem(row_count , 0, new QStandardItem(id_str));
    //ui->LV_selected_Items->setModel(selected_items_model);
    ui->treeView_slelect_items->setModel(selected_items_model);
}
