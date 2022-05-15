#include "Utils.h"
#include <QFileInfo>
//Utils::Utils(QObject *parent)
//	: QObject(parent)
//{
//}

Utils::~Utils()
{
}

 QString Utils::GetBaseName(QString path)
{
	QString name = QFileInfo(path).baseName();
	return name;
}
 QStringList Utils::GetBaseName(QStringList paths)
 {
	 QStringList name_list;
	 for each (QString path  in paths)
	 {
		 QString name = QFileInfo(path).baseName();
		 name_list.append(name);
	 }
	
	 return name_list;
 }

 void Utils::CalcNumberPoints(QSize srcsize, QPoint src_point, QMap<int, QPoint>* points, int digit, int interval)
 {
	 int src_x = src_point.x();
	 points->clear();
	 int digit_index = digit - 1;
	 for (int i = 0; i < digit; i++)
	 {
		 QPoint point = src_point;
		 int width = srcsize.width();
		 point.setX(src_x + (width+ interval) * i); //根据图片的宽度自动偏移
		 points->insert(digit_index,point); //根据万，千，百，十，个，的顺序保存
		 digit_index--;
	 }
 }
