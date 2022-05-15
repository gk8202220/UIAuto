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
	//QRect Geometry;
	int interval;  //文字或者图片的间隔
	int id;
	int count; //这个控件有多少的子元素(一般为数字的位数)
	font_t font;
	QMap<Language_e, language_offset> text_point;//语言对应的坐标
	QStringList element_list; //元素的列表
	QMap<int, QPoint>points;
	QMap<int , QStringList>element_lists;

} ComponnetsItem;

