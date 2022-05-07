#include "ComponnetsItem.h"
#include <QDebug>
#include <QVariant>
ComponnetsItem::ComponnetsItem()
{
}

ComponnetsItem::ComponnetsItem(QString foamt, QVariant *data)
{
	this->fomat = foamt;
	this->data  = data;
	qDebug() << foamt << data->toString();
}

ComponnetsItem::~ComponnetsItem()
{
}
