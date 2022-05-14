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
	int interval; 
	int id;
	font_t font;
	QMap<Language_e, language_offset> text_point;//语言对应的坐标
	QStringList element_list; //元素的列表
	QList<QPoint>points;
	QList<QStringList>element_lists;

} ComponnetsItem;

typedef struct
{
	QString fomat;
	//QPoint point;
	QSize size;
	//QString current_element;
	int id;
	//QStringList element_list; //元素的列表
	//QMap<QString, QStringList>element_lists; //有附带的子项
	//QMap<QString, QPoint>points; //有附带的子项
	QList<QPoint>points;
	QList<QStringList>element_lists;


} NumberComponnetsItem;