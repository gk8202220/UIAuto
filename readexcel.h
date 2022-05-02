#pragma once

#include <QObject>
#include <QAxObject>
class readexcel : public QObject
{
	Q_OBJECT

public:
	readexcel(QObject *parent);
	~readexcel();
	void read(QString file, QList<QList<QVariant> >& res);
	void castVariant2ListListVariant(const QVariant& var, QList<QList<QVariant> >& res);
};
