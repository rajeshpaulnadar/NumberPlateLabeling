/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <matdisplay.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox_4;
    QPushButton *pushButton_6;
    QLabel *label_14;
    QPushButton *pushButton_8;
    QComboBox *comboBox_8;
    QGroupBox *groupBox_5;
    QPushButton *pushButton_10;
    QPushButton *pushButton_9;
    QPushButton *pushButton_11;
    QComboBox *comboBox_10;
    QGroupBox *groupBox_6;
    matDisplay *label_3;
    QGroupBox *groupBox_3;
    QComboBox *comboBox;
    QLabel *label_15;
    QComboBox *comboBox_4;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QComboBox *comboBox_3;
    QComboBox *comboBox_9;
    QLabel *label_5;
    QComboBox *comboBox_2;
    QTextEdit *textEdit_5;
    QLabel *label_13;
    QTextEdit *textEdit_4;
    QLabel *label_9;
    QLabel *label_11;
    QLabel *label_10;
    QLabel *label_12;
    QComboBox *comboBox_7;
    QComboBox *comboBox_6;
    QComboBox *comboBox_5;
    QPushButton *pushButton_7;
    QGroupBox *groupBox_7;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QTextEdit *textEdit;
    QTextEdit *textEdit_6;
    QTextEdit *textEdit_7;
    QTextEdit *textEdit_8;
    QLabel *label_26;
    QLabel *label_27;
    QLabel *label_28;
    QLabel *label_29;
    QLabel *label_44;
    QLabel *label_45;
    QTextEdit *textEdit_25;
    QTextEdit *textEdit_26;
    QTextEdit *textEdit_27;
    QLabel *label_46;
    QLabel *label_47;
    QTextEdit *textEdit_28;
    QPushButton *pushButton_5;
    QTextEdit *textEdit_9;
    QLabel *label_16;
    QGroupBox *groupBox;
    QRadioButton *radioButton_5;
    QRadioButton *radioButton_6;
    QRadioButton *radioButton_7;
    QRadioButton *radioButton_8;
    QLabel *label;
    QPushButton *pushButton;
    QLabel *label_2;
    QGroupBox *groupBox_2;
    QTextEdit *textEdit_3;
    QPushButton *pushButton_3;
    QTextEdit *textEdit_2;
    QLabel *label_4;
    QPushButton *pushButton_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1361, 946);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(1040, 569, 321, 80));
        pushButton_6 = new QPushButton(groupBox_4);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(180, 50, 75, 23));
        label_14 = new QLabel(groupBox_4);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(50, 20, 101, 16));
        pushButton_8 = new QPushButton(groupBox_4);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(90, 50, 75, 23));
        comboBox_8 = new QComboBox(groupBox_4);
        comboBox_8->setObjectName(QStringLiteral("comboBox_8"));
        comboBox_8->setGeometry(QRect(140, 20, 101, 22));
        groupBox_5 = new QGroupBox(centralWidget);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(1040, 680, 321, 31));
        pushButton_10 = new QPushButton(groupBox_5);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setGeometry(QRect(80, 2, 75, 23));
        pushButton_9 = new QPushButton(groupBox_5);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(3, 3, 75, 23));
        pushButton_11 = new QPushButton(groupBox_5);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setGeometry(QRect(161, 3, 75, 23));
        comboBox_10 = new QComboBox(groupBox_5);
        comboBox_10->setObjectName(QStringLiteral("comboBox_10"));
        comboBox_10->setGeometry(QRect(242, 4, 69, 22));
        groupBox_6 = new QGroupBox(centralWidget);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(3, 50, 961, 651));
        label_3 = new matDisplay(groupBox_6);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(3, 10, 961, 651));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(1040, 40, 321, 531));
        comboBox = new QComboBox(groupBox_3);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(160, 20, 141, 20));
        label_15 = new QLabel(groupBox_3);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(12, 160, 142, 20));
        comboBox_4 = new QComboBox(groupBox_3);
        comboBox_4->setObjectName(QStringLiteral("comboBox_4"));
        comboBox_4->setGeometry(QRect(160, 125, 141, 20));
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(12, 55, 142, 20));
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(12, 90, 142, 20));
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(12, 125, 142, 20));
        comboBox_3 = new QComboBox(groupBox_3);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));
        comboBox_3->setGeometry(QRect(160, 90, 141, 20));
        comboBox_9 = new QComboBox(groupBox_3);
        comboBox_9->setObjectName(QStringLiteral("comboBox_9"));
        comboBox_9->setGeometry(QRect(160, 160, 141, 20));
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(12, 20, 142, 20));
        comboBox_2 = new QComboBox(groupBox_3);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(160, 55, 141, 20));
        textEdit_5 = new QTextEdit(groupBox_3);
        textEdit_5->setObjectName(QStringLiteral("textEdit_5"));
        textEdit_5->setGeometry(QRect(160, 190, 141, 31));
        label_13 = new QLabel(groupBox_3);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(10, 380, 101, 16));
        textEdit_4 = new QTextEdit(groupBox_3);
        textEdit_4->setObjectName(QStringLiteral("textEdit_4"));
        textEdit_4->setGeometry(QRect(160, 292, 141, 31));
        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 230, 101, 16));
        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(10, 302, 101, 16));
        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 260, 101, 16));
        label_12 = new QLabel(groupBox_3);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 190, 101, 16));
        comboBox_7 = new QComboBox(groupBox_3);
        comboBox_7->setObjectName(QStringLiteral("comboBox_7"));
        comboBox_7->setGeometry(QRect(160, 370, 141, 22));
        comboBox_6 = new QComboBox(groupBox_3);
        comboBox_6->setObjectName(QStringLiteral("comboBox_6"));
        comboBox_6->setGeometry(QRect(160, 260, 141, 22));
        comboBox_5 = new QComboBox(groupBox_3);
        comboBox_5->setObjectName(QStringLiteral("comboBox_5"));
        comboBox_5->setGeometry(QRect(160, 230, 141, 22));
        pushButton_7 = new QPushButton(groupBox_3);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(70, 504, 51, 23));
        groupBox_7 = new QGroupBox(groupBox_3);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setGeometry(QRect(10, 400, 291, 31));
        radioButton = new QRadioButton(groupBox_7);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(17, 7, 82, 17));
        radioButton_2 = new QRadioButton(groupBox_7);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(139, 6, 121, 17));
        textEdit = new QTextEdit(groupBox_3);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(20, 433, 51, 31));
        textEdit_6 = new QTextEdit(groupBox_3);
        textEdit_6->setObjectName(QStringLiteral("textEdit_6"));
        textEdit_6->setGeometry(QRect(99, 432, 51, 31));
        textEdit_7 = new QTextEdit(groupBox_3);
        textEdit_7->setObjectName(QStringLiteral("textEdit_7"));
        textEdit_7->setGeometry(QRect(171, 432, 61, 31));
        textEdit_8 = new QTextEdit(groupBox_3);
        textEdit_8->setObjectName(QStringLiteral("textEdit_8"));
        textEdit_8->setGeometry(QRect(255, 430, 61, 31));
        label_26 = new QLabel(groupBox_3);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(8, 437, 16, 16));
        label_27 = new QLabel(groupBox_3);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setGeometry(QRect(78, 437, 16, 16));
        label_28 = new QLabel(groupBox_3);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setGeometry(QRect(235, 440, 16, 16));
        label_29 = new QLabel(groupBox_3);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setGeometry(QRect(153, 440, 16, 16));
        label_44 = new QLabel(groupBox_3);
        label_44->setObjectName(QStringLiteral("label_44"));
        label_44->setGeometry(QRect(153, 480, 16, 16));
        label_45 = new QLabel(groupBox_3);
        label_45->setObjectName(QStringLiteral("label_45"));
        label_45->setGeometry(QRect(235, 480, 16, 16));
        textEdit_25 = new QTextEdit(groupBox_3);
        textEdit_25->setObjectName(QStringLiteral("textEdit_25"));
        textEdit_25->setGeometry(QRect(20, 470, 51, 31));
        textEdit_26 = new QTextEdit(groupBox_3);
        textEdit_26->setObjectName(QStringLiteral("textEdit_26"));
        textEdit_26->setGeometry(QRect(100, 470, 51, 31));
        textEdit_27 = new QTextEdit(groupBox_3);
        textEdit_27->setObjectName(QStringLiteral("textEdit_27"));
        textEdit_27->setGeometry(QRect(171, 472, 61, 31));
        label_46 = new QLabel(groupBox_3);
        label_46->setObjectName(QStringLiteral("label_46"));
        label_46->setGeometry(QRect(78, 477, 16, 16));
        label_47 = new QLabel(groupBox_3);
        label_47->setObjectName(QStringLiteral("label_47"));
        label_47->setGeometry(QRect(8, 477, 16, 16));
        textEdit_28 = new QTextEdit(groupBox_3);
        textEdit_28->setObjectName(QStringLiteral("textEdit_28"));
        textEdit_28->setGeometry(QRect(255, 470, 61, 31));
        pushButton_5 = new QPushButton(groupBox_3);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(163, 505, 75, 23));
        textEdit_9 = new QTextEdit(groupBox_3);
        textEdit_9->setObjectName(QStringLiteral("textEdit_9"));
        textEdit_9->setGeometry(QRect(160, 331, 141, 31));
        label_16 = new QLabel(groupBox_3);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(10, 340, 141, 16));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(2, -1, 661, 51));
        radioButton_5 = new QRadioButton(groupBox);
        radioButton_5->setObjectName(QStringLiteral("radioButton_5"));
        radioButton_5->setGeometry(QRect(45, 20, 38, 17));
        radioButton_6 = new QRadioButton(groupBox);
        radioButton_6->setObjectName(QStringLiteral("radioButton_6"));
        radioButton_6->setGeometry(QRect(85, 20, 41, 17));
        radioButton_7 = new QRadioButton(groupBox);
        radioButton_7->setObjectName(QStringLiteral("radioButton_7"));
        radioButton_7->setGeometry(QRect(130, 20, 43, 17));
        radioButton_8 = new QRadioButton(groupBox);
        radioButton_8->setObjectName(QStringLiteral("radioButton_8"));
        radioButton_8->setGeometry(QRect(180, 20, 58, 17));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 30, 16));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(580, 20, 75, 23));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(250, 18, 321, 23));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(1045, 649, 311, 31));
        textEdit_3 = new QTextEdit(groupBox_2);
        textEdit_3->setObjectName(QStringLiteral("textEdit_3"));
        textEdit_3->setGeometry(QRect(190, 0, 121, 31));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textEdit_3->sizePolicy().hasHeightForWidth());
        textEdit_3->setSizePolicy(sizePolicy);
        pushButton_3 = new QPushButton(groupBox_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(40, 0, 41, 31));
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);
        textEdit_2 = new QTextEdit(groupBox_2);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(80, 0, 101, 31));
        sizePolicy.setHeightForWidth(textEdit_2->sizePolicy().hasHeightForWidth());
        textEdit_2->setSizePolicy(sizePolicy);
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(183, 5, 16, 20));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        pushButton_2 = new QPushButton(groupBox_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(0, 0, 41, 31));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1361, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Load Labelled Data", 0));
        pushButton_6->setText(QApplication::translate("MainWindow", "Delete", 0));
        label_14->setText(QApplication::translate("MainWindow", "Vechicle ID ", 0));
        pushButton_8->setText(QApplication::translate("MainWindow", "Update", 0));
        groupBox_5->setTitle(QString());
        pushButton_10->setText(QApplication::translate("MainWindow", "Zoom Out", 0));
        pushButton_9->setText(QApplication::translate("MainWindow", "Zoom In", 0));
        pushButton_11->setText(QApplication::translate("MainWindow", "Rotate Image", 0));
        groupBox_6->setTitle(QString());
        label_3->setText(QString());
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Ground Truth Attributes", 0));
        label_15->setText(QApplication::translate("MainWindow", "Light Condition", 0));
        label_6->setText(QApplication::translate("MainWindow", "Vehicle View", 0));
        label_7->setText(QApplication::translate("MainWindow", "Vehicle occlusion", 0));
        label_8->setText(QApplication::translate("MainWindow", "Partially Hidden From", 0));
        label_5->setText(QApplication::translate("MainWindow", "Vehicle Type", 0));
        label_13->setText(QApplication::translate("MainWindow", "Number plate View", 0));
        label_9->setText(QApplication::translate("MainWindow", "Number Plate color", 0));
        label_11->setText(QApplication::translate("MainWindow", "Vechicle Number ", 0));
        label_10->setText(QApplication::translate("MainWindow", "Occlusion", 0));
        label_12->setText(QApplication::translate("MainWindow", "Vechicle ID ", 0));
        pushButton_7->setText(QApplication::translate("MainWindow", "New", 0));
        groupBox_7->setTitle(QString());
        radioButton->setText(QApplication::translate("MainWindow", "Vehicle ROI", 0));
        radioButton_2->setText(QApplication::translate("MainWindow", "Number Plate ROI", 0));
        label_26->setText(QApplication::translate("MainWindow", "x1", 0));
        label_27->setText(QApplication::translate("MainWindow", "y1", 0));
        label_28->setText(QApplication::translate("MainWindow", "h", 0));
        label_29->setText(QApplication::translate("MainWindow", "w", 0));
        label_44->setText(QApplication::translate("MainWindow", "w", 0));
        label_45->setText(QApplication::translate("MainWindow", "h", 0));
        label_46->setText(QApplication::translate("MainWindow", "y1", 0));
        label_47->setText(QApplication::translate("MainWindow", "x1", 0));
        pushButton_5->setText(QApplication::translate("MainWindow", "Save", 0));
        label_16->setText(QApplication::translate("MainWindow", "Other Text in Number Plate", 0));
        groupBox->setTitle(QString());
        radioButton_5->setText(QApplication::translate("MainWindow", "jpg", 0));
        radioButton_6->setText(QApplication::translate("MainWindow", "png", 0));
        radioButton_7->setText(QApplication::translate("MainWindow", "bmp", 0));
        radioButton_8->setText(QApplication::translate("MainWindow", "All Files", 0));
        label->setText(QApplication::translate("MainWindow", "Image", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Load", 0));
        label_2->setText(QString());
        groupBox_2->setTitle(QString());
        pushButton_3->setText(QApplication::translate("MainWindow", ">", 0));
        label_4->setText(QApplication::translate("MainWindow", "/", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "<", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
