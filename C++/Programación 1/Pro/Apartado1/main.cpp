#include <iostream>
#include <vector>
#include <string.h>

struct vehiculo{
    std::string matricula;
    int nRuedas;
};

struct ticket{
    int minutos;
    int id;
    vehiculo vehiculo;
};

vehiculo moto1 = {"1234ABC",2};
vehiculo moto2 = {"4567ABC",2};
vehiculo coche1 = {"0123GNU",4};

ticket T1 = {60,1001,coche1};
ticket T2 = {30,1002,moto1};
ticket T3 = {10,1003,moto2};

ticket getTicket(){

    int id = 0;
    ticket ticketToReturn;

    std::cout << "Introduzca ID del ticket: ";
    std::cin >> id;

    switch (id){
        case 1001: ticketToReturn = T1; break;
        case 1002: ticketToReturn = T2;; break;
        case 1003: ticketToReturn = T3;; break;
        default: std::cout << "No existe esa Id";
    }
    return ticketToReturn;
}

void buscarCoche(){

    std::string matricula = "";
    vehiculo vehiculoElegido;

    std::cout << "Introduzca la matricula del coche: ";
    std::cin >> matricula;

    if (matricula == "1234ABC")
    {
        vehiculoElegido = moto1;
    }else if (matricula == "4567ABC")
    {
        vehiculoElegido = moto2;
    }else if (matricula == "0123GNU")
    {
        vehiculoElegido = coche1;
    }else
    {
        std::cout << "No existe ese coche" << std::endl;
        return;
    }

    std::cout << "Matricula: " << vehiculoElegido.matricula << std::endl;
    std::cout << "Ruedas: " << vehiculoElegido.nRuedas << std::endl;
}

void printRegistros(std::vector<ticket> registros){

    for(auto ticket : registros){

        std::cout << "Tiempo: " << ticket.minutos << " Minutos" << std::endl;
        std::cout << "Id: " << ticket.id << std::endl;
        std::cout << "Matricula: " << ticket.vehiculo.matricula << std::endl;
        std::cout << "Ruedas: " << ticket.vehiculo.nRuedas << std::endl;
    }
}

int main(int argc, char const *argv[])
{

    int option = 0;
    std::vector<ticket> registros;

    do
    {
        std::cout << "0.- Salir del programa" << std::endl;
        std::cout << "1.- Registrar Ticket" << std::endl;
        std::cout << "2.- Buscar coche" << std::endl;
        std::cout << "3.- Listar vehículos aparcados" << std::endl;

        std::cin >> option;

        switch(option){
            case 1: registros.push_back(getTicket()); break;
            case 2: buscarCoche(); break;
            case 3: printRegistros(registros); break;
        }

    } while (option != 0);

    return 0;
}

