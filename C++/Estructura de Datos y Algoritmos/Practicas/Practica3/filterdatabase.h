#ifndef FILTERDATABASE_H
#define FILTERDATABASE_H
#include "binarysearchtree.h"


class FilterDatabase
{
public:
    FilterDatabase();
    void filter_database(const BinarySearchTree& all, BinarySearchTree& employees, BinarySearchTree& managers);
private:
    const BinarySearchTree& all;
    BinarySearchTree& employees;
    BinarySearchTree& managers;
};

#endif // FILTERDATABASE_H

