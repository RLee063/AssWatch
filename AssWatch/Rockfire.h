#ifndef ROCKFIRE_H
#define ROCKFIRE_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "Enemy.h"
class Rockfire
{
    public:
        sf::Vector2f speed;
        sf::Music fire;
        sf::Sprite My_sprite;
        Rockfire(float, float, float, float);
        Rockfire(float, float, float, float, float);
        virtual ~Rockfire();
        void move();
        virtual sf::Sprite get();
    protected:
        float totalspeed = 2;
        float sin(float, float);
        float cos(float, float);
        sf::Texture my_texture;

    private:
};

#endif // ROCKFIRE_H
