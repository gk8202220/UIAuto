/********************************************************************************
** Form generated from reading UI file 'WatchComponentsWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WATCHCOMPONENTSWIDGET_H
#define UI_WATCHCOMPONENTSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WatchComponentsWidget
{
public:

    void setupUi(QWidget *WatchComponentsWidget)
    {
        if (WatchComponentsWidget->objectName().isEmpty())
            WatchComponentsWidget->setObjectName(QString::fromUtf8("WatchComponentsWidget"));
        WatchComponentsWidget->resize(400, 300);

        retranslateUi(WatchComponentsWidget);

        QMetaObject::connectSlotsByName(WatchComponentsWidget);
    } // setupUi

    void retranslateUi(QWidget *WatchComponentsWidget)
    {
        WatchComponentsWidget->setWindowTitle(QCoreApplication::translate("WatchComponentsWidget", "WatchComponentsWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WatchComponentsWidget: public Ui_WatchComponentsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WATCHCOMPONENTSWIDGET_H
