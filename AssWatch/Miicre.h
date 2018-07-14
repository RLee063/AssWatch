#ifndef MIICRE_H
#define MIICRE_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "GenJi.h"

class Miicre
{
    public:
        //music
        sf::Music shooting_M;
        sf::Music highnoon_M;
        sf::Music die_M;
        //life
        int life;
        bool is_alive;
        //sprite
        bool is_circle;
        sf::FloatRect MicreBox;
        float temp;
        bool is_aimming;
        int lock_delay;
        sf::Texture altimate_circle;
        sf::Sprite Altimate_circle;
        sf::Texture my_texture;
        sf::Sprite My_sprite;

        void update(sf::Vector2f, GenJi*, sf::RenderWindow*);
        void shoot(GenJi*);
        void getGB();
        void die();
        void move();
        void hurt(int);
        Miicre();
        virtual ~Miicre();

    protected:

    private:
};

#endif // MIICRE_H
