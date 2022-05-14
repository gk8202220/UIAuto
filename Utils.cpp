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

 void Utils::CalcNumberPoints(QSize srcsize, QPoint src_point, QList<QPoint>* points, int digit, int interval)
 {
	 int src_x = src_point.x();
	 for (int i = 0; i < digit; i++)
	 {
		 QPoint point = src_point;
		 int width = srcsize.width();
		 point.setX(src_x + (width+ interval) * i); //根据图片的宽度自动偏移
		 points->append(src_point);
	 }
	
	

	 points->append(src_point);
 }
