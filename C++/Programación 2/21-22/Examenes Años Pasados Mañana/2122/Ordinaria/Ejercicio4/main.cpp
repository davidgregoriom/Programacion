#include <iostream>
#include <memory>
#include <vector>

using namespace std;
class Persona
{
private:
    int birthdate;
    string name;
    string job;
public:
    Persona(int b, string const & n, string const & job):job{job}{
        setBirthdate(b);
        setName(n);
    }

    Persona(Persona const & other){
        setBirthdate(other.birthdate);
        setName(other.name);
    }

    ~Persona(){
        std::cout << name << " ha muerto";
    }

    int getBirthdate() const{
        return birthdate;
    }
    void setBirthdate(int newBirthdate){
        if(newBirthdate <= 1900) throw string{"year must be greater than 1900"};
        birthdate = newBirthdate;
    }

    const string &getName() const{
        return name;
    }
    void setName(const string &newName){
        name = newName;
    }

    const string &getJob() const{
        return job;
    }

};
class Bombero : public Persona
{
public:
    Bombero(float b, int f, string const & n, int birth):Persona{birth,n,"bombero"}{
        setBiceps(b);
        setFires(f);
    }

    float getBiceps() const{
        return biceps;
    }
    void setBiceps(float newBiceps){
        if(newBiceps<=0) throw string{"wrong biceps"};
        newBiceps=biceps;
    }

    int getFires() const{
        return fires;
    }
    void setFires(int newFires){
        if(fires<=0) throw string("wrong fires");
        newFires=fires;
    }

private:
    float biceps;
    int fires;
};
class Futbolista : public Persona
{
public:
    Futbolista(int m, int g, int b, const string &n):Persona{b,n,"futbolista"}{
        setMillones(m);
        setGoles(g);
    }

    int getGoles() const{
        return goles;
    }
    void setGoles(int newGoles){
        if(goles<0)throw string {"no puede pasar"};
        goles = newGoles;
    }

    int getMillones() const{
        return millones;
    }
    void setMillones(int newMillones){
        if(millones<0)throw string{"imposible"};
        millones=newMillones;
    }

private:
    int goles;
    int millones;
};

int main()
{
    vector<shared_ptr<Persona>>personas;
    personas.push_back(make_shared<Futbolista>(10,21,1978,"Pedro"));
    personas.push_back(make_shared<Bombero>(12,32,"Luis",1967));

    for(auto p:personas){
        if(p->getJob()=="bombero"){
            auto aux=static_pointer_cast<Bombero>(p);
            cout << aux->getBiceps()<<endl;
        }
        if(p->getJob()=="futbolista"){
            auto aux=static_pointer_cast<Futbolista>(p);
            cout<<aux->getMillones()<<endl;

        }
    }
    return 0;
}
