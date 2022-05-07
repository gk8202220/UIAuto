#pragma once

#include <QObject>
#include "Language.h"
#include <QIcon>
#include <QList>

class ComponnetsItem 
{
public:
	ComponnetsItem();
	~ComponnetsItem();
	QString fomat;	
	QPoint point;
	QSize size;
	QString text;
	QRect Geometry;
	int id;
	font_t font;
	QMap<Language_e, language_offset> text_point;//语言对应的坐标
	QStringList element_list; //元素的列表
	

};
