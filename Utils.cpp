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