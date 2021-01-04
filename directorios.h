#ifndef DIRECTORIOS_H
#define DIRECTORIOS_H
#include <QDir>
#include <QDebug>
#include <QWidget>
#include <qfile.h>
#include <QMainWindow>

#include <QDateTimeEdit>



QT_BEGIN_NAMESPACE
namespace Ui { class Directorios; }
QT_END_NAMESPACE

class Directorios : public QMainWindow
{
    Q_OBJECT

public:
    Directorios(QWidget *parent = nullptr);
    ~Directorios();

    void crearDirectorio();
    void mostrarContenido();
    void REFRESH();

    void EliminarDirectorios();
    void Rename();
    void EliminarDirRestantes();

private slots:
    void on_pbCrear_clicked();
    void on_pbDelete_clicked();
    void on_pbRefresh_clicked();

    void on_pbRename_clicked();

    void on_pushButton_clicked();

    QString on_pbAdd_clicked();

    void on_pbDelete_Direc_clicked();



private:
    enum columna{
        NOMBRE, DIRECTORIO, ESCRITURA, CREACION
    };
    Ui::Directorios *ui;
};
#endif // DIRECTORIOS_H
