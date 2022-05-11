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
    json = new pxcpJson();
    watch_view = new WatchView(this);

    ui->CB_old->setChecked(false);
	ui->label_display->installEventFilter(this); //
  
   
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
     QObject::connect(languageTextSelect, SIGNAL(updata_text()), this, SLOT(on_updata_select_text_list()));
     QObject::connect(imageSelectWidget, SIGNAL(updata_image()), this, SLOT(on_updata_select_text_list()));    

    vpWatchCode = VpWatchCode::getInstance();
	
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
	if (watched == ui->label_display && event->type() == QEvent::Paint)
		//paint();
	this->update();
   

	return QWidget::eventFilter(watched, event);
}
void MainWindow::mousePressEvent(QMouseEvent* event)
{
    qDebug() << "Press";
    //直接点击效果图进行坐标的设置
    QPoint label_dipaly_point = ui->label_display->mapFromGlobal(QCursor::pos());
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
   
    if (item_is_drop)
    {
        ui->spinBox_cood_x->setValue(point.x());
        ui->spinBox_cood_y->setValue(point.y());
        on_updata_item_param();
    }
 
}
//显示合成的效果图
void MainWindow::paintEvent(QPaintEvent * event)
{

	QPainter paint(this);   
    
    QPainter painter;

    int label_h = ui->label_display->height(); //  current_select_text.param.font_size;
    int label_w =  ui->label_display->width();//rec.width(); 

    QPixmap pix(label_w, label_h);
    pix.fill(QColor(Qt::black));
    painter.begin(&pix);
    /*进行预览图的绘画*/
    if (!priview_path.isEmpty())
    {          
        painter.drawPixmap(QPoint(0, 0), QPixmap(priview_path));
     
    }
  
  
    DislayView(&painter); //画控件

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
                /*  控件的拖拽添加*/
              
                QString componnet_type =  ui->listView_componnets->currentIndex().data().toString();     
                qDebug() << "Add Item" << componnet_type;
                QPoint point = ui->label_display->mapFromGlobal(QCursor::pos()); //鼠标相对控件的位置
                /*int label_x = ui->label_display->x();
                int label_y = ui->label_display->y();
                int x = event->pos().x() - label_x;
                int y = event->pos().y() - label_y;
                point.setX(x);
                point.setY(y);*/
                CreatItem(componnet_type, point);
              

                
            }
        }
        else if (format == "text/uri-list")
        {
            QString file_path = event->mimeData()->urls().first().toLocalFile();
            this->filePath = event->mimeData()->urls().first().toLocalFile();
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
                    if (json->GetJsonAndImage(info.filePath()))
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
                        if (json->getJson(info.filePath()))
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
                    language->SetLanguageFileExcel(file_path);
                    languageTextSelect->SetTextList(language->text_id_list);

                }

                return;
            }
            // readexcel *excel = new readexcel(this);
            //excel->read(file_path); 
            
            return;
            if (!info.isDir())
            {
                QMessageBox::warning(this, "Error", tr("The Path is Error!"));
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
              
                json->FindPxcpJsonFile(filePath);
               
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

    }
    return;
   
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
            vpWatchCode->UI_one(iconName, iconListnum.value(title));
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
              vpWatchCode->UI_week(iconName,iconName);
         }
         if(iconName.contains("UNIT"))
         {
            ui->CB_unit->setCurrentText(iconName);
            vpWatchCode->UI_uint(iconName);

         }
         if(iconName.contains("AM"))
         {
              ui->CB_ampm->setCurrentText(iconName);
              vpWatchCode->UI_AMPM(iconName);
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
    this->update();
}

void MainWindow::on_CB_one_activated(const QString &arg1)
{
    ui->textBrowser->clear();
    vpWatchCode->UI_one(arg1, iconListnum.value(title));
}

void MainWindow::on_CB_Time_activated(const QString &arg1)
{
    ui->textBrowser->clear();
    vpWatchCode->UI_time(arg1);
}

void MainWindow::on_CB_heart_activated(const QString &arg1)
{
    ui->textBrowser->clear();
    vpWatchCode->UI_heart(arg1);
}

void MainWindow::on_CB_step_activated(const QString &arg1)
{
   ui->textBrowser->clear();
    vpWatchCode->UI_Step(arg1);
}

void MainWindow::on_CB_blu_activated(const QString &arg1)
{
    ui->textBrowser->clear();
    vpWatchCode->UI_blue(arg1);
}

void MainWindow::on_CB_data_activated(const QString &arg1)
{
    ui->textBrowser->clear();
    vpWatchCode->UI_data(arg1);
}

void MainWindow::on_CB_ampm_activated(const QString &arg1)
{
    ui->textBrowser->clear();
    vpWatchCode->UI_AMPM(arg1);
}

void MainWindow::on_CB_charge_activated(const QString &arg1)
{
    ui->textBrowser->clear();
    vpWatchCode->UI_charge(arg1);
}

void MainWindow::on_CB_week_activated(const QString &arg1)
{
    ui->textBrowser->clear();
    vpWatchCode->UI_week(arg1,arg1);
}

void MainWindow::on_CB_calories_activated(const QString &arg1)
{
    ui->textBrowser->clear();
    vpWatchCode->UI_calories(arg1);
}

void MainWindow::on_CB_unit_activated(const QString &arg1)
{
    ui->textBrowser->clear();
    vpWatchCode->UI_uint(arg1);
}

void MainWindow::on_CB_distant_activated(const QString &arg1)
{
   ui->textBrowser->clear();
    vpWatchCode->UI_distance(arg1);
}

void MainWindow::on_CB_sleep_activated(const QString &arg1)
{
   ui->textBrowser->clear();
    vpWatchCode->UI_Sleep(arg1);
}

void MainWindow::on_CB_postion_activated(const QString &arg1)
{
    ui->textBrowser->clear();
   UI_position(arg1);
}

void MainWindow::on_CB_BP_activated(const QString &arg1)
{
    ui->textBrowser->clear();
    vpWatchCode->UI_BP(arg1);
}


void MainWindow::on_CB_women_activated(const QString &arg1)
{
    ui->textBrowser->clear();
    vpWatchCode->UI_Women(arg1);
}

void MainWindow::on_CB_sleep_2_activated(const QString &arg1)
{
    ui->textBrowser->clear();
    vpWatchCode->UI_Sleep_4(arg1);

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
   QString path = json->GetPageImage(key);
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
void MainWindow::on_updata_select_text_list()
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
               QString name = Utils::GetBaseName(path);//QFileInfo(path).baseName();
               
               QString current = watch_view->GetPriview(current_item_id);
              
               ui->comboBox_texts->addItem(QIcon(path), name);
            }
           
            
        }
        
    }   
   
   // qDebug() << "on_updata_select_text_list" << select_element_list;
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
            if (!select_element_list.isEmpty() && (index != -1))
            {
                QString current_element = select_element_list.at(index);
                qDebug() << "current_element" << current_element;
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
            }
        
        }
        watch_view->AppendItem(current_item_id, current_item);
        qDebug() << "GetPriview" << watch_view->GetPriview(current_item_id);
        
    }
    CodeJson* josn1 = new CodeJson(this);
    josn1->FontParamToJson(&watch_view->view_items_map);
    ui->textBrowser->setText(josn1->GetCode());
    this->update();
}
void MainWindow::on_selected_item(QModelIndex index)
{
      int row =   index.row();
      QModelIndex row_index = ui->treeView_slelect_items->model()->index(row, 0);
      QString select_id = row_index.data().toString();
      SelectingItem(select_id);
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
   
    QStringList view_id_list = watch_view->GetViewId();
    for each(QString id in view_id_list)
    {   
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
        CreatItem(componnet_type , &point);
    }
    SaveSelectedItem(componnet_type, current_item_id); //保存当前的控件ID
}

void MainWindow::CreatItem(QString componnet_type, QPoint* point)
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
    int width  = 0;
    int height = 0;

    item.point = QPoint(x, y);
    item.size.setWidth(width);
    item.size.setHeight(height);
    

    select_element_list.clear(); //清除当前的文字列表
    ui->comboBox_texts->clear();

    watch_view->AppendItem(current_item_id, item); //添加新的控件
    watch_view->SetCurrentItem(current_item_id);


    ui->spinBox_width->setValue(width);
    ui->spinBox_height->setValue(height);

    ui->spinBox_cood_x->setValue(x);
    ui->spinBox_cood_y->setValue(y);

    watch_view->AppendItem(current_item_id, item); //添加新的控件
    watch_view->SetCurrentItem(current_item_id);

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
        //ui->comboBox_texts->clear();

        on_updata_select_text_list();
    }
}

void MainWindow::DislayView(QPainter* painter)
{
    QStringList view_id_list = watch_view->GetViewId();
    for each (QString id in view_id_list)
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
           
           // 
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
    //添加到已选择的控件  
    QStandardItem* item_type = new QStandardItem(type);
    int row_count = selected_items_model->rowCount();
    selected_items_model->setItem(row_count, 1, item_type);
    selected_items_model->setItem(row_count, 0, new QStandardItem(id));
    ui->treeView_slelect_items->setModel(selected_items_model);
}
