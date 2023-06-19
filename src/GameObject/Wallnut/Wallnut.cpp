#include "Wallnut.hpp"
#include "../../utils.hpp"
#define TOTALHP 4000
/*
change a plant:
from plant file
image
hp
plot
*/



Wallnut::Wallnut(int x, int y) : Plant(IMGID_WALLNUT, x, y, TOTALHP)
     {}





void Wallnut::Update() {
    if (isDead()){
        return;
    }
    if (getHP() < TOTALHP/3) {
       ChangeImage(IMGID_WALLNUT_CRACKED); 
    }
}

