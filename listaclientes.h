#ifndef LISTACLIENTES_H
#define LISTACLIENTES_H

#include <QDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QDataStream>

namespace Ui {
class ListaClientes;
}

class ListaClientes : public QDialog
{
    Q_OBJECT

public:
    explicit ListaClientes(QWidget *parent = nullptr);
    ~ListaClientes();
    QString filepath;
    void mostrarClientes();

private:
    Ui::ListaClientes *ui;

};

#endif // LISTACLIENTES_H
