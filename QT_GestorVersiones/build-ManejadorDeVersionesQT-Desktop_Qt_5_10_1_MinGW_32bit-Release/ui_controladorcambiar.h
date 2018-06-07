/********************************************************************************
** Form generated from reading UI file 'controladorcambiar.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLADORCAMBIAR_H
#define UI_CONTROLADORCAMBIAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ControladorCambiar
{
public:
    QCommandLinkButton *botonVolver;
    QTextEdit *textEdit;
    QCommandLinkButton *botonModificar;

    void setupUi(QWidget *ControladorCambiar)
    {
        if (ControladorCambiar->objectName().isEmpty())
            ControladorCambiar->setObjectName(QStringLiteral("ControladorCambiar"));
        ControladorCambiar->resize(273, 445);
        botonVolver = new QCommandLinkButton(ControladorCambiar);
        botonVolver->setObjectName(QStringLiteral("botonVolver"));
        botonVolver->setGeometry(QRect(40, 330, 168, 41));
        textEdit = new QTextEdit(ControladorCambiar);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(20, 20, 231, 231));
        botonModificar = new QCommandLinkButton(ControladorCambiar);
        botonModificar->setObjectName(QStringLiteral("botonModificar"));
        botonModificar->setGeometry(QRect(40, 270, 168, 41));

        retranslateUi(ControladorCambiar);

        QMetaObject::connectSlotsByName(ControladorCambiar);
    } // setupUi

    void retranslateUi(QWidget *ControladorCambiar)
    {
        ControladorCambiar->setWindowTitle(QApplication::translate("ControladorCambiar", "Form", nullptr));
        botonVolver->setText(QApplication::translate("ControladorCambiar", "Volver", nullptr));
        botonModificar->setText(QApplication::translate("ControladorCambiar", "Modificar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ControladorCambiar: public Ui_ControladorCambiar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLADORCAMBIAR_H
