/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tabP;
    QPushButton *PpushButtonSelectFolder;
    QGraphicsView *PgraphicsView;
    QGraphicsView *PgraphicsViewEdge;
    QWidget *tabFS;
    QPushButton *FSpushButtonOpenFile;
    QPushButton *FSpushButtonSaveFile;
    QComboBox *FScomboBox;
    QLabel *label;
    QRadioButton *FSradioButtonFisher;
    QRadioButton *FSradioButtonSFS;
    QPushButton *FSpushButtonCompute;
    QTextBrowser *FStextBrowserDatabaseInfo;
    QPushButton *TrainTest;
    QTextBrowser *textBrowser;
    QPushButton *NN;
    QPushButton *NM;
    QPushButton *bootstrap;
    QWidget *tabC;
    QPushButton *CpushButtonOpenFile;
    QPushButton *CpushButtonSaveFile;
    QComboBox *CcomboBoxK;
    QLabel *ClabelK;
    QPushButton *CpushButtonTrain;
    QLabel *ClabelClassifiers;
    QComboBox *CcomboBoxClassifiers;
    QPlainTextEdit *CplainTextEditTrainingPart;
    QPushButton *CpushButtonExecute;
    QLabel *ClabelTraningPart;
    QTextBrowser *CtextBrowser;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(991, 540);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 0, 971, 491));
        tabP = new QWidget();
        tabP->setObjectName(QStringLiteral("tabP"));
        PpushButtonSelectFolder = new QPushButton(tabP);
        PpushButtonSelectFolder->setObjectName(QStringLiteral("PpushButtonSelectFolder"));
        PpushButtonSelectFolder->setGeometry(QRect(10, 10, 75, 31));
        PgraphicsView = new QGraphicsView(tabP);
        PgraphicsView->setObjectName(QStringLiteral("PgraphicsView"));
        PgraphicsView->setGeometry(QRect(680, 30, 256, 192));
        PgraphicsView->setInteractive(true);
        PgraphicsView->setViewportUpdateMode(QGraphicsView::MinimalViewportUpdate);
        PgraphicsViewEdge = new QGraphicsView(tabP);
        PgraphicsViewEdge->setObjectName(QStringLiteral("PgraphicsViewEdge"));
        PgraphicsViewEdge->setGeometry(QRect(680, 250, 256, 192));
        tabWidget->addTab(tabP, QString());
        tabFS = new QWidget();
        tabFS->setObjectName(QStringLiteral("tabFS"));
        FSpushButtonOpenFile = new QPushButton(tabFS);
        FSpushButtonOpenFile->setObjectName(QStringLiteral("FSpushButtonOpenFile"));
        FSpushButtonOpenFile->setGeometry(QRect(10, 10, 75, 31));
        FSpushButtonSaveFile = new QPushButton(tabFS);
        FSpushButtonSaveFile->setObjectName(QStringLiteral("FSpushButtonSaveFile"));
        FSpushButtonSaveFile->setGeometry(QRect(10, 60, 75, 31));
        FScomboBox = new QComboBox(tabFS);
        FScomboBox->setObjectName(QStringLiteral("FScomboBox"));
        FScomboBox->setGeometry(QRect(250, 10, 69, 31));
        label = new QLabel(tabFS);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(150, 10, 101, 31));
        FSradioButtonFisher = new QRadioButton(tabFS);
        FSradioButtonFisher->setObjectName(QStringLiteral("FSradioButtonFisher"));
        FSradioButtonFisher->setGeometry(QRect(251, 50, 71, 20));
        FSradioButtonFisher->setChecked(true);
        FSradioButtonSFS = new QRadioButton(tabFS);
        FSradioButtonSFS->setObjectName(QStringLiteral("FSradioButtonSFS"));
        FSradioButtonSFS->setGeometry(QRect(250, 80, 82, 21));
        FSpushButtonCompute = new QPushButton(tabFS);
        FSpushButtonCompute->setObjectName(QStringLiteral("FSpushButtonCompute"));
        FSpushButtonCompute->setGeometry(QRect(380, 10, 75, 31));
        FStextBrowserDatabaseInfo = new QTextBrowser(tabFS);
        FStextBrowserDatabaseInfo->setObjectName(QStringLiteral("FStextBrowserDatabaseInfo"));
        FStextBrowserDatabaseInfo->setGeometry(QRect(700, 10, 256, 192));
        TrainTest = new QPushButton(tabFS);
        TrainTest->setObjectName(QStringLiteral("TrainTest"));
        TrainTest->setGeometry(QRect(10, 110, 93, 28));
        textBrowser = new QTextBrowser(tabFS);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(0, 211, 951, 231));
        NN = new QPushButton(tabFS);
        NN->setObjectName(QStringLiteral("NN"));
        NN->setGeometry(QRect(10, 160, 93, 28));
        NM = new QPushButton(tabFS);
        NM->setObjectName(QStringLiteral("NM"));
        NM->setGeometry(QRect(110, 110, 91, 31));
        bootstrap = new QPushButton(tabFS);
        bootstrap->setObjectName(QStringLiteral("bootstrap"));
        bootstrap->setGeometry(QRect(110, 160, 91, 31));
        tabWidget->addTab(tabFS, QString());
        tabC = new QWidget();
        tabC->setObjectName(QStringLiteral("tabC"));
        CpushButtonOpenFile = new QPushButton(tabC);
        CpushButtonOpenFile->setObjectName(QStringLiteral("CpushButtonOpenFile"));
        CpushButtonOpenFile->setGeometry(QRect(10, 10, 75, 31));
        CpushButtonSaveFile = new QPushButton(tabC);
        CpushButtonSaveFile->setObjectName(QStringLiteral("CpushButtonSaveFile"));
        CpushButtonSaveFile->setGeometry(QRect(10, 60, 75, 31));
        CcomboBoxK = new QComboBox(tabC);
        CcomboBoxK->setObjectName(QStringLiteral("CcomboBoxK"));
        CcomboBoxK->setGeometry(QRect(210, 61, 69, 31));
        ClabelK = new QLabel(tabC);
        ClabelK->setObjectName(QStringLiteral("ClabelK"));
        ClabelK->setGeometry(QRect(190, 70, 20, 31));
        CpushButtonTrain = new QPushButton(tabC);
        CpushButtonTrain->setObjectName(QStringLiteral("CpushButtonTrain"));
        CpushButtonTrain->setGeometry(QRect(380, 10, 75, 31));
        ClabelClassifiers = new QLabel(tabC);
        ClabelClassifiers->setObjectName(QStringLiteral("ClabelClassifiers"));
        ClabelClassifiers->setGeometry(QRect(150, 10, 71, 31));
        CcomboBoxClassifiers = new QComboBox(tabC);
        CcomboBoxClassifiers->setObjectName(QStringLiteral("CcomboBoxClassifiers"));
        CcomboBoxClassifiers->setGeometry(QRect(210, 10, 69, 31));
        CcomboBoxClassifiers->setEditable(true);
        CplainTextEditTrainingPart = new QPlainTextEdit(tabC);
        CplainTextEditTrainingPart->setObjectName(QStringLiteral("CplainTextEditTrainingPart"));
        CplainTextEditTrainingPart->setGeometry(QRect(380, 60, 71, 31));
        CpushButtonExecute = new QPushButton(tabC);
        CpushButtonExecute->setObjectName(QStringLiteral("CpushButtonExecute"));
        CpushButtonExecute->setGeometry(QRect(540, 10, 75, 31));
        ClabelTraningPart = new QLabel(tabC);
        ClabelTraningPart->setObjectName(QStringLiteral("ClabelTraningPart"));
        ClabelTraningPart->setGeometry(QRect(300, 60, 81, 31));
        CtextBrowser = new QTextBrowser(tabC);
        CtextBrowser->setObjectName(QStringLiteral("CtextBrowser"));
        CtextBrowser->setGeometry(QRect(700, 10, 256, 192));
        tabWidget->addTab(tabC, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 991, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);
        CcomboBoxClassifiers->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        PpushButtonSelectFolder->setText(QApplication::translate("MainWindow", "Select Folder", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tabP), QApplication::translate("MainWindow", "Preprocessing", Q_NULLPTR));
        FSpushButtonOpenFile->setText(QApplication::translate("MainWindow", "Open File", Q_NULLPTR));
        FSpushButtonSaveFile->setText(QApplication::translate("MainWindow", "Save File", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt;\">Feature number:</span></p></body></html>", Q_NULLPTR));
        FSradioButtonFisher->setText(QApplication::translate("MainWindow", "Fisher", Q_NULLPTR));
        FSradioButtonSFS->setText(QApplication::translate("MainWindow", "SFS", Q_NULLPTR));
        FSpushButtonCompute->setText(QApplication::translate("MainWindow", "Compute", Q_NULLPTR));
        TrainTest->setText(QApplication::translate("MainWindow", "test/train", Q_NULLPTR));
        NN->setText(QApplication::translate("MainWindow", "NN", Q_NULLPTR));
        NM->setText(QApplication::translate("MainWindow", "NM", Q_NULLPTR));
        bootstrap->setText(QApplication::translate("MainWindow", "bootstrap", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tabFS), QApplication::translate("MainWindow", "Features Selection", Q_NULLPTR));
        CpushButtonOpenFile->setText(QApplication::translate("MainWindow", "Open File", Q_NULLPTR));
        CpushButtonSaveFile->setText(QApplication::translate("MainWindow", "Save File", Q_NULLPTR));
        ClabelK->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt;\">k:</span></p></body></html>", Q_NULLPTR));
        CpushButtonTrain->setText(QApplication::translate("MainWindow", "Train", Q_NULLPTR));
        ClabelClassifiers->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt;\">Classifiers:</span></p></body></html>", Q_NULLPTR));
        CcomboBoxClassifiers->setCurrentText(QString());
        CpushButtonExecute->setText(QApplication::translate("MainWindow", "Execute", Q_NULLPTR));
        ClabelTraningPart->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt;\">Training part:</span></p></body></html>", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tabC), QApplication::translate("MainWindow", "Classifiers", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
