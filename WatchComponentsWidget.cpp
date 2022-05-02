#include "WatchComponentsWidget.h"
#pragma execution_character_set("UTF-8")
WatchComponentsWidget::WatchComponentsWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	components_model = new QStandardItemModel(this);
	QStandardItem* item = new QStandardItem("ÎÄ±¾");
	components_model->setItem(0, 0, item);
	
}

WatchComponentsWidget::~WatchComponentsWidget()
{

}
