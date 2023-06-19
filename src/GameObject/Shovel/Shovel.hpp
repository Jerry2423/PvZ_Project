#ifndef SHOVEL_HPP__
#define SHOVEL_HPP__

#include "../GameObject.hpp"

class Shovel : public GameObject {
    public:
        Shovel(int x, int y);
        void Update();
        void OnClick();

        bool isDead() const;
        bool isZombie() const;
};

#endif // !DEBUG
