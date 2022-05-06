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
	QMap<Language_e, language_offset> text_point;//���Զ�Ӧ������

	

};
