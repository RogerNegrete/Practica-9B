#include "listaclientes.h"
#include "ui_listaclientes.h"

ListaClientes::ListaClientes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListaClientes)
{
    ui->setupUi(this);

}

ListaClientes::~ListaClientes()
{
    delete ui;
}


void ListaClientes::mostrarClientes()
{
    QString filePath=QFileDialog::getOpenFileName(this, tr("Abrir Archivo"), QDir::homePath(), "Dat Files (*.dat)");

    if (filePath.isEmpty()) {
        return;
    }

    QFile file(filePath);
       if (!file.open(QIODevice::ReadOnly)) {
           QMessageBox::critical(this, tr("Error"), tr("No se pudo abrir el archivo"));
           return;
       }

       QDataStream in(&file);

       ui->listWidget->clear();

       while (!in.atEnd()) {

           QString cedula, nombre, apellido, direccion, telefono, email;
           in >> cedula >> nombre >> apellido>> direccion >> telefono >>email;

           QString clienteInfo = cedula + ", " +nombre + ", " + apellido + ", " + direccion + ", " + telefono + ", " + email ;

           ui->listWidget->addItem(clienteInfo);
       }
       file.close();
}

