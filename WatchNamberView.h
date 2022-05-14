#pragma once

#include <QObject>
#include <QMap>
#include "ComponnetsItem.h"

class WatchNamberView : public QObject
{
	Q_OBJECT

public:
	WatchNamberView(QObject *parent);
	~WatchNamberView();
	int Height(QString id);
	int Width(QString id);
	int FontSize(QString id);
	int Spacing(QString id);
	int LineHeight(QString id);
	int X(QString id);
	int Y(QString id);
	QString Fomat(QString id);
	QStringList GetElementList(QString id);
	void SetItem(NumberComponnetsItem item);
	void SetCurrentItem(QString id);
	QString ItemType(QString id);
	QPoint GetPoint(QString id, Language_e lan);
	QPoint GetPoint(QString id);
	QString GetPriview(QString id);
	QString Family(QString id);
	void AppendItem(QString id, NumberComponnetsItem item);
	QStringList GetViewId();
	bool contains(QString id);
	NumberComponnetsItem GetCurrentItem(QString id);
	int Count();

	QString GetComponnetType(QString type);
	QStringList component_list;
	NumberComponnetsItem current_item;
	
	QMap<QString, NumberComponnetsItem> view_number_items_map;
private:
	QStringList numberComponnet_id_list;
	QMap<QString, QString> numberComponnet_id_map;
};
