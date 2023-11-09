 #include "printer.h"
#include "printjob.h"
#include "iostream"


using namespace std;

Printer::Printer(int maxNumJobs, int maxNumPages){
    maxNumJobs = _maxNumJobs;
    maxNumPages = _maxNumPages;
}

int Printer::queueLength() const
{
   return v1.size();
}

int Printer::queuePages() const
{
    int contador;
    for(int i=0; i<v1.size(); i++){
        contador = contador + v1.at(i).getPages();
    }
    return contador;
}

bool Printer::isEmpty() const
{
   if(v1.empty()){
        return true;
   }else{
       return false;
   }
}

bool Printer::isFull() const
{
   if(maxNumJobs < v1.size() || maxNumPages < plusPages){
       return true;
   }else{
       return false;
   }
}

PrintJob Printer::next()
{
    string a = " ";
        int contador = 0;
        int borrador = 0;
        PrintJob ej{9999999,9999999, a};
        for(auto elem: v1){
            if(elem < ej){
                ej = elem;
                borrador = contador;
            }
            contador++;
        }
        v1.erase(v1.begin()+borrador);
        return ej;
}

bool Printer::push(const PrintJob &dato, bool force)
{
    if(force==false){
        if(queuePages()+dato.getPages()< v1.size()+1<=_maxNumJobs){
            v1.push_back(dato);
            return true;}
        else{
            return false;
        }
    }else if(force==true){
        if(queuePages()+dato.getPages()<_maxNumPages||v1.size()+1<=_maxNumJobs){
            v1.push_back(dato);
            return true;
        }else{
            std::string s=" ";
            int cont=0;
            int borrar=0;
            PrintJob result{0,0,s};
            for (auto elem:v1){
                if(elem>result){
                    result=elem;
                    borrar=cont;
                }
                cont++;
            }
            v1.erase (v1.begin()+borrar);
            v1.push_back(dato);
            return true;
        }
    }else{
        return false;
    }
}
