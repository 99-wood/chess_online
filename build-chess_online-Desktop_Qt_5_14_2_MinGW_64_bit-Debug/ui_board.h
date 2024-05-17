/********************************************************************************
** Form generated from reading UI file 'board.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOARD_H
#define UI_BOARD_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Board
{
public:

    void setupUi(QWidget *Board)
    {
        if (Board->objectName().isEmpty())
            Board->setObjectName(QString::fromUtf8("Board"));
        Board->resize(720, 960);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Board->sizePolicy().hasHeightForWidth());
        Board->setSizePolicy(sizePolicy);
        Board->setMinimumSize(QSize(720, 960));
        Board->setMaximumSize(QSize(720, 960));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/hongzu.svg"), QSize(), QIcon::Normal, QIcon::Off);
        Board->setWindowIcon(icon);

        retranslateUi(Board);

        QMetaObject::connectSlotsByName(Board);
    } // setupUi

    void retranslateUi(QWidget *Board)
    {
        Board->setWindowTitle(QCoreApplication::translate("Board", "\345\257\271\345\261\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Board: public Ui_Board {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOARD_H
