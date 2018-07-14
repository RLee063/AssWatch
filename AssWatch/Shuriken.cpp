#include "Shuriken.h"
#include <math.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
Shuriken::Shuriken(float x, float y, float pos_x, float pos_y)
{
    damage = 5;
    my_texture.loadFromFile("picture\\fire\\feibiao.png");
    My_sprite.setTexture(my_texture);

    My_sprite.setPosition(pos_x+10,pos_y+10);
    speed.x = totalspeed*cos(x,y);
    speed.y = totalspeed*sin(x,y);
}

Shuriken::Shuriken(float x, float y, float pos_x, float pos_y, int index)
{
    float icos;
    float isin;
    my_texture.loadFromFile("picture\\fire\\feibiao.png");
    My_sprite.setTexture(my_texture);
    My_sprite.setPosition(pos_x+10,pos_y+10);
    switch(index){
        case 1:
            icos = cos(x,y);
            isin = sin(x,y);
            if(icos>=0&&isin>=0){
                isin += 0.2;
                icos -= 0.2;
            }
            else if(icos<=0&&isin>=0){
                isin -= 0.2;
                icos -= 0.2;
            }
            else if(icos<=0&&isin<=0){
                isin -= 0.2;
                icos += 0.2;
            }
            else if(icos>=0&&isin<=0){
                isin += 0.2;
                icos += 0.2;
            }
            speed.x = 0.9*totalspeed*icos;
            speed.y = 0.9*totalspeed*isin;
            break;

        case 2:
            icos = cos(x,y);
            isin = sin(x,y);
            if(icos>=0&&isin>=0){
                isin -= 0.2;
                icos += 0.2;
            }
            else if(icos<=0&&isin>=0){
                isin += 0.2;
                icos += 0.2;
            }
            else if(icos<=0&&isin<=0){
                isin += 0.2;
                icos -= 0.2;
            }
            else if(icos>=0&&isin<=0){
                isin -= 0.2;
                icos -= 0.2;
            }
            speed.x = 0.9*totalspeed*icos;
            speed.y = 0.9*totalspeed*isin;
            break;
    }
}

float Shuriken::cos(float x, float y)
{
    return x/sqrt(x*x+y*y);
}

float Shuriken::sin(float x, float y)
{
    return y/sqrt(x*x+y*y);
}

void Shuriken::move()
{
    My_sprite.move(speed.x, speed.y);
}

sf::Sprite Shuriken::get(){
    return My_sprite;
}
