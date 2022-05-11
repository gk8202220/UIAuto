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
