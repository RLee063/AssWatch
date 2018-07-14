#ifndef DROGEN_H
#define DROGEN_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

class Drogen
{
    public:
        sf::Sprite My_sprite;
        Drogen(float,float);
        virtual ~Drogen();
        sf::Music drogen_music;

        void attack();
    protected:

        sf::Texture my_texture;
    private:
};

#endif // DROGEN_H
