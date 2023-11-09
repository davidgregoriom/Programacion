#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <functional>
#include "elementolistadoble.h"

using namespace std;
class Empleado {
    public:

bool is_boss() const;

    void filter_database(const BinarySearchTree& all, BinarySearchTree& employees, BinarySearchTree& managers);
     bool operator<(const Empleado& other) const;
     bool operator>(const Empleado& other) const;
     bool operator==(const Empleado& other) const;
     friend std::ostream& operator<<(std::ostream& os, const Empleado& empleado);
 private:
     int id_;

     };
#endif // LINKEDLIST_H
