#include "controlador.h"
#include <QApplication>

//Main que Crea un objeto de Controlador, ya el cual se encarga de iniciar todo
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Controlador w;
    w.show();

    return a.exec();
}
