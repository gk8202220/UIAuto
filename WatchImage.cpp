#include "WatchImage.h"
#include <QDir>
WatchImage::WatchImage(QObject *parent)
	: QObject(parent)
{
}

WatchImage::~WatchImage()
{
}

void WatchImage::LondImage(QString path)
{
}


void WatchImage::LondingImage(QString path)
{
	QDir dir(path);

	foreach(QFileInfo fileInfo, dir.entryInfoList(QDir::Dirs | QDir::Files, QDir::DirsFirst))
	{
		if (fileInfo.isDir())
		{
			//目录遍历
			if (fileInfo.fileName() == "." || fileInfo.fileName() == "..")continue;
	
			LondingImage(fileInfo.absoluteFilePath());


		}
		else {
			//qDebug() << fileInfo.filePath();
			//QImage image(fileInfo.filePath());
			if (fileInfo.suffix() == "bmp" || fileInfo.suffix() == "png")
			{
				QString icon_src = fileInfo.baseName();// .toUpper();q

				//Image_Path_Map.insert(icon_src, fileInfo.filePath());
			}
			else if (fileInfo.suffix() == "json")
			{
				//jsonfile(fileInfo.filePath());//获取坐标信息
			}

		}
	}
}
