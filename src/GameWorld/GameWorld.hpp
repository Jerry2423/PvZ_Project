#ifndef GAMEWORLD_HPP__
#define GAMEWORLD_HPP__

#include <list>
#include <memory>

#include "../Framework/WorldBase.hpp"
#include "../utils.hpp"
#include "../GameObject/GameObject.hpp"
using std::list;


enum class SeedType {Default, Sunflower, Peashooter, Wallnut, Cherry, Repeater, Shovel};
enum class SunType {FlySun, GroundSun};

class GameWorld : public WorldBase, public std::enable_shared_from_this<GameWorld> {
public:
  // Use shared_from_this() instead of "this".
  GameWorld();
  virtual ~GameWorld();

  void Init() override;

  LevelStatus Update() override;

  void CleanUp() override;

  void addSun(int num);

  int getTime() const;
  void setTimer(int t);
  int getSunInterval() const;
  void setSunInterval(int t);

  int getZInterval() const;
  void setZInterval(int t);

  SeedType getSeedType() const;
  void setSeedType(SeedType seed);

  void addObject(SeedType seed, int x, int y);
  void addCoolDownMask(int x, int y, int coolDownTime);
  void genSun(SunType sun, int x, int y);
  void addPea(int x, int y);
  void addExplosion(int x, int y);

  bool findZombie(int x, int y) const;
  bool SameType(std::shared_ptr<GameObject>p1, std::shared_ptr<GameObject>p2) const;
  bool CollisionDetect(std::shared_ptr<GameObject>p1, std::shared_ptr<GameObject>p2) const;
  bool collWithPlant(std::shared_ptr<GameObject> p) const;

private: 
    list<std::shared_ptr<GameObject>> objects;
    //time
    int timer;
    int sunInterval;
    SeedType bunnyMarker;
    int zombieInterval;

    bool inRange(int a, int b, int c) const;
};

#endif // !GAMEWORLD_HPP__
