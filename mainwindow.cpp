#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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

