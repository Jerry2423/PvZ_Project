#ifndef SEED_HPP__
#define SEED_HPP__

#include "../GameObject.hpp"

class Seed : public GameObject {
    public:
        void Update();
        virtual void OnClick() = 0;
        bool isZombie() const;
        bool canClick() const;
        bool isDead() const;
        int getCoolDownTime() const;
        int getPrice() const;

        Seed(ImageID image, int x, int y, int price, int coolDownTime);
        virtual ~Seed() = default;

    private:
        int price;
        int coolDownTime;
};


#endif // !DEBUG
