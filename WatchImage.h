#pragma once

#include <QObject>
#include <QMap>
class WatchImage : public QObject
{
	Q_OBJECT

public:
	WatchImage(QObject *parent);
	~WatchImage();
	void LondImage(QString path); //加载图片
private:
	QMap<QString, QStringList> path_images_map;  //路径对应的图片
	void LondingImage(QString path);
	
};
