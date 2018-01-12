#pragma once
class stones : public Entity
{
  public:
    stones()
    {
        dx = rand() % 8 - 7; // Speed by x
        dy = rand() % 8 - 7; // Speed by y
        name = "stones";
    }

    void update()
    {
        x += dx;
        y += dy;
        // condition of Rocks
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
