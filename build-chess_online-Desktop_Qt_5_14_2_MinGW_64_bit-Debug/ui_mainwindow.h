/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QPushButton *buttonStart;
    QPushButton *buttonOnline;
    QPushButton *buttonReproduce;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(600, 614);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(600, 0));
        MainWindow->setMaximumSize(QSize(600, 16777215));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/heixiang.svg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMouseTracking(false);
        centralwidget->setTabletTracking(false);
        centralwidget->setAcceptDrops(false);
        centralwidget->setAutoFillBackground(false);
        centralwidget->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        buttonStart = new QPushButton(widget);
        buttonStart->setObjectName(QString::fromUtf8("buttonStart"));
        buttonStart->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(buttonStart->sizePolicy().hasHeightForWidth());
        buttonStart->setSizePolicy(sizePolicy1);
        buttonStart->setMinimumSize(QSize(0, 150));
        buttonStart->setMaximumSize(QSize(16777215, 150));
        QFont font;
        font.setFamily(QString::fromUtf8("\350\203\241\346\225\254\347\244\274\346\257\233\347\254\224\350\241\214\344\271\246\347\271\201"));
        font.setPointSize(100);
        buttonStart->setFont(font);
        buttonStart->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/hongshuai.svg"), QSize(), QIcon::Normal, QIcon::Off);
        buttonStart->setIcon(icon1);
        buttonStart->setIconSize(QSize(200, 200));
        buttonStart->setCheckable(false);
        buttonStart->setAutoDefault(true);

        verticalLayout->addWidget(buttonStart);

        buttonOnline = new QPushButton(widget);
        buttonOnline->setObjectName(QString::fromUtf8("buttonOnline"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(buttonOnline->sizePolicy().hasHeightForWidth());
        buttonOnline->setSizePolicy(sizePolicy2);
        buttonOnline->setMinimumSize(QSize(0, 150));
        buttonOnline->setMaximumSize(QSize(16777215, 150));
        buttonOnline->setFont(font);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/hongxiang.svg"), QSize(), QIcon::Normal, QIcon::Off);
        buttonOnline->setIcon(icon2);
        buttonOnline->setIconSize(QSize(200, 200));

        verticalLayout->addWidget(buttonOnline);

        buttonReproduce = new QPushButton(widget);
        buttonReproduce->setObjectName(QString::fromUtf8("buttonReproduce"));
        sizePolicy2.setHeightForWidth(buttonReproduce->sizePolicy().hasHeightForWidth());
        buttonReproduce->setSizePolicy(sizePolicy2);
        buttonReproduce->setMinimumSize(QSize(0, 150));
        buttonReproduce->setMaximumSize(QSize(16777215, 150));
        buttonReproduce->setFont(font);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/image/heishuai.svg"), QSize(), QIcon::Normal, QIcon::Off);
        buttonReproduce->setIcon(icon3);
        buttonReproduce->setIconSize(QSize(200, 200));

        verticalLayout->addWidget(buttonReproduce);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addWidget(widget);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213", nullptr));
        buttonStart->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213", nullptr));
        buttonOnline->setText(QCoreApplication::translate("MainWindow", "\350\201\224\346\234\272", nullptr));
        buttonReproduce->setText(QCoreApplication::translate("MainWindow", "\345\244\215\347\233\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
