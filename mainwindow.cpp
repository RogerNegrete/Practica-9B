#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Conectar el botón "Guardar" a la función de guardar
    connect(ui->bttnGuardar, SIGNAL(clicked()), this, SLOT(on_actionGuardar_triggered()));

    // Conectar el botón "Clientes" a la función que maneja su evento
    connect(ui->bttnClientes, SIGNAL(clicked()), this, SLOT(on_bttnclientes_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    // Obtener texto del lineEdit
    QString campoTexto = ui->textCampoDatos->toPlainText();

    // Crear cliente a partir de texto
    Cliente cliente(campoTexto.toStdString());
    if (!cliente.validarCedula()) {
        QMessageBox::information(this, "Error", "La cédula no es válida.");
        return;
    }
    // Actualizar campos de la UI con datos del cliente
    ui->textCedula->setText(QString::fromStdString(cliente.getCedula()));
    ui->textNames->setText(QString::fromStdString(cliente.getName()));
    ui->textLastname->setText(QString::fromStdString(cliente.getLastName()));
    ui->textDireccion->setText(QString::fromStdString(cliente.getDireccion()));
    ui->textTelefono->setText(QString::fromStdString(cliente.getTelefono()));
    ui->textEmail->setText(QString::fromStdString(cliente.getEmail()));
}


void MainWindow::on_bttnClientes_clicked()
{

    ListaClientes dialog;
    dialog.mostrarClientes();
    dialog.exec();
}


void MainWindow::on_bttnGuardar_clicked()
{

    QString fileName;
    if (!currentFilePath.isEmpty())
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, tr("Guardar"), tr("¿Desea guardar en el mismo archivo?"),
                                      QMessageBox::Yes|QMessageBox::No);

        if (reply == QMessageBox::Yes)
        {
            fileName = currentFilePath;
        }
        else
        {
            fileName = QFileDialog::getSaveFileName(nullptr, tr("Guardar Archivo"), QDir::homePath(), "DAT files (*.dat)");
            fileName += ".dat";
            currentFilePath = fileName;
        }
    }
    else
    {
        fileName = QFileDialog::getSaveFileName(nullptr, tr("Guardar Archivo"), QDir::homePath(), "DAT files (*.dat)");
        fileName += ".dat";
        currentFilePath = fileName;
    }

    QFile file(fileName);
    if (!file.open(QIODevice::Append | QIODevice::Text))
    {
        QMessageBox::critical(this, tr("Error"), tr("No se pudo abrir el archivo"));
        return;
    }

    QDataStream out(&file);



    QString cedula =ui->textCedula->toPlainText();
    QString nombre = ui->textNames->toPlainText();
    QString apellido = ui->textLastname->toPlainText();
    QString direccion = ui->textDireccion->toPlainText();
    QString telefono = ui->textTelefono->toPlainText();
    QString email =ui->textEmail->toPlainText();

    out <<cedula << nombre << apellido << direccion << telefono <<email;
    file.close();

    QMessageBox::information(this, tr("Mensaje"), tr("Guardado con exito"));
}


void MainWindow::on_actionAcerca_de_triggered()
{
    Acerca ventana;
    ventana.exec();
}

