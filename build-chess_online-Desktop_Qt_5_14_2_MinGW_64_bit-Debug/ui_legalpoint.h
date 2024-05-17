/********************************************************************************
** Form generated from reading UI file 'legalpoint.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEGALPOINT_H
#define UI_LEGALPOINT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LegalPoint
{
public:

    void setupUi(QWidget *LegalPoint)
    {
        if (LegalPoint->objectName().isEmpty())
            LegalPoint->setObjectName(QString::fromUtf8("LegalPoint"));
        LegalPoint->resize(80, 80);

        retranslateUi(LegalPoint);

        QMetaObject::connectSlotsByName(LegalPoint);
    } // setupUi

    void retranslateUi(QWidget *LegalPoint)
    {
        LegalPoint->setWindowTitle(QCoreApplication::translate("LegalPoint", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LegalPoint: public Ui_LegalPoint {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEGALPOINT_H
