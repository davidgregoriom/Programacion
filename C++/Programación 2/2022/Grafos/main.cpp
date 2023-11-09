#include <iostream>
#include <memory>
#include <set>

using namespace std;

template<class T>
class Node
{
public:
    Node(std::shared_ptr<T> data):data{data}{}
    std::shared_ptr<T> getData() const;
    void setData(std::shared_ptr<T> d);
    void addNeighbour(std::shared_ptr<Node<T>> n);
    std::set<std::shared_ptr<Node<T>>> getNeighbours() const;

private:
    std::shared_ptr<T> data;
    std::set< std::shared_ptr< Node<T> > > neighbours;
};

template<class T>
std::shared_ptr<T> Node<T>::getData() const
{
    return data;
}

template<class T>
void Node<T>::setData(std::shared_ptr<T> d)
{
    data = d;
}

template<class T>
void Node<T>::addNeighbour(std::shared_ptr<Node<T> > n)
{
    neighbours.insert(n);
}

template<class T>
std::set<std::shared_ptr<Node<T> > > Node<T>::getNeighbours() const
{
    return neighbours;
}


int main()
{

    auto parada1 = std::make_shared<Node<std::string>>( Node<std::string>{ std::make_shared<std::string>("Pavones") } );
    auto parada2 = std::make_shared<Node<std::string>>( Node<std::string>{ std::make_shared<std::string>("Artilleros") } );
    auto parada3 = std::make_shared<Node<std::string>>( Node<std::string>{ std::make_shared<std::string>("Vinateros") } );
    auto parada4 = std::make_shared<Node<std::string>>( Node<std::string>{ std::make_shared<std::string>("Estrella") } );

    parada1->addNeighbour(parada2);
    parada2->addNeighbour(parada1);

    parada2->addNeighbour(parada3);
    parada3->addNeighbour(parada2);

    parada3->addNeighbour(parada4);
    parada4->addNeighbour(parada3);

    auto it = parada1;
    auto last = parada1;

    while(it){
        std::string este = *(it->getData());
        std::string anterior = *(last->getData());

        std::cout << este << " - ";
        auto neighbours = it->getNeighbours();

        for(auto const & elem: neighbours){
            if(*(elem->getData()) != anterior){
                last = it;
                it = elem;
                break;
            }
        }
        if(este == *(it->getData())) break;
    }

    std::cout << "\n";

    return 0;
}
