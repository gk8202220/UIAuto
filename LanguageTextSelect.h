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
	void SetSelectedText(QStringList *text_list);//�����Ѿ�ѡ�������
private slots:
	void filterChanged(const QString text);
	void ShowSelectText();
	void on_selected_text(QModelIndex index); //ѡ�����ֵ��ź�
	void on_change_text(QModelIndex index); //����������
	void on_confirm();
private:
	Ui::LanguageTextSelect ui;
	QStringList *selected_text_list; //�Ѿ�ѡ����ı��б�
	QSortFilterProxyModel* modelProxy;
	QStandardItemModel* text_model; //��ѡ�������
	QStandardItemModel* selected_text_model;//�Ѿ�ѡ�������
signals:
	void updata_text();
};
