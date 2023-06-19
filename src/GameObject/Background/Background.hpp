#ifndef BACKGROUND_HPP__
#define BACKGROUND_HPP__

#include "../GameObject.hpp"
#include "../../utils.hpp"

class Background : public GameObject {
public:
    bool isDead() const;
    bool isZombie() const;
    Background(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID);

    void Update();
    void OnClick();

private:

};

#endif // !DEBUG
