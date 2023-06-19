#ifndef ZOMBIE_HPP__
#define ZOMBIE_HPP__

#include "../GameObject.hpp"


class Zombie : public GameObject {
    public:
        void OnClick();
        void collide();
        virtual void Update() = 0;

        Zombie(ImageID image, int x, int y, AnimID anim, int hp);

        bool isZombie() const;
        bool isAttacker() const;

    private:
};

#endif // !DEBUG
