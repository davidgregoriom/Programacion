#include "police.h"
#include "queue.h"


Queue police_raid(Queue joy_slava,const vector<string> & dni){
    Queue result;
    shared_ptr<ElementListaDoble> iterator = joy_slava.getback();
    for(auto elem: dni){
        while (iterator != nullptr){
            if(elem == iterator ->dato.get_dni()){
                result.push(iterator->dato);

            }
            iterator = iterator->prev;
        }
    }
   return result;
}
