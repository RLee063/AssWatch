#include "Drogen.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
Drogen::Drogen(float x, float y)
{
    my_texture.loadFromFile("picture\\fire\\Drogen_nomal.png");
    My_sprite.setTexture(my_texture);
    My_sprite.setPosition(x, y);
    My_sprite.move(-20, 55);
    drogen_music.openFromFile("music\\genji\\drogen.ogg");
}

Drogen::~Drogen()
{
    //dtor
}

void Drogen::attack(){

}
