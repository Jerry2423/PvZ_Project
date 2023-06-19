#ifndef SKY_SUN_HPP__
#define SKY_SUN_HPP__

#include "../Sun/Sun.hpp"

class SkySun : public Sun {
    public:
        // void movement();
        void Update();
        SkySun(int x, int y);
};


#endif // !DEBUG
