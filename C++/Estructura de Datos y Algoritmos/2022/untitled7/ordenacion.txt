#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

template<typename Comparable>
void insertionSort(vector<Comparable> & a){
    for(int p=1; p<a.size();++p){
        Comparable tmp = move(a[p]);
        int j;
        for(j=p;j>0 && tmp<a[j-1];--j)
            a[j]= move(a[j-1]);
        a[j]=move(tmp);
    }
}

template <typename Comparable>
void insertionSort( vector<Comparable> & a, int left, int right )
{
    for( int p = left + 1; p <= right; ++p )
    {
        Comparable tmp = std::move( a[ p ] );
        int j;

        for( j = p; j > left && tmp < a[ j - 1 ]; --j )
            a[ j ] = std::move( a[ j - 1 ] );
        a[ j ] = std::move( tmp );
    }
}

template <typename Comparable>
void shellsort( vector<Comparable> & a )
{
    for( int gap = a.size( ) / 2; gap > 0; gap /= 2 )
        for( int i = gap; i < a.size( ); ++i )
        {
            Comparable tmp = std::move( a[ i ] );
            int j = i;

            for( ; j >= gap && tmp < a[ j - gap ]; j -= gap )
                a[ j ] = std::move( a[ j - gap ] );
            a[ j ] = std::move( tmp );
        }
}

template <typename Comparable>
void heapsort( vector<Comparable> & a )
{
    for( int i = a.size( ) / 2 - 1; i >= 0; --i )  /* buildHeap */
        percDown( a, i, a.size( ) );
    for( int j = a.size( ) - 1; j > 0; --j )
    {
        std::swap( a[ 0 ], a[ j ] );               /* deleteMax */
        percDown( a, 0, j );
    }
}

inline int leftChild( int i )
{
    return 2 * i + 1;
}

template <typename Comparable>
void percDown( vector<Comparable> & a, int i, int n )
{
    int child;
    Comparable tmp;

    for( tmp = std::move( a[ i ] ); leftChild( i ) < n; i = child )
    {
        child = leftChild( i );
        if( child != n - 1 && a[ child ] < a[ child + 1 ] )
            ++child;
        if( tmp < a[ child ] )
            a[ i ] = std::move( a[ child ] );
        else
            break;
    }
    a[ i ] = std::move( tmp );
}



void selectionSort(int array[],int size){
    for(int step=0;step <size-1;step++){
        int min_idx=step;
        for(int i=step+1; i<size;i++){
            if(array[i]<array[min_idx])
                min_idx=i;
        }
        swap(array[min_idx],array[step]);
    }
}

void bubbleSort(int array[],int size){
    for(int step=0;step<size;++step){
        for(int i=0;i<size-step;++i){
            if(array[i]>array[i+1]){
                int temp= array[i];
                array[i]=array[i+1];
                array[i+1]=temp;
           }
        }
    }
}

template<typename Comparable>
void mergeSort(vector<Comparable> & a){
    vector<Comparable> tmpArray(a.size());
    mergeSorts(a,tmpArray,0,a.size()-1);
}

template<typename Comparable>
void mergeSorts(vector<Comparable> &a,vector <Comparable> &tmpArray,int left,int right){
    if(left<right){
        int center=(left+ right)/2;
        mergeSorts(a,tmpArray,left,center);
        mergeSorts(a,tmpArray,center+1,right);
        merge(a,tmpArray,left,center+1,right);
    }
}
template<typename Comparable>
void merge(vector<Comparable>& a,vector<Comparable> & tmpArray,int leftPos,int rightPos, int rightEnd){
    int leftEnd =rightPos-1;
    int tmpPos = leftPos;
    int numElements = rightEnd -leftPos + 1;

    while(leftPos <= leftEnd && rightPos <=rightEnd)
        if(a[leftPos]<=a[rightPos]){
            tmpArray[tmpPos++]= move(a[leftPos++]);
        }else{
            tmpArray[tmpPos++]=move(a[rightPos++]);
        }
    while(leftPos<=leftEnd){
        tmpArray[tmpPos++]=move(a[leftPos++]);
    }
    while(rightPos<=rightEnd){
        tmpArray[tmpPos++]=move(a[rightPos++]);
    }
    for(int i=0;i<numElements;i++,--rightEnd){
        a[rightEnd]=move(tmpArray[rightEnd]);
    }
}

template <typename Comparable>
const Comparable & median3( vector<Comparable> & a, int left, int right )
{
    int center = ( left + right ) / 2;

    if( a[ center ] < a[ left ] )
        std::swap( a[ left ], a[ center ] );
    if( a[ right ] < a[ left ] )
        std::swap( a[ left ], a[ right ] );
    if( a[ right ] < a[ center ] )
        std::swap( a[ center ], a[ right ] );

        // Place pivot at position right - 1
    std::swap( a[ center ], a[ right - 1 ] );
    return a[ right - 1 ];
}

template<class Comparable>
void quicksort(vector<Comparable>&a,int low,int high){
    if(low+CUTOFF >high){
        insertionSort(a,low,high);
    }else{
        int middle=(low+high)/2;
        if(a[middle]<a[low]){
            swap(a[low],a[middle]);
        }else if(a[high]<a[low]){
            swap(a[low],a[high]);
        }else if(a[middle]<a[middle]){
            swap(a[middle],a[high]);
        }
        Comparable pivot=a[middle];
        swap(a[middle],a[high-1]);

        int i,j;
        for(i=low,j=high-1;;){
            while(a[++i]<pivot){}
            while(pivot<a[--j]){}
            if(i<j){
                swap(a[i],a[j]);
            }else{
                break;
            }
        }
    }
}

template <typename Comparable>
void quicksort( vector<Comparable> & a )
{
    quicksort( a, 0, a.size( ) - 1 );
}

template <typename Comparable>
void quickSelect( vector<Comparable> & a, int left, int right, int k )
{
    if( left + 10 <= right )
    {
        const Comparable & pivot = median3( a, left, right );

            // Begin partitioning
        int i = left, j = right - 1;
        for( ; ; )
        {
            while( a[ ++i ] < pivot ) { }
            while( pivot < a[ --j ] ) { }
            if( i < j )
                std::swap( a[ i ], a[ j ] );
            else
                break;
        }

        std::swap( a[ i ], a[ right - 1 ] );  // Restore pivot

            // Recurse; only this part changes
        if( k <= i )
            quickSelect( a, left, i - 1, k );
        else if( k > i + 1 )
            quickSelect( a, i + 1, right, k );
    }
    else  // Do an insertion sort on the subarray
        insertionSort( a, left, right );
}

template <typename Comparable>
void quickSelect( vector<Comparable> & a, int k )
{
    quickSelect( a, 0, a.size( ) - 1, k );
}

template <typename Comparable>
void SORT( vector<Comparable> & items )
{
    if( items.size( ) > 1 )
    {
        vector<Comparable> smaller;
        vector<Comparable> same;
        vector<Comparable> larger;

        auto chosenItem = items[ items.size( ) / 2 ];

        for( auto & i : items )
        {
            if( i < chosenItem )
                smaller.push_back( std::move( i ) );
            else if( chosenItem < i )
                larger.push_back( std::move( i ) );
            else
                same.push_back( std::move( i ) );
        }

        SORT( smaller );     // Recursive call!
        SORT( larger );      // Recursive call!

        std::move( begin( smaller ), end( smaller ), begin( items ) );
        std::move( begin( same ), end( same ), begin( items ) + smaller.size( ) );
        std::move( begin( larger ), end( larger ), end( items ) - larger.size( ) );

/*
        items.clear( );
        items.insert( end( items ), begin( smaller ), end( smaller ) );
        items.insert( end( items ), begin( same ), end( same ) );
        items.insert( end( items ), begin( larger ), end( larger ) );
*/
    }
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
