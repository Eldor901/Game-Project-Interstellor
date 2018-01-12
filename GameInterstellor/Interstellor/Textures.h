struct Textures
{
    Texture t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13;
};
void loadTextures(Textures &textures)
{
    textures.t1.loadFromFile("images/spaceship.png");
    textures.t2.loadFromFile("images/background.png");
    textures.t3.loadFromFile("images/explosions/type_C.png");
    textures.t4.loadFromFile("images/rock.png");
    textures.t5.loadFromFile("images/fire_blue.png");
    textures.t6.loadFromFile("images/rock_small.png");
    textures.t7.loadFromFile("images/explosions/type_B.png");
    textures.t8.loadFromFile("images/fire_red.png");
    textures.t9.loadFromFile("images/coin.png");
    textures.t10.loadFromFile("images/AlienShipp.png");
    textures.t11.loadFromFile("images/hello.png");
    textures.t12.loadFromFile("images/background2.jpg");
    textures.t13.loadFromFile("images/interpic.png");

    textures.t1.setSmooth(true);
    textures.t2.setSmooth(true);
    textures.t10.setSmooth(true);
    textures.t11.setSmooth(true);
    textures.t12.setSmooth(true);
    textures.t13.setSmooth(true);
}