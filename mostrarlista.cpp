#include "mostrarlista.h"

MostrarLista::MostrarLista()
{
    int cantidad;
    QDir directorio;
    directorio.setPath("C:/Users/Kenneth D/OneDrive - Universidad Politecnica Salesiana/Actividad QT");
    cantidad = directorio.count();

    for(int i=2;i<cantidad;i++){
        ui->listWidget->addItem(QString(directorio[i]));
    }
}
