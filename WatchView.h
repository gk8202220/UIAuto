#pragma once
#pragma execution_character_set("utf-8")
#define COMPONNET_FORMAT_BETTARY	"Bettary"
#define COMPONNET_FORMAT_TEXT		"Text"
#define COMPONNET_FORMAT_BG			"bg"
#define COMPONNET_FORMAT_CALORIES	"calories"
#define COMPONNET_FORMAT_HOUR		"hour"
#define COMPONNET_FORMAT_MINUTE		"minute"
#define COMPONNET_FORMAT_SECOND		"second"
#define COMPONNET_FORMAT_YEAR		"year"
#define COMPONNET_FORMAT_MONTH		"month"
#define COMPONNET_FORMAT_DAY		"day"
#define COMPONNET_FORMAT_WEEK		"week"
#define COMPONNET_FORMAT_HEART		"heart"
#define COMPONNET_FORMAT_SLEEP		"sleep"
#define COMPONNET_FORMAT_BP			"BP"
#define COMPONNET_FORMAT_DISTANCE	"Distance"
#define COMPONNET_FORMAT_BLE		"BLE"
#define COMPONNET_FORMAT_BUTTON		"Button"
#define COMPONNET_FORMAT_LABEL		"label"

#include <QObject>
#include <QMap>
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
	QStringList GetElementList(QString id);
	void SetItem(ComponnetsItem item);
	void SetCurrentItem(QString id);
	ComponnetsItem current_item;
	QMap<QString, ComponnetsItem> view_items_map;
	QPoint GetPoint(QString id, Language_e lan);
	QPoint GetPoint(QString id);
	QString GetPriview(QString id);
	QString Family(QString id);
	void AppendItem(QString id, ComponnetsItem item);
	QStringList GetViewId();
	bool contains(QString id);
	ComponnetsItem GetCurrentItem(QString id);
	int Count();
	QStringList component_list;
	QString GetComponnetType(QString type);
private:
	QStringList component_id_list;
	QMap<QString, QString> componnet_id_map;
};
