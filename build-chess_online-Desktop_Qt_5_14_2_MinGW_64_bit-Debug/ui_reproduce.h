/********************************************************************************
** Form generated from reading UI file 'reproduce.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPRODUCE_H
#define UI_REPRODUCE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <board.h>

QT_BEGIN_NAMESPACE

class Ui_Reproduce
{
public:
    QVBoxLayout *verticalLayout;
    Board *board;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *preButton;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *nxtButton;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *Reproduce)
    {
        if (Reproduce->objectName().isEmpty())
            Reproduce->setObjectName(QString::fromUtf8("Reproduce"));
        Reproduce->resize(720, 1000);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Reproduce->sizePolicy().hasHeightForWidth());
        Reproduce->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/heishuai.svg"), QSize(), QIcon::Normal, QIcon::Off);
        Reproduce->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(Reproduce);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        board = new Board(Reproduce);
        board->setObjectName(QString::fromUtf8("board"));
        sizePolicy.setHeightForWidth(board->sizePolicy().hasHeightForWidth());
        board->setSizePolicy(sizePolicy);
        board->setMinimumSize(QSize(720, 960));

        verticalLayout->addWidget(board);

        widget = new QWidget(Reproduce);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        preButton = new QPushButton(widget);
        preButton->setObjectName(QString::fromUtf8("preButton"));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\232\266\344\271\246"));
        font.setPointSize(20);
        preButton->setFont(font);

        horizontalLayout->addWidget(preButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        nxtButton = new QPushButton(widget);
        nxtButton->setObjectName(QString::fromUtf8("nxtButton"));
        nxtButton->setFont(font);

        horizontalLayout->addWidget(nxtButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addWidget(widget);


        retranslateUi(Reproduce);

        QMetaObject::connectSlotsByName(Reproduce);
    } // setupUi

    void retranslateUi(QWidget *Reproduce)
    {
        Reproduce->setWindowTitle(QCoreApplication::translate("Reproduce", "\345\244\215\347\233\230", nullptr));
        preButton->setText(QCoreApplication::translate("Reproduce", "\344\270\212\344\270\200\346\255\245", nullptr));
        nxtButton->setText(QCoreApplication::translate("Reproduce", "\344\270\213\344\270\200\346\255\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Reproduce: public Ui_Reproduce {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPRODUCE_H
