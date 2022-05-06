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
#include <QtWidgets/QCheckBox>
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
    QHBoxLayout *horizontalLayout_30;
    QLineEdit *lineEdit;
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
    QListView *listView_page;
    QLabel *label_20;
    QLabel *label_24;
    QListView *listView_Text;
    QListView *listView_text_select;
    QLabel *label_47;
    QTreeView *treeView_slelect_items;
    QLabel *label_display;
    QDockWidget *dockWidget_3;
    QWidget *dockWidgetContents_4;
    QToolBox *toolBox;
    QWidget *page;
    QGridLayout *gridLayout_8;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_8;
    QComboBox *CB_ampm;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label;
    QComboBox *CB_Time;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_2;
    QComboBox *CB_week;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_3;
    QComboBox *CB_week_en;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_4;
    QComboBox *CB_step;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_6;
    QComboBox *CB_heart;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_12;
    QComboBox *CB_calories;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_16;
    QComboBox *CB_distant;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_17;
    QComboBox *CB_sleep;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_18;
    QComboBox *CB_sleep_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_19;
    QComboBox *CB_BP;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QComboBox *CB_data;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_9;
    QComboBox *CB_women;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_15;
    QComboBox *CB_unit;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    QComboBox *CB_blu;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_11;
    QComboBox *CB_charge;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_10;
    QComboBox *CB_one;
    QHBoxLayout *horizontalLayout_19;
    QCheckBox *CB_old;
    QPushButton *pushButton;
    QGridLayout *gridLayout;
    QLineEdit *LE_X;
    QHBoxLayout *horizontalLayout_17;
    QLineEdit *LE_Y;
    QLineEdit *LE_distance;
    QComboBox *CB_postion;
    QComboBox *CB_FunSelect;
    QWidget *page_2;
    QGridLayout *gridLayout_7;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_21;
    QLabel *label_25;
    QLabel *label_22;
    QSpinBox *spinBox_cood_x;
    QLabel *label_23;
    QSpinBox *spinBox_cood_y;
    QHBoxLayout *horizontalLayout_23;
    QLabel *label_28;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label_26;
    QSpinBox *spinBox_width;
    QLabel *label_27;
    QSpinBox *spinBox_height;
    QHBoxLayout *horizontalLayout_24;
    QLabel *label_31;
    QFontComboBox *fontComboBox;
    QHBoxLayout *horizontalLayout_33;
    QLabel *label_21;
    QComboBox *CB_language;
    QHBoxLayout *horizontalLayout_43;
    QLabel *label_29;
    QSpinBox *spinBox_font;
    QHBoxLayout *horizontalLayout_22;
    QComboBox *comboBox_texts;
    QPushButton *PB_lond_font;
    QHBoxLayout *horizontalLayout_31;
    QLabel *label_33;
    QSpinBox *spinBox_spacing;
    QHBoxLayout *horizontalLayout_27;
    QHBoxLayout *horizontalLayout_25;
    QLabel *label_30;
    QHBoxLayout *horizontalLayout_26;
    QLineEdit *lineEdit_2;
    QLabel *label_13;
    QHBoxLayout *horizontalLayout_32;
    QLabel *label_34;
    QSpinBox *spinBox_LineHeight;
    QListView *listView_componnets;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(989, 865);
        MainWindow->setMinimumSize(QSize(56, 50));
        QIcon icon;
        icon.addFile(QString::fromUtf8("C:/Users/Administrator/Desktop/1.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setAutoFillBackground(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_6 = new QGridLayout(centralWidget);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        horizontalLayout_30 = new QHBoxLayout();
        horizontalLayout_30->setSpacing(6);
        horizontalLayout_30->setObjectName(QString::fromUtf8("horizontalLayout_30"));

        gridLayout_6->addLayout(horizontalLayout_30, 0, 0, 2, 2);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);
        lineEdit->setMaximumSize(QSize(240, 20));

        gridLayout_6->addWidget(lineEdit, 2, 3, 1, 1);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        tabWidget->setUsesScrollButtons(false);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_3 = new QGridLayout(tab);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        textBrowser = new QTextBrowser(tab);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        sizePolicy.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy);

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
        sizePolicy.setHeightForWidth(TB_Positon->sizePolicy().hasHeightForWidth());
        TB_Positon->setSizePolicy(sizePolicy);

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
        listView_page = new QListView(tab_5);
        listView_page->setObjectName(QString::fromUtf8("listView_page"));
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221 Light")});
        font.setPointSize(12);
        listView_page->setFont(font);
        listView_page->setIconSize(QSize(200, 200));
        listView_page->setTextElideMode(Qt::ElideNone);
        listView_page->setFlow(QListView::LeftToRight);
        listView_page->setGridSize(QSize(200, 220));
        listView_page->setViewMode(QListView::IconMode);

        gridLayout_2->addWidget(listView_page, 0, 0, 4, 1);

        label_20 = new QLabel(tab_5);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        gridLayout_2->addWidget(label_20, 0, 1, 1, 1);

        label_24 = new QLabel(tab_5);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        gridLayout_2->addWidget(label_24, 0, 3, 1, 1);

        listView_Text = new QListView(tab_5);
        listView_Text->setObjectName(QString::fromUtf8("listView_Text"));

        gridLayout_2->addWidget(listView_Text, 1, 1, 3, 1);

        listView_text_select = new QListView(tab_5);
        listView_text_select->setObjectName(QString::fromUtf8("listView_text_select"));
        listView_text_select->setSelectionMode(QAbstractItemView::ExtendedSelection);

        gridLayout_2->addWidget(listView_text_select, 1, 2, 1, 2);

        label_47 = new QLabel(tab_5);
        label_47->setObjectName(QString::fromUtf8("label_47"));

        gridLayout_2->addWidget(label_47, 2, 2, 1, 1);

        treeView_slelect_items = new QTreeView(tab_5);
        treeView_slelect_items->setObjectName(QString::fromUtf8("treeView_slelect_items"));
        treeView_slelect_items->setTextElideMode(Qt::ElideMiddle);

        gridLayout_2->addWidget(treeView_slelect_items, 3, 2, 1, 2);

        tabWidget->addTab(tab_5, QString());

        gridLayout_6->addWidget(tabWidget, 3, 2, 1, 1);

        label_display = new QLabel(centralWidget);
        label_display->setObjectName(QString::fromUtf8("label_display"));
        label_display->setMinimumSize(QSize(360, 360));
        label_display->setMaximumSize(QSize(454, 454));
        label_display->setAcceptDrops(true);
        label_display->setAutoFillBackground(false);
        label_display->setStyleSheet(QString::fromUtf8(""));
        label_display->setTextFormat(Qt::PlainText);
        label_display->setWordWrap(false);

        gridLayout_6->addWidget(label_display, 3, 3, 1, 1);

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
        toolBox->setFrameShape(QFrame::Box);
        toolBox->setFrameShadow(QFrame::Raised);
        toolBox->setLineWidth(0);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setGeometry(QRect(0, 0, 494, 640));
        gridLayout_8 = new QGridLayout(page);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_8 = new QLabel(page);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_5->addWidget(label_8);

        CB_ampm = new QComboBox(page);
        CB_ampm->setObjectName(QString::fromUtf8("CB_ampm"));
        sizePolicy.setHeightForWidth(CB_ampm->sizePolicy().hasHeightForWidth());
        CB_ampm->setSizePolicy(sizePolicy);
        CB_ampm->setMinimumSize(QSize(220, 20));
        CB_ampm->setMaximumSize(QSize(130, 16777215));
        CB_ampm->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_5->addWidget(CB_ampm);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        label = new QLabel(page);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_15->addWidget(label);

        CB_Time = new QComboBox(page);
        CB_Time->setObjectName(QString::fromUtf8("CB_Time"));
        sizePolicy.setHeightForWidth(CB_Time->sizePolicy().hasHeightForWidth());
        CB_Time->setSizePolicy(sizePolicy);
        CB_Time->setMinimumSize(QSize(220, 20));
        CB_Time->setMaximumSize(QSize(130, 16777215));
        CB_Time->setSizeAdjustPolicy(QComboBox::AdjustToContentsOnFirstShow);

        horizontalLayout_15->addWidget(CB_Time);


        verticalLayout->addLayout(horizontalLayout_15);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        label_2 = new QLabel(page);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_14->addWidget(label_2);

        CB_week = new QComboBox(page);
        CB_week->setObjectName(QString::fromUtf8("CB_week"));
        sizePolicy.setHeightForWidth(CB_week->sizePolicy().hasHeightForWidth());
        CB_week->setSizePolicy(sizePolicy);
        CB_week->setMinimumSize(QSize(220, 20));
        CB_week->setMaximumSize(QSize(130, 16777215));

        horizontalLayout_14->addWidget(CB_week);


        verticalLayout->addLayout(horizontalLayout_14);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_3 = new QLabel(page);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_13->addWidget(label_3);

        CB_week_en = new QComboBox(page);
        CB_week_en->setObjectName(QString::fromUtf8("CB_week_en"));
        sizePolicy.setHeightForWidth(CB_week_en->sizePolicy().hasHeightForWidth());
        CB_week_en->setSizePolicy(sizePolicy);
        CB_week_en->setMinimumSize(QSize(220, 20));
        CB_week_en->setMaximumSize(QSize(130, 16777215));

        horizontalLayout_13->addWidget(CB_week_en);


        verticalLayout->addLayout(horizontalLayout_13);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_4 = new QLabel(page);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_12->addWidget(label_4);

        CB_step = new QComboBox(page);
        CB_step->setObjectName(QString::fromUtf8("CB_step"));
        sizePolicy.setHeightForWidth(CB_step->sizePolicy().hasHeightForWidth());
        CB_step->setSizePolicy(sizePolicy);
        CB_step->setMinimumSize(QSize(220, 20));
        CB_step->setMaximumSize(QSize(130, 16777215));

        horizontalLayout_12->addWidget(CB_step);


        verticalLayout->addLayout(horizontalLayout_12);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_6 = new QLabel(page);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_11->addWidget(label_6);

        CB_heart = new QComboBox(page);
        CB_heart->setObjectName(QString::fromUtf8("CB_heart"));
        sizePolicy.setHeightForWidth(CB_heart->sizePolicy().hasHeightForWidth());
        CB_heart->setSizePolicy(sizePolicy);
        CB_heart->setMinimumSize(QSize(220, 20));
        CB_heart->setMaximumSize(QSize(130, 16777215));

        horizontalLayout_11->addWidget(CB_heart);


        verticalLayout->addLayout(horizontalLayout_11);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_12 = new QLabel(page);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_10->addWidget(label_12);

        CB_calories = new QComboBox(page);
        CB_calories->setObjectName(QString::fromUtf8("CB_calories"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(CB_calories->sizePolicy().hasHeightForWidth());
        CB_calories->setSizePolicy(sizePolicy2);
        CB_calories->setMinimumSize(QSize(220, 20));
        CB_calories->setMaximumSize(QSize(130, 16777215));

        horizontalLayout_10->addWidget(CB_calories);


        verticalLayout->addLayout(horizontalLayout_10);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_16 = new QLabel(page);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_9->addWidget(label_16);

        CB_distant = new QComboBox(page);
        CB_distant->setObjectName(QString::fromUtf8("CB_distant"));
        sizePolicy.setHeightForWidth(CB_distant->sizePolicy().hasHeightForWidth());
        CB_distant->setSizePolicy(sizePolicy);
        CB_distant->setMinimumSize(QSize(220, 20));
        CB_distant->setMaximumSize(QSize(130, 16777215));

        horizontalLayout_9->addWidget(CB_distant);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_17 = new QLabel(page);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_8->addWidget(label_17);

        CB_sleep = new QComboBox(page);
        CB_sleep->setObjectName(QString::fromUtf8("CB_sleep"));
        sizePolicy.setHeightForWidth(CB_sleep->sizePolicy().hasHeightForWidth());
        CB_sleep->setSizePolicy(sizePolicy);
        CB_sleep->setMinimumSize(QSize(220, 20));
        CB_sleep->setMaximumSize(QSize(130, 16777215));

        horizontalLayout_8->addWidget(CB_sleep);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        label_18 = new QLabel(page);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_18->addWidget(label_18);

        CB_sleep_2 = new QComboBox(page);
        CB_sleep_2->setObjectName(QString::fromUtf8("CB_sleep_2"));
        sizePolicy.setHeightForWidth(CB_sleep_2->sizePolicy().hasHeightForWidth());
        CB_sleep_2->setSizePolicy(sizePolicy);
        CB_sleep_2->setMinimumSize(QSize(220, 20));
        CB_sleep_2->setMaximumSize(QSize(130, 16777215));

        horizontalLayout_18->addWidget(CB_sleep_2);


        verticalLayout->addLayout(horizontalLayout_18);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_19 = new QLabel(page);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_7->addWidget(label_19);

        CB_BP = new QComboBox(page);
        CB_BP->setObjectName(QString::fromUtf8("CB_BP"));
        sizePolicy.setHeightForWidth(CB_BP->sizePolicy().hasHeightForWidth());
        CB_BP->setSizePolicy(sizePolicy);
        CB_BP->setMinimumSize(QSize(220, 20));
        CB_BP->setMaximumSize(QSize(130, 16777215));

        horizontalLayout_7->addWidget(CB_BP);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_7 = new QLabel(page);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_6->addWidget(label_7);

        CB_data = new QComboBox(page);
        CB_data->setObjectName(QString::fromUtf8("CB_data"));
        sizePolicy.setHeightForWidth(CB_data->sizePolicy().hasHeightForWidth());
        CB_data->setSizePolicy(sizePolicy);
        CB_data->setMinimumSize(QSize(220, 20));
        CB_data->setMaximumSize(QSize(130, 16777215));

        horizontalLayout_6->addWidget(CB_data);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_9 = new QLabel(page);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_4->addWidget(label_9);

        CB_women = new QComboBox(page);
        CB_women->setObjectName(QString::fromUtf8("CB_women"));
        sizePolicy.setHeightForWidth(CB_women->sizePolicy().hasHeightForWidth());
        CB_women->setSizePolicy(sizePolicy);
        CB_women->setMinimumSize(QSize(220, 20));
        CB_women->setMaximumSize(QSize(130, 16777215));

        horizontalLayout_4->addWidget(CB_women);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_15 = new QLabel(page);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_3->addWidget(label_15);

        CB_unit = new QComboBox(page);
        CB_unit->setObjectName(QString::fromUtf8("CB_unit"));
        sizePolicy.setHeightForWidth(CB_unit->sizePolicy().hasHeightForWidth());
        CB_unit->setSizePolicy(sizePolicy);
        CB_unit->setMinimumSize(QSize(220, 20));
        CB_unit->setMaximumSize(QSize(130, 16777215));

        horizontalLayout_3->addWidget(CB_unit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_5 = new QLabel(page);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMaximumSize(QSize(50, 16777215));

        horizontalLayout->addWidget(label_5);

        CB_blu = new QComboBox(page);
        CB_blu->setObjectName(QString::fromUtf8("CB_blu"));
        sizePolicy.setHeightForWidth(CB_blu->sizePolicy().hasHeightForWidth());
        CB_blu->setSizePolicy(sizePolicy);
        CB_blu->setMinimumSize(QSize(220, 20));
        CB_blu->setMaximumSize(QSize(130, 16777215));

        horizontalLayout->addWidget(CB_blu);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_11 = new QLabel(page);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_2->addWidget(label_11);

        CB_charge = new QComboBox(page);
        CB_charge->setObjectName(QString::fromUtf8("CB_charge"));
        sizePolicy.setHeightForWidth(CB_charge->sizePolicy().hasHeightForWidth());
        CB_charge->setSizePolicy(sizePolicy);
        CB_charge->setMinimumSize(QSize(220, 20));
        CB_charge->setMaximumSize(QSize(130, 16777215));

        horizontalLayout_2->addWidget(CB_charge);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        label_10 = new QLabel(page);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMaximumSize(QSize(50, 16777215));
        label_10->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\256\213\344\275\223\";"));

        horizontalLayout_16->addWidget(label_10);

        CB_one = new QComboBox(page);
        CB_one->setObjectName(QString::fromUtf8("CB_one"));
        sizePolicy.setHeightForWidth(CB_one->sizePolicy().hasHeightForWidth());
        CB_one->setSizePolicy(sizePolicy);
        CB_one->setMinimumSize(QSize(220, 20));
        CB_one->setMaximumSize(QSize(130, 16777215));

        horizontalLayout_16->addWidget(CB_one);


        verticalLayout->addLayout(horizontalLayout_16);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        CB_old = new QCheckBox(page);
        CB_old->setObjectName(QString::fromUtf8("CB_old"));
        sizePolicy.setHeightForWidth(CB_old->sizePolicy().hasHeightForWidth());
        CB_old->setSizePolicy(sizePolicy);
        CB_old->setMaximumSize(QSize(70, 16777215));

        horizontalLayout_19->addWidget(CB_old);

        pushButton = new QPushButton(page);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMinimumSize(QSize(0, 20));
        pushButton->setMaximumSize(QSize(130, 16777215));
        pushButton->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\256\213\344\275\223\";"));

        horizontalLayout_19->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout_19);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        LE_X = new QLineEdit(page);
        LE_X->setObjectName(QString::fromUtf8("LE_X"));
        sizePolicy.setHeightForWidth(LE_X->sizePolicy().hasHeightForWidth());
        LE_X->setSizePolicy(sizePolicy);
        LE_X->setMaximumSize(QSize(30, 20));

        gridLayout->addWidget(LE_X, 1, 0, 1, 1);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        LE_Y = new QLineEdit(page);
        LE_Y->setObjectName(QString::fromUtf8("LE_Y"));
        sizePolicy.setHeightForWidth(LE_Y->sizePolicy().hasHeightForWidth());
        LE_Y->setSizePolicy(sizePolicy);
        LE_Y->setMaximumSize(QSize(30, 20));

        horizontalLayout_17->addWidget(LE_Y);

        LE_distance = new QLineEdit(page);
        LE_distance->setObjectName(QString::fromUtf8("LE_distance"));
        sizePolicy.setHeightForWidth(LE_distance->sizePolicy().hasHeightForWidth());
        LE_distance->setSizePolicy(sizePolicy);
        LE_distance->setMaximumSize(QSize(30, 20));

        horizontalLayout_17->addWidget(LE_distance);

        CB_postion = new QComboBox(page);
        CB_postion->setObjectName(QString::fromUtf8("CB_postion"));
        sizePolicy.setHeightForWidth(CB_postion->sizePolicy().hasHeightForWidth());
        CB_postion->setSizePolicy(sizePolicy);
        CB_postion->setMaximumSize(QSize(130, 20));

        horizontalLayout_17->addWidget(CB_postion);


        gridLayout->addLayout(horizontalLayout_17, 1, 1, 1, 1);

        CB_FunSelect = new QComboBox(page);
        CB_FunSelect->addItem(QString());
        CB_FunSelect->addItem(QString());
        CB_FunSelect->addItem(QString());
        CB_FunSelect->addItem(QString());
        CB_FunSelect->addItem(QString());
        CB_FunSelect->setObjectName(QString::fromUtf8("CB_FunSelect"));
        sizePolicy.setHeightForWidth(CB_FunSelect->sizePolicy().hasHeightForWidth());
        CB_FunSelect->setSizePolicy(sizePolicy);
        CB_FunSelect->setMinimumSize(QSize(0, 20));
        CB_FunSelect->setMaximumSize(QSize(16777215, 20));

        gridLayout->addWidget(CB_FunSelect, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);


        gridLayout_8->addLayout(verticalLayout, 0, 0, 1, 1);

        toolBox->addItem(page, QString::fromUtf8("\346\216\247\344\273\266"));
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        page_2->setGeometry(QRect(0, 0, 454, 535));
        gridLayout_7 = new QGridLayout(page_2);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
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


        verticalLayout_2->addLayout(horizontalLayout_21);

        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setSpacing(6);
        horizontalLayout_23->setObjectName(QString::fromUtf8("horizontalLayout_23"));
        label_28 = new QLabel(page_2);
        label_28->setObjectName(QString::fromUtf8("label_28"));
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


        verticalLayout_2->addLayout(horizontalLayout_23);

        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setSpacing(6);
        horizontalLayout_24->setObjectName(QString::fromUtf8("horizontalLayout_24"));
        label_31 = new QLabel(page_2);
        label_31->setObjectName(QString::fromUtf8("label_31"));

        horizontalLayout_24->addWidget(label_31);

        fontComboBox = new QFontComboBox(page_2);
        fontComboBox->setObjectName(QString::fromUtf8("fontComboBox"));

        horizontalLayout_24->addWidget(fontComboBox);


        verticalLayout_2->addLayout(horizontalLayout_24);

        horizontalLayout_33 = new QHBoxLayout();
        horizontalLayout_33->setSpacing(6);
        horizontalLayout_33->setObjectName(QString::fromUtf8("horizontalLayout_33"));
        label_21 = new QLabel(page_2);
        label_21->setObjectName(QString::fromUtf8("label_21"));

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


        verticalLayout_2->addLayout(horizontalLayout_33);

        horizontalLayout_43 = new QHBoxLayout();
        horizontalLayout_43->setSpacing(6);
        horizontalLayout_43->setObjectName(QString::fromUtf8("horizontalLayout_43"));
        label_29 = new QLabel(page_2);
        label_29->setObjectName(QString::fromUtf8("label_29"));

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


        verticalLayout_2->addLayout(horizontalLayout_43);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setSpacing(6);
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        comboBox_texts = new QComboBox(page_2);
        comboBox_texts->setObjectName(QString::fromUtf8("comboBox_texts"));

        horizontalLayout_22->addWidget(comboBox_texts);

        PB_lond_font = new QPushButton(page_2);
        PB_lond_font->setObjectName(QString::fromUtf8("PB_lond_font"));

        horizontalLayout_22->addWidget(PB_lond_font);


        verticalLayout_2->addLayout(horizontalLayout_22);

        horizontalLayout_31 = new QHBoxLayout();
        horizontalLayout_31->setSpacing(6);
        horizontalLayout_31->setObjectName(QString::fromUtf8("horizontalLayout_31"));
        label_33 = new QLabel(page_2);
        label_33->setObjectName(QString::fromUtf8("label_33"));

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


        verticalLayout_2->addLayout(horizontalLayout_31);

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


        verticalLayout_2->addLayout(horizontalLayout_27);

        horizontalLayout_32 = new QHBoxLayout();
        horizontalLayout_32->setSpacing(6);
        horizontalLayout_32->setObjectName(QString::fromUtf8("horizontalLayout_32"));
        label_34 = new QLabel(page_2);
        label_34->setObjectName(QString::fromUtf8("label_34"));

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


        verticalLayout_2->addLayout(horizontalLayout_32);


        gridLayout_7->addLayout(verticalLayout_2, 0, 0, 1, 1);

        toolBox->addItem(page_2, QString::fromUtf8("\346\226\207\345\255\227"));
        listView_componnets = new QListView(dockWidgetContents_4);
        listView_componnets->setObjectName(QString::fromUtf8("listView_componnets"));
        listView_componnets->setGeometry(QRect(9, 9, 256, 192));
        listView_componnets->setDragEnabled(true);
        listView_componnets->setDefaultDropAction(Qt::ActionMask);
        dockWidget_3->setWidget(dockWidgetContents_4);
        MainWindow->addDockWidget(Qt::RightDockWidgetArea, dockWidget_3);
        QWidget::setTabOrder(LE_distance, CB_Time);
        QWidget::setTabOrder(CB_Time, CB_week);
        QWidget::setTabOrder(CB_week, CB_week_en);
        QWidget::setTabOrder(CB_week_en, CB_step);
        QWidget::setTabOrder(CB_step, CB_blu);
        QWidget::setTabOrder(CB_blu, CB_heart);
        QWidget::setTabOrder(CB_heart, CB_ampm);
        QWidget::setTabOrder(CB_ampm, CB_women);
        QWidget::setTabOrder(CB_women, CB_one);
        QWidget::setTabOrder(CB_one, CB_charge);
        QWidget::setTabOrder(CB_charge, CB_calories);
        QWidget::setTabOrder(CB_calories, CB_unit);
        QWidget::setTabOrder(CB_unit, CB_distant);
        QWidget::setTabOrder(CB_distant, CB_sleep);
        QWidget::setTabOrder(CB_sleep, LE_Y);
        QWidget::setTabOrder(LE_Y, LE_X);
        QWidget::setTabOrder(LE_X, CB_BP);

        retranslateUi(MainWindow);
        QObject::connect(listView_Text, SIGNAL(clicked(QModelIndex)), MainWindow, SLOT(on_display_text(QModelIndex)));
        QObject::connect(listView_page, SIGNAL(clicked(QModelIndex)), MainWindow, SLOT(on_display_page(QModelIndex)));
        QObject::connect(listView_text_select, SIGNAL(clicked(QModelIndex)), MainWindow, SLOT(on_select_text(QModelIndex)));
        QObject::connect(PB_lond_font, SIGNAL(clicked()), MainWindow, SLOT(on_lond_language_file()));
        QObject::connect(CB_language, SIGNAL(currentIndexChanged(int)), MainWindow, SLOT(on_select_language_file(int)));
        QObject::connect(comboBox_texts, SIGNAL(currentTextChanged(QString)), MainWindow, SLOT(on_updata_item_param()));
        QObject::connect(spinBox_cood_x, SIGNAL(valueChanged(int)), MainWindow, SLOT(on_updata_item_param()));
        QObject::connect(spinBox_cood_y, SIGNAL(valueChanged(int)), MainWindow, SLOT(on_updata_item_param()));
        QObject::connect(spinBox_width, SIGNAL(valueChanged(int)), MainWindow, SLOT(on_updata_item_param()));
        QObject::connect(spinBox_height, SIGNAL(valueChanged(int)), MainWindow, SLOT(on_updata_item_param()));
        QObject::connect(treeView_slelect_items, SIGNAL(clicked(QModelIndex)), MainWindow, SLOT(on_selected_item(QModelIndex)));

        tabWidget->setCurrentIndex(4);
        toolBox->setCurrentIndex(1);
        toolBox->layout()->setSpacing(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\347\273\264\344\272\277\351\255\204\344\270\223\345\261\236 \344\275\234\350\200\205:\346\234\261\346\214\257\345\261\225  V2.1 \350\201\224\347\263\273:442446835", nullptr));
        lineEdit->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "\344\273\243\347\240\201\345\214\272", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "\345\235\220\346\240\207", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "\345\244\264\346\226\207\344\273\266", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainWindow", "\345\234\260\345\235\200", nullptr));
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
        label_20->setText(QCoreApplication::translate("MainWindow", "\346\226\207\345\255\227\351\200\211\346\213\251", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "\345\205\267\344\275\223\346\226\207\345\255\227\346\230\276\347\244\272", nullptr));
        label_47->setText(QCoreApplication::translate("MainWindow", "\345\267\262\351\200\211\346\213\251\346\216\247\344\273\266", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("MainWindow", "\345\244\232\345\233\275\350\257\255\350\250\200", nullptr));
        label_display->setText(QString());
        dockWidget_3->setWindowTitle(QCoreApplication::translate("MainWindow", "\345\261\236\346\200\247", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\344\270\212\344\270\213\345\215\210", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\346\227\266\351\227\264", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\346\230\237\346\234\237\344\270\255\346\226\207", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\346\230\237\346\234\237\350\213\261\346\226\207", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\350\256\241\346\255\245", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\345\277\203\347\216\207", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "\345\215\241\350\267\257\351\207\214", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "\351\207\214\347\250\213", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "3\344\275\215\347\235\241\347\234\240", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "4\344\275\215\347\235\241\347\234\240", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "\350\241\200\345\216\213", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\346\227\245\346\234\237", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\345\245\263\346\200\247", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "\345\215\225\344\275\215", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\350\223\235\347\211\231", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "\347\224\265\346\261\240", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\345\215\225\347\213\254", nullptr));
        CB_old->setText(QCoreApplication::translate("MainWindow", "\346\227\247\346\230\276\347\244\272", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\346\225\210\346\236\234\345\233\276", nullptr));
        LE_X->setPlaceholderText(QCoreApplication::translate("MainWindow", "X", nullptr));
        LE_Y->setPlaceholderText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        LE_distance->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        CB_FunSelect->setItemText(0, QCoreApplication::translate("MainWindow", "setXY()", nullptr));
        CB_FunSelect->setItemText(1, QCoreApplication::translate("MainWindow", "setPosionType2(index,)", nullptr));
        CB_FunSelect->setItemText(2, QCoreApplication::translate("MainWindow", "setPosion()", nullptr));
        CB_FunSelect->setItemText(3, QCoreApplication::translate("MainWindow", "Gui_PageClearBackground(\357\274\211", nullptr));
        CB_FunSelect->setItemText(4, QCoreApplication::translate("MainWindow", "Gui_PageClearBackgroundType2(index,\357\274\211", nullptr));

        toolBox->setItemText(toolBox->indexOf(page), QCoreApplication::translate("MainWindow", "\346\216\247\344\273\266", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "\345\235\220\346\240\207", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "X:", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "Y:", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "\345\260\272\345\257\270", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "\345\256\275\345\272\246:", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "\351\253\230\345\272\246:", nullptr));
        label_31->setText(QCoreApplication::translate("MainWindow", "\345\255\227\344\275\223", nullptr));
        fontComboBox->setCurrentText(QCoreApplication::translate("MainWindow", "OPPOSans M", nullptr));
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

        label_29->setText(QCoreApplication::translate("MainWindow", "\345\255\227\345\217\267", nullptr));
        PB_lond_font->setText(QCoreApplication::translate("MainWindow", "\345\212\240\350\275\275\345\255\227\345\272\223", nullptr));
        label_33->setText(QCoreApplication::translate("MainWindow", "\345\255\227\351\227\264\350\267\235", nullptr));
        label_30->setText(QCoreApplication::translate("MainWindow", "\351\242\234\350\211\262", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "HEX", nullptr));
        label_34->setText(QCoreApplication::translate("MainWindow", "\350\241\214\351\253\230", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_2), QCoreApplication::translate("MainWindow", "\346\226\207\345\255\227", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
