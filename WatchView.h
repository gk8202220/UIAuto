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
#define COMPONNET_FORMAT_STEP		"Step"
#define COMPONNET_FORMAT_BLE		"BLE"
#define COMPONNET_FORMAT_BUTTON		"Button"
#define COMPONNET_FORMAT_LABEL		"label"
typedef enum
{
	COMPONNET_TYPE_GENERAL,
	COMPONNET_TYPE_TEXT,
	COMPONNET_TYPE_NUMBER,

}COMPONNET_TYPE_E;

//typedef QMap<QString, ComponnetsItem> View_Items;
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
	int interval(QString id);
	QString Fomat(QString id);
	QStringList GetElementList(QString id);	
	void SetCurrentItem(QString id);
	COMPONNET_TYPE_E Type(QString id); //获取控件的类型
	QPoint GetPoint(QString id, Language_e lan);
	QPoint GetPoint(QString id);
	QMap<int, QPoint>* GetPoints(QString id);
	QString GetPriview(QString id);
	QString Family(QString id);
	void AppendItem(QString id, ComponnetsItem item);
	QMap<int, QStringList>* GetElementLists(QString id);
	QStringList *GetViewId(QString page_id); //获取界面的所有id
	bool contains(QString id);
	ComponnetsItem GetCurrentItem(QString id);
	int Count(); //当前界面元素的个数
	QString GetComponnetType(QString type);

	/*  界面相关操作  */
	bool SelectPage(QString page_id); //选择界面
	bool AppendPage(); //添加界面
	bool RemovePage(QString page_id); //删除界面
	QString CurrentPageId();
	QMap<QString, ComponnetsItem>* GetPage(QString page_id);//获取界面元素

	QStringList component_list; //控件的中文 名称 

	
	int Digit(QString fomat); //获取该类型有多少位数
	QString DigitToString(int digit);
	int DigitToInt(QString digit);
private:
	QStringList component_id_list;//控件的英文
	QMap<QString, QString> componnet_id_map; //控件对应的中文名称
	QMap<int, QString> digit_string_map; //数字位数对应的中文名称
	QMap<QString, QMap<QString, ComponnetsItem> > Page_view_items_map; //所有界面的控件
	QMap<QString, ComponnetsItem>*view_items_map;//当前界面的所有的ID和控件
	ComponnetsItem *current_item; //当前选择的控件

	QString current_page_id; //当前界面的id
};
