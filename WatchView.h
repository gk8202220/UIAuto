#pragma once

#include <QObject>
#include "ComponnetsItem.h"
#include "Language.h"
class WatchView : public QObject
{
	Q_OBJECT

public:
	WatchView(QObject *parent);
	~WatchView();
	int Height(QString id);
	int Width(QString id);
	int FontSize(QString id);
	int Spacing(QString id);
	int LineHeight(QString id);
	int X(QString id);
	int Y(QString id);
	QString Fomat(QString id);
	QStringList GetTextList(QString id);
	void SetItem(ComponnetsItem item);
	void SetCurrentItem(QString id);
	ComponnetsItem current_item;
	QMap<QString, ComponnetsItem> *view_items_map;
	void SetView(QMap<QString, ComponnetsItem> *items_map);
	QPoint GetPoint(QString id, Language_e lan);
	QPoint GetPoint(QString id);
	QString GetPriviewText(QString id);
	QString Family(QString id);

};
