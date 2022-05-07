#pragma once

#include <QObject>
#include "Language.h"
#include <QIcon>
#include <QList>
#define COMPONNET_FORMAT_BETTARY "Bettary"
#define COMPONNET_FORMAT_TEXT "Text"
class ComponnetsItem 
{
public:
	ComponnetsItem();
	ComponnetsItem(QString foamt, QVariant *data);
	~ComponnetsItem();
	QString fomat;
	QVariant *data;
	
	QPoint point;
	QSize size;
	QString text;
	QRect Geometry;
	int id;
	QIcon *icon;
	QStringList texts;
	font_t font;
	QMap<Language_e, language_offset> text_point;//语言对应的坐标

	

};
