#pragma once
#include <SFML/Graphics.hpp>
class Entity
{

  public:
    float x, y, dx, dy, R, angle;
    bool life;
    std::string name; 
    Animation anim;

    Entity()
    {
        life = true;
    }

    void settings(Animation &a, int X, int Y, float Angle = 0, int radius = 1) //setings
    {
        anim = a;
        x = X;
        y = Y;
        angle = Angle;
        R = radius;
    }

    virtual void update(){};

    void draw(RenderWindow &window) // drawing sprite of ship
    {
        anim.sprite.setPosition(x, y);
        anim.sprite.setRotation(angle + 90);
        window.draw(anim.sprite);

        CircleShape circle(R);
        circle.setPosition(x, y);
        circle.setOrigin(R, R);
    }
};

bool isCollide(Entity *a, Entity *b) // condition for collision
{
    return (b->x - a->x) * (b->x - a->x) +
               (b->y - a->y) * (b->y - a->y) <
           (a->R + b->R) * (a->R + b->R);
}
