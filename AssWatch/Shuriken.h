#ifndef SHURIKEN_H
#define SHURIKEN_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Friend.h"

class Shuriken
{
    public:
        int damage;
        sf::Sprite My_sprite;
        Shuriken(float, float, float, float);
        Shuriken(float, float, float, float, int);
        void move();
        virtual sf::Sprite get();
    protected:
        float angle_ratio = 0.2;
        float totalspeed = 5;
        float sin(float, float);
        float cos(float, float);
        sf::Texture my_texture;
        sf::Vector2f speed;

    private:
};

#endif // SHURIKEN_H
