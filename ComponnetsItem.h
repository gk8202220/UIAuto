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
	
	QPoint point;
	QSize size;
	QString text;
	QRect Geometry;
	int id;
	QIcon *icon;
	QStringList texts;
	font_t font;
	QStringList text_id;
	QMap<QString, QString> id_text_map;


	

};
