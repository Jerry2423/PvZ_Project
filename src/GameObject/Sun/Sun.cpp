#include "Sun.hpp"
#include "../../GameWorld/GameWorld.hpp"

Sun::Sun(ImageID imageID, int x, int y, LayerID layer, AnimID animID, int falling_time) :GameObject(imageID, x, y, layer, 80, 80, animID), 
    falling_time(falling_time), onLandTime(300) {}

bool Sun::isZombie() const {
    return false;
}

bool Sun::isOnLand() const {
    return falling_time <= 0;
}

bool Sun::isDead() const {
    return isOnLand() && onLandTime <= 0;
}

// class GameWorld {
//     public:
//         void addSun(int num);
// };

void Sun::setFallingTime(int t) {
    falling_time = t;
}

void Sun::setOnLandTime(int t) {
    onLandTime = t;
}


void Sun::OnClick() {
    livingWorld->addSun(25);
    //set this to death
    setOnLandTime(0);
    setFallingTime(0);
}

int Sun::getFallingTime() const {
    return falling_time;
}

int Sun::getOnLandTime() const {
    return onLandTime;
}

void Sun::decrFallingTime() {
    if (falling_time > 0) {
        falling_time --;
    }
}

void Sun::decrOnLandTime() {
    if (onLandTime > 0) {
        onLandTime --;
    }
}

