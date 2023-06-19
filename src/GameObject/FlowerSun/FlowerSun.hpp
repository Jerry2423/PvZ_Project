#ifndef FLOWER_SUN_HPP__
#define FLOWER_SUN_HPP__

#include "../Sun/Sun.hpp"

/*
   vx
   vy
   a
   function
   delta vy (change of vy)
   falling time is 12 by defalut
   falling time init?
   */


class FlowerSun: public Sun {
    public:
        void Update();
        FlowerSun(int x, int y);
        void deltaVy();
    private:
        static const int accel = -1;
        static const int v_x = -1;
        int v_y;
};

#endif // !DEBUG
