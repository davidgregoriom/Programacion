#include <iostream>
#include <memory>
#include <vector>

using namespace std;


/***************************
 * DeclaraciÃ³n de la clase *
 * ************************/
class NumeroPositivo
{
    private:
        float num;
    public:
        //Constructores
        NumeroPositivo();
        NumeroPositivo(float num);

        //Metodos
        float DividePor(float);
        float MultiplicaPor(float);
        float SumaA(float);

        //Getters/Setters
        float getNum() const;
        void setNum(float value);
};

//Funciones
float PedirOtroNum(void)
{
    float numero;

    std::cout<<"Introduce segundo numero: ";
    std::cin>>numero; std::cout<<std::endl;

    return numero;
}

int main()
{
    float temp=0;
    int t=0,aux=0;
    NumeroPositivo MiNumero;

    while(aux==0)
    {
    std::cout<<"Con que numero quieres empezar a operar?: ";
    std::cin>>temp; std::cout<<std::endl;

        try{
            MiNumero.setNum(temp);
        }
        catch (std::string s) {
            std::cout<<"Excepcion capturada: "<<s<<std::endl;
            continue;
        }
        std::cout<<"Numero positivo almacenado. Continuamos..."<<std::endl;
        aux=1; //Para salir del bucle
    }

    std::cout<<"Que operacion deseas realizar? ( S[0]; M[1]; D[2] ): ";
    std::cin>>t; std::cout<<std::endl;

    switch(t)
    {
        case 0://Sumamos
            std::cout<<MiNumero.SumaA(PedirOtroNum())<<std::endl;
        break;
        case 1://Multiplcamos
            std::cout<<MiNumero.MultiplicaPor(PedirOtroNum())<<std::endl;
        break;
        case 2://dividimos
            try{
                std::cout<<MiNumero.DividePor(PedirOtroNum())<<std::endl;
            }catch(string){
                std::cout<<"Excepcion atrapada. Division por cero."<<std::endl;
            }
        break;
        default:
            std::cout<<"Opcion no permitida"<<std::endl;

    }

    return 0;
}

//*************************************
//DefiniciÃ³n de los mÃ©todos de la clase
//*************************************

NumeroPositivo::NumeroPositivo()
{
    num=0;
}

NumeroPositivo::NumeroPositivo(float n)
{
     setNum(num); //Utilizamos el setter porque tenemos implementar un control de nÃºmero positivo
}

float NumeroPositivo::DividePor(float n2)
{
    if(n2==0)
    {
        throw string{"Division por 0"}; //Una vez que se lanza no se continua ejecutando lo de debajo...
    }

    this->num=this->num/n2; //Actualizamos el valor encapsulado

    return num/n2;
}

float NumeroPositivo::MultiplicaPor(float n2)
{
    this->num=n2*num; //Actualizamos el valor encapsulado

    return this->num;
}

float NumeroPositivo::SumaA(float n2)
{
    this->num+=n2;

    return this->num;
}

float NumeroPositivo::getNum() const
{
    return num;
}

void NumeroPositivo::setNum(float num)
{
    //Como el enunciado pide que la clase sea NÃºmero positivo lo controlamos
    if(num<0){
        throw string{"Debe ser Positivo"}; //Si el nÃºmero es negativo lanzamos una excepciÃ³n para "avisar del problema"
    }
    else{//Si es positivo lo almacenamos en la varable encapsulada
        this->num=num; //this es el puntero implicito de la clase. Un puntero que apunta a uno mismo
                        //this->num es la variable encapsulada dentro del objeto
                        //num es el parÃ¡metro de entrada de setNum
    }
}
