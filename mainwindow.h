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
	//bool eventFilter(QObject *watched, QEvent *event);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
private slots:

    void on_display_text(const QModelIndex index); //选择的文字项
    void on_display_page(const QModelIndex index); //选择的文字项
    void on_lond_language_file(); //加载语言文件
    void on_select_language_file(int select); //选择语言文件
    void on_updata_select_content_list(); //更新选择的文字
    void on_updata_item_param(); //更新控件的参数
    void on_selected_item(QModelIndex index); //从已选择的列表中选中控件
    void on_creat_item();
    void on_create_page(); //创建界面
private:
    Ui::MainWindow *ui;
    int  GetX();
    int  GetY();

  
    void LanguageProcess(); //多国语言处理
    bool CheckPointText(QPoint touch); //判断是否选中到文字

    void CreatTextItem(QPoint* point); //创建一个文字的控件
   
    void CreatItem(QString componnet_type, QPoint point); //创建一个的控件
    void CreatNumber(QString componnet_type, QPoint *point); //创建一个数字的控件
    void CreatItem(QString componnet_type, QPoint* point);
    void SelectingItem(QString id); //选中的控件
    void DislayView(QPainter *painter); //显示界面
    void SaveSelectedItem(QString type, QString id);

    pxcpJson  *pxcp;
    QStandardItemModel* iconModel;
    QStandardItemModel* selected_items_model; //已经选择的控件
    QStandardItemModel* page_model; //已经选择的控件
      //多国语言
    Language* language;
    QJsonObject text_object;
    QString priview_path;
    font_t *current_select_text; //当前选中的文字

    bool item_is_drop; //选中项是否拖动

    Language_e current_lan; //当前的语言
    LanguageTextSelect* languageTextSelect; // 文字选中界面
    QStringList select_element_list;//当前选择的图片或者文字的ID
    QString current_item_id; //当前选择的控件

    WatchView *watch_view;
    VpWatchCode* vpWatchCode;
    ImageSelectWidget* imageSelectWidget;

    QString creat_componnet_type; //创建的类型
    QPoint creat_point;//创建的位置
    QPoint oldPoint;
    QString current_page_id; //当前界面的id

   
};

#endif // MAINWINDOW_H
