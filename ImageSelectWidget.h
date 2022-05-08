#pragma once

#include <QWidget>
#include "ui_ImageSelectWidget.h"
#include <QSortFilterProxyModel>
#include <QStandardItemModel>
#include <QRegularExpression>
#include <QModelIndex>
#include <QStandardItem>
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

private:
	Ui::ImageSelectWidget ui;
	QString root_path;
	QString current_path;
	void SelectPath(QString Path);

	QStringList* selected_image_list; //�Ѿ�ѡ����ı��б�
	QSortFilterProxyModel* modelProxy;
	QStandardItemModel* image_model; //��ѡ�������
	QStandardItemModel* selected_image_model;//�Ѿ�ѡ�������
signals:
	void updata_image();
};
