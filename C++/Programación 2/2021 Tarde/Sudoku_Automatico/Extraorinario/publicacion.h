#include <iostream>
#include <vector>
#include <memory>
#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

using namespace std;

class publicacion
{
private:
    vector<shared_ptr<publicacion>>publicado;
public:
    publicacion();

    vector<shared_ptr<publicacion> > getPublicado() const;
    void setPublicado(const vector<shared_ptr<publicacion> > &value);
};

#endif // BIBLIOTECA_H
