#include "GameObject.hpp"

GameObject::GameObject(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID) : ObjectBase(imageID, x, y, layer, width, height, animID),
    hp(0), attackValue(0), state(MotionState::Stop){}

pGameWorld GameObject::livingWorld; // if the static member is not declared first, just use the static member function directly there would a linker error

void GameObject::setWorld(pGameWorld world) {
   GameObject::livingWorld = world;
}

bool GameObject::isPlant() const {
    return false;
}

void GameObject::collide() {}

MotionState GameObject::getMState() const {
    return state;
}

void GameObject::setMState(MotionState s) {
    state = s;
}

bool GameObject::isAttacker() const {
    return false;
}

bool GameObject::isZombie() const {
    return false;
}

int GameObject::getHP() const {
    return hp;
}

void GameObject::setHP(int k) {
    hp = k;
}

int GameObject::getAttVal() const {
    return attackValue;
}

void GameObject::setAttVal(int value) {
    attackValue = value;
}

bool GameObject::isDead() const {
    return hp <= 0;
}

// void GameObject::collide() {}

