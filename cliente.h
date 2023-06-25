#ifndef CLIENTE_H
#define CLIENTE_H
#include <string>
#include <QStringList>
using namespace std;
class Cliente//: public MAINWINDOW_H
{
private:
    string cedula;
    string name;
    string lastName;
    string direccion;
    string telefono;
    string email;

public:
    Cliente();
    Cliente(const string &textoCompleto);
    void procesoInformacion(const string &textoCompleto);
    string getCedula() const;
    void setCedula(string newCedula);
    string getName() const;
    void setName(const string &newName);
    string getLastName() const;
    void setLastName(const string &newLastName);
    string getDireccion() const;
    void setDireccion(const string &newDireccion);
    string getTelefono() const;
    void setTelefono(string newTelefono);
    string getEmail() const;
    void setEmail(const string &newEmail);
    bool validarCedula();
};

#endif // CLIENTE_H
