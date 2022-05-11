#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDragEnterEvent>
#include <QUrl>
#include <QMimeData>
#include <QDropEvent>
#include  <QFile>
#include <QFileInfo>
#include <QDebug>
#include <QDir>
#include <QFileDevice>
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include  <QMap>
#include  "pxcpjson.h"
#include "formdraw.h"
#include <QMap>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QStandardItem>
#include "Language.h"
#include "ComponnetsItem.h"
#include "LanguageTextSelect.h"
#include "WatchView.h"
#include "VpWatchCode.h"
#include "ImageSelectWidget.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
	void paintEvent(QPaintEvent *event);
	bool eventFilter(QObject *watched, QEvent *event);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
private slots:
    void on_pushButton_clicked();

    void getBmpAddr(QString path);

    void on_CB_one_activated(const QString &arg1);

    void on_CB_Time_activated(const QString &arg1);

    void on_CB_heart_activated(const QString &arg1);

    void on_CB_step_activated(const QString &arg1);

    void on_CB_blu_activated(const QString &arg1);

    void on_CB_data_activated(const QString &arg1);

    void on_CB_ampm_activated(const QString &arg1);

    void on_CB_charge_activated(const QString &arg1);

    void on_CB_week_activated(const QString &arg1);

    void on_CB_calories_activated(const QString &arg1);

    void on_CB_unit_activated(const QString &arg1);

    void on_CB_distant_activated(const QString &arg1);

    void on_CB_sleep_activated(const QString &arg1);

    void on_CB_postion_activated(const QString &arg1);

    void on_CB_BP_activated(const QString &arg1);


    void on_CB_women_activated(const QString &arg1);

    void on_CB_sleep_2_activated(const QString &arg1);

    void on_display_text(const QModelIndex index); //选择的文字项
    void on_display_page(const QModelIndex index); //选择的文字项
    void on_lond_language_file(); //加载语言文件
    void on_select_language_file(int select); //选择语言文件
    void on_updata_select_text_list(); //更新选择的文字
    void on_updata_item_param(); //更新控件的参数
    void on_selected_item(QModelIndex index); //选择已经存在的控件
private:
    Ui::MainWindow *ui;
    QString filePath;
    QString iconName;
    QStringList iconTitleList;
    void UI_position(QString title);
    void display();
    void initDisplay();
    void FingPxcpJsonFile(QString jsonPath);
    void dispaly_BP(QString icon_data,QString icon_person,QString icon_no,QString icon_error);
    void write_code(QString data);
    void writePosiAndData(QString tile);
    void getBmpPaths(QString path);
    int  GetX();
    int  GetY();
    void saveBmpPaths(QString path);
    void DislayAddrParm(QString Image_title, QJsonArray image_arry);
    void LanguageProcess(); //多国语言处理
    bool CheckPointText(QPoint touch); //判断是否选中到文字
    //void SelectedText(QString id); //选中已有的文字
    void CreatTextItem(QPoint* point); //创建一个文字的控件
    void CreatItem(QString componnet_type, QPoint point); //创建一个的控件
    void CreatItem(QString componnet_type, QPoint* point);
    void SelectingItem(QString id); //选中的控件
    void DislayView(QPainter *painter); //显示界面
    void SaveSelectedItem(QString type, QString id);
    QJsonArray iconArray;
    QFile *file_c;
    QFile *file;
    QString title;
    QString dirName;
    QString addrName;
    QMap<QString,int> iconListnum;
    pxcpJson  *json;
    QString last_filePath;
    QString setPostionFun;
    QString WriteDataFun;

    QMap<QString, QString>Image_Path_Map; //图片命名和路径
    QStringList titleList; //图片类型的标题
    QJsonObject Title_Image_json;  //保存标题和对应的所有切图
    QStandardItemModel* iconModel;
    QStandardItemModel* selected_items_model; //已经选择的控件
   
      //多国语言
    Language* language;
    QJsonObject text_object;
    QString priview_path;
    font_t *current_select_text; //当前选中的文字

    bool item_is_drop; //选中项是否拖动

    Language_e current_lan; //当前的语言
    LanguageTextSelect* languageTextSelect; // 文字选中界面
    QStringList select_element_list;//当前选择的文本控件的ID
    QString current_item_id; //当前选择的控件

    WatchView *watch_view;
    VpWatchCode* vpWatchCode;
    ImageSelectWidget* imageSelectWidget;
   
};

#endif // MAINWINDOW_H
