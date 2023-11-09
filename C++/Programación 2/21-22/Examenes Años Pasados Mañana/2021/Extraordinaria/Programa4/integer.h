#ifndef INTEGER_H
#define INTEGER_H
#include <string>
#include <vector>
#include <iostream>

using namespace std;


class integer
{
public:
    integer();
    integer(const int &_numero);
    int getNumero() const;
    void setNumero(const int  &value);
    vector<int> getFactors( int &numero) const ;
    bool isPrime(const int & numero) const;

private:
    int numero;
};

integer operator* (integer const & n1, integer const & n2);
integer operator/ (integer const & n1, integer const & n2);

#endif // INTEGER_H
