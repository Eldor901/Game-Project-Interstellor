#pragma once
#include <SFML\Graphics.hpp>
const int HEIGHT_MAP = 25; //размер карты высота
const int WIDTH_MAP = 40;  //размер карты ширина

sf::String Map[HEIGHT_MAP] = {
    "0000000000000000000000000000000000000000",
    "0                                      0",
    "0                                      0",
    "0                                      0",
    "0                S                     0",
    "0                                      0",
    "0                                      0",
    "0          S                           0",
    "0                   S                  0",
    "0                                      0",
    "0                                      0",
    "0                           A          0",
    "0                                      0",
    "0                                      0",
    "0                                      0",
    "0                                      0",
    "0                                      0",
    "0                 s                    0",
    "0                                      0",
    "0                                      0",
    "0                                      0",
    "0                                      0",
    "0                                      0",
    "0                                      0",
    "0000000000000000000000000000000000000000",
};

for (int i = 0; i < HEIGHT_MAP; i++)
    for (int j = 0; j < WIDTH_MAP; j++)
    {
        if (Map[i][j] == 'S')
        {
            coin.setTextureRect(IntRect(0, 0, 32, 17));
        }
        if (Map[i][j] == 'A')
            coin.setTextureRect(IntRect(0, 0, 32, 17));

        if (Map[i][j] == '0')
            continue;
        if (Map[i][j] == ' ')
            continue;

        coin.setPosition(j * 32, i * 32);
        window.draw(coin);
    }