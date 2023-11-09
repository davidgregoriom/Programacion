#include <array>
#include <cmath>
​
int main()
{
    std::array<double,20> serie;

    //Asignamos los primeros valores de la serie que nos da el enunciado
    serie.at(0)=1;
    serie.at(1)=1;
    serie.at(2)=2;

    //Calculamos los 20 primeros valores de la serie
    for(int i=3;i<serie.size();i++)
    {//Como tenemos los 3 primeros empezamos en 3 hasta el tamaño del array
        serie.at(i)=pow(-1,i)*serie.at(i-1)+serie.at(i-2)-1/serie.at(i-3);
    }

    //Mostroamos por pantalla la serie
    for(double elem:serie)
    {
        std::cout<<elem<<std::endl;
    }

    //Calculamos la suma acumulada de los valores de la serie
    double acum{0};
    for(double elem:serie)
    {//Recorremos el array y vamos sumando
        acum=acum+elem;
    }
    std::cout<<"La suma acumulada es: "<<acum<<std::endl;

    //Mostramos la media de los 20 valores de la serie
    std::cout<<"La media es: "<<acum/serie.size()<<std::endl;

    return 0;
}
