#ifndef SUN_FLOWER_HPP__
#define SUN_FLOWER_HPP__

#include "../Plant/Plant.hpp"

class SunFlower : public Plant {
    public:
        void Update();
        void genSun();

        SunFlower(int x, int y);

        int getTime() const;
        void setTime(int t);

        int getInterval() const;
        void setInterval(int interval);

        bool isFirst() const;
        void negFirst();

        int getGenSunTime() const;

    private:
        int genSunTime;
        int timer;
        int genInterval;
        bool first;

};

#endif // !DEBUG

/*
   timer
   interval
   signFirst?
   */
