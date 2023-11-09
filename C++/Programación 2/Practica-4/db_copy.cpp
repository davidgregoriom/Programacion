#include "db.h"
template<typename K,typename V>
DB<K,V>::DB()
{

}

template<typename K,typename V>
const Data<K,V> &_find(std::shared_ptr<pair<K,V>> element, const  Data<K,V>& dato) {
    // Handle corner case
    if (element == nullptr) {
        return dato;
    }
    if (element->dato > dato) {
        return _find(element->left, dato);
    }
    else if (element->dato < dato) {
        return _find(element->right, dato);
    }
    else {
        return element->dato = dato;
    }
}
template<typename K,typename V>
const Data<K,V> &DB<K,V>::find(int id) const
{
    return _find(db,db ->dato);
}
