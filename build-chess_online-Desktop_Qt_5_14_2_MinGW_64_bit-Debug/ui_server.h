/********************************************************************************
** Form generated from reading UI file 'server.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVER_H
#define UI_SERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Server
{
public:
    QHBoxLayout *horizontalLayout_2;
    QListWidget *listWidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QPushButton *enter;
    QSpacerItem *verticalSpacer;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *name;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *Server)
    {
        if (Server->objectName().isEmpty())
            Server->setObjectName(QString::fromUtf8("Server"));
        Server->resize(469, 424);
        horizontalLayout_2 = new QHBoxLayout(Server);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        listWidget = new QListWidget(Server);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        horizontalLayout_2->addWidget(listWidget);

        widget = new QWidget(Server);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        enter = new QPushButton(widget);
        enter->setObjectName(QString::fromUtf8("enter"));

        verticalLayout->addWidget(enter);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(widget_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addWidget(widget_2);

        name = new QPushButton(widget);
        name->setObjectName(QString::fromUtf8("name"));

        verticalLayout->addWidget(name);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);


        horizontalLayout_2->addWidget(widget);


        retranslateUi(Server);

        QMetaObject::connectSlotsByName(Server);
    } // setupUi

    void retranslateUi(QWidget *Server)
    {
        Server->setWindowTitle(QCoreApplication::translate("Server", "Form", nullptr));
        enter->setText(QCoreApplication::translate("Server", "\350\277\233\345\205\245\346\210\277\351\227\264", nullptr));
        label->setText(QCoreApplication::translate("Server", "\347\224\250\346\210\267\345\220\215", nullptr));
        name->setText(QCoreApplication::translate("Server", "\345\210\233\345\273\272\346\210\277\351\227\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Server: public Ui_Server {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVER_H
