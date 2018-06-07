#ifndef CONTROLADORCAMBIAR_H
#define CONTROLADORCAMBIAR_H

#include <QWidget>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QIcon>
#include <QTreeWidget>
#include <QtWidgets>
#include "archivo.h"
#include "version.h"

namespace Ui {
class ControladorCambiar;
}

class ControladorCambiar : public QWidget
{
    Q_OBJECT

public:
    Archivo a;
    Version v;
    explicit ControladorCambiar(QWidget *parent = 0);
    ~ControladorCambiar();

private slots:
    void on_botonVolver_clicked();

    void on_botonModificar_clicked();

private:
    Ui::ControladorCambiar *ui;
};

#endif // CONTROLADORCAMBIAR_H
