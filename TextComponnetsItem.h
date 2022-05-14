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
	QMap<Language_e, language_offset> text_point;//���Զ�Ӧ������
	QStringList element_list; //Ԫ�ص��б�
	//QList<ComponnetsItem> items;  //�и���������


} TextComponnetsItem;