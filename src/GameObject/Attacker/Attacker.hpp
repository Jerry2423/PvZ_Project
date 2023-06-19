#ifndef ATTACKER_HPP__
#define ATTACKER_HPP__

#include "../GameObject.hpp"

class Attacker : public GameObject {
    public:
        Attacker(ImageID img, int x, int y, LayerID layer, int width, int hight, AnimID ani);
        bool isPlant() const;
        bool isAttacker() const;
        void OnClick();
};

#endif // !DEBUG
