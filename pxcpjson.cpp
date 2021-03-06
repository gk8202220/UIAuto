#include "pxcpjson.h"
#include <QFile>
//#pragma execution_character_set("UTF-8")
pxcpJson::pxcpJson()
{

    image_path_list.clear();
    page_name_list.clear();


}

void pxcpJson::jsonAnalysis(QString josnfile)
{

  QJsonArray iconArray; // 保存原始的x y heigh wide
  int count = 0;

  QFileInfo info(josnfile);
  iconFilePath = info.path();  //该目录为一级路径
   //读取原始的json文件文件数据
   QFile file(josnfile);
   if(!file.open(QIODevice::ReadOnly))
   {
      qDebug()<< "open file error!" << josnfile;
      return ;
   }
   bmpPath.clear();
   getBmpPaths(iconFilePath);
  QByteArray fileData = file.readAll();
  file.close();
   QJsonParseError  json_error;
   //json读取格式
   QJsonDocument json(QJsonDocument::fromJson(fileData,&json_error));
   if(json_error.error != QJsonParseError::NoError)
   {
         qDebug() << "json error!" <<json_error.error ;
         return;
   }

   QJsonObject rootObj = json.object();
       QStringList keys = rootObj.keys();

//          for(int i = 0; i < keys.size(); i++)
//          {
//              qDebug() << "key" << i << " is:" << keys.at(i);

//          }
      if(rootObj.contains("elements"))
      {

          QJsonArray subArray = rootObj.value("elements").toArray();
          for(int i = 0; i< subArray.size(); i++)
          {

                QJsonObject  rectInfo = subArray.at(i).toObject();
                if(rectInfo.contains("rectInfo"))
                {
                    QJsonObject baseInfo =rectInfo.value("baseInfo").toObject();
                   //  if(baseInfo.value("name").toString() == "#")
                     {

                         //匹配Map中的height width 获取到对应的图片并用对应的x y 轴显示在界面上
                         QJsonObject subArray = rectInfo.value("rectInfo").toObject();
                        // if(image->height() == subArray.value("height").toInt() && image->width() ==subArray.value("width").toInt())
                         {
                           //  qDebug()<<"-----------------" << filepath;
                            // qDebug()<<"X ="<<subArray.value("x").toInt();
                           //qDebug()<<"Y ="<<subArray.value("y").toInt();
//                             qDebug()<<"height ="<<subArray.value("height").toInt();
//                             qDebug()<<"width ="<<subArray.value("width").toInt();
                              int width  = subArray.value("width").toInt();
                              int height = subArray.value("height").toInt();
                                QJsonObject json1;
                                json1.insert("x",subArray.value("x").toInt());
                                json1.insert("y",subArray.value("y").toInt());
                                json1.insert("height",subArray.value("height").toInt());
                                json1.insert("width",subArray.value("width").toInt());

                               // iconArray.insert(count++,json1);

                                foreach(QString iconPath,bmpPath)
                                {

                                   QImage *image = new QImage(iconPath);
                                  // qDebug()<<"X ="<<image->height();
                                   //qDebug()<<"Y ="<<image->width();
                                   //根据高度和宽度匹配到对应的切图路径
                                   if(abs(image->height() - height ) < 2 && abs(image->width() - width) < 2)
                                   {


                                       json1.insert("path",iconPath);
                                        // rectInfo.insert("path",iconPath);
                                         iconArray.insert(count++,json1);

                                         break;
                                   }
                                }

                         }

                     }
                }
           }


      }
      QString tmpFile = iconFilePath+"/iconWH.txt";
      QFile * iconfile = new QFile(tmpFile);
      if(!iconfile->open(QIODevice::WriteOnly))
      {
         qDebug()<< "open file error!" << tmpFile;
         return ;
      }
      QJsonDocument doc;
      doc.setArray(iconArray);
      iconfile->write(doc.toJson());
      iconfile->close();
    // qDebug() << "ok!" << iconArray;
      //isok = true;
      /*以坐标去查找对应切图的路径*/
     // findIconSize(tmpFile);

}
//切图的高度、高度与pxcp文件配对
void pxcpJson::findIconSize(QString path)
{
    QJsonArray iconWHArray;
    getBmpPaths(iconFilePath);
    //读取文件数据
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly))
    {
       qDebug()<< "open file error!" << path;
       return ;
    }

    QByteArray fileData = file.readAll();
    file.close();
    QJsonParseError  json_error;
    //json读取格式
    QJsonDocument json(QJsonDocument::fromJson(fileData,&json_error));
    if(json_error.error != QJsonParseError::NoError)
    {
          qDebug() << "json error!" <<json_error.error ;
          return;
    }

    QJsonArray iconArray = json.array();
    if(!iconArray.isEmpty())
    {

        for(int i = 0; i< iconArray.size(); i++)
        {
              QJsonObject  rectInfo = iconArray.at(i).toObject();
              int width  = rectInfo.value("width").toInt();
              int height = rectInfo.value("height").toInt();
              foreach(QString iconPath,bmpPath)
              {

                 QImage *image = new QImage(iconPath);
                 //根据高度和宽度匹配到对应的切图路径
                 if(abs(image->height() - height) < 2 && abs(image->width() - width) < 2)
                 {
                    // qDebug()<<   iconPath;
                     rectInfo.insert("path",iconPath);
                     iconWHArray.insert(iconconut++,rectInfo);
                     break;
                 }
              }
         }
     }
    //保存成文件
    QFile *iconWHFile;
    saveiconFile = iconFilePath+ "/iconWH.txt";
   // qDebug() << "saveIconFile = " << saveiconFile;
    iconWHFile = new QFile(saveiconFile);
    if(!iconWHFile->open(QIODevice::WriteOnly))
    {
       qDebug()<< "open iconWHFile error!";
       return ;
    }
    QJsonDocument doc;
    doc.setArray(iconWHArray);
    iconWHFile->write(doc.toJson());
    iconWHFile->close();
}

//该文件保存切图的路径、宽度、高度、Ｘ　Ｙ轴
void pxcpJson::savefile()
{

    QFileInfo info(iconFilePath);

    qDebug()<< info.path()+ "/iconWH.txt";



}

QJsonArray pxcpJson::geticonArray(QString iconFilePath)
{
    QJsonArray arry;
    QFile *iconWHFile;

    iconWHFile = new QFile(iconFilePath +"/iconWH.txt");
  //  qDebug()<< iconFilePath +"/iconWH.txt" ;
    if(iconWHFile->open(QIODevice::ReadOnly))
    {
        QByteArray fileData =  iconWHFile->readAll();
        iconWHFile->close();

        QJsonParseError  json_error;
        QJsonDocument json(QJsonDocument::fromJson(fileData,&json_error));
        if(json_error.error == QJsonParseError::NoError)
        {
            arry = json.array();

        }
    }
    return  arry;
}

bool pxcpJson::isOk()
{
    return isok;

}
//从pxcp文件中提取正确的json数据    //路径为当前保存.json文件
bool  pxcpJson::getJson(QString srcPath)
{

    QFileInfo info(srcPath);
    QFile file(srcPath);
    bool ret = false;
    if(!file.open(QIODevice::ReadOnly))
    {

        return false;
    }
     while (!file.atEnd()) {
        QByteArray data =  file.readLine();

        if( data.contains("elements"))
        {

             int left = data.indexOf("{\"");
             int right = 0;

            for(int i = data.size() -1;i>0;i--)
            {


                if(data.at(i) == '}')
                {
                    right = i;
                    qDebug() <<right;
                    break;


                }
            }
             QByteArray josndata;
            josndata .append( data.mid(left,right-left));
            josndata.append("}");
           // josndata = josndata.right(right);
            //QList <QByteArray> dataList = data.split("{\"stampCreated");
//            int i = data.indexOf("stampCreated");
//            if(i >0)
//            {
//                QByteArray data1 = "{\""+data.mid(i);
//                int x = data1.indexOf(",\"filePath");
//                if(x > 0)
//                {

//                    //获取到每个独立界面的json
//                    data1 = data1.left(x);
//                    data1.append("}\r\n");

//                }
               QString name =  getValue(josndata);
               //保存json
                QFile jsonfile(info.path()+"/" + name +".json");
                if(!jsonfile.open(QIODevice::WriteOnly))
                {
                    return false;
                }
                jsonfile.write(josndata);
                ret = true;



        }
    }
   // jsonfile.close();
    file.close();
    return ret;

}

QString pxcpJson::getValue(QByteArray data)
{

     QJsonParseError  json_error;
    QJsonDocument json(QJsonDocument::fromJson(data,&json_error));
    if(json_error.error != QJsonParseError::NoError)
    {
          qDebug() << "json error!" <<json_error.error ;
          isok = false;
          return "";
    }
    QJsonObject rootObj = json.object();
    if( rootObj.contains("name"))
    {
       return  rootObj.value("name").toString(); //返回界面名称
    }

//    QStringList keys = rootObj.keys();

//       for(int i = 0; i < keys.size(); i++)
//       {
//           qDebug() << "key" << i << " is:" << keys.at(i);

//       }
     return "";
}

//获取所有的bmp切图
void  pxcpJson::getBmpPaths(QString srcPath)
{



    QDir dir(srcPath);
    foreach(QFileInfo fileInfo ,dir.entryInfoList(QDir::Dirs|QDir::Files,QDir::DirsFirst))
    {

         if(fileInfo.isDir())
         {
             //目录遍历
             if(fileInfo.fileName()  == "." || fileInfo.fileName()  == ".."  )continue;
             getBmpPaths(fileInfo.absoluteFilePath());

         }else {

             if(fileInfo.suffix() == "bmp" || fileInfo.suffix() == "png")
             {
                  bmpPath.append(fileInfo.filePath()); //添加切图的路径
             }


          }
    }


}

QString pxcpJson::getBmpPath(QString name)
{
//    foreach(QString bmp,bmpPath)
//    {

//        if(bmp.contains(name))
//            return bmp;
//    }
    return NULL;
}

void pxcpJson::setPath(QString path)
{
    jsonPath = path;
}

void pxcpJson::run()
{
    //qDebug()<< jsonPath;
    jsonAnalysis(jsonPath);
}

bool pxcpJson::GetJsonAndImage(QString srcPath)
{
    image_path_list.clear();
    page_name_list.clear();
    PageImageMap.clear();
   // QFileInfo info(srcPath);
    const char png_head[8] = { 0x89,0x50,0x4E,0x47,0x0D,0x0A,0x1A,0x0A }; //png图片的起始标志位
    const char png_end[12] = { 0x00,0x00,0x00,0x00, 0x49,0x45,0x4E,0x44,0xAE , 0x42, 0x60, 0x82}; //png图片的结束标志位
    QFile file(srcPath);

    if (!file.open(QIODevice::ReadOnly))
    {
        return false;
    }

    QList<QByteArray>json_list;
    
    QByteArray readdata;
    readdata .append(file.readAll());
    file.close();
    QByteArray pngstart; //转为QByteArray
    QByteArray pngend;//转为QByteArray
    for (int i = 0; i < sizeof(png_end); i++)
    {
        pngend.append(png_end[i]);
    }
    for (int i = 0; i < sizeof(png_head); i++)
    {   
        pngstart.append(png_head[i]);
    }

    //解析图片
    int image_count = 0; //图片的总数
    int json_count = 0; //json的总数
    QString json_start_flag = "{\""; //json的起始标志位
    QString json_end_flag = "}";//json的结束标志位
    QString json_name;
    bool priview_flag = false;
    while(readdata.contains(pngstart)) //是否还有图片
    {
      
        int json_start = readdata.indexOf(json_start_flag.toLocal8Bit());
        
        int image_start = readdata.indexOf(pngstart);
        int image_end = readdata.indexOf(pngend);

        if ((json_start < image_start) && json_start != -1) //先保存json，json后面是切图，如果又遇到新json这是下一个界面的切图
        {
            QByteArray temp_json_data = readdata.mid(json_start, image_start - json_start);
            int json_end = temp_json_data.lastIndexOf(json_end_flag.toLocal8Bit()) + json_end_flag.size();
            QByteArray josndata = temp_json_data.mid(0, json_end); //截取json的字符串
            json_name = GetPageName(josndata);
            page_name_list.append(json_name);
            qDebug() << json_name;
            QString json_path = "./PxcpJson/";
            json_path.append(json_name);
            json_path.append(QString::number(json_count));
            json_path.append(".json");
            //保存json文件
            QFile json_file(json_path);
            if (!json_file.open(QIODevice::WriteOnly))
            {
                qDebug() << "open file image error" << pngstart;
                break;
            }
            json_file.write(josndata);
            json_file.close();
            priview_flag = true;
            json_count++;
        }
        
        
        if (image_end == 0 || image_start == -1 || image_end == -1)
        {
            break;
        }
        if (image_end < image_start)
        {
            continue;
        }
        int next_image_offset = image_end + pngend.size();
        QByteArray imagedata;
        imagedata.append(readdata.mid(image_start, next_image_offset - image_start)); //截取图片数据
        //保存图片
        QString path = "./PxcpImage/";
        path.append(json_name);
        path.append(QString::number(json_count));
        path.append("_image");
        path.append(QString::number(image_count));
        path.append(".png");
        if (priview_flag)
        {
            PagePriviewMap.insert(json_name, path);
            priview_flag = false;
        }
        else
        {
             PageImageMap.insert(json_name, path);
        }
     
        QFile image_file(path);
        if (!image_file.open(QIODevice::WriteOnly))
        {
            qDebug() << "open file image error" << pngstart;
            break;
        }
        image_path_list.append(path);
        image_file.write(imagedata);
        image_file.close();
        image_count++;
        //偏移数据
       
        readdata = readdata.mid(next_image_offset + 1, readdata.size() - next_image_offset);    
     
    }   
    return true;
}

QStringList pxcpJson::GetImages()
{
    return image_path_list;
}

QStringList pxcpJson::GetPages()
{
    return page_name_list;
}

QString pxcpJson::GetPriview(QString key)
{
    return PagePriviewMap.value(key);
}
QString pxcpJson::GetPageImage(QString key)
{
    return PageImageMap.value(key);
}

void pxcpJson::FindPxcpJsonFile(QString jsonPath)
{
    jsonPaths.clear();
    FindJsonFile(jsonPath);
    jsonAnalysis(jsonPaths.at(0));
}

QString pxcpJson::GetPageName(QByteArray json_data)
{
    QString page_name;
    QJsonParseError  json_error;
    //json读取格式
    QJsonDocument json(QJsonDocument::fromJson(json_data, &json_error));
    if (json_error.error != QJsonParseError::NoError)
    {
        qDebug() << "GetPageName   error!" << json_data;
        return page_name;
    }

    QJsonObject rootObj = json.object();
    QStringList keys = rootObj.keys();
    if (rootObj.contains("name"))
    {
       QString name = rootObj.value("name").toString();
        
        //int start_flag = name.lastIndexOf("/");
       // int end_flag = name.lastIndexOf(".");
       // page_name = name.mid(start_flag + 1, end_flag - start_flag);
       page_name = name;
        qDebug() << name;
       
    }
    
    return page_name;
}

void pxcpJson::FindJsonFile(QString jsonPath)
{
    /*先对json进行解析获取坐标 */
    QDir dir(jsonPath);
    foreach(QFileInfo fileInfo, dir.entryInfoList(QDir::Dirs | QDir::Files, QDir::DirsFirst))
    {
        if (fileInfo.isDir())
        {
            //目录遍历
            if (fileInfo.fileName() == "." || fileInfo.fileName() == "..")continue;
            FindPxcpJsonFile(fileInfo.absoluteFilePath());
        }
        else {

            if (fileInfo.suffix() == "json")
            {
                //对位置json文件进行分析 获取到x y 高度 宽度的 icontmp.txt 文件

                jsonPaths.append(fileInfo.filePath());
                break;
            }
        }

    }

}