#ifndef GAMEOBJECT_HPP__
#define GAMEOBJECT_HPP__

#include <memory>
#include "../Framework/ObjectBase.hpp"

// Declares the class name GameWorld so that its pointers can be used.
class GameWorld;
using pGameWorld = std::shared_ptr<GameWorld>;

enum class MotionState {Move, Stop, Run, Jump};

class GameObject : public ObjectBase, public std::enable_shared_from_this<GameObject> {
public:
    using std::enable_shared_from_this<GameObject>::shared_from_this; // Use shared_from_this() instead of "this".
    
    GameObject(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID);
    virtual bool isDead() const;
    virtual bool isZombie() const;
    static void setWorld(pGameWorld world);

    virtual bool isPlant() const;
    virtual bool isAttacker() const;

    int getHP() const;
    void setHP(int k);

    int getAttVal() const;
    void setAttVal(int value);

    MotionState getMState() const;
    void setMState(MotionState s);

    virtual void collide();

protected:
    static pGameWorld livingWorld; 

private:
    int hp;
    int attackValue;
    MotionState state;
};


#endif // !GAMEOBJECT_HPP__
