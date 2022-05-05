#include "LanguageTextSelect.h"
#pragma execution_character_set("UTF-8")
LanguageTextSelect::LanguageTextSelect(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	selected_text_model = new QStandardItemModel(this);
}

LanguageTextSelect::~LanguageTextSelect()
{
}

void LanguageTextSelect::SetTextList(QMap<QString, QString> id_text_map)
{
	text_model = new QStandardItemModel(this);
	modelProxy = new QSortFilterProxyModel(this);
	text_model->setHorizontalHeaderItem(1, new QStandardItem("ID"));
	text_model->setHorizontalHeaderItem(0, new QStandardItem("文字"));
	int row = 0;
	for each (QString id in id_text_map.keys())
	{
		//text_model->appendRow()
		QString text = id_text_map.value(id);
		text_model->setItem(row, 1, new QStandardItem(id));
		text_model->setItem(row, 0, new QStandardItem(text));
		row++;
	}
	modelProxy->setSourceModel(text_model);
	ui.treeView_textList->setModel(modelProxy);
}

void LanguageTextSelect::SetSelectedText(QStringList *text_list)
{
	selected_text_list = text_list;
	selected_text_model->clear();
	if (text_list->isEmpty())
	{
		return;
	}
	for each (QString text in *selected_text_list)
	{
		QStandardItem* item = new QStandardItem(text);
		selected_text_model->appendRow(item);
	
		ui.listView_selected->setModel(selected_text_model);
	}
	
}

void LanguageTextSelect::ShowSelectText()
{

}

void LanguageTextSelect::on_selected_text(QModelIndex index)
{
	QModelIndexList select_list = ui.treeView_textList->selectionModel()->selectedIndexes();
	for each (QModelIndex index in select_list)
	{
		int row = index.row();
		QModelIndex text_index = ui.treeView_textList->model()->index(row, 0);
		QString  text = text_index.data().toString();
		if (selected_text_list->contains(text))
		{
			continue;
		}
		selected_text_list->append(text);
		QStandardItem* item = new QStandardItem(text);
		selected_text_model->appendRow(item);
		ui.listView_selected->setModel(selected_text_model);
	}
	
	qDebug() << "on_selected_text";
}

void LanguageTextSelect::on_change_text(QModelIndex index)
{
	qDebug() << "on_change_text";
}

void LanguageTextSelect::on_confirm()
{
	int rows = selected_text_model->rowCount();
	/* 将原有的文字清空。再进行新的文字的获取*/
	selected_text_list->clear();
	for (int i = 0; i < rows; i++)
	{
		QString text = selected_text_model->index(i, 0).data().toString();
		selected_text_list->append(text);
	}
	emit updata_text();
	this->hide();
}

void LanguageTextSelect::filterChanged(const QString text)
{
	QRegularExpression regExp(text);
	modelProxy->setFilterRegularExpression(regExp);
}
