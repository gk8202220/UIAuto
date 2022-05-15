#pragma once

#include <QObject>
#include <QSize>
#include <QPoint>
class Utils : public QObject
{
	Q_OBJECT

public:
	//Utils(QObject *parent);
	~Utils();
	static Utils* GetInstans()
	{
		static Utils urils;
		return &urils;
	}
	static QString GetBaseName(QString path);
	static QStringList GetBaseName(QStringList paths);
	static void CalcNumberPoints(QSize srcsize, QPoint src_point, QMap<int, QPoint>* points, int digit, int interval);
};
