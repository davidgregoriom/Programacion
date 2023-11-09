#include <iostream>
#include <set>
#include <cmath>
#include <string>
#include <memory>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;
//Bubble Sort --> Mejor Complejidad O(n). Peor Complejidad O(n^2)
void bubbleSort(int array[],int size){
    for(int s=0;s<size;++s){
        for(int i=0;i<size-s;++i){
            if(array[i]>array[i+1]){
                int temp=array[i];
                array[i]=array[i+1];
                array[i+1]=temp;
            }
        }
    }
}
//Selection Sort --> Complejidad O(n^2)
/*
 * Se busca el mínimo elemento de la lista, se intercambia con el primero, se busca el siguiente minimo en el
 * resto de la lista y se vuelve a intercambiar con el segundo, y asi sucesivamente.
 */

void selectionSort(int array[],int size){
    for(int s=0;s<size-1;s++){
        int min=s;
        for(int i=s+1;i<size;i++){
            if(array[i]<array[min]){
                min=i;
            }
        }

        swap(array[min],array[s]);
    }
}


template<typename Comparable>
void insertionSort(vector<Comparable>&a){
    for(int p=1;p<a.size();p++){
        Comparable t=move(a[p]);
        int j;
        for(j=p;j>0&&t<a[j-1];--j){
            a[j]=move(a[j-1]);
        }
        a[j]=move(t);
    }
}
//Merge Sort --> Complejidad O(n log n)
/*
 * Se comprueba si el tamaño de la lista es 0 o 1 para saber si esta ya ordenada. Si no, se divide la lista
 * desordenada en dos sublistas, se ordena cada sublista recursivamente, y luego se juntan ambas listas.
 */

template<typename Comparable>
void mergeSort(vector<Comparable> &a){
    vector<Comparable>A(a.size());
    mergeSort(a,A,0,a.size()-1);
}


template<typename Comparable>
void mergeSort(vector<Comparable> &a, vector<Comparable> &t, int iz, int de){
    if(iz<de){
        int cen=(iz+de)/2;
        mergeSort(a,t,iz,cen);
        mergeSort(a,t,cen+1,de);
        merge(a,t,iz,cen+1,de);
    }
}

template<typename Comparable>
void merge(vector<Comparable>&a,vector<Comparable>&tArray,int iz,int de,int definal){
    int izfinal=de-1;
    int tPos=iz;
    int numeroElementos=definal-iz+1;

    while(de<=definal&&iz<=izfinal){
        if(a[iz]<=a[de]){
            tArray[tPos++]=move(a[iz++]);
        }else{
            tArray[tPos++]=move(a[de++]);
        }
    }
    while(iz<=izfinal){
        tArray[tPos]=move(a[iz++]);
    }
    while(de<=definal){
         tArray[tPos]=move(a[de++]);
    }
    for(int i=0;i<numeroElementos;++i,--de){
        a[definal]=move(tArray[de]);
    }
}

//QuickSort --> Complejidad habitual O(n log n). En el peor de los casos O(n^2)
/*
 * Se elige un elemento del vector llamado pivote. Resituamos el resto de elementos a cada lado del pivote,
 * un lado queden todos los menores que él, y al otro los mayores. La lista queda separada en dos sublistas,
 * una formada por los elementos a la izquierda del pivote, y otra por los elementos a su derecha.
 * Se repite este proceso de manera recursiva hasta que esten ordenados.
 */
template<typename Comparable>
void quickSort(vector<Comparable>&a,int ba,int al){
    if(ba>=al){
        insertionSort(a,ba,al);
    }else{
        int medio=(ba+al)/2;
        if(a[medio]<a[ba]){
            swap(a[ba],a[medio]);
        }
        if(a[al]<a[ba]){
            swap(a[ba],a[al]);
        }
        if(a[al]<a[medio]){
            swap(a[medio],a[al]);
        }
        Comparable pivote=a[medio];
        swap(a[medio],a[al-1]);

        int i,j;
        for(i=ba,j=al-1;;){
            while(a[++i]<pivote){}
            while(pivote<a[--j]){}
            if(i<j){
                swap(a[i],a[j]);
            }else{
                break;
            }
            swap(a[i],a[al-1]);

            quickSort(a,ba,i-1);
            quickSort(a,i+1,al);
        }
    }
}


/**********************************************************************/
int hacerigualLongitud(string &st1,string &st2){
    int long1=st1.size();
    int long2=st2.size();
    if(long1<long2){
        for(int i=0;i<long2-long1;i++){
            st1='0'+st1;
            return long2;
        }
    }else if(long1>long2){
        for(int i=0;i<long1-long2;i++){
            st2='0'+st2;
        }
    }
    return long1;
}
string addbits(string primero,string segundo){
    string resultado;
    int longitud=hacerigualLongitud(primero,segundo);
    int carry=0;
    for(int i=longitud-1;i>=0;i--){
        int primerBit=primero.at(i)-'0';
        int segundoBit=segundo.at(i)-'0';
        int suma=(primerBit^segundoBit^carry)+'0';
        resultado=(char)suma+resultado;
        carry=(primerBit&segundoBit)|(segundoBit&carry)|(primerBit&carry);
    }
    if(carry)resultado='1'+resultado;
    return resultado;
}
int multiplicarIndividual(string x,string y){
    return(x[0]-'0')*(y[0]-'0');
}

long int multiplicar(string x,string y){
    int n=hacerigualLongitud(x,y);
    if (n==0)return 0;
    if (n==1)return multiplicarIndividual(x,y);
    int primeraMitad=n/2;
    int segundaMitad=(n-primeraMitad);


    string Xderecha=x.substr(0,primeraMitad);
    string Xizquierda=x.substr(primeraMitad,segundaMitad);
    string Yderecha=y.substr(0,primeraMitad);
    string Yizquierda=y.substr(primeraMitad,segundaMitad);

    long int P1=multiplicar(Xderecha,Yderecha);
    long int P2=multiplicar(Xizquierda,Yizquierda);
    long int P3=multiplicar(addbits(Xizquierda,Yderecha),addbits(Xderecha,Yizquierda));

    return P1*(1<<(2*segundaMitad))+(P3-P1-P2)*(1<<segundaMitad)+P2;
}

int deducir_numero(int n1,int n2,int n3,char t){
    if(t=1){
        return(n1+n2);
    }else if(t=2){
        return(n2+n3);
    }else if(t=3){
        return(n1+n3);
    }else{
        return false;
    }
}



int makeChange(const vector<int> &c,int cg){
    int min=cg;
    for(int i=0;i<c.size();i++){
        if(c[i]==cg){
            return 1;
        }
    }
    for(int j=1;j<cg/2;j++){
        int thisC=makeChange(c,j)+makeChange(c,cg-j);
        if(thisC<min){
            min=thisC;
        }
    }
    return min;
}
int makeChange(const vector<int>&coins,int max, vector<int>&coinsU,vector<int>&lastC){
    int diff=coins.size();
    coinsU.resize(max+1);
    lastC.resize(max+1);

    coinsU[0]=0;
    lastC[0]=1;
    for(int cents=1;cents<=max;cents++){
        int min=cents,newC=1;
        for(int j=0;j<diff;j++){
            if(coins[j]>cents){
                continue;
            }
            if(coinsU[cents-coins[j]]+1<min){
                min=coinsU[cents-coins[j]]+1;
                newC=coins[j];
            }
        }
        coinsU[cents]=min;
        lastC[cents]=newC;
    }

}
/****************************************************************************************/

int main(){



}
