#include <iostream>
#include <memory>
#include <string>
#include <vector>


using namespace std;

class Trabajador{
private:
    int IDempleado,horas;
    string Nombre;
public:
    Trabajador(){IDempleado=0;horas=0;}
    Trabajador(const int &ID,const string &nom){
        IDempleado=ID;
        Nombre=nom;
        horas=0;
    }
    virtual ~Trabajador(){}

    virtual string WhoAmI() const =0;

    int getIDempleado() const{return IDempleado;}
    string getNombre() const {return Nombre;}

    void setHorasRealizadas(const int & horas){this->horas=horas;}
    int getHorasRealizadas(void)const {return horas;}
};
class Becario:public Trabajador{
private:
    string NombreResponsable;
public:
    Becario():Trabajador(){}
    Becario(const string &nom,const int &id,const string & jefe):Trabajador(id,nom){
        NombreResponsable=jefe;
    }
    string WhoAmI() const {
        return ("Becario");
    }
    string getResponable()const {return NombreResponsable;}
};
class Empleado:public Trabajador{
private:
    string NombreResponsable;
    shared_ptr<Becario>BecarioAsignado;
public:
    Empleado():Trabajador(){}
    Empleado(const string & nom, const int & id, const string & jefe):Trabajador(id,nom){
        NombreResponsable=jefe;
    }
    string WhoAmI() const{
        return("Empleado");
    }

    void setBecario(const shared_ptr<Becario> & bec){BecarioAsignado=bec;}
    shared_ptr<Becario>getBecario(void){return BecarioAsignado;}
    string getResponsable() const {return NombreResponsable;}
};
class ResponsableArea:public Trabajador{
private:
    vector<shared_ptr<Empleado>>Equipo;
    string NombreProyecto;
    int HorasProyecto;
public:
    ResponsableArea():Trabajador(){HorasProyecto=0;}
    ResponsableArea(const string &nom,const int & id,const string &proyecto):Trabajador(id,nom){
        NombreProyecto=proyecto;
        HorasProyecto=0;
    }
    ResponsableArea(const string &nom,const int &id,const string &proyecto,vector<shared_ptr<Empleado>>&eq):Trabajador(id,nom){
        NombreProyecto=proyecto;
        Equipo=eq;
        HorasProyecto=0;
    }
    void setProyecto(const string &nom){NombreProyecto=nom;}
    string getProyecto(void)const{return NombreProyecto;}
    void setEquipo(const vector<shared_ptr<Empleado>>&eq){Equipo=eq;}
    vector<shared_ptr<Empleado>>getEquipo()const {return Equipo;}

    string WhoAmI() const{
        return ("Responsable");
    }

    int CalculoHoras(){
        int horasEquipo{0};
        for(auto elem:Equipo){
            horasEquipo+=elem->getHorasRealizadas();
        }
        horasEquipo+=this->getHorasRealizadas();
        if(horasEquipo>HorasProyecto){
            throw string {"se enfada"};
        }
        return horasEquipo;
    }


};

ostream &operator <<(ostream &os,shared_ptr<Trabajador> & tra){
    os<<tra->getNombre()<<tra->getIDempleado()<<tra->WhoAmI()<<endl;
    if(tra->WhoAmI()=="Becario"){
        Becario*b=dynamic_cast<Becario*>(tra.get());
        if(b!=nullptr){
            os<<b->getResponable()<<endl;
        }
    }else if(tra->WhoAmI()=="Empleado"){
        Empleado*e=dynamic_cast<Empleado*>(tra.get());
        if(e!=nullptr){
            os<<e->getBecario()<<e->getResponsable()<<endl;
        }
    }else if(tra->WhoAmI()=="Responsable"){
        ResponsableArea*r=dynamic_cast<ResponsableArea*>(tra.get());
        if(r!=nullptr){
            os<<r->getProyecto()<<r->getHorasRealizadas()<<endl;
            for(auto elem:r->getEquipo()){
                os<<elem->getNombre()<<endl;
            }
        }
    }else{
        os<<"Error"<<endl;
    }
    return os;
}
shared_ptr<Empleado>CrearEmpleado(const string &nombre,int ID,const string & jefe){
    shared_ptr<Empleado> empleado= make_shared<Empleado>(nombre,ID,jefe);
    return empleado;
}
shared_ptr<Becario>CrearBecario(const string &nombre,int ID,const string & jefe){
    shared_ptr<Becario> becario=make_shared<Becario>(nombre,ID,jefe);
    return becario;
}
shared_ptr<ResponsableArea>CrearResponsable(const string & nombre,int ID,const string & proyecto){
    shared_ptr<ResponsableArea>responsable=make_shared<ResponsableArea>(nombre,ID,proyecto);
    return responsable;
}

int main()
{
    int opcion{-1},encontrado{0};
       std::string nombreTrabajador;
       std::string nombreResp;
       std::string nombreProyecto;
       int IDtrabajador;
       int nPersonas{0};
       std::vector<std::shared_ptr<Empleado>> equipo;

       //Contenedor para almacenar punteros
       //En un vector de punteros a Trabajado guardaremos becarios, empleados y responsables
       vector<shared_ptr<Trabajador>> Plantilla;

       while(opcion!=0)
       {
           cout << "Que opcion quieres?\n 1:Ingresa becario\n 2:Ingresa empleado\n 3:Ingresa responsable\n 4:Crea equipo\n 5:Buscar trabajador\n 0:Salir\n " << endl;
           cin>>opcion;cin.ignore();

           switch(opcion)
           {
           case 0:
               cout<<"terminando..."<<endl;
               break;
           case 1: //Registramos becario
               cout<<"\nIntroduce nombre: ";

               getline(cin,nombreTrabajador); //Ojo que cin con los espacios se lleva mal.... :)
               cout<<"\nIntroduce ID trabajador: ";
               cin>>IDtrabajador;cin.ignore();  //Entre cin y getline usamos cin.ignore()

               cout<<"\nIntroduce nombre del jefe: ";
               getline(cin,nombreResp);

               //Plantilla es vector de trabajadores y almacenamos un becario
               Plantilla.push_back(CrearBecario(nombreTrabajador,IDtrabajador,nombreResp));
               break;
           case 2: //Registramos empleado
               cout<<"\nIntroduce nombre: ";

               getline(cin,nombreTrabajador);
               cout<<"\nIntroduce ID trabajador: ";
               cin>>IDtrabajador;cin.ignore();

               cout<<"\nIntroduce nombre del jefe: ";
               getline(cin,nombreResp);

               //Plantilla es vector de trabajadores y almacenamos un empleado
               Plantilla.push_back(CrearEmpleado(nombreTrabajador,IDtrabajador,nombreResp));
               break;
           case 3: //Registramos responsable
               cout<<"\nIntroduce nombre: ";

               getline(cin,nombreTrabajador);
               cout<<"\nIntroduce ID trabajador: ";
               cin>>IDtrabajador;cin.ignore();

               cout<<"\nIntroduce nombre del proyecto: ";
               getline(cin,nombreProyecto);

               //Plantilla es vector de trabajadores y almacenamos un responsable
               Plantilla.push_back(CrearResponsable(nombreTrabajador,IDtrabajador,nombreProyecto));
               break;
           case 4://Creamos equipo para asignar a Responsable
               cout<<"cuantas personas van a formar el equipo?"<<endl;
               cin>>nPersonas;cin.ignore();

               //Buscamos en plantilla a la persona
               while(nPersonas>0)
               {
                   cout<<"\nNombre integrante equipo?:";
                   getline(cin,nombreTrabajador);
                   if(nombreTrabajador.size()==0)
                   {
                       break;
                   }

                   for(unsigned int i{0};i<Plantilla.size();i++)
                   {//vector.size() devuelve un unsigned int. Si declaramos i como ese tipo quitaremos el warning
                       if(Plantilla.at(i)->getNombre()==nombreTrabajador && Plantilla.at(i)->WhoAmI() == "Empleado")
                       {//Si el nombre coincide y es empleado lo aÃ±adimos al equipo
                           //Equipo es un vector de punteros a empleados, no admite otro rol
                           cout<<"Encontrado!"<<endl;
                           //Empleado *e = dynamic_cast<Empleado*>(Plantilla.at(i).get());
                           //Para poder aÃ±adirlo al vector tenemos que hacerlo puntero shared a empleado
                           //equipo.push_back(make_shared<Empleado>(*e));

                           //O usamos dynamic_pointer_cast que devuelve un puntero inteligente
                           auto emplInteligente=dynamic_pointer_cast<Empleado>(Plantilla.at(i));
                           equipo.push_back(emplInteligente);

                           nombreTrabajador.clear();
                           nPersonas--;
                           break;
                       }
                   }
               }
               //Este bucle tiene un problema...
               //
               //
               //Â¿Â¿QuÃ© pasa si no hay suficientes empleados para llenar el equipo??


               cout<<"\nA que responsable le asignas el equipo?:";
               getline(cin,nombreTrabajador);

               for(unsigned int i{0};i<Plantilla.size();i++)
               {//Recorremos la plantilla
                   if(Plantilla.at(i)->getNombre()==nombreTrabajador && Plantilla.at(i)->WhoAmI() == "Responsable")
                   {//Buscando el nombre del resposable al que vamos a asignar el equipo
                       cout<<"Responsable encontrado!"<<endl;
                       //Para usar el setEquipo tenemos que hacer downcasting para poder acceder
                       //desde la clase base a la clase derivada
                       ResponsableArea *r = dynamic_cast<ResponsableArea*>(Plantilla.at(i).get());
                       r->setEquipo(equipo);

                       equipo.clear();
                       nombreTrabajador.clear();
                       break;
                   }
               }

               break;
           case 5: //Buscar persona
               cout<<"\nA quien buscas?:";
               getline(cin,nombreTrabajador);

               for(auto elem: Plantilla)
               {//Recorremos Plantilla
                   if(elem->getNombre() == nombreTrabajador)
                   {//Buscando el nombre indicado
                       //No hace falta downcasting porque Trabajador tiene getNombre()
                       cout<<"Trabajador "<<nombreTrabajador<<" encontrado\n"<<elem<<endl;
                       encontrado = 1;
                   }
               }

               if(encontrado==1)
               {
                   encontrado=0;
               }
               else
               {
                   std::cout<<"No he encontrado a "<<nombreTrabajador<<std::endl;
               }

               break;
           default:
               cout<<"Opcion no contemplada."<<endl;
           }
       }
       return 0;
   }
