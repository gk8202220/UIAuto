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
	QString UI_time(QString title);
	QString UI_AMPM(QString title);
	QString UI_one(QString title, int count);
	QString UI_charge(QString title);
	QString UI_uint(QString title);
	QString UI_BP(QString title);
	QString UI_Sleep(QString title);
	QString UI_week(QString title);
	QString UI_week(QString title, QString title_en);
	QString UI_Step(QString title);
	QString UI_Sleep_4(QString title);
	QString UI_blue(QString title);
	QString UI_heart(QString title);
	QString UI_data(QString title);
	QString UI_calories(QString title);
	QString UI_distance(QString title);
	QString UI_Women(QString title);
	bool CodeIsOld();
	
private:
	QString setPostionFun = "LCD_SetXY(icon_16_";
	QString WriteDataFun = "LCD_SetImage(icon_16_";
};
