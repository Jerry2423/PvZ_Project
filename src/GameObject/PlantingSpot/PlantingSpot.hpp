#ifndef PLANTING_SPOT_HPP__
#define PLANTING_SPOT_HPP__

#include "../GameObject.hpp"

/*
onclick: new bunny!
   */


class PlantingSpot : public GameObject {
    public:
        PlantingSpot(int x, int y);
        void Update();
        void OnClick();

        bool isDead() const;
        bool isZombie() const;
};

#endif // !DEBUG
