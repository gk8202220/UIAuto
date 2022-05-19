#pragma once

#include <QWidget>
#include "ui_ImageSelectWidget.h"
#include <QSortFilterProxyModel>
#include <QStandardItemModel>
#include <QRegularExpression>
#include <QModelIndex>
#include <QStandardItem>
typedef enum
{
	SELECT_MODE_CREAT,
	SELECT_MODE_APPEND,
}SELECT_MODE_T;
class ImageSelectWidget : public QWidget
{
	Q_OBJECT
private	slots:
	void on_select_item(const QModelIndex index);
	void on_selected_image(const QModelIndex index);
	void on_pb_confirm();

public:
	ImageSelectWidget(QWidget *parent = Q_NULLPTR);
	~ImageSelectWidget();
	void OpenPath(QString path);
	void setSelectedImage(QStringList* image_list);
	void SetMode(SELECT_MODE_T mode);

private:
	Ui::ImageSelectWidget ui;
	QString root_path;
	QString current_path;
	void SelectPath(QString Path);

	QStringList* selected_image_list; //已经选择的文本列表
	QSortFilterProxyModel* modelProxy;
	QStandardItemModel* image_model; //待选择的文字
	QStandardItemModel* selected_image_model;//已经选择的文字
	SELECT_MODE_T mode; 
signals:
	void updata_image();
	void create_image();
};
