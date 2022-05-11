/********************************************************************************
** Form generated from reading UI file 'ImageSelectWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGESELECTWIDGET_H
#define UI_IMAGESELECTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageSelectWidget
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_filter;
    QListView *LV_Image_Browse;
    QListView *LV_Image_selected;
    QPushButton *PB_Confirm;

    void setupUi(QWidget *ImageSelectWidget)
    {
        if (ImageSelectWidget->objectName().isEmpty())
            ImageSelectWidget->setObjectName(QString::fromUtf8("ImageSelectWidget"));
        ImageSelectWidget->resize(560, 567);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(18);
        ImageSelectWidget->setFont(font);
        gridLayout = new QGridLayout(ImageSelectWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(ImageSelectWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit_filter = new QLineEdit(ImageSelectWidget);
        lineEdit_filter->setObjectName(QString::fromUtf8("lineEdit_filter"));

        horizontalLayout->addWidget(lineEdit_filter);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        LV_Image_Browse = new QListView(ImageSelectWidget);
        LV_Image_Browse->setObjectName(QString::fromUtf8("LV_Image_Browse"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(16);
        LV_Image_Browse->setFont(font1);
        LV_Image_Browse->setEditTriggers(QAbstractItemView::NoEditTriggers);
        LV_Image_Browse->setSelectionMode(QAbstractItemView::ExtendedSelection);

        gridLayout->addWidget(LV_Image_Browse, 1, 0, 1, 1);

        LV_Image_selected = new QListView(ImageSelectWidget);
        LV_Image_selected->setObjectName(QString::fromUtf8("LV_Image_selected"));

        gridLayout->addWidget(LV_Image_selected, 1, 1, 1, 1);

        PB_Confirm = new QPushButton(ImageSelectWidget);
        PB_Confirm->setObjectName(QString::fromUtf8("PB_Confirm"));

        gridLayout->addWidget(PB_Confirm, 2, 1, 1, 1);


        retranslateUi(ImageSelectWidget);
        QObject::connect(LV_Image_Browse, SIGNAL(doubleClicked(QModelIndex)), ImageSelectWidget, SLOT(on_select_item(QModelIndex)));
        QObject::connect(LV_Image_Browse, SIGNAL(pressed(QModelIndex)), ImageSelectWidget, SLOT(on_selected_image(QModelIndex)));
        QObject::connect(PB_Confirm, SIGNAL(clicked()), ImageSelectWidget, SLOT(on_pb_confirm()));

        QMetaObject::connectSlotsByName(ImageSelectWidget);
    } // setupUi

    void retranslateUi(QWidget *ImageSelectWidget)
    {
        ImageSelectWidget->setWindowTitle(QApplication::translate("ImageSelectWidget", "\350\265\204\346\272\220\346\265\217\350\247\210\345\231\250", nullptr));
        label->setText(QApplication::translate("ImageSelectWidget", "\346\220\234\347\264\242", nullptr));
        PB_Confirm->setText(QApplication::translate("ImageSelectWidget", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ImageSelectWidget: public Ui_ImageSelectWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGESELECTWIDGET_H
