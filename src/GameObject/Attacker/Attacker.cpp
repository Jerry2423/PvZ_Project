#include "Attacker.hpp"

Attacker::Attacker(ImageID img, int x, int y, LayerID layer, int width, int height, AnimID ani) : GameObject(img, x, y, layer, width, height, ani) {}

bool Attacker::isPlant() const {
    return true;
}

bool Attacker::isAttacker() const {
    return true;
}

void Attacker::OnClick() {}
