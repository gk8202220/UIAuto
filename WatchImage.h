#pragma once

#include <QObject>
#include <QMap>
class WatchImage : public QObject
{
	Q_OBJECT

public:
	WatchImage(QObject *parent);
	~WatchImage();
	void LondImage(QString path); //����ͼƬ
private:
	QMap<QString, QStringList> path_images_map;  //·����Ӧ��ͼƬ
	void LondingImage(QString path);
	
};
