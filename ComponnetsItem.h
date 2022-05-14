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
	QMap<Language_e, language_offset> text_point;//���Զ�Ӧ������
	QStringList element_list; //Ԫ�ص��б�
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
	//QStringList element_list; //Ԫ�ص��б�
	//QMap<QString, QStringList>element_lists; //�и���������
	//QMap<QString, QPoint>points; //�и���������
	QList<QPoint>points;
	QList<QStringList>element_lists;


} NumberComponnetsItem;