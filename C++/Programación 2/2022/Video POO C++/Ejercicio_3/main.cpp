#include <iostream>

using namespace std;
class Tablero{
public:
    Tablero(const int & x,const int &y){
        this->x=x;
        this->y=y;
    }
    void moverArriba(int &n){
        if(n!=0){
            y+=n;
        }
    }
    void moverAbajo(int &n){
        if(n!=0){
            y-=n;
        }
    }
    void moverIzquierda(int &n){
        if(n!=0){
            x-=n;
        }
    }
    void moverDerecha(int &n){
        if(n!=0){
            x+=n;
        }
    }
    int getX() const{
        return x;
    }

    int getY() const{
        return y;
    }

private:
    int x,y;
};

int menu()
{
    int op{0};
    std::cout<<"1.MoverArriba"<<std::endl;
    std::cout<<"2.MoverAbajo"<<std::endl;
    std::cout<<"3.MoverIzquierda"<<std::endl;
    std::cout<<"4.MoverDerecha"<<std::endl;
    std::cout<<"Que quieres hacer?: ";
    std::cin>>op;cin.ignore();

    if(op>0 && op<5)
    {
        return op;
    }
    else
    {
        return -1;
    }
}

int main()
{
    Tablero* ob1;
    int x,y,opcion=0,n;
    bool continuar=true;
    cout << "Dime la posicion:" << endl;
    cin>>x>>y;
    ob1=new Tablero(x,y);

    while(continuar){
        opcion=menu();
        switch (opcion) {
        case 1:
            cout << "Arriba cuanto?: "<< endl;
            cin>>n;
            ob1->moverArriba(n);
            cout << ob1->getY()<< endl;
            break;
        case 2:
            cout << "Abajo cuanto?: "<< endl;
            cin>>n;
            ob1->moverAbajo(n);
            cout << ob1->getY()<< endl;
            break;
        case 3:
            cout << "Izquierda cuanto?: "<< endl;
            cin>>n;
            ob1->moverIzquierda(n);
            cout << ob1->getX()<< endl;
            break;
        case 4:
            cout << "Derecha cuanto?: "<< endl;
            cin>>n;
            ob1->moverDerecha(n);
            cout << ob1->getX()<< endl;
            break;
        default:
        cout<<"elige otra opcion "<< endl;
        }
        cout <<"¿Continuar?:[0->NO; 1->SI]";
        cin >>continuar;cin.ignore();
    }
    cout << "las posiciones finales son en x: "<< ob1->getX()<< endl << "Y en y: "<< ob1->getY()<< endl;

    delete ob1;
}




