#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "cliente.h"
#include "acerca.h"
#include "listaclientes.h"
#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QDataStream>>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_bttnClientes_clicked();

    void on_bttnGuardar_clicked();

    void on_actionAcerca_de_triggered();

private:
    QString currentFilePath;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
