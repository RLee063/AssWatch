#include "Rockfire.h"
#include <math.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
Rockfire::Rockfire(float x, float y, float pos_x, float pos_y)
{
    fire.openFromFile("music\\fara\\rocketfire.ogg");
    fire.play();
    my_texture.loadFromFile("picture\\fire\\rockfire.png");
    My_sprite.setTexture(my_texture);

    My_sprite.setPosition(pos_x+10,pos_y+10);
    speed.x = totalspeed*cos(x,y);
    speed.y = totalspeed*sin(x,y);
}

Rockfire::Rockfire(float x, float y, float pos_x, float pos_y, float n){
    my_texture.loadFromFile("picture\\fire\\rockfire2.png");
    My_sprite.setTexture(my_texture);
    totalspeed = 4;
    My_sprite.setPosition(pos_x+10,pos_y+10);
    speed.x = totalspeed*cos(x,y);
    speed.y = totalspeed*sin(x,y);
}

Rockfire::~Rockfire()
{
    //dtor
}

float Rockfire::cos(float x, float y)
{
    return x/sqrt(x*x+y*y);
}

float Rockfire::sin(float x, float y)
{
    return y/sqrt(x*x+y*y);
}

void Rockfire::move()
{
    My_sprite.move(speed.x, speed.y);
}

sf::Sprite Rockfire::get(){
    return My_sprite;
}
