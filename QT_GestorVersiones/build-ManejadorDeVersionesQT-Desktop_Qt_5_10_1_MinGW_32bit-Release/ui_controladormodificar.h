/********************************************************************************
** Form generated from reading UI file 'controladormodificar.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLADORMODIFICAR_H
#define UI_CONTROLADORMODIFICAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ControladorModificar
{
public:
    QCommandLinkButton *BotonCerrar;
    QGroupBox *groupBox;
    QCommandLinkButton *botonHistorial;
    QGroupBox *groupBox_2;
    QCommandLinkButton *botonModificar;
    QCommandLinkButton *botonGuardar;
    QGroupBox *groupBox_3;
    QCommandLinkButton *botonDiferencia;
    QGroupBox *groupBox_4;
    QCommandLinkButton *botonVisualizar;
    QLabel *label;
    QTextEdit *textBrowser;
    QLabel *label_2;

    void setupUi(QWidget *ControladorModificar)
    {
        if (ControladorModificar->objectName().isEmpty())
            ControladorModificar->setObjectName(QStringLiteral("ControladorModificar"));
        ControladorModificar->resize(668, 366);
        ControladorModificar->setCursor(QCursor(Qt::ArrowCursor));
        BotonCerrar = new QCommandLinkButton(ControladorModificar);
        BotonCerrar->setObjectName(QStringLiteral("BotonCerrar"));
        BotonCerrar->setGeometry(QRect(440, 300, 121, 41));
        BotonCerrar->setCursor(QCursor(Qt::CrossCursor));
        groupBox = new QGroupBox(ControladorModificar);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(30, 20, 311, 81));
        botonHistorial = new QCommandLinkButton(groupBox);
        botonHistorial->setObjectName(QStringLiteral("botonHistorial"));
        botonHistorial->setGeometry(QRect(10, 30, 291, 41));
        botonHistorial->setCursor(QCursor(Qt::CrossCursor));
        groupBox_2 = new QGroupBox(ControladorModificar);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(30, 190, 311, 71));
        botonModificar = new QCommandLinkButton(groupBox_2);
        botonModificar->setObjectName(QStringLiteral("botonModificar"));
        botonModificar->setGeometry(QRect(10, 20, 151, 41));
        botonModificar->setCursor(QCursor(Qt::CrossCursor));
        botonGuardar = new QCommandLinkButton(groupBox_2);
        botonGuardar->setObjectName(QStringLiteral("botonGuardar"));
        botonGuardar->setEnabled(false);
        botonGuardar->setGeometry(QRect(180, 20, 121, 41));
        groupBox_3 = new QGroupBox(ControladorModificar);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(30, 270, 311, 71));
        botonDiferencia = new QCommandLinkButton(groupBox_3);
        botonDiferencia->setObjectName(QStringLiteral("botonDiferencia"));
        botonDiferencia->setGeometry(QRect(10, 20, 291, 41));
        botonDiferencia->setCursor(QCursor(Qt::CrossCursor));
        groupBox_4 = new QGroupBox(ControladorModificar);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(30, 110, 311, 71));
        botonVisualizar = new QCommandLinkButton(groupBox_4);
        botonVisualizar->setObjectName(QStringLiteral("botonVisualizar"));
        botonVisualizar->setGeometry(QRect(10, 20, 291, 41));
        botonVisualizar->setCursor(QCursor(Qt::CrossCursor));
        label = new QLabel(ControladorModificar);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(440, 20, 171, 16));
        label->setCursor(QCursor(Qt::CrossCursor));
        textBrowser = new QTextEdit(ControladorModificar);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(360, 40, 281, 241));
        label_2 = new QLabel(ControladorModificar);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(380, 20, 171, 16));
        label_2->setCursor(QCursor(Qt::CrossCursor));

        retranslateUi(ControladorModificar);

        QMetaObject::connectSlotsByName(ControladorModificar);
    } // setupUi

    void retranslateUi(QWidget *ControladorModificar)
    {
        ControladorModificar->setWindowTitle(QApplication::translate("ControladorModificar", "Manejador de Versiones", nullptr));
        BotonCerrar->setText(QApplication::translate("ControladorModificar", "Volver atras", nullptr));
        groupBox->setTitle(QApplication::translate("ControladorModificar", "Mostrar el HISTORIAL de todas las versiones del archivo", nullptr));
        botonHistorial->setText(QApplication::translate("ControladorModificar", "Generar HISTORIAL", nullptr));
        groupBox_2->setTitle(QApplication::translate("ControladorModificar", "Realiza MODIFICACIONES a versiones almacenadas", nullptr));
        botonModificar->setText(QApplication::translate("ControladorModificar", "MODIFICAR", nullptr));
        botonGuardar->setText(QApplication::translate("ControladorModificar", "GUARDAR", nullptr));
        groupBox_3->setTitle(QApplication::translate("ControladorModificar", "Muestra la DIFERENCIA de dos versiones del archivo de control", nullptr));
        botonDiferencia->setText(QApplication::translate("ControladorModificar", "DIFERENCIAR dos Versiones", nullptr));
        groupBox_4->setTitle(QApplication::translate("ControladorModificar", "Puedes VISUALIZAR cualquier version", nullptr));
        botonVisualizar->setText(QApplication::translate("ControladorModificar", "VISUALIZAR", nullptr));
        label->setText(QApplication::translate("ControladorModificar", "xxxxxxxxx", nullptr));
        label_2->setText(QApplication::translate("ControladorModificar", "Proyecto:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ControladorModificar: public Ui_ControladorModificar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLADORMODIFICAR_H
