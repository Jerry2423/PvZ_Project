#ifndef PLANT_HPP__
#define PLANT_HPP__

#include "../GameObject.hpp"
#include <memory>

class Plant : public GameObject  {
    public:
        // int getHP() const;
        // void setHP(int k);

        void OnClick();
        virtual void Update() = 0;
        // bool isDead() const;
        bool isZombie() const;
        bool isPlant() const;

        Plant(ImageID image, int x, int y, int hp);
        virtual ~Plant() = default;

    // private:
    //     int hp;
};

#endif // !DEBUG
