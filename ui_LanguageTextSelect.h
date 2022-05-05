/********************************************************************************
** Form generated from reading UI file 'LanguageTextSelect.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LANGUAGETEXTSELECT_H
#define UI_LANGUAGETEXTSELECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LanguageTextSelect
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_filter;
    QTreeView *treeView_textList;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QListView *listView_selected;
    QPushButton *PB_confirm;

    void setupUi(QWidget *LanguageTextSelect)
    {
        if (LanguageTextSelect->objectName().isEmpty())
            LanguageTextSelect->setObjectName(QString::fromUtf8("LanguageTextSelect"));
        LanguageTextSelect->resize(547, 423);
        LanguageTextSelect->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        gridLayout = new QGridLayout(LanguageTextSelect);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(LanguageTextSelect);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit_filter = new QLineEdit(LanguageTextSelect);
        lineEdit_filter->setObjectName(QString::fromUtf8("lineEdit_filter"));

        horizontalLayout->addWidget(lineEdit_filter);


        verticalLayout->addLayout(horizontalLayout);

        treeView_textList = new QTreeView(LanguageTextSelect);
        treeView_textList->setObjectName(QString::fromUtf8("treeView_textList"));
        treeView_textList->setEditTriggers(QAbstractItemView::NoEditTriggers);
        treeView_textList->setSelectionMode(QAbstractItemView::ExtendedSelection);

        verticalLayout->addWidget(treeView_textList);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(LanguageTextSelect);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);

        listView_selected = new QListView(LanguageTextSelect);
        listView_selected->setObjectName(QString::fromUtf8("listView_selected"));
        listView_selected->setDragEnabled(true);
        listView_selected->setDragDropOverwriteMode(false);
        listView_selected->setDragDropMode(QAbstractItemView::InternalMove);
        listView_selected->setDefaultDropAction(Qt::MoveAction);

        verticalLayout_2->addWidget(listView_selected);


        verticalLayout_3->addLayout(verticalLayout_2);

        PB_confirm = new QPushButton(LanguageTextSelect);
        PB_confirm->setObjectName(QString::fromUtf8("PB_confirm"));

        verticalLayout_3->addWidget(PB_confirm);


        horizontalLayout_2->addLayout(verticalLayout_3);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);


        retranslateUi(LanguageTextSelect);
        QObject::connect(lineEdit_filter, SIGNAL(textChanged(QString)), LanguageTextSelect, SLOT(filterChanged(QString)));
        QObject::connect(PB_confirm, SIGNAL(clicked()), LanguageTextSelect, SLOT(on_confirm()));
        QObject::connect(treeView_textList, SIGNAL(pressed(QModelIndex)), LanguageTextSelect, SLOT(on_selected_text(QModelIndex)));

        QMetaObject::connectSlotsByName(LanguageTextSelect);
    } // setupUi

    void retranslateUi(QWidget *LanguageTextSelect)
    {
        LanguageTextSelect->setWindowTitle(QCoreApplication::translate("LanguageTextSelect", "\346\226\207\345\255\227\351\200\211\346\213\251", nullptr));
        label->setText(QCoreApplication::translate("LanguageTextSelect", "\346\220\234\347\264\242", nullptr));
        label_2->setText(QCoreApplication::translate("LanguageTextSelect", "\345\267\262\351\200\211\346\213\251", nullptr));
        PB_confirm->setText(QCoreApplication::translate("LanguageTextSelect", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LanguageTextSelect: public Ui_LanguageTextSelect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LANGUAGETEXTSELECT_H
