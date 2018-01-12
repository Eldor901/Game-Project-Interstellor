
class alien : public Entity
{
  public:
    alien()
    {
        dx = rand() % 8 - 1; // Speed alien  by  x
        dy = rand() % 8 - 1; // Speed alien  by y
        name = "alien";
    }

    void update()
    {
        x += dx;
        y += dy;

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
