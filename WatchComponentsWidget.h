#pragma once

#include <QWidget>
#include "ui_WatchComponentsWidget.h"
#include <QStandardItemModel>
class WatchComponentsWidget : public QWidget
{
	Q_OBJECT

public:
	WatchComponentsWidget(QWidget *parent = Q_NULLPTR);
	~WatchComponentsWidget();

private:
	Ui::WatchComponentsWidget ui;
	QStandardItemModel* components_model;
};
