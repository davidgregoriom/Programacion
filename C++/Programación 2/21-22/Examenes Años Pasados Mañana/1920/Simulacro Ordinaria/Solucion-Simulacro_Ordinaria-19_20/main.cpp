#include <iostream>
#include <vector>
#include <functional>
#include <memory>

using namespace std;

using std::vector;
using std::string;
using std::function;
using std::ostream;
using std::shared_ptr;
using std::make_shared;
using std::array;

template <class T>
class Lista{
public:
    Lista(){}
    ~Lista(){}
    void push_back(T const & d);
    void push_front(T const & d);
    void insert(T const & d, int pos);
    void erase(int pos);
    int findIndex( function< bool(T)> const & f);
    Lista<T> filter( function< bool(T)> const & f);
    void forEach(function< bool(T)> const & f);

    vector<T> getData() const;
    void setData(const vector<T> &value);
    T & at(int pos);

private:
    vector<T> data;
};



template <class T>
void Lista<T>::push_back(const T &d)
{
    data.push_back(d);
}

template<class T>
void Lista<T>::push_front(const T &d)
{
    data.insert(data.begin(),d);
}

template<class T>
void Lista<T>::insert(const T &d, int pos)
{
    if(pos >= data.size() || pos < 0) throw string{"Out of bounds"};
    data.insert(data.begin() + pos, d);
}

template<class T>
void Lista<T>::erase(int pos)
{
    if(pos >= data.size() || pos < 0) throw string{"Out of bounds"};
    data.erase(data.begin() + pos);
}

template<class T>
int Lista<T>::findIndex(const function<bool (T)> &f)
{
    for(uint i{0}; i < data.size(); i++){
        if(f(data.at(i))) return i;
    }

    return -1;
}

template<class T>
Lista<T> Lista<T>::filter(const function<bool (T)> &f)
{
    Lista<T> result;
    for(auto const & elem: data){
        if(f(elem)) result.push_back(elem);
    }

    return result;

}

template<class T>
void Lista<T>::forEach(const function<bool (T)> &f)
{
    for(auto const & elem: data){
        f(elem);
    }
}

template<class T>
vector<T> Lista<T>::getData() const
{
    return data;
}

template <class T>
void Lista<T>::setData(const vector<T> &value)
{
    data = value;
}

template<class T>
T &Lista<T>::at(int pos)
{
    if(pos >= data.size() || pos < 0) throw string{"Out of bounds"};
    return data.at(pos);
}

template <class T>
ostream & operator<<(ostream &os, Lista<T> p){
    auto data = p.getData();
    for(auto elem: data){
        os << elem << "  --  ";
    }
    return os;
}

class Persona{
public:
    Persona(string name, int age): name{name}, age{age}{}

    int getAge() const;
    void setAge(int value);

    string getName() const;
    void setName(const string &value);

private:
    int age;
    string name;
};

ostream & operator<<(ostream &os, shared_ptr<Persona> p){
    os << p->getName() << ": "<<  p->getAge();
    return os;
}

int main()
{

    try{
        Lista<shared_ptr<Persona> > personas;

        personas.push_back(make_shared<Persona>("Juan", 23));
        personas.push_back(make_shared<Persona>("Lucia", 22));
        personas.push_front(make_shared<Persona>("Antonio", 20));
        personas.push_front(make_shared<Persona>("Agueda", 19));

        std::cout << personas << "\n";

        // filter older than 21

        auto filtered = personas.filter([](shared_ptr<Persona> p){
                return p->getAge() > 21;
        });

        std::cout << filtered << "\n";

        // find, print and erase Lucia

        int index = personas.findIndex([](shared_ptr<Persona> p) {
                return p->getName() == "Lucia";
        });
        if(index != -1) std::cout << personas.at(index) << "\n";
        if(index != -1) personas.erase(index);

        std::cout << personas << "\n";

    }catch(string e){
        cout << e << "\n";
    }

    return 0;
}

int Persona::getAge() const
{
    return age;
}

void Persona::setAge(int value)
{
    age = value;
}

string Persona::getName() const
{
    return name;
}

void Persona::setName(const string &value)
{
    name = value;
}
