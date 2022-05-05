#pragma once

#include <QWidget>
#include "ui_LanguageTextSelect.h"
#include <QSortFilterProxyModel>
#include <QStandardItemModel>
#include <QRegularExpression>
class LanguageTextSelect : public QWidget
{
	Q_OBJECT

public:
	LanguageTextSelect(QWidget *parent = Q_NULLPTR);
	~LanguageTextSelect();
	void SetTextList(QMap<QString, QString> id_text_map);
	void SetSelectedText(QStringList *text_list);//设置已经选择的文字
private slots:
	void filterChanged(const QString text);
	void ShowSelectText();
	void on_selected_text(QModelIndex index); //选中文字的信号
	void on_change_text(QModelIndex index); //更新了文字
	void on_confirm();
private:
	Ui::LanguageTextSelect ui;
	QStringList *selected_text_list; //已经选择的文本列表
	QSortFilterProxyModel* modelProxy;
	QStandardItemModel* text_model; //待选择的文字
	QStandardItemModel* selected_text_model;//已经选择的文字
signals:
	void updata_text();
};
