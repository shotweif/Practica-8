#include "directorios.h"
#include "ui_directorios.h"

Directorios::Directorios(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Directorios)
{
    ui->setupUi(this);
    mostrarContenido();

    QPushButton *ptr = ui->pbSalir;
    QStringList titulos;

    ui->tableWidgetObj->selectColumn(4);
    titulos << "Nombre" << "Es directorio" << "Se puede escribir" << "Última de creación";
    ui->tableWidgetObj->setHorizontalHeaderLabels(titulos);

    QObject::connect(ptr,SIGNAL(clicked()),this,SLOT(close()));
}

Directorios::~Directorios()
{
    delete ui;
}

void Directorios::crearDirectorio()
{
    int cantidad;

    QDir directorio;
    directorio.setPath("C:/Users/Kenneth D/OneDrive - Universidad Politecnica Salesiana/Actividad QT");
    cantidad = directorio.count();

    QString mPath = "Carpeta";
    QString T;
    int x = 1;

    for(int i=2;i<cantidad;i++){
        T = T.number(x);
        if(!directorio.exists(mPath+T)){
            directorio.mkpath(mPath+T);
            break;
        }
        x++;
    }
    T = T.number(x);
    directorio.mkpath(mPath+T);

    REFRESH();
}

void Directorios::mostrarContenido()
{
    int cantidad;
    QString escrito;
    QString direc;
    QDir directorio;
    directorio.setPath(on_pbAdd_clicked());
    cantidad = directorio.count();


        QFileInfoList contenido = directorio.entryInfoList();

        //qDebug() << info.lastModified().toString();

        foreach (const QFileInfo &info, contenido) {
            if(info.isWritable()==true){
                escrito = "Si";
            }else{
                escrito = "No";
            }
            if(info.isDir()==true){
                direc = "Si";
            }else{
                direc = "No";
            }/*
                qDebug() << "Nombre:" << info.fileName();
                qDebug() << "Es directorio:" << info.isDir();
                qDebug() << "Se puede escribir:" << info.isWritable();
                qDebug() << "Última de creación:" << info.lastModified().toString();
                */

                ui->listWidget->addItem(info.fileName()+"   "+
                                        direc+"     "+
                                        escrito+"   "+
                                        info.lastModified().toString());

                //ui->tableWidgetObj->setItem(ui->tableWidgetObj->rowCount() - 1, NOMBRE
                                            //new QTableWidgetItem(nombre));
                /*ui->listWDir->addItem(direc);
                ui->listWEscr->addItem(escrito);
                ui->listWFcha->addItem(info.lastModified().toString())*/


        }
    for(int i=2;i<cantidad;i++){
       //*ui->listWidget->addItem(QString(directorio[i]));
        ui->cbCarpetas->addItem(QString(directorio[i]));
    }
}

void Directorios::REFRESH()
{
    ui->listWidget->clear();
    ui->cbCarpetas->clear();

    mostrarContenido();
}

void Directorios::EliminarDirectorios()
{
    int cantidad;
    QString direc = "C:/Users/Kenneth D/OneDrive - Universidad Politecnica Salesiana/Actividad QT";
    QDir directorio;
    directorio.setPath(direc);
    cantidad = directorio.count();

    QString T;
    int x = 1;

    for(int i=2;i<cantidad;i++){
        T = T.number(x);
        QString mPath = "Carpeta"+T;

        if(directorio.exists(mPath)){
            if(x%2 == 0){}else {
                directorio.cd(mPath);
                int cont=0;
                cont = directorio.count();
                if(cont != 0){
                   directorio.removeRecursively();
                }
                directorio.cd("..");
            }
        }
        x++;
    }
    REFRESH();
}

void Directorios::Rename()
{

    QDir directorio;
    directorio.setPath("C:/Users/Kenneth D/OneDrive - Universidad Politecnica Salesiana/Actividad QT");

    QString name = ui->cbCarpetas->currentText();
    QString change = ui->lineEdit->text();
    qDebug() << name;

    directorio.rename(name,change);

    REFRESH();
}

void Directorios::EliminarDirRestantes()
{
    int cantidad;
    QString direc = "C:/Users/Kenneth D/OneDrive - Universidad Politecnica Salesiana/Actividad QT";
    QDir directorio;
    directorio.setPath(direc);
    cantidad = directorio.count();

    QString T;
    int x = 1;

    for(int i=2;i<cantidad;i++){
        T = T.number(x);
        QString mPath = "Carpeta"+T;

        if(directorio.exists(mPath)){
            if(x%2 == 0){
                directorio.cd(mPath);
                int cont=0;
                cont = directorio.count();
                if(cont != 0){
                    for(int y=2;y<cont;y++){
                        directorio.remove(directorio[y]);
                    }
                }
                directorio.cd("..");
            }
        }
        x++;
    }
    REFRESH();
}
//------------------------------------------------------
//------------------------------------------------------
void Directorios::on_pbCrear_clicked()
{
    ui->tableWidgetObj->insertRow(ui->tableWidgetObj->rowCount());

    crearDirectorio();
}

void Directorios::on_pbDelete_clicked()
{
    EliminarDirectorios();
}

void Directorios::on_pbRefresh_clicked()
{
    REFRESH();
}

void Directorios::on_pbRename_clicked()
{
    Rename();
}

void Directorios::on_pushButton_clicked()
{
    EliminarDirRestantes();
}

QString Directorios::on_pbAdd_clicked()
{
    QString nombre = ui->lineNombre->text();
    ui->listWidget_2->addItem(nombre);
    //REFRESH();
    return nombre;
}

void Directorios::on_pbDelete_Direc_clicked()
{
    delete ui->listWidget_2->currentItem();
}

