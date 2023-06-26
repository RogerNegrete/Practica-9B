#include "cliente.h"


Cliente::Cliente(const string &textoCompleto) {
   procesoInformacion(textoCompleto);
}


string Cliente::getCedula() const
{
    return cedula;
}

void Cliente::setCedula(string newCedula)
{
    cedula = newCedula;
}

string Cliente::getName() const
{
    return name;
}

void Cliente::setName(const string &newName)
{
    name = newName;
}

string Cliente::getLastName() const
{
    return lastName;
}

void Cliente::setLastName(const string &newLastName)
{
    lastName = newLastName;
}

string Cliente::getDireccion() const
{
    return direccion;
}

void Cliente::setDireccion(const string &newDireccion)
{
    direccion = newDireccion;
}

string Cliente::getTelefono() const
{
    return telefono;
}

void Cliente::setTelefono(string newTelefono)
{
    telefono = newTelefono;
}

string Cliente::getEmail() const
{
    return email;
}

void Cliente::setEmail(const string &newEmail)
{
    email = newEmail;
}
void Cliente::procesoInformacion(const string &textoCompleto) {
    // Divido textoCompleto en lineas
    QStringList lineas = QString::fromStdString(textoCompleto).split("\n");
    //Iterar sobre cada línea
    for (const QString &linea : lineas) {
        //Sirve para que el valor que este me tome si esta unido asi ":" oa si ": "
        //Me separa en 2 campos Nombres y Apellidos
        QRegExp regExp("[:][ ]?");
        QStringList campos = linea.split(regExp);

        if (campos.size() == 2) {
            string label = campos[0].trimmed().toStdString();
            string value = campos[1].trimmed().toStdString();

            // Es un condicional para que por si acaso me coloque diferente el formulario igual me toma los datos
            if (label == "Nombre completo"||label == "Nombres") {
                QStringList nombreCompleto = campos[1].split(" ");
                setName(nombreCompleto[0].trimmed().toStdString() + " " + nombreCompleto[1].trimmed().toStdString());
                setLastName(nombreCompleto[2].trimmed().toStdString() + " " + nombreCompleto[3].trimmed().toStdString());
            } else if (label == "Cédula"||label == "Cedula") {
                setCedula(value);
            } else if (label == "Dirección"||label == "Direccion") {
                setDireccion(value);
            } else if (label == "Teléfono"||label == "Telefono") {
                setTelefono(value);
            } else if (label == "Correo electrónico"||label == "Correo electronico"||label == "Email") {
                setEmail(value);
            }
        }
    }
}
bool Cliente::validarCedula() {
    // Verificar que la cédula tenga 10 dígitos
    if (cedula.length() != 10) {
        return false;
    }

    // Verificar que los dos primeros dígitos sean válidos (01-24)
    int provincia = stoi(cedula.substr(0, 2));
    if(provincia < 1 || provincia > 24){
        return false;
    }

    // Verificar que el tercer dígito sea menor a 6
    int tipo = stoi(cedula.substr(2, 1));
    if(tipo >= 6){
        return false;
    }

    // Algoritmo de Luhn modificado para la validación
    int total = 0;
    int tam = cedula.size();
    int residuo = 0;
    int verificador = 0;
    int digito = 0;

    for(int i=0; i<tam-1; i++){
        digito = stoi(cedula.substr(i, 1));

        if(i%2==0){
            digito = digito * 2;
            if(digito > 9){
                digito = digito - 9;
            }
        }

        total = total + digito;
    }

    residuo = total % 10;
    if(residuo == 0){
        verificador = 0;
    }else{
        verificador = 10 - residuo;
    }

    // Verificar si el último dígito es igual al verificador
    if(verificador == stoi(cedula.substr(tam-1, 1))){
        return true;
    }

    return false;
}
