#ifndef PXCPJSON_H
#define PXCPJSON_H

#include <QObject>
#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QPainter>
#include <QPixmap>
#include <QImage>
#include <QFile>
#include <QJsonParseError>
#include <QFileInfo>
#include <QDir>
#include <QThread>
class pxcpJson : public QThread
{
    Q_OBJECT
public:
    // explicit pxcpJson(QObject *parent = nullptr);
    pxcpJson();
    void jsonAnalysis(QString jsonfile); //json解析
     void findIconSize(QString path);
     void savefile();
     QJsonArray geticonArray(QString iconFilePath); // 获取到有x y 高度 宽度 切图路径的json数组
     bool isOk();
     bool getJson(QString srcPath);
     QString getValue(QByteArray data);
     void  getBmpPaths(QString srcPath);//获取所有的bmp切图
     QString getBmpPath(QString name);
     void setPath(QString path);
     void run();
     QStringList bmpPath;
     bool GetJsonAndImage(QString srcPath); //获取坐标json文件和png图片
     QStringList GetImages();
     QStringList GetPages(); //获取所有界面
     QString GetPriview(QString key); //获取预览图
     QString GetPageImage(QString key); //获取效果图
     void FindPxcpJsonFile(QString jsonPath); //获取到该目录下的pxcp对应的json文件

private:


    int iconconut;
    QFile *iconfile;
    QString jsonPath;
   // QJsonArray object;
    QString iconFilePath;
    bool isok;
    QStringList image_path_list; //图片路径
    QString saveiconFile;
    QStringList page_name_list;
    QString GetPageName(QByteArray json_data); //获取界面的名字
    QMap<QString, QString> PagePriviewMap; //预览图
    QMap<QString, QString> PageImageMap; //效果图
    QStringList jsonPaths;
    void FindJsonFile(QString jsonPath);

signals:

public slots:
};

#endif // PXCPJSON_H
