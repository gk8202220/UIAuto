#pragma once
#include <QObject>
#include "Language.h"
#include <QIcon>
#include <QList>

typedef struct
{

	QString fomat;
	QPoint point;
	QSize size;
	QString current_element;
	QRect Geometry;
	int id;
	font_t font;
	QMap<Language_e, language_offset> text_point;//语言对应的坐标
	QStringList element_list; //元素的列表
	//QList<ComponnetsItem> items;  //有附带的子项


} TextComponnetsItem;