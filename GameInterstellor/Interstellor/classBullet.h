#pragma once
const float Center = 6;

class bullet : public Entity
{

  public:
    bullet()
    {
        name = "bullet";
    }

    void update()
    {
        dx = cos(angle * DEGTORAD) * Center; // shooting correctly
        dy = sin(angle * DEGTORAD) * Center;

        x += dx;
        y += dy;

        if (x > W || x < 0 || y > H || y < 0) // condition of bullet
            life = 0;
    }
};