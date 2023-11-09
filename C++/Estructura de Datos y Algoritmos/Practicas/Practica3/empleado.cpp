#include "empleado.h"
using namespace std;
Empleado::Empleado(int id, bool is_boss)
{
    id = id_;
    is_boss = is_boss_;
}

int Empleado::get_id() const
{
    return id_;
}

bool Empleado::is_boss() const
{
    return (is_boss_ == 1);
}

bool Empleado::operator<(const Empleado &other) const
{
    return id_ < other.get_id();
}
bool Empleado::operator>(const Empleado& other) const{
    return id_ > other.get_id();
}
std::ostream& operator<<(std::ostream& os, const Empleado& empleado){
    os << empleado.id_ << empleado.is_boss_ << endl;
    return os;
}
