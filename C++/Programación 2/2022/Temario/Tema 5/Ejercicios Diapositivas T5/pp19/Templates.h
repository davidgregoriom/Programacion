#ifndef TEMPLATES_H
#define TEMPLATES_H

#include<vector>

template<typename T>
T sumar(T const &a, T const &b)
{
    return a+b;
}
//Particularizamos el template
template<>
std::vector<std::vector<double>> sumar(std::vector<std::vector<double>> const &a, std::vector<std::vector<double>> const &b)
{
    std::vector<double> aux;
    std::vector<std::vector<double>> res;
    int k=a.size();
    int m=b.size();
    int n=b.at(0).size();
    int l=a.at(0).size();

    if(k==m && n==l)
    {
        aux.resize(l);
        for(int i=0;i<k;i++)
        {
            res.push_back(aux);
        }

        for(int f=0;f<l;f++)
        {
            for(int c=0;c<k;c++)
            {
                res[f][c]=a[f][c]+b[f][c];
            }
        }
        return res;
    }
    else
    {
        throw "Error dimension";
    }
}

template<typename T>
T restar(T const &a, T const &b)
{
    return a-b;
}
//Particularizamos el template
template<>
std::vector<std::vector<double>> restar(std::vector<std::vector<double>> const &a, std::vector<std::vector<double>> const &b)
{
    std::vector<double> aux;
    std::vector<std::vector<double>> res;
    int k=a.size();
    int m=b.size();
    int n=b.at(0).size();
    int l=a.at(0).size();

    if(k==m && n==l)
    {
        aux.resize(l);
        for(int i=0;i<k;i++)
        {
            res.push_back(aux);
        }

        for(int f=0;f<l;f++)
        {
            for(int c=0;c<k;c++)
            {
                res[f][c]=a[f][c]-b[f][c];
            }
        }
        return res;
    }
    else
    {
        throw "Error dimension";
    }
}

template<typename T>
T multiplicar(T const &a, T const &b)
{
    return a*b;
}

//Particularizamos el template
/*template<>
std::vector<std::vector<double>> multiplicar(std::vector<std::vector<double>> const &a, std::vector<std::vector<double>> const &b)
{
    std::vector<double> aux;
    std::vector<std::vector<double>> res;
    int k=a.size();
    int m=b.size();
    int n=b.at(0).size();

    aux.resize(m);
    for(int i=0;i<m;i++)
    {
        res.push_back(aux);
    }


    for(int i=0; i<k; ++i)
    {
            for(int j=0; j<n; ++j)
            {
                for(int z=0; z<m; ++z)
                {
                    res.at(i).at(j) += a.at(i).at(z) * b.at(z).at(j);
                }
            }
    }

    return res;
}*/

//Sobrecarga * para matrices
std::vector<std::vector<double>> operator*(std::vector<std::vector<double>> const &a, std::vector<std::vector<double>> const &b)
{
    std::vector<double> aux;
    std::vector<std::vector<double>> res;
    int k=a.size();
    int m=b.size();
    int n=b.at(0).size();

    aux.resize(m);
    for(int i=0;i<m;i++)
    {
        res.push_back(aux);
    }

    for(int i=0; i<k; ++i)
    {
            for(int j=0; j<n; ++j)
            {
                for(int z=0; z<m; ++z)
                {
                    res.at(i).at(j) += a.at(i).at(z) * b.at(z).at(j);
                }
            }
    }

    return res;
}

#endif // TEMPLATES_H

