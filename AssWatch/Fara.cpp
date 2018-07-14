#include "Fara.h"
#include "Rockfire.h"
#include <math.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
Fara::Fara(float pos_x, float pos_y)
{
    altimate.openFromFile("music\\fara\\altimate.ogg");

    fara_get_hurt1.openFromFile("music\\fara\\get_hurt1.ogg");

    my_texture.loadFromFile("picture\\fara\\fara.png");

    My_sprite.setTexture(my_texture);
    My_sprite.setPosition(pos_x, pos_y);
    speed_ratio = 0.5;
    xmax = rand()%(1650-1550+1)+1550;
    life = 200;
    speed_in = 1.5;
    move_smooth = rand()%(200-100+1)+100;
    is_alive = 1;
    dead_index = 0;
    super_fire_index = 300;
    is_super_fire=0;
    fire_index = -1;
    is_dying = 0;
}

Fara::~Fara()
{
    //dtor
}

void Fara::move(int time)
{
    if(My_sprite.getPosition().x>xmax){
        My_sprite.move(-speed_in, 0);
    }
    if(time%move_smooth==0||speed.x==0||speed.y==0){
        speed.x = speed_ratio*(rand()%(1+1+1)-1);
        speed.y = speed_ratio*(rand()%(1+1+1)-1);
    }
    speed.x*=0.999;
    speed.y*=0.999;
    My_sprite.move(speed.x, speed.y);
}



bool Fara::hurt(int hurt){
    life -= hurt;
    if(life<0){
        dead_texture[0].loadFromFile("picture\\fara\\fara_die1.png");
        dead_texture[1].loadFromFile("picture\\fara\\fara_die2.png");
        dead_texture[2].loadFromFile("picture\\fara\\fara_die3.png");
        dead_texture[3].loadFromFile("picture\\fara\\fara_die4.png");
        altimate.play();
        is_alive = 0;
        is_super_fire = 1;
        return 1;
    }
    return 0;
}

bool Fara::draw_dead(){
    if(dead_index<4){
        My_sprite.setTexture(dead_texture[dead_index]);
        dead_index++;
        return 1;
    }
    else{
        return 0;
    }
}

void Fara::create_fire_nomal(Weapon & myWeapon,float mx,float my,float farax,float faray){
    fire_index++;
    if(fire_index%500==0){
        Rockfire_p = new Rockfire(mx-farax, my-faray, farax, faray);
        myWeapon.add_rockfire(Rockfire_p);
    }
}

void Fara::create_fire_super(Weapon & myWeapon,float farax,float faray){
    if(super_fire_index%15==0){
        float randx = rand()%(-1+10+1)-10;
        float randy = rand()%(1+1+1)-1;
        Rockfire_p = new Rockfire(randx,randy,farax+20,faray,2);
        myWeapon.add_rockfire(Rockfire_p);
    }
    else if(super_fire_index<0){
        is_dying = 1;
    }
    super_fire_index--;
}
