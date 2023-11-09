#include <memory>
#include <iostream>
#include <vector>
#include "persona.h"
#include "queue.h"
#include "wardrove.h"
#include "police.h"

using namespace std;

int main(){
        // Manuel is going today to Joy Slava, he is waiting for some friends
        Persona manuel{"Manuel", "dni-manuel", 0};

        // Create the queue for the disco
        Queue joy_eslava;
        joy_eslava.push(Persona{"Sergio", "dni-sergio", 0});
        joy_eslava.push(manuel);
        joy_eslava.push(Persona{"Leticia", "dni-leticia", 1});
        // ...

        // Create the queue with Manuel's friends
        Queue friends;
        friends.push(Persona{"Miguel", "dni-miguel", 0});
        friends.push(Persona{"Samuel", "dni-samuel", 0});
        friends.push(Persona{"Raquel", "dni-raquel", 1});

        // Sneak in
        joy_eslava.sneak_in(manuel, friends);

        Wardrobe men;
        Wardrobe women;



        // Check the queue is the expected one: print size and names
        std::cout << "Joy Slava, people waiting: " << joy_eslava.size() << std::endl;

        //cout << "Genero: " << men.wardrobe(joy_eslava, men, women) << "\n";

}
