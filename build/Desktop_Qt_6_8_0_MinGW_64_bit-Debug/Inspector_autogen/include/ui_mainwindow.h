/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpenFile;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QTabWidget *tabWidget;
    QWidget *summaryTab;
    QGridLayout *gridLayout_3;
    QListView *listView;
    QWidget *tab_2;
    QGridLayout *gridLayout_2;
    QTableWidget *tableWidget;
    QWidget *ntHeadersTab;
    QGridLayout *gridLayout_4;
    QTableWidget *ntHeadersTableWidget;
    QWidget *fileHeaderTab;
    QGridLayout *gridLayout_5;
    QTableWidget *fileHeaderTableWidget;
    QWidget *optionalHeaderTab;
    QGridLayout *gridLayout_6;
    QTableWidget *optionalHeaderTableWidget;
    QWidget *dataDirectoriesTab;
    QGridLayout *gridLayout_7;
    QTableWidget *dataDirectoriesTableWidget;
    QWidget *sectionHeaderTab;
    QGridLayout *gridLayout_8;
    QListWidget *sectionHeaderListWidget;
    QWidget *dllImportTab;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(626, 585);
        QFont font;
        font.setFamilies({QString::fromUtf8("Courier New")});
        MainWindow->setFont(font);
        actionOpenFile = new QAction(MainWindow);
        actionOpenFile->setObjectName("actionOpenFile");
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::DocumentOpen));
        actionOpenFile->setIcon(icon);
        actionOpenFile->setMenuRole(QAction::MenuRole::NoRole);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setMinimumSize(QSize(90, 90));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(0, 50));
        QPalette palette;
        QBrush brush(QColor(0, 141, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        pushButton->setPalette(palette);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Consolas")});
        font1.setPointSize(18);
        font1.setBold(true);
        pushButton->setFont(font1);

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Consolas")});
        tabWidget->setFont(font2);
        tabWidget->setTabBarAutoHide(false);
        summaryTab = new QWidget();
        summaryTab->setObjectName("summaryTab");
        gridLayout_3 = new QGridLayout(summaryTab);
        gridLayout_3->setObjectName("gridLayout_3");
        listView = new QListView(summaryTab);
        listView->setObjectName("listView");
        listView->setFont(font);

        gridLayout_3->addWidget(listView, 0, 0, 1, 1);

        tabWidget->addTab(summaryTab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        gridLayout_2 = new QGridLayout(tab_2);
        gridLayout_2->setObjectName("gridLayout_2");
        tableWidget = new QTableWidget(tab_2);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        if (tableWidget->rowCount() < 17)
            tableWidget->setRowCount(17);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(6, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(7, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(8, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(9, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(10, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(11, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(12, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(13, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(14, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(15, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(16, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget->setItem(0, 3, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget->setItem(1, 3, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget->setItem(2, 3, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget->setItem(3, 3, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget->setItem(4, 3, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget->setItem(5, 3, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget->setItem(6, 3, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget->setItem(7, 3, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidget->setItem(8, 3, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableWidget->setItem(9, 3, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        tableWidget->setItem(10, 3, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        tableWidget->setItem(11, 3, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        tableWidget->setItem(12, 3, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        tableWidget->setItem(13, 3, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        tableWidget->setItem(14, 3, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        tableWidget->setItem(15, 3, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        tableWidget->setItem(16, 3, __qtablewidgetitem37);
        tableWidget->setObjectName("tableWidget");

        gridLayout_2->addWidget(tableWidget, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());
        ntHeadersTab = new QWidget();
        ntHeadersTab->setObjectName("ntHeadersTab");
        gridLayout_4 = new QGridLayout(ntHeadersTab);
        gridLayout_4->setObjectName("gridLayout_4");
        ntHeadersTableWidget = new QTableWidget(ntHeadersTab);
        if (ntHeadersTableWidget->columnCount() < 4)
            ntHeadersTableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        ntHeadersTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        ntHeadersTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        ntHeadersTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        ntHeadersTableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem41);
        if (ntHeadersTableWidget->rowCount() < 1)
            ntHeadersTableWidget->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        ntHeadersTableWidget->setVerticalHeaderItem(0, __qtablewidgetitem42);
        ntHeadersTableWidget->setObjectName("ntHeadersTableWidget");

        gridLayout_4->addWidget(ntHeadersTableWidget, 0, 0, 1, 1);

        tabWidget->addTab(ntHeadersTab, QString());
        fileHeaderTab = new QWidget();
        fileHeaderTab->setObjectName("fileHeaderTab");
        gridLayout_5 = new QGridLayout(fileHeaderTab);
        gridLayout_5->setObjectName("gridLayout_5");
        fileHeaderTableWidget = new QTableWidget(fileHeaderTab);
        if (fileHeaderTableWidget->columnCount() < 4)
            fileHeaderTableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        fileHeaderTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem43);
        QTableWidgetItem *__qtablewidgetitem44 = new QTableWidgetItem();
        fileHeaderTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem44);
        QTableWidgetItem *__qtablewidgetitem45 = new QTableWidgetItem();
        fileHeaderTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem45);
        QTableWidgetItem *__qtablewidgetitem46 = new QTableWidgetItem();
        fileHeaderTableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem46);
        if (fileHeaderTableWidget->rowCount() < 6)
            fileHeaderTableWidget->setRowCount(6);
        QTableWidgetItem *__qtablewidgetitem47 = new QTableWidgetItem();
        fileHeaderTableWidget->setVerticalHeaderItem(0, __qtablewidgetitem47);
        QTableWidgetItem *__qtablewidgetitem48 = new QTableWidgetItem();
        fileHeaderTableWidget->setVerticalHeaderItem(1, __qtablewidgetitem48);
        QTableWidgetItem *__qtablewidgetitem49 = new QTableWidgetItem();
        fileHeaderTableWidget->setVerticalHeaderItem(2, __qtablewidgetitem49);
        QTableWidgetItem *__qtablewidgetitem50 = new QTableWidgetItem();
        fileHeaderTableWidget->setVerticalHeaderItem(3, __qtablewidgetitem50);
        QTableWidgetItem *__qtablewidgetitem51 = new QTableWidgetItem();
        fileHeaderTableWidget->setVerticalHeaderItem(4, __qtablewidgetitem51);
        QTableWidgetItem *__qtablewidgetitem52 = new QTableWidgetItem();
        fileHeaderTableWidget->setVerticalHeaderItem(5, __qtablewidgetitem52);
        fileHeaderTableWidget->setObjectName("fileHeaderTableWidget");

        gridLayout_5->addWidget(fileHeaderTableWidget, 0, 0, 1, 1);

        tabWidget->addTab(fileHeaderTab, QString());
        optionalHeaderTab = new QWidget();
        optionalHeaderTab->setObjectName("optionalHeaderTab");
        gridLayout_6 = new QGridLayout(optionalHeaderTab);
        gridLayout_6->setObjectName("gridLayout_6");
        optionalHeaderTableWidget = new QTableWidget(optionalHeaderTab);
        if (optionalHeaderTableWidget->columnCount() < 4)
            optionalHeaderTableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem53 = new QTableWidgetItem();
        optionalHeaderTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem53);
        QTableWidgetItem *__qtablewidgetitem54 = new QTableWidgetItem();
        optionalHeaderTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem54);
        QTableWidgetItem *__qtablewidgetitem55 = new QTableWidgetItem();
        optionalHeaderTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem55);
        QTableWidgetItem *__qtablewidgetitem56 = new QTableWidgetItem();
        optionalHeaderTableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem56);
        if (optionalHeaderTableWidget->rowCount() < 30)
            optionalHeaderTableWidget->setRowCount(30);
        QTableWidgetItem *__qtablewidgetitem57 = new QTableWidgetItem();
        optionalHeaderTableWidget->setVerticalHeaderItem(0, __qtablewidgetitem57);
        QTableWidgetItem *__qtablewidgetitem58 = new QTableWidgetItem();
        optionalHeaderTableWidget->setVerticalHeaderItem(1, __qtablewidgetitem58);
        QTableWidgetItem *__qtablewidgetitem59 = new QTableWidgetItem();
        optionalHeaderTableWidget->setVerticalHeaderItem(2, __qtablewidgetitem59);
        QTableWidgetItem *__qtablewidgetitem60 = new QTableWidgetItem();
        optionalHeaderTableWidget->setVerticalHeaderItem(3, __qtablewidgetitem60);
        QTableWidgetItem *__qtablewidgetitem61 = new QTableWidgetItem();
        optionalHeaderTableWidget->setVerticalHeaderItem(4, __qtablewidgetitem61);
        QTableWidgetItem *__qtablewidgetitem62 = new QTableWidgetItem();
        optionalHeaderTableWidget->setVerticalHeaderItem(5, __qtablewidgetitem62);
        QTableWidgetItem *__qtablewidgetitem63 = new QTableWidgetItem();
        optionalHeaderTableWidget->setVerticalHeaderItem(6, __qtablewidgetitem63);
        QTableWidgetItem *__qtablewidgetitem64 = new QTableWidgetItem();
        optionalHeaderTableWidget->setVerticalHeaderItem(7, __qtablewidgetitem64);
        QTableWidgetItem *__qtablewidgetitem65 = new QTableWidgetItem();
        optionalHeaderTableWidget->setVerticalHeaderItem(8, __qtablewidgetitem65);
        QTableWidgetItem *__qtablewidgetitem66 = new QTableWidgetItem();
        optionalHeaderTableWidget->setVerticalHeaderItem(9, __qtablewidgetitem66);
        QTableWidgetItem *__qtablewidgetitem67 = new QTableWidgetItem();
        optionalHeaderTableWidget->setVerticalHeaderItem(10, __qtablewidgetitem67);
        QTableWidgetItem *__qtablewidgetitem68 = new QTableWidgetItem();
        optionalHeaderTableWidget->setVerticalHeaderItem(11, __qtablewidgetitem68);
        QTableWidgetItem *__qtablewidgetitem69 = new QTableWidgetItem();
        optionalHeaderTableWidget->setVerticalHeaderItem(12, __qtablewidgetitem69);
        QTableWidgetItem *__qtablewidgetitem70 = new QTableWidgetItem();
        optionalHeaderTableWidget->setVerticalHeaderItem(13, __qtablewidgetitem70);
        QTableWidgetItem *__qtablewidgetitem71 = new QTableWidgetItem();
        optionalHeaderTableWidget->setVerticalHeaderItem(14, __qtablewidgetitem71);
        QTableWidgetItem *__qtablewidgetitem72 = new QTableWidgetItem();
        optionalHeaderTableWidget->setVerticalHeaderItem(15, __qtablewidgetitem72);
        QTableWidgetItem *__qtablewidgetitem73 = new QTableWidgetItem();
        optionalHeaderTableWidget->setVerticalHeaderItem(16, __qtablewidgetitem73);
        QTableWidgetItem *__qtablewidgetitem74 = new QTableWidgetItem();
        optionalHeaderTableWidget->setVerticalHeaderItem(17, __qtablewidgetitem74);
        QTableWidgetItem *__qtablewidgetitem75 = new QTableWidgetItem();
        optionalHeaderTableWidget->setVerticalHeaderItem(18, __qtablewidgetitem75);
        QTableWidgetItem *__qtablewidgetitem76 = new QTableWidgetItem();
        optionalHeaderTableWidget->setVerticalHeaderItem(19, __qtablewidgetitem76);
        QTableWidgetItem *__qtablewidgetitem77 = new QTableWidgetItem();
        optionalHeaderTableWidget->setVerticalHeaderItem(20, __qtablewidgetitem77);
        QTableWidgetItem *__qtablewidgetitem78 = new QTableWidgetItem();
        optionalHeaderTableWidget->setVerticalHeaderItem(21, __qtablewidgetitem78);
        QTableWidgetItem *__qtablewidgetitem79 = new QTableWidgetItem();
        optionalHeaderTableWidget->setVerticalHeaderItem(22, __qtablewidgetitem79);
        QTableWidgetItem *__qtablewidgetitem80 = new QTableWidgetItem();
        optionalHeaderTableWidget->setVerticalHeaderItem(23, __qtablewidgetitem80);
        QTableWidgetItem *__qtablewidgetitem81 = new QTableWidgetItem();
        optionalHeaderTableWidget->setVerticalHeaderItem(24, __qtablewidgetitem81);
        QTableWidgetItem *__qtablewidgetitem82 = new QTableWidgetItem();
        optionalHeaderTableWidget->setVerticalHeaderItem(25, __qtablewidgetitem82);
        QTableWidgetItem *__qtablewidgetitem83 = new QTableWidgetItem();
        optionalHeaderTableWidget->setVerticalHeaderItem(26, __qtablewidgetitem83);
        QTableWidgetItem *__qtablewidgetitem84 = new QTableWidgetItem();
        optionalHeaderTableWidget->setVerticalHeaderItem(27, __qtablewidgetitem84);
        QTableWidgetItem *__qtablewidgetitem85 = new QTableWidgetItem();
        optionalHeaderTableWidget->setVerticalHeaderItem(28, __qtablewidgetitem85);
        QTableWidgetItem *__qtablewidgetitem86 = new QTableWidgetItem();
        optionalHeaderTableWidget->setVerticalHeaderItem(29, __qtablewidgetitem86);
        optionalHeaderTableWidget->setObjectName("optionalHeaderTableWidget");

        gridLayout_6->addWidget(optionalHeaderTableWidget, 0, 0, 1, 1);

        tabWidget->addTab(optionalHeaderTab, QString());
        dataDirectoriesTab = new QWidget();
        dataDirectoriesTab->setObjectName("dataDirectoriesTab");
        gridLayout_7 = new QGridLayout(dataDirectoriesTab);
        gridLayout_7->setObjectName("gridLayout_7");
        dataDirectoriesTableWidget = new QTableWidget(dataDirectoriesTab);
        if (dataDirectoriesTableWidget->columnCount() < 4)
            dataDirectoriesTableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem87 = new QTableWidgetItem();
        dataDirectoriesTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem87);
        QTableWidgetItem *__qtablewidgetitem88 = new QTableWidgetItem();
        dataDirectoriesTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem88);
        QTableWidgetItem *__qtablewidgetitem89 = new QTableWidgetItem();
        dataDirectoriesTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem89);
        QTableWidgetItem *__qtablewidgetitem90 = new QTableWidgetItem();
        dataDirectoriesTableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem90);
        if (dataDirectoriesTableWidget->rowCount() < 2)
            dataDirectoriesTableWidget->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem91 = new QTableWidgetItem();
        dataDirectoriesTableWidget->setVerticalHeaderItem(0, __qtablewidgetitem91);
        QTableWidgetItem *__qtablewidgetitem92 = new QTableWidgetItem();
        dataDirectoriesTableWidget->setVerticalHeaderItem(1, __qtablewidgetitem92);
        dataDirectoriesTableWidget->setObjectName("dataDirectoriesTableWidget");

        gridLayout_7->addWidget(dataDirectoriesTableWidget, 0, 0, 1, 1);

        tabWidget->addTab(dataDirectoriesTab, QString());
        sectionHeaderTab = new QWidget();
        sectionHeaderTab->setObjectName("sectionHeaderTab");
        gridLayout_8 = new QGridLayout(sectionHeaderTab);
        gridLayout_8->setObjectName("gridLayout_8");
        sectionHeaderListWidget = new QListWidget(sectionHeaderTab);
        sectionHeaderListWidget->setObjectName("sectionHeaderListWidget");

        gridLayout_8->addWidget(sectionHeaderListWidget, 0, 0, 1, 1);

        tabWidget->addTab(sectionHeaderTab, QString());
        dllImportTab = new QWidget();
        dllImportTab->setObjectName("dllImportTab");
        tabWidget->addTab(dllImportTab, QString());

        gridLayout->addWidget(tabWidget, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);

        toolBar->addAction(actionOpenFile);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(6);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpenFile->setText(QCoreApplication::translate("MainWindow", "Open file", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Analyze", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(summaryTab), QCoreApplication::translate("MainWindow", "Summary", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Value", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Offset", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Size", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Description", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "e_magic", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "e_cblp", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "e_cp", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "e_crlc", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "e_cparhdr", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->verticalHeaderItem(5);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "e_minalloc", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->verticalHeaderItem(6);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "e_maxalloc", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->verticalHeaderItem(7);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "e_ss", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->verticalHeaderItem(8);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "e_sp", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->verticalHeaderItem(9);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWindow", "e_csum", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->verticalHeaderItem(10);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("MainWindow", "e_ip", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->verticalHeaderItem(11);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("MainWindow", "e_cs", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->verticalHeaderItem(12);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("MainWindow", "e_lfarlc", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget->verticalHeaderItem(13);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("MainWindow", "e_ovno", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget->verticalHeaderItem(14);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("MainWindow", "e_oemid", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget->verticalHeaderItem(15);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("MainWindow", "e_oeminfo", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget->verticalHeaderItem(16);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("MainWindow", "e_lfanew", nullptr));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget->item(0, 3);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("MainWindow", "Magic number", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget->item(1, 3);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("MainWindow", "Bytes on last page of file", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget->item(2, 3);
        ___qtablewidgetitem23->setText(QCoreApplication::translate("MainWindow", "Pages in file", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget->item(3, 3);
        ___qtablewidgetitem24->setText(QCoreApplication::translate("MainWindow", "Relocations", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget->item(4, 3);
        ___qtablewidgetitem25->setText(QCoreApplication::translate("MainWindow", "Size of header in paragraphs", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget->item(5, 3);
        ___qtablewidgetitem26->setText(QCoreApplication::translate("MainWindow", "Minimum extra paragraphs needed", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget->item(6, 3);
        ___qtablewidgetitem27->setText(QCoreApplication::translate("MainWindow", "Maximum extra paragraphs needed", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget->item(7, 3);
        ___qtablewidgetitem28->setText(QCoreApplication::translate("MainWindow", "Initial (relative) SS value", nullptr));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidget->item(8, 3);
        ___qtablewidgetitem29->setText(QCoreApplication::translate("MainWindow", "Initial SP value", nullptr));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidget->item(9, 3);
        ___qtablewidgetitem30->setText(QCoreApplication::translate("MainWindow", "Checksum", nullptr));
        QTableWidgetItem *___qtablewidgetitem31 = tableWidget->item(10, 3);
        ___qtablewidgetitem31->setText(QCoreApplication::translate("MainWindow", "Initial IP value", nullptr));
        QTableWidgetItem *___qtablewidgetitem32 = tableWidget->item(11, 3);
        ___qtablewidgetitem32->setText(QCoreApplication::translate("MainWindow", "Intial (relative) CS value", nullptr));
        QTableWidgetItem *___qtablewidgetitem33 = tableWidget->item(12, 3);
        ___qtablewidgetitem33->setText(QCoreApplication::translate("MainWindow", "File address of relocation table", nullptr));
        QTableWidgetItem *___qtablewidgetitem34 = tableWidget->item(13, 3);
        ___qtablewidgetitem34->setText(QCoreApplication::translate("MainWindow", "Overlay number", nullptr));
        QTableWidgetItem *___qtablewidgetitem35 = tableWidget->item(14, 3);
        ___qtablewidgetitem35->setText(QCoreApplication::translate("MainWindow", "OEM identifier", nullptr));
        QTableWidgetItem *___qtablewidgetitem36 = tableWidget->item(15, 3);
        ___qtablewidgetitem36->setText(QCoreApplication::translate("MainWindow", "OEM information", nullptr));
        QTableWidgetItem *___qtablewidgetitem37 = tableWidget->item(16, 3);
        ___qtablewidgetitem37->setText(QCoreApplication::translate("MainWindow", "File address of new exe header", nullptr));
        tableWidget->setSortingEnabled(__sortingEnabled);

        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "DOS Header", nullptr));
        QTableWidgetItem *___qtablewidgetitem38 = ntHeadersTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem38->setText(QCoreApplication::translate("MainWindow", "Value", nullptr));
        QTableWidgetItem *___qtablewidgetitem39 = ntHeadersTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem39->setText(QCoreApplication::translate("MainWindow", "Offset", nullptr));
        QTableWidgetItem *___qtablewidgetitem40 = ntHeadersTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem40->setText(QCoreApplication::translate("MainWindow", "Size", nullptr));
        QTableWidgetItem *___qtablewidgetitem41 = ntHeadersTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem41->setText(QCoreApplication::translate("MainWindow", "Description", nullptr));
        QTableWidgetItem *___qtablewidgetitem42 = ntHeadersTableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem42->setText(QCoreApplication::translate("MainWindow", "Signature", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(ntHeadersTab), QCoreApplication::translate("MainWindow", "NT Headers", nullptr));
        QTableWidgetItem *___qtablewidgetitem43 = fileHeaderTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem43->setText(QCoreApplication::translate("MainWindow", "Value", nullptr));
        QTableWidgetItem *___qtablewidgetitem44 = fileHeaderTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem44->setText(QCoreApplication::translate("MainWindow", "Offset", nullptr));
        QTableWidgetItem *___qtablewidgetitem45 = fileHeaderTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem45->setText(QCoreApplication::translate("MainWindow", "Size", nullptr));
        QTableWidgetItem *___qtablewidgetitem46 = fileHeaderTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem46->setText(QCoreApplication::translate("MainWindow", "Description", nullptr));
        QTableWidgetItem *___qtablewidgetitem47 = fileHeaderTableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem47->setText(QCoreApplication::translate("MainWindow", "Machine", nullptr));
        QTableWidgetItem *___qtablewidgetitem48 = fileHeaderTableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem48->setText(QCoreApplication::translate("MainWindow", "TimeDateStamp", nullptr));
        QTableWidgetItem *___qtablewidgetitem49 = fileHeaderTableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem49->setText(QCoreApplication::translate("MainWindow", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem50 = fileHeaderTableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem50->setText(QCoreApplication::translate("MainWindow", "PointerToSymbolTable", nullptr));
        QTableWidgetItem *___qtablewidgetitem51 = fileHeaderTableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem51->setText(QCoreApplication::translate("MainWindow", "NumberOfSymbols", nullptr));
        QTableWidgetItem *___qtablewidgetitem52 = fileHeaderTableWidget->verticalHeaderItem(5);
        ___qtablewidgetitem52->setText(QCoreApplication::translate("MainWindow", "Characteristics", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(fileHeaderTab), QCoreApplication::translate("MainWindow", "File Header", nullptr));
        QTableWidgetItem *___qtablewidgetitem53 = optionalHeaderTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem53->setText(QCoreApplication::translate("MainWindow", "Value", nullptr));
        QTableWidgetItem *___qtablewidgetitem54 = optionalHeaderTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem54->setText(QCoreApplication::translate("MainWindow", "Offset", nullptr));
        QTableWidgetItem *___qtablewidgetitem55 = optionalHeaderTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem55->setText(QCoreApplication::translate("MainWindow", "Size", nullptr));
        QTableWidgetItem *___qtablewidgetitem56 = optionalHeaderTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem56->setText(QCoreApplication::translate("MainWindow", "Description", nullptr));
        QTableWidgetItem *___qtablewidgetitem57 = optionalHeaderTableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem57->setText(QCoreApplication::translate("MainWindow", "Magic", nullptr));
        QTableWidgetItem *___qtablewidgetitem58 = optionalHeaderTableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem58->setText(QCoreApplication::translate("MainWindow", "MajorLinkerVersion", nullptr));
        QTableWidgetItem *___qtablewidgetitem59 = optionalHeaderTableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem59->setText(QCoreApplication::translate("MainWindow", "MinorLinkerVersion", nullptr));
        QTableWidgetItem *___qtablewidgetitem60 = optionalHeaderTableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem60->setText(QCoreApplication::translate("MainWindow", "SizeOfCode", nullptr));
        QTableWidgetItem *___qtablewidgetitem61 = optionalHeaderTableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem61->setText(QCoreApplication::translate("MainWindow", "SizeOfInitializedData", nullptr));
        QTableWidgetItem *___qtablewidgetitem62 = optionalHeaderTableWidget->verticalHeaderItem(5);
        ___qtablewidgetitem62->setText(QCoreApplication::translate("MainWindow", "SizeOfUninitializedData", nullptr));
        QTableWidgetItem *___qtablewidgetitem63 = optionalHeaderTableWidget->verticalHeaderItem(6);
        ___qtablewidgetitem63->setText(QCoreApplication::translate("MainWindow", "AddressOfEntryPoint", nullptr));
        QTableWidgetItem *___qtablewidgetitem64 = optionalHeaderTableWidget->verticalHeaderItem(7);
        ___qtablewidgetitem64->setText(QCoreApplication::translate("MainWindow", "BaseOfCode", nullptr));
        QTableWidgetItem *___qtablewidgetitem65 = optionalHeaderTableWidget->verticalHeaderItem(8);
        ___qtablewidgetitem65->setText(QCoreApplication::translate("MainWindow", "BaseOfData", nullptr));
        QTableWidgetItem *___qtablewidgetitem66 = optionalHeaderTableWidget->verticalHeaderItem(9);
        ___qtablewidgetitem66->setText(QCoreApplication::translate("MainWindow", "ImageBase", nullptr));
        QTableWidgetItem *___qtablewidgetitem67 = optionalHeaderTableWidget->verticalHeaderItem(10);
        ___qtablewidgetitem67->setText(QCoreApplication::translate("MainWindow", "SectionAlignment", nullptr));
        QTableWidgetItem *___qtablewidgetitem68 = optionalHeaderTableWidget->verticalHeaderItem(11);
        ___qtablewidgetitem68->setText(QCoreApplication::translate("MainWindow", "FileAlignment", nullptr));
        QTableWidgetItem *___qtablewidgetitem69 = optionalHeaderTableWidget->verticalHeaderItem(12);
        ___qtablewidgetitem69->setText(QCoreApplication::translate("MainWindow", "MajorOperatingSystemVersion", nullptr));
        QTableWidgetItem *___qtablewidgetitem70 = optionalHeaderTableWidget->verticalHeaderItem(13);
        ___qtablewidgetitem70->setText(QCoreApplication::translate("MainWindow", "MinorOperatingSystemVersion", nullptr));
        QTableWidgetItem *___qtablewidgetitem71 = optionalHeaderTableWidget->verticalHeaderItem(14);
        ___qtablewidgetitem71->setText(QCoreApplication::translate("MainWindow", "MajorImageVersion", nullptr));
        QTableWidgetItem *___qtablewidgetitem72 = optionalHeaderTableWidget->verticalHeaderItem(15);
        ___qtablewidgetitem72->setText(QCoreApplication::translate("MainWindow", "MinorImageVersion", nullptr));
        QTableWidgetItem *___qtablewidgetitem73 = optionalHeaderTableWidget->verticalHeaderItem(16);
        ___qtablewidgetitem73->setText(QCoreApplication::translate("MainWindow", "MajorSubsystemVersion", nullptr));
        QTableWidgetItem *___qtablewidgetitem74 = optionalHeaderTableWidget->verticalHeaderItem(17);
        ___qtablewidgetitem74->setText(QCoreApplication::translate("MainWindow", "MinorSubsystemVersion", nullptr));
        QTableWidgetItem *___qtablewidgetitem75 = optionalHeaderTableWidget->verticalHeaderItem(18);
        ___qtablewidgetitem75->setText(QCoreApplication::translate("MainWindow", "Win32VersionValue", nullptr));
        QTableWidgetItem *___qtablewidgetitem76 = optionalHeaderTableWidget->verticalHeaderItem(19);
        ___qtablewidgetitem76->setText(QCoreApplication::translate("MainWindow", "SizeOfImage", nullptr));
        QTableWidgetItem *___qtablewidgetitem77 = optionalHeaderTableWidget->verticalHeaderItem(20);
        ___qtablewidgetitem77->setText(QCoreApplication::translate("MainWindow", "SizeOfHeaders", nullptr));
        QTableWidgetItem *___qtablewidgetitem78 = optionalHeaderTableWidget->verticalHeaderItem(21);
        ___qtablewidgetitem78->setText(QCoreApplication::translate("MainWindow", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem79 = optionalHeaderTableWidget->verticalHeaderItem(22);
        ___qtablewidgetitem79->setText(QCoreApplication::translate("MainWindow", "CheckSum", nullptr));
        QTableWidgetItem *___qtablewidgetitem80 = optionalHeaderTableWidget->verticalHeaderItem(23);
        ___qtablewidgetitem80->setText(QCoreApplication::translate("MainWindow", "Subsystem", nullptr));
        QTableWidgetItem *___qtablewidgetitem81 = optionalHeaderTableWidget->verticalHeaderItem(24);
        ___qtablewidgetitem81->setText(QCoreApplication::translate("MainWindow", "DllCharacteristics", nullptr));
        QTableWidgetItem *___qtablewidgetitem82 = optionalHeaderTableWidget->verticalHeaderItem(25);
        ___qtablewidgetitem82->setText(QCoreApplication::translate("MainWindow", "SizeOfStackReserve", nullptr));
        QTableWidgetItem *___qtablewidgetitem83 = optionalHeaderTableWidget->verticalHeaderItem(26);
        ___qtablewidgetitem83->setText(QCoreApplication::translate("MainWindow", "SizeOfStackCommit", nullptr));
        QTableWidgetItem *___qtablewidgetitem84 = optionalHeaderTableWidget->verticalHeaderItem(27);
        ___qtablewidgetitem84->setText(QCoreApplication::translate("MainWindow", "SizeOfHeapReserve", nullptr));
        QTableWidgetItem *___qtablewidgetitem85 = optionalHeaderTableWidget->verticalHeaderItem(28);
        ___qtablewidgetitem85->setText(QCoreApplication::translate("MainWindow", "SizeOfHeapCommit", nullptr));
        QTableWidgetItem *___qtablewidgetitem86 = optionalHeaderTableWidget->verticalHeaderItem(29);
        ___qtablewidgetitem86->setText(QCoreApplication::translate("MainWindow", "NumberOfRvaAndSizes", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(optionalHeaderTab), QCoreApplication::translate("MainWindow", "Optional Header", nullptr));
        QTableWidgetItem *___qtablewidgetitem87 = dataDirectoriesTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem87->setText(QCoreApplication::translate("MainWindow", "Value", nullptr));
        QTableWidgetItem *___qtablewidgetitem88 = dataDirectoriesTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem88->setText(QCoreApplication::translate("MainWindow", "Offset", nullptr));
        QTableWidgetItem *___qtablewidgetitem89 = dataDirectoriesTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem89->setText(QCoreApplication::translate("MainWindow", "Size", nullptr));
        QTableWidgetItem *___qtablewidgetitem90 = dataDirectoriesTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem90->setText(QCoreApplication::translate("MainWindow", "Description", nullptr));
        QTableWidgetItem *___qtablewidgetitem91 = dataDirectoriesTableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem91->setText(QCoreApplication::translate("MainWindow", "Export Directory Address", nullptr));
        QTableWidgetItem *___qtablewidgetitem92 = dataDirectoriesTableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem92->setText(QCoreApplication::translate("MainWindow", "Import Directory Address", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(dataDirectoriesTab), QCoreApplication::translate("MainWindow", "Data Directories", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(sectionHeaderTab), QCoreApplication::translate("MainWindow", "Section Headers", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(dllImportTab), QCoreApplication::translate("MainWindow", "DLL Imports", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
