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
	QMap<Language_e, language_offset> text_point;//���Զ�Ӧ������
	QStringList element_list; //Ԫ�ص��б�
	

};
