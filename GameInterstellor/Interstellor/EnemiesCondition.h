void spaceShipCondition(player *p, Animation &sPlayer_go, Animation &sPlayer, std::list<Entity *> &entities)
{

    if (p->movement)
        p->anim = sPlayer;
    else
        p->anim = sPlayer_go;

    for (auto e : entities)
        if (e->name == "explosion")
            if (e->anim.isEnd())
            {

                e->life = 0;
            }
}

void asteroidsCondition(std::list<Entity *> &entities, Animation &sRock, Animation &sAlien)
{

    if (rand() % 50 == 0) // amount of rocks
    {
        stones *a = new stones();
        a->settings(sRock, 0, rand() % H, rand() % 360, 25);
        entities.push_back(a);
    }

    if (rand() % 300 == 0) // amount of alien
    {
        alien *a = new alien();
        a->settings(sAlien, 0, rand() % H, rand() % 360, 25);
        entities.push_back(a);
    }

    for (auto i = entities.begin(); i != entities.end();)
    {
        Entity *e = *i;

        e->update();
        e->anim.update();

        if (e->life == false)
        {
            i = entities.erase(i);
            delete e;
        }
        else
            i++;
    }
}