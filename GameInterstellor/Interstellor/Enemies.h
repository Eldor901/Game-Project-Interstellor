void alienEnemy(std::list<Entity *> &entities, Animation &sExplosion, Animation &sCoin,
                Animation &sExplosion_ship, Animation &sPlayer, player *p,
                Animation &sAlien, Animation &sAlien2, int &spec)
{
    for (auto a : entities)
    {
        for (auto b : entities)
        {
            if (a->name == "alien" && b->name == "bullet")
                if (isCollide(a, b))
                {
                    a->life = false;
                    b->life = false;
                    spec = spec + 10;
                    Entity *e = new Entity();
                    e->settings(sExplosion, a->x, a->y);
                    e->name = "explosion";
                    entities.push_back(e);
                }
            if (a->name == "player" && b->name == "alien")
                if (isCollide(a, b))
                {
                    b->life = false;

                    Entity *e = new Entity();
                    e->settings(sAlien2, a->x, a->y);
                    e->name = "explosion";
                    entities.push_back(e);

                    p->settings(sPlayer, W / 2, H / 2, 0, 20);
                    p->dx = 0;
                    p->dy = 0;
                }
        }
    }
}
void smallAsteroids(std::list<Entity *> &entities, Animation &sExplosion, Animation &sRock_small,
                    Animation &sExplosion_ship, Animation &sPlayer, player *p, int &spec)
{
    for (auto a : entities)
    {
        for (auto b : entities)
        {
            if (a->name == "stones" && b->name == "bullet")
                if (isCollide(a, b))
                {
                    a->life = false;
                    b->life = false;
                    spec++;
                    Entity *e = new Entity();
                    e->settings(sExplosion, a->x, a->y);
                    e->name = "explosion";
                    entities.push_back(e);

                    for (int tiny = 0; tiny < 2; tiny++) // amount of tiny stones when it is broken
                    {
                        if (a->R == 15)
                            continue;
                        Entity *e = new stones();
                        e->settings(sRock_small, a->x, a->y, rand() % 360, 15);
                        entities.push_back(e);
                    }
                }

            if (a->name == "player" && b->name == "stones")
                if (isCollide(a, b))
                {
                    b->life = false;

                    Entity *e = new Entity();
                    e->settings(sExplosion_ship, a->x, a->y);
                    e->name = "explosion";
                    entities.push_back(e);

                    p->settings(sPlayer, W / 2, H / 2, 0, 20);
                    p->dx = 0;
                    p->dy = 0;
                }
        }
    }
}