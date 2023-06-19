seed ->    cool mask -> plant spot
           \
(shovel)->  bunny mark-> remove plant

#### Game Object
- image
- x, y
- layer
- width and height
- aniId
methods:
- update
- onclick
- isdead
- isZombie
new
- isplant()
- isattacker()
2 kinds collide:
- collide(): if collide, what happen to object itself
- collideWithZomb(zombie): if collide with Zombie, what happen to zombie and itself

new property:
all have hp!
all have attackValue

#### Make the collide function a member function:
```
collide(game object)
```


#### Collision Detection and Control: **all under** game world control!
In the Game Object
Define:
    - Performance

In the Game World: Detection and sort types
Define Coolision Function:
    - iterate all element
        - nested loop: iterate element after the selected element
            - check diff type?
            - y: call the collision performance function of both object

New:
- Define Collision Detection
- Collision Function(GO A, GO B):
    A.hp - B.attackValue
    B.hp - A.attackValue

#### Zombie
property:
- image
- position
- animation
- hp

common:
- layer
- w, h: 20, 80
- state: stop or walk?

method:
common:
- onclick
- collision
- sethp
- gethp
- getState
- setState
- gethp


#### Pole Vaulting Zombie
- for GB: add check state function(op)
- add run state
- In GW: define CollideWithPlant(ptr: zombie)
- jump timer



#### Attacker: Pea and Explosion




#### Shovel
- position


#### Plant
- position
- width, height:60, 80
- hp
diff:
- image
- position
- hp

same:
- w, h
- animation
- onclick
- state: alive or dead



#### SunFlower
- generate a sun
    when?
    sun from flower!

#### Peashooter
- shoot
- one bullets/30ticks

#### Game world
- stuff in hands! (record what is holding in your hand)
    type of plant
- add object()


#### SEED
- price
- cool time
- onclick:
    generate a cool mask with corresponding cool time
    set the type of stuff in hand


    ~generate a bunny marker: push it at the front of the list(alive)~




#### cool mask
- timer(kill)


#### bunny marker: 5 seeds (seed spot)
- seed id
- state: alive / dead




#### planting spot
- onclick()
    generate corresponding plant
    set the stuff in hand to be default!

