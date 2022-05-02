#pragma once

#include <QObject>
#include "Language.h"
#include <QIcon>
#include <QList>
class ComponnetsItem 
{
public:
	ComponnetsItem();
	ComponnetsItem(QString foamt, QVariant *data);
	~ComponnetsItem();
	QString fomat;
	QVariant *data;
	//font_t font;
	QPoint point;
	QSize size;
	QString text;
	QRect Geometry;
	int id;
	QIcon *icon;
	QStringList texts;


	

};
