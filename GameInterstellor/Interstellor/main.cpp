#include <time.h>
#include <list>
#include <cmath>
#include <vector>
#include "Animation.h"
#include "classEntity.h"
#include "classStones.h"
#include "classPlayer.h"
#include "classBullet.h"
#include "Timer.h"
#include "classAlienship.h"
#include "Enemies.h"
#include "EnemiesCondition.h"
#include <iostream>
#include <sstream>
#include <string>
#include <string>
#include <conio.h>
#include "Textures.h"
#include <SFML/Audio.hpp>
using namespace sf;
using namespace std;

string intToString(int a) // converts a number to a string
{

    std::ostringstream ost;
    ost << a;
    std::string s_num = ost.str();

    return s_num;
}

void createWindow(RenderWindow &window)
{

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    window.create(
        sf::VideoMode(W, H),
        "Eldor", sf::Style::Default, settings);
    Font font;
    font.loadFromFile("images/arial.ttf");
    Text text("", font, 20);
    text.setFillColor(Color(128, 128, 128));
    text.setStyle(Text::Bold);
}

void handleEvents(RenderWindow &window, std::list<Entity *> &entities, Animation &sBullet,
                  Animation &sBullet2, player *p, bool &gameOver, bool &changeMap,
                  bool &startGame)
{
    Event event;
    while (window.pollEvent(event))
    {
        if (event.type == Event::Closed)
            window.close();

        if (event.type == Event::KeyPressed)
        {
            if (event.key.code == Keyboard::Pause)
            {
                gameOver = false;
            }
            if (event.key.code == Keyboard::F1)
            {
                gameOver = true;
            }
            if (event.key.code == Keyboard::Escape)
            {
                window.close();
            }
            if (event.key.code == Keyboard::L)
            {
                changeMap = true;
            }
            if (event.key.code == Keyboard::G)
            {
                changeMap = false;
            }
            if (event.key.code == Keyboard::Return)
            {
                startGame = true;
                if (event.key.code == Keyboard::Pause)
                {
                    gameOver = true;
                }
                if (event.key.code == Keyboard::F1)
                {
                    gameOver = false;
                }
            }
            if (event.key.code == Keyboard::Space)
            {
                bullet *b = new bullet();
                b->settings(sBullet, p->x, p->y, p->angle, 10);
                entities.push_back(b);
            }
        }
    }
    if (!gameOver)
    {
        if (Mouse::isButtonPressed(Mouse::Left))
        {
            bullet *b = new bullet();
            b->settings(sBullet2, p->x, p->y, p->angle, 10);
            entities.push_back(b);
        }
        if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D))))
            p->angle += 3;
        if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A))))
            p->angle -= 3;
        if ((Keyboard::isKeyPressed(Keyboard::Up)) || (Keyboard::isKeyPressed(Keyboard::W)))
            p->movement = true;
        else
            p->movement = false;
    }
}

void timerFrame(RenderWindow &window, Text &minText, Text &secText, Text &miliText,
                Text &text1, int &min, int &sec, int &mili, int &spec, Text &specText)
{
    timeDesign(min, sec, mili);

    minText.setString(intToString(min));
    secText.setString(intToString(sec));
    miliText.setString(intToString(mili));
    specText.setString(intToString(spec));

    text1.setPosition(950, 20);
    window.draw(text1);
    window.draw(minText);
    text1.setPosition(1050, 20);
    window.draw(text1);
    window.draw(secText);

    window.draw(miliText);
    window.draw(specText);
}
void redrawFrame(RenderWindow &window, Sprite &background, std::list<Entity *> &entities, Sprite &coin,
                 player *p, Text &minText, Text &secText, Text &miliText, Text &text1, int &min, int &sec, int &mili,
                 Text &specText, int &spec, Sprite &change, bool &changeMap, bool &startGame, Sprite &Menu, Text &pressEnter)
{
    window.clear();

    window.draw(background);
    if (changeMap)
    {
        window.draw(change);
    }
    if (startGame)
    {
        timerFrame(window, minText, secText, miliText, text1, min, sec, mili, spec, specText);
        for (auto i : entities)
            i->draw(window);
    }

    if (!startGame)
    {
        window.draw(Menu);
        window.draw(pressEnter);
    }

    window.display();
}

int main()
{
    srand(time(0));

    RenderWindow window;
    createWindow(window);

    window.setFramerateLimit(60);

    Textures textures;
    loadTextures(textures);
    Sprite background(textures.t2);
    Sprite coin(textures.t9);
    Sprite change(textures.t12);
    Sprite Menu(textures.t13);

    const int size = 40;
    const int anotherSize = 80;
    Font font;
    font.loadFromFile("images/arial.ttf");

    Text minText("", font, size);
    Text secText("", font, size);
    Text miliText("", font, size);
    Text text1(":", font, size);

    Text specText("Spec:", font, size);

    Text pressEnter("Press Enter to start the game", font, anotherSize);
    pressEnter.setPosition(50, 100);
    pressEnter.setFillColor(Color(0, 0, 51));

    text1.setFillColor(Color::Green);

    timer(minText, secText, miliText, specText);

    int min = 0, sec = 0, mili = 0, spec = 0;

    Animation sExplosion(textures.t3, 0, 0, 256, 256, 48, 0.5);
    Animation sRock(textures.t4, 0, 0, 64, 64, 16, 0.5);
    Animation sRock_small(textures.t6, 0, 0, 64, 64, 16, 0.5);
    Animation sBullet(textures.t5, 0, 0, 32, 64, 16, 0.1);
    Animation sPlayer(textures.t1, 0, 0, 50, 60, 1, 0);
    Animation sPlayer_go(textures.t1, 54, 73, 35, 80, 1, 0);
    Animation sExplosion_ship(textures.t7, 0, 0, 192, 192, 64, 0.5);
    Animation sBullet2(textures.t8, 0, 0, 32, 24, 16, 0.1);
    Animation sAlien(textures.t10, 20, 10, 60, 40, 1, 0);
    Animation sCoin(textures.t9, 0, 0, 32, 17, 1, 0);
    Animation sAlien2(textures.t11, 0, 0, 30, 50, 1, 0);

    std::list<Entity *>
        entities;
    std::list<player *> x, y;

    player *p = new player();
    p->settings(sPlayer, 200, 200, 0, 20);
    entities.push_back(p);

    bool gameOver = false;
    bool changeMap = false;
    bool startGame = false;
    while (window.isOpen())
    {

        handleEvents(window, entities, sBullet, sBullet2, p, gameOver, changeMap, startGame);
        if (!gameOver)
        {
            alienEnemy(entities, sExplosion, sCoin, sExplosion_ship,
                       sPlayer, p, sAlien, sAlien2, spec);
            smallAsteroids(entities, sExplosion, sRock_small, sExplosion_ship,
                           sPlayer, p, spec);

            spaceShipCondition(p, sPlayer, sPlayer_go, entities);
            asteroidsCondition(entities, sRock, sAlien);
            redrawFrame(window, background, entities, coin, p, minText, secText, miliText,
                        text1, min, sec, mili, specText, spec, change, changeMap, startGame,
                        Menu, pressEnter);
        }
    }

    return 0;
}