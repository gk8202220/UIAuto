#pragma once

#include <QObject>

class VpWatchCode : public QObject
{
	Q_OBJECT

public:
	//VpWatchCode(QObject *parent);
	static VpWatchCode* getInstance()
	{
		static VpWatchCode vpWatchCode;
		return &vpWatchCode;
	}

	~VpWatchCode();
	void UI_time(QString title);
	void UI_AMPM(QString title);
	void UI_one(QString title, int count);
	void UI_charge(QString title);
	void UI_uint(QString title);
	void UI_BP(QString title);
	void UI_Sleep(QString title);

	void UI_week(QString title, QString title_en);
	void UI_Step(QString title);
	void UI_Sleep_4(QString title);
	void UI_blue(QString title);
	void UI_heart(QString title);
	void UI_data(QString title);
	void UI_calories(QString title);
	void UI_distance(QString title);
	void UI_Women(QString title);
	void CodesetOld();
	bool CodeIsOld();
	
private:
	QString setPostionFun = "LCD_SetXY(icon_16_";
	QString WriteDataFun = "LCD_SetImage(icon_16_";
};
