/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_6;
    QLineEdit *lineEdit;
    QListView *listView_page;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_47;
    QTreeView *treeView_slelect_items;
    QLabel *label_display;
    QSpacerItem *verticalSpacer;
    QDockWidget *dockWidget_3;
    QWidget *dockWidgetContents_4;
    QToolBox *toolBox;
    QWidget *page;
    QGridLayout *gridLayout_8;
    QWidget *page_2;
    QGridLayout *gridLayout_7;
    QHBoxLayout *horizontalLayout_24;
    QLabel *label_31;
    QFontComboBox *fontComboBox;
    QHBoxLayout *horizontalLayout_31;
    QLabel *label_33;
    QSpinBox *spinBox_spacing;
    QHBoxLayout *horizontalLayout_28;
    QLabel *label_24;
    QComboBox *comboBox_number;
    QHBoxLayout *horizontalLayout_21;
    QLabel *label_25;
    QLabel *label_22;
    QSpinBox *spinBox_cood_x;
    QLabel *label_23;
    QSpinBox *spinBox_cood_y;
    QHBoxLayout *horizontalLayout_43;
    QLabel *label_29;
    QSpinBox *spinBox_font;
    QHBoxLayout *horizontalLayout_22;
    QComboBox *comboBox_texts;
    QPushButton *PB_lond_font;
    QHBoxLayout *horizontalLayout_33;
    QLabel *label_21;
    QComboBox *CB_language;
    QHBoxLayout *horizontalLayout_27;
    QHBoxLayout *horizontalLayout_25;
    QLabel *label_30;
    QHBoxLayout *horizontalLayout_26;
    QLineEdit *lineEdit_2;
    QLabel *label_13;
    QHBoxLayout *horizontalLayout_32;
    QLabel *label_34;
    QSpinBox *spinBox_LineHeight;
    QHBoxLayout *horizontalLayout_23;
    QLabel *label_28;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label_26;
    QSpinBox *spinBox_width;
    QLabel *label_27;
    QSpinBox *spinBox_height;
    QSpacerItem *verticalSpacer_2;
    QListView *listView_componnets;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QGridLayout *gridLayout_9;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_3;
    QTextBrowser *textBrowser;
    QWidget *tab_2;
    QGridLayout *gridLayout_4;
    QTextBrowser *TB_Positon;
    QWidget *tab_3;
    QGridLayout *gridLayout_5;
    QTextBrowser *TB_head;
    QWidget *tab_4;
    QTextBrowser *TB_addr;
    QWidget *tab_5;
    QGridLayout *gridLayout_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1042, 865);
        MainWindow->setMinimumSize(QSize(56, 50));
        QIcon icon;
        icon.addFile(QString::fromUtf8("C:/Users/Administrator/Desktop/1.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 47, 48);\n"
"color: rgb(255, 255, 255);"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_6 = new QGridLayout(centralWidget);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);
        lineEdit->setMaximumSize(QSize(240, 20));

        gridLayout_6->addWidget(lineEdit, 0, 0, 1, 1);

        listView_page = new QListView(centralWidget);
        listView_page->setObjectName(QString::fromUtf8("listView_page"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(listView_page->sizePolicy().hasHeightForWidth());
        listView_page->setSizePolicy(sizePolicy1);
        listView_page->setMinimumSize(QSize(280, 0));
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221 Light")});
        font.setPointSize(12);
        listView_page->setFont(font);
        listView_page->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        listView_page->setDragEnabled(true);
        listView_page->setIconSize(QSize(200, 200));
        listView_page->setTextElideMode(Qt::ElideNone);
        listView_page->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
        listView_page->setFlow(QListView::LeftToRight);
        listView_page->setGridSize(QSize(200, 220));
        listView_page->setViewMode(QListView::IconMode);

        gridLayout_6->addWidget(listView_page, 1, 0, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_47 = new QLabel(centralWidget);
        label_47->setObjectName(QString::fromUtf8("label_47"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_47->sizePolicy().hasHeightForWidth());
        label_47->setSizePolicy(sizePolicy2);

        verticalLayout_3->addWidget(label_47);


        verticalLayout_4->addLayout(verticalLayout_3);

        treeView_slelect_items = new QTreeView(centralWidget);
        treeView_slelect_items->setObjectName(QString::fromUtf8("treeView_slelect_items"));
        sizePolicy.setHeightForWidth(treeView_slelect_items->sizePolicy().hasHeightForWidth());
        treeView_slelect_items->setSizePolicy(sizePolicy);
        treeView_slelect_items->setTextElideMode(Qt::ElideMiddle);

        verticalLayout_4->addWidget(treeView_slelect_items);

        label_display = new QLabel(centralWidget);
        label_display->setObjectName(QString::fromUtf8("label_display"));
        label_display->setMinimumSize(QSize(360, 360));
        label_display->setMaximumSize(QSize(360, 360));
        label_display->setAcceptDrops(true);
        label_display->setAutoFillBackground(false);
        label_display->setStyleSheet(QString::fromUtf8(""));
        label_display->setFrameShape(QFrame::Box);
        label_display->setFrameShadow(QFrame::Sunken);
        label_display->setTextFormat(Qt::PlainText);
        label_display->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_display->setWordWrap(true);

        verticalLayout_4->addWidget(label_display);

        verticalSpacer = new QSpacerItem(20, 228, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);


        gridLayout_6->addLayout(verticalLayout_4, 0, 1, 2, 1);

        MainWindow->setCentralWidget(centralWidget);
        dockWidget_3 = new QDockWidget(MainWindow);
        dockWidget_3->setObjectName(QString::fromUtf8("dockWidget_3"));
        dockWidget_3->setMinimumSize(QSize(350, 986));
        dockWidget_3->setMaximumSize(QSize(350, 524287));
        dockWidget_3->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
        dockWidgetContents_4 = new QWidget();
        dockWidgetContents_4->setObjectName(QString::fromUtf8("dockWidgetContents_4"));
        toolBox = new QToolBox(dockWidgetContents_4);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        toolBox->setGeometry(QRect(10, 200, 332, 614));
        toolBox->setMaximumSize(QSize(350, 800));
        toolBox->setLayoutDirection(Qt::LeftToRight);
        toolBox->setAutoFillBackground(false);
        toolBox->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 47, 48);\n"
"color: rgb(255, 255, 255);"));
        toolBox->setFrameShape(QFrame::WinPanel);
        toolBox->setFrameShadow(QFrame::Sunken);
        toolBox->setLineWidth(0);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setGeometry(QRect(0, 0, 328, 562));
        gridLayout_8 = new QGridLayout(page);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        toolBox->addItem(page, QString::fromUtf8("\346\216\247\344\273\266"));
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        page_2->setGeometry(QRect(0, 0, 328, 562));
        gridLayout_7 = new QGridLayout(page_2);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setSpacing(6);
        horizontalLayout_24->setObjectName(QString::fromUtf8("horizontalLayout_24"));
        label_31 = new QLabel(page_2);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_31->sizePolicy().hasHeightForWidth());
        label_31->setSizePolicy(sizePolicy3);

        horizontalLayout_24->addWidget(label_31);

        fontComboBox = new QFontComboBox(page_2);
        fontComboBox->setObjectName(QString::fromUtf8("fontComboBox"));

        horizontalLayout_24->addWidget(fontComboBox);


        gridLayout_7->addLayout(horizontalLayout_24, 5, 0, 1, 1);

        horizontalLayout_31 = new QHBoxLayout();
        horizontalLayout_31->setSpacing(6);
        horizontalLayout_31->setObjectName(QString::fromUtf8("horizontalLayout_31"));
        label_33 = new QLabel(page_2);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        sizePolicy3.setHeightForWidth(label_33->sizePolicy().hasHeightForWidth());
        label_33->setSizePolicy(sizePolicy3);

        horizontalLayout_31->addWidget(label_33);

        spinBox_spacing = new QSpinBox(page_2);
        spinBox_spacing->setObjectName(QString::fromUtf8("spinBox_spacing"));
        spinBox_spacing->setMinimumSize(QSize(100, 0));
        spinBox_spacing->setFocusPolicy(Qt::ClickFocus);
        spinBox_spacing->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        spinBox_spacing->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);
        spinBox_spacing->setKeyboardTracking(false);
        spinBox_spacing->setValue(0);

        horizontalLayout_31->addWidget(spinBox_spacing);


        gridLayout_7->addLayout(horizontalLayout_31, 7, 0, 1, 1);

        horizontalLayout_28 = new QHBoxLayout();
        horizontalLayout_28->setSpacing(6);
        horizontalLayout_28->setObjectName(QString::fromUtf8("horizontalLayout_28"));
        label_24 = new QLabel(page_2);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        QSizePolicy sizePolicy4(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_24->sizePolicy().hasHeightForWidth());
        label_24->setSizePolicy(sizePolicy4);

        horizontalLayout_28->addWidget(label_24);

        comboBox_number = new QComboBox(page_2);
        comboBox_number->setObjectName(QString::fromUtf8("comboBox_number"));

        horizontalLayout_28->addWidget(comboBox_number);


        gridLayout_7->addLayout(horizontalLayout_28, 2, 0, 1, 1);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setSpacing(6);
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        label_25 = new QLabel(page_2);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setMaximumSize(QSize(50, 30));

        horizontalLayout_21->addWidget(label_25);

        label_22 = new QLabel(page_2);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setMaximumSize(QSize(30, 30));

        horizontalLayout_21->addWidget(label_22);

        spinBox_cood_x = new QSpinBox(page_2);
        spinBox_cood_x->setObjectName(QString::fromUtf8("spinBox_cood_x"));
        spinBox_cood_x->setMinimumSize(QSize(100, 0));
        spinBox_cood_x->setFocusPolicy(Qt::ClickFocus);
        spinBox_cood_x->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 47, 48);"));
        spinBox_cood_x->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        spinBox_cood_x->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);
        spinBox_cood_x->setKeyboardTracking(false);
        spinBox_cood_x->setMaximum(2000);
        spinBox_cood_x->setValue(0);

        horizontalLayout_21->addWidget(spinBox_cood_x);

        label_23 = new QLabel(page_2);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setMaximumSize(QSize(30, 35));

        horizontalLayout_21->addWidget(label_23);

        spinBox_cood_y = new QSpinBox(page_2);
        spinBox_cood_y->setObjectName(QString::fromUtf8("spinBox_cood_y"));
        spinBox_cood_y->setMinimumSize(QSize(100, 0));
        spinBox_cood_y->setFocusPolicy(Qt::ClickFocus);
        spinBox_cood_y->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        spinBox_cood_y->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);
        spinBox_cood_y->setKeyboardTracking(false);
        spinBox_cood_y->setMaximum(2000);
        spinBox_cood_y->setValue(0);

        horizontalLayout_21->addWidget(spinBox_cood_y);


        gridLayout_7->addLayout(horizontalLayout_21, 0, 0, 1, 1);

        horizontalLayout_43 = new QHBoxLayout();
        horizontalLayout_43->setSpacing(6);
        horizontalLayout_43->setObjectName(QString::fromUtf8("horizontalLayout_43"));
        label_29 = new QLabel(page_2);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        sizePolicy3.setHeightForWidth(label_29->sizePolicy().hasHeightForWidth());
        label_29->setSizePolicy(sizePolicy3);

        horizontalLayout_43->addWidget(label_29);

        spinBox_font = new QSpinBox(page_2);
        spinBox_font->setObjectName(QString::fromUtf8("spinBox_font"));
        spinBox_font->setMinimumSize(QSize(100, 0));
        spinBox_font->setFocusPolicy(Qt::ClickFocus);
        spinBox_font->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        spinBox_font->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);
        spinBox_font->setKeyboardTracking(false);
        spinBox_font->setValue(16);

        horizontalLayout_43->addWidget(spinBox_font);


        gridLayout_7->addLayout(horizontalLayout_43, 6, 0, 1, 1);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setSpacing(6);
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        comboBox_texts = new QComboBox(page_2);
        comboBox_texts->setObjectName(QString::fromUtf8("comboBox_texts"));

        horizontalLayout_22->addWidget(comboBox_texts);

        PB_lond_font = new QPushButton(page_2);
        PB_lond_font->setObjectName(QString::fromUtf8("PB_lond_font"));

        horizontalLayout_22->addWidget(PB_lond_font);


        gridLayout_7->addLayout(horizontalLayout_22, 3, 0, 1, 1);

        horizontalLayout_33 = new QHBoxLayout();
        horizontalLayout_33->setSpacing(6);
        horizontalLayout_33->setObjectName(QString::fromUtf8("horizontalLayout_33"));
        label_21 = new QLabel(page_2);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        sizePolicy3.setHeightForWidth(label_21->sizePolicy().hasHeightForWidth());
        label_21->setSizePolicy(sizePolicy3);

        horizontalLayout_33->addWidget(label_21);

        CB_language = new QComboBox(page_2);
        CB_language->addItem(QString());
        CB_language->addItem(QString());
        CB_language->addItem(QString());
        CB_language->addItem(QString());
        CB_language->addItem(QString());
        CB_language->addItem(QString());
        CB_language->addItem(QString());
        CB_language->addItem(QString());
        CB_language->addItem(QString());
        CB_language->addItem(QString());
        CB_language->addItem(QString());
        CB_language->addItem(QString());
        CB_language->addItem(QString());
        CB_language->addItem(QString());
        CB_language->addItem(QString());
        CB_language->addItem(QString());
        CB_language->addItem(QString());
        CB_language->addItem(QString());
        CB_language->addItem(QString());
        CB_language->addItem(QString());
        CB_language->addItem(QString());
        CB_language->addItem(QString());
        CB_language->addItem(QString());
        CB_language->addItem(QString());
        CB_language->addItem(QString());
        CB_language->addItem(QString());
        CB_language->addItem(QString());
        CB_language->setObjectName(QString::fromUtf8("CB_language"));

        horizontalLayout_33->addWidget(CB_language);


        gridLayout_7->addLayout(horizontalLayout_33, 4, 0, 1, 1);

        horizontalLayout_27 = new QHBoxLayout();
        horizontalLayout_27->setSpacing(6);
        horizontalLayout_27->setObjectName(QString::fromUtf8("horizontalLayout_27"));
        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setSpacing(6);
        horizontalLayout_25->setObjectName(QString::fromUtf8("horizontalLayout_25"));
        label_30 = new QLabel(page_2);
        label_30->setObjectName(QString::fromUtf8("label_30"));

        horizontalLayout_25->addWidget(label_30);


        horizontalLayout_27->addLayout(horizontalLayout_25);

        horizontalLayout_26 = new QHBoxLayout();
        horizontalLayout_26->setSpacing(6);
        horizontalLayout_26->setObjectName(QString::fromUtf8("horizontalLayout_26"));
        lineEdit_2 = new QLineEdit(page_2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout_26->addWidget(lineEdit_2);

        label_13 = new QLabel(page_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_26->addWidget(label_13);


        horizontalLayout_27->addLayout(horizontalLayout_26);


        gridLayout_7->addLayout(horizontalLayout_27, 8, 0, 1, 1);

        horizontalLayout_32 = new QHBoxLayout();
        horizontalLayout_32->setSpacing(6);
        horizontalLayout_32->setObjectName(QString::fromUtf8("horizontalLayout_32"));
        label_34 = new QLabel(page_2);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        sizePolicy3.setHeightForWidth(label_34->sizePolicy().hasHeightForWidth());
        label_34->setSizePolicy(sizePolicy3);

        horizontalLayout_32->addWidget(label_34);

        spinBox_LineHeight = new QSpinBox(page_2);
        spinBox_LineHeight->setObjectName(QString::fromUtf8("spinBox_LineHeight"));
        spinBox_LineHeight->setMinimumSize(QSize(100, 0));
        spinBox_LineHeight->setFocusPolicy(Qt::ClickFocus);
        spinBox_LineHeight->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        spinBox_LineHeight->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);
        spinBox_LineHeight->setKeyboardTracking(false);
        spinBox_LineHeight->setValue(0);

        horizontalLayout_32->addWidget(spinBox_LineHeight);


        gridLayout_7->addLayout(horizontalLayout_32, 9, 0, 1, 1);

        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setSpacing(6);
        horizontalLayout_23->setObjectName(QString::fromUtf8("horizontalLayout_23"));
        label_28 = new QLabel(page_2);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        sizePolicy3.setHeightForWidth(label_28->sizePolicy().hasHeightForWidth());
        label_28->setSizePolicy(sizePolicy3);
        label_28->setMaximumSize(QSize(50, 30));

        horizontalLayout_23->addWidget(label_28);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setSpacing(6);
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        label_26 = new QLabel(page_2);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setMaximumSize(QSize(60, 30));

        horizontalLayout_20->addWidget(label_26);

        spinBox_width = new QSpinBox(page_2);
        spinBox_width->setObjectName(QString::fromUtf8("spinBox_width"));
        spinBox_width->setMinimumSize(QSize(50, 0));
        spinBox_width->setFocusPolicy(Qt::ClickFocus);
        spinBox_width->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        spinBox_width->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);
        spinBox_width->setKeyboardTracking(false);
        spinBox_width->setMaximum(2000);
        spinBox_width->setValue(0);

        horizontalLayout_20->addWidget(spinBox_width);

        label_27 = new QLabel(page_2);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setMaximumSize(QSize(60, 30));

        horizontalLayout_20->addWidget(label_27);

        spinBox_height = new QSpinBox(page_2);
        spinBox_height->setObjectName(QString::fromUtf8("spinBox_height"));
        spinBox_height->setMinimumSize(QSize(50, 0));
        spinBox_height->setFocusPolicy(Qt::ClickFocus);
        spinBox_height->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        spinBox_height->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);
        spinBox_height->setKeyboardTracking(false);
        spinBox_height->setMaximum(2000);
        spinBox_height->setValue(0);

        horizontalLayout_20->addWidget(spinBox_height);


        horizontalLayout_23->addLayout(horizontalLayout_20);


        gridLayout_7->addLayout(horizontalLayout_23, 1, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_7->addItem(verticalSpacer_2, 10, 0, 1, 1);

        toolBox->addItem(page_2, QString::fromUtf8("\350\256\276\347\275\256"));
        listView_componnets = new QListView(dockWidgetContents_4);
        listView_componnets->setObjectName(QString::fromUtf8("listView_componnets"));
        listView_componnets->setGeometry(QRect(9, 9, 321, 192));
        listView_componnets->setContextMenuPolicy(Qt::NoContextMenu);
        listView_componnets->setFrameShape(QFrame::Box);
        listView_componnets->setFrameShadow(QFrame::Plain);
        listView_componnets->setDragEnabled(true);
        listView_componnets->setDefaultDropAction(Qt::ActionMask);
        dockWidget_3->setWidget(dockWidgetContents_4);
        MainWindow->addDockWidget(Qt::RightDockWidgetArea, dockWidget_3);
        dockWidget = new QDockWidget(MainWindow);
        dockWidget->setObjectName(QString::fromUtf8("dockWidget"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(dockWidget->sizePolicy().hasHeightForWidth());
        dockWidget->setSizePolicy(sizePolicy5);
        dockWidget->setAutoFillBackground(false);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        gridLayout_9 = new QGridLayout(dockWidgetContents);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        tabWidget = new QTabWidget(dockWidgetContents);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        sizePolicy5.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy5);
        tabWidget->setTabPosition(QTabWidget::West);
        tabWidget->setTabShape(QTabWidget::Triangular);
        tabWidget->setElideMode(Qt::ElideNone);
        tabWidget->setUsesScrollButtons(false);
        tabWidget->setDocumentMode(true);
        tabWidget->setTabBarAutoHide(true);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_3 = new QGridLayout(tab);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        textBrowser = new QTextBrowser(tab);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        sizePolicy5.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy5);

        gridLayout_3->addWidget(textBrowser, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_4 = new QGridLayout(tab_2);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        TB_Positon = new QTextBrowser(tab_2);
        TB_Positon->setObjectName(QString::fromUtf8("TB_Positon"));
        sizePolicy5.setHeightForWidth(TB_Positon->sizePolicy().hasHeightForWidth());
        TB_Positon->setSizePolicy(sizePolicy5);

        gridLayout_4->addWidget(TB_Positon, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        gridLayout_5 = new QGridLayout(tab_3);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        TB_head = new QTextBrowser(tab_3);
        TB_head->setObjectName(QString::fromUtf8("TB_head"));

        gridLayout_5->addWidget(TB_head, 0, 0, 1, 1);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        TB_addr = new QTextBrowser(tab_4);
        TB_addr->setObjectName(QString::fromUtf8("TB_addr"));
        TB_addr->setGeometry(QRect(10, 10, 891, 801));
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        gridLayout_2 = new QGridLayout(tab_5);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        tabWidget->addTab(tab_5, QString());

        gridLayout_9->addWidget(tabWidget, 0, 0, 1, 1);

        dockWidget->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(Qt::LeftDockWidgetArea, dockWidget);

        retranslateUi(MainWindow);
        QObject::connect(listView_page, SIGNAL(clicked(QModelIndex)), MainWindow, SLOT(on_display_page(QModelIndex)));
        QObject::connect(PB_lond_font, SIGNAL(clicked()), MainWindow, SLOT(on_lond_language_file()));
        QObject::connect(CB_language, SIGNAL(activated(int)), MainWindow, SLOT(on_select_language_file(int)));
        QObject::connect(comboBox_texts, SIGNAL(currentIndexChanged(int)), MainWindow, SLOT(on_updata_item_param()));
        QObject::connect(spinBox_cood_x, SIGNAL(valueChanged(int)), MainWindow, SLOT(on_updata_item_param()));
        QObject::connect(spinBox_cood_y, SIGNAL(valueChanged(int)), MainWindow, SLOT(on_updata_item_param()));
        QObject::connect(spinBox_width, SIGNAL(valueChanged(int)), MainWindow, SLOT(on_updata_item_param()));
        QObject::connect(spinBox_height, SIGNAL(valueChanged(int)), MainWindow, SLOT(on_updata_item_param()));
        QObject::connect(treeView_slelect_items, SIGNAL(clicked(QModelIndex)), MainWindow, SLOT(on_selected_item(QModelIndex)));
        QObject::connect(spinBox_font, SIGNAL(valueChanged(int)), MainWindow, SLOT(on_updata_item_param()));
        QObject::connect(spinBox_spacing, SIGNAL(valueChanged(int)), MainWindow, SLOT(on_updata_item_param()));

        toolBox->setCurrentIndex(1);
        toolBox->layout()->setSpacing(0);
        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\347\273\264\344\272\277\351\255\204\344\270\223\345\261\236 \344\275\234\350\200\205:\346\234\261\346\214\257\345\261\225  V2.1 \350\201\224\347\263\273:442446835", nullptr));
        lineEdit->setText(QString());
#if QT_CONFIG(tooltip)
        listView_page->setToolTip(QCoreApplication::translate("MainWindow", "\347\225\214\351\235\242\351\200\211\346\213\251", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        listView_page->setStatusTip(QCoreApplication::translate("MainWindow", "\347\225\214\351\235\242\351\200\211\346\213\251", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(whatsthis)
        listView_page->setWhatsThis(QCoreApplication::translate("MainWindow", "\347\225\214\351\235\242\351\200\211\346\213\251", nullptr));
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(accessibility)
        listView_page->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
        label_47->setText(QCoreApplication::translate("MainWindow", "\345\267\262\351\200\211\346\213\251\346\216\247\344\273\266", nullptr));
        label_display->setText(QString());
        dockWidget_3->setWindowTitle(QCoreApplication::translate("MainWindow", "\345\261\236\346\200\247", nullptr));
        toolBox->setItemText(toolBox->indexOf(page), QCoreApplication::translate("MainWindow", "\346\216\247\344\273\266", nullptr));
        label_31->setText(QCoreApplication::translate("MainWindow", "\345\255\227\344\275\223", nullptr));
        fontComboBox->setCurrentText(QCoreApplication::translate("MainWindow", "OPPOSans M", nullptr));
        label_33->setText(QCoreApplication::translate("MainWindow", "\351\227\264\350\267\235", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "\344\275\215\346\225\260", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "\345\235\220\346\240\207", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "X:", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "Y:", nullptr));
        label_29->setText(QCoreApplication::translate("MainWindow", "\345\255\227\345\217\267", nullptr));
        PB_lond_font->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "\350\257\255\350\250\200", nullptr));
        CB_language->setItemText(0, QCoreApplication::translate("MainWindow", "\344\270\255\346\226\207", nullptr));
        CB_language->setItemText(1, QCoreApplication::translate("MainWindow", "\350\213\261\346\226\207", nullptr));
        CB_language->setItemText(2, QCoreApplication::translate("MainWindow", "\346\227\245\350\257\255", nullptr));
        CB_language->setItemText(3, QCoreApplication::translate("MainWindow", "\351\237\251\350\257\255", nullptr));
        CB_language->setItemText(4, QCoreApplication::translate("MainWindow", "\345\276\267\350\257\255", nullptr));
        CB_language->setItemText(5, QCoreApplication::translate("MainWindow", "\344\277\204\350\257\255", nullptr));
        CB_language->setItemText(6, QCoreApplication::translate("MainWindow", "\350\245\277\347\217\255\347\211\231\350\257\255", nullptr));
        CB_language->setItemText(7, QCoreApplication::translate("MainWindow", "\346\204\217\345\244\247\345\210\251\350\257\255", nullptr));
        CB_language->setItemText(8, QCoreApplication::translate("MainWindow", "\346\263\225\350\257\255", nullptr));
        CB_language->setItemText(9, QCoreApplication::translate("MainWindow", "\350\266\212\345\215\227\350\257\255", nullptr));
        CB_language->setItemText(10, QCoreApplication::translate("MainWindow", "\350\221\241\350\220\204\347\211\231\350\257\255", nullptr));
        CB_language->setItemText(11, QCoreApplication::translate("MainWindow", "\345\267\264\350\245\277", nullptr));
        CB_language->setItemText(12, QCoreApplication::translate("MainWindow", "\347\271\201\344\275\223", nullptr));
        CB_language->setItemText(13, QCoreApplication::translate("MainWindow", "\346\263\242\345\205\260\350\257\255", nullptr));
        CB_language->setItemText(14, QCoreApplication::translate("MainWindow", "\346\215\267\345\205\213\350\257\255", nullptr));
        CB_language->setItemText(15, QCoreApplication::translate("MainWindow", "\344\271\214\345\205\213\345\205\260", nullptr));
        CB_language->setItemText(16, QCoreApplication::translate("MainWindow", "\345\214\210\347\211\231\345\210\251", nullptr));
        CB_language->setItemText(17, QCoreApplication::translate("MainWindow", "\345\234\237\350\200\263\345\205\266", nullptr));
        CB_language->setItemText(18, QCoreApplication::translate("MainWindow", "\345\215\260\345\272\246\345\260\274\350\245\277\344\272\232", nullptr));
        CB_language->setItemText(19, QCoreApplication::translate("MainWindow", "\347\275\227\351\251\254\345\260\274\344\272\232", nullptr));
        CB_language->setItemText(20, QCoreApplication::translate("MainWindow", "\346\226\257\346\264\233\344\274\220\345\205\213", nullptr));
        CB_language->setItemText(21, QCoreApplication::translate("MainWindow", "\345\205\213\347\275\227\345\234\260\344\272\232", nullptr));
        CB_language->setItemText(22, QCoreApplication::translate("MainWindow", "\347\253\213\351\231\266\345\256\233", nullptr));
        CB_language->setItemText(23, QCoreApplication::translate("MainWindow", "\345\270\214\350\205\212", nullptr));
        CB_language->setItemText(24, QCoreApplication::translate("MainWindow", "\351\230\277\346\213\211\344\274\257", nullptr));
        CB_language->setItemText(25, QCoreApplication::translate("MainWindow", "\347\221\236\345\205\270", nullptr));
        CB_language->setItemText(26, QCoreApplication::translate("MainWindow", "\350\215\267\345\205\260", nullptr));

        label_30->setText(QCoreApplication::translate("MainWindow", "\351\242\234\350\211\262", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "HEX", nullptr));
        label_34->setText(QCoreApplication::translate("MainWindow", "\350\241\214\351\253\230", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "\345\260\272\345\257\270", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "\345\256\275\345\272\246:", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "\351\253\230\345\272\246:", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_2), QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "\344\273\243\347\240\201\345\214\272", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "\345\235\220\346\240\207", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "\345\244\264\346\226\207\344\273\266", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainWindow", "\345\234\260\345\235\200", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("MainWindow", "\345\244\232\345\233\275\350\257\255\350\250\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
