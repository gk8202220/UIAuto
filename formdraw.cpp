#include "formdraw.h"
#include "ui_formdraw.h"
#include <QDebug>
#include <QLabel>
#include <QPixmap>

FormDraw::FormDraw(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormDraw)
{
    ui->setupUi(this);
}

FormDraw::~FormDraw()
{
    delete ui;
}

void FormDraw::setPath(QJsonArray path)
{
    object = path ;
}

void FormDraw::paintEvent(QPaintEvent *event)
{

      QPainter paint(this);
      pxcpJson json;
      if(!object.isEmpty())
      {
          for(int i = 0; i< object.size(); i++)
          {
                   QJsonObject  rectInfo = object.at(i).toObject();
                   int x = rectInfo.value("x").toInt();
                   int y =rectInfo.value("y").toInt();
                   //显示大背景
                   if(x == 0 && y == 0)
                   {
                       QString filePath1 =  rectInfo.value("path").toString();
                       if(!filePath1.isEmpty())
                       {
                           qDebug()<<"x = "<< x << ",y =  " << y  << ",parh = " << filePath1;
                           QImage *image = new QImage(filePath1);
                           paint.drawImage(x,y,*image);
                           break;
                       }
                   }
           }
          for(int i = 0; i< object.size(); i++)
          {


               QJsonObject  rectInfo = object.at(i).toObject();
               int x = rectInfo.value("x").toInt();
               int y =rectInfo.value("y").toInt();
               if(x == 0 && y ==  0)
               {
                   continue;
               }
              // int height =rectInfo.value("height").toInt();
              // int width = rectInfo.value("width").toInt();
               QString filePath1 =  rectInfo.value("path").toString();
               //qDebug() << "*********显示切图*********";
               //qDebug()<<"x = "<< x << ",y =  " << y  << ",parh = " << filePath1;
               QImage *image = new QImage(filePath1);
               paint.drawImage(x,y,*image);

          }

      }

}
