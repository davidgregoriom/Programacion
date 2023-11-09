#ifndef COMPLETO_H
#define COMPLETO_H
#include <vector>
using namespace std;


class Complejo
{
public:
    Complejo(float a, float b,vector<float> vectorcompl);

    float getA() const;
    void setA(float value);

    float getB() const;
    void setB(float value);

    vector<float> getVectorcompl() const;
    void setVectorcompl(const vector<float> &value);

private:
    float a;
    float b;
    vector<float>vectorcompl;
};

#endif // COMPLETO_H
