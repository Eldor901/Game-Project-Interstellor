#pragma once
#include <SFML\Graphics.hpp>
float DEGTORAD = 0.017453f;
float speedanim = 0.2;
class player : public Entity
{
  private:
    float X, Y;

  public:
    bool movement;

    player()
    {
        name = "player";
    }

    void update()
    {

        if (movement) //condition for movement
        {
            dx += cos(angle * DEGTORAD) * speedanim; //speed
            dy += sin(angle * DEGTORAD) * speedanim;
        }
        else
        {
            dx *= 0.99;
            dy *= 0.99;
        }

        int maxSpeed = 25;
        float speed = sqrt(dx * dx + dy * dy);
        if (speed > maxSpeed)
        {
            dx *= maxSpeed / speed;
            dy *= maxSpeed / speed;
        }

        x += dx;
        y += dy;
        // condition of Spaceship
        if (x > W)
            x = 0;
        if (x < 0)
            x = W;
        if (y > H)
            y = 0;
        if (y < 0)

            y = H;
    }
};