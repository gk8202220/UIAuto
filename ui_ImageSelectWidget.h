/********************************************************************************
** Form generated from reading UI file 'ImageSelectWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageSelectWidget
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_filter;
    QPushButton *PB_UP;
    QPushButton *PB_Confirm;
    QSpacerItem *verticalSpacer_2;
    QListView *LV_Image_Browse;
    QListView *LV_Image_selected;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer;
    QPushButton *PB_Down;

    void setupUi(QWidget *ImageSelectWidget)
    {
        if (ImageSelectWidget->objectName().isEmpty())
            ImageSelectWidget->setObjectName(QString::fromUtf8("ImageSelectWidget"));
        ImageSelectWidget->resize(486, 567);
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font.setPointSize(18);
        ImageSelectWidget->setFont(font);
        gridLayout = new QGridLayout(ImageSelectWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer = new QSpacerItem(227, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 2);

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

        PB_UP = new QPushButton(ImageSelectWidget);
        PB_UP->setObjectName(QString::fromUtf8("PB_UP"));
        PB_UP->setMaximumSize(QSize(80, 60));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font1.setPointSize(9);
        PB_UP->setFont(font1);

        gridLayout->addWidget(PB_UP, 2, 2, 1, 1);

        PB_Confirm = new QPushButton(ImageSelectWidget);
        PB_Confirm->setObjectName(QString::fromUtf8("PB_Confirm"));

        gridLayout->addWidget(PB_Confirm, 6, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 98, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 3, 2, 1, 1);

        LV_Image_Browse = new QListView(ImageSelectWidget);
        LV_Image_Browse->setObjectName(QString::fromUtf8("LV_Image_Browse"));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font2.setPointSize(16);
        LV_Image_Browse->setFont(font2);
        LV_Image_Browse->setEditTriggers(QAbstractItemView::NoEditTriggers);
        LV_Image_Browse->setSelectionMode(QAbstractItemView::ExtendedSelection);

        gridLayout->addWidget(LV_Image_Browse, 1, 0, 5, 1);

        LV_Image_selected = new QListView(ImageSelectWidget);
        LV_Image_selected->setObjectName(QString::fromUtf8("LV_Image_selected"));
        LV_Image_selected->setEditTriggers(QAbstractItemView::NoEditTriggers);
        LV_Image_selected->setDragEnabled(true);
        LV_Image_selected->setDragDropOverwriteMode(false);
        LV_Image_selected->setDragDropMode(QAbstractItemView::InternalMove);
        LV_Image_selected->setDefaultDropAction(Qt::TargetMoveAction);
        LV_Image_selected->setMovement(QListView::Snap);

        gridLayout->addWidget(LV_Image_selected, 1, 1, 5, 1);

        horizontalSpacer_2 = new QSpacerItem(229, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 6, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 138, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 1, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 118, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 5, 2, 2, 1);

        PB_Down = new QPushButton(ImageSelectWidget);
        PB_Down->setObjectName(QString::fromUtf8("PB_Down"));
        PB_Down->setMaximumSize(QSize(80, 60));
        PB_Down->setFont(font1);

        gridLayout->addWidget(PB_Down, 4, 2, 1, 1);


        retranslateUi(ImageSelectWidget);
        QObject::connect(LV_Image_Browse, SIGNAL(doubleClicked(QModelIndex)), ImageSelectWidget, SLOT(on_select_item(QModelIndex)));
        QObject::connect(LV_Image_Browse, SIGNAL(pressed(QModelIndex)), ImageSelectWidget, SLOT(on_selected_image(QModelIndex)));
        QObject::connect(PB_Confirm, SIGNAL(clicked()), ImageSelectWidget, SLOT(on_pb_confirm()));
        QObject::connect(LV_Image_selected, SIGNAL(doubleClicked(QModelIndex)), ImageSelectWidget, SLOT(on_delete_item(QModelIndex)));
        QObject::connect(PB_UP, SIGNAL(clicked()), ImageSelectWidget, SLOT(on_item_up()));

        QMetaObject::connectSlotsByName(ImageSelectWidget);
    } // setupUi

    void retranslateUi(QWidget *ImageSelectWidget)
    {
        ImageSelectWidget->setWindowTitle(QCoreApplication::translate("ImageSelectWidget", "\350\265\204\346\272\220\346\265\217\350\247\210\345\231\250", nullptr));
        label->setText(QCoreApplication::translate("ImageSelectWidget", "\346\220\234\347\264\242", nullptr));
        PB_UP->setText(QCoreApplication::translate("ImageSelectWidget", "\344\270\212\347\247\273", nullptr));
        PB_Confirm->setText(QCoreApplication::translate("ImageSelectWidget", "\347\241\256\345\256\232", nullptr));
        PB_Down->setText(QCoreApplication::translate("ImageSelectWidget", "\344\270\213\347\247\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ImageSelectWidget: public Ui_ImageSelectWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGESELECTWIDGET_H
