#include <iostream>

using namespace std;

class Person{
public:
    Person(string _name, unsigned short int _age, unsigned short int _weight ){
        setName(_name);
        setAge(_age);
        setWeight(_weight);
    }

    string getName() const{
        return name;
    }

    unsigned short int getAge() const{
        return age;
    }

    unsigned short int getWeight() const{
        return weight;
    }

    void setName(string const & _name){
        name = _name;
    }

    void setAge(unsigned short int _age){
        if (_age > 150){
            cout << "There must be a mistake, your age cannot be " << _age
                 << " . I'll set your age to 0"
                 << endl;
            age = 0;
        }else{
            age = _age;
        }
    }

    void setWeight(unsigned short int _weight){
        if (_weight > 200){
            cout << "There must be a mistake, your weight cannot be more than " << _weight
                 << " . I'll set your weight to 0"
                 << endl;
            weight = 0;
        }else{
            weight = _weight;
        }
    }

private:
    string name;
    unsigned short int age;
    unsigned short int weight;
};

int main()
{
    Person me("Alberto", 75, 17);
    cout << "Hello " << me.getName() << ", you are " << me.getAge() << ", you weight "  << me.getWeight() << " kg." << endl;

    me.setAge(78);
    cout << "Hello " << me.getName() << ", today you are " << me.getAge() << endl;

    return 0;
}
