#pragma once

#include <QObject>

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
};
