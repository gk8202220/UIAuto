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
	COMPONNET_TYPE_E Type(QString id); //��ȡ�ؼ�������
	QPoint GetPoint(QString id, Language_e lan);
	QPoint GetPoint(QString id);
	QMap<int, QPoint>* GetPoints(QString id);
	QString GetPriview(QString id);
	QString Family(QString id);
	void AppendItem(QString id, ComponnetsItem item);
	QMap<int, QStringList>* GetElementLists(QString id);
	QStringList *GetViewId(QString page_id); //��ȡ���������id
	bool contains(QString id);
	ComponnetsItem GetCurrentItem(QString id);
	int Count(); //��ǰ����Ԫ�صĸ���
	QString GetComponnetType(QString type);

	/*  ������ز���  */
	bool SelectPage(QString page_id); //ѡ�����
	bool AppendPage(); //��ӽ���
	bool RemovePage(QString page_id); //ɾ������
	QString CurrentPageId();
	QMap<QString, ComponnetsItem>* GetPage(QString page_id);//��ȡ����Ԫ��

	QStringList component_list; //�ؼ������� ���� 

	
	int Digit(QString fomat); //��ȡ�������ж���λ��
	QString DigitToString(int digit);
	int DigitToInt(QString digit);
private:
	QStringList component_id_list;//�ؼ���Ӣ��
	QMap<QString, QString> componnet_id_map; //�ؼ���Ӧ����������
	QMap<int, QString> digit_string_map; //����λ����Ӧ����������
	QMap<QString, QMap<QString, ComponnetsItem> > Page_view_items_map; //���н���Ŀؼ�
	QMap<QString, ComponnetsItem>*view_items_map;//��ǰ��������е�ID�Ϳؼ�
	ComponnetsItem *current_item; //��ǰѡ��Ŀؼ�

	QString current_page_id; //��ǰ�����id
};
