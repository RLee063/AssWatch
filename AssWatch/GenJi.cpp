#include "GenJi.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Drogen.h"
#include <iostream>
#include "Weapon.h"
using namespace std;
GenJi::GenJi(float pos_x, float pos_y)
{
    reload_delay=0;
    is_reload = 0;
    shuriken_num = 24;
    drogen_delay=-1;
    dragon_energy = 0;
    is_dragon_ready = 0;
    my_drogen = new Drogen(pos_x, pos_y);
    reload_M.openFromFile("music\\genji\\reload.ogg");
    Got_hurt1.openFromFile("music\\genji\\get_hurt1.ogg");
    Shoot_enemy.openFromFile("music\\genji\\genji_shoot_enemy.ogg");
    Shoot_bullet.openFromFile("music\\genji\\genji_shoot_bullet.ogg");
    Left_shuriken.openFromFile("music\\genji\\genji_left.ogg");
    Right_shuriken.openFromFile("music\\genji\\genji_right.ogg");
    my_texture.loadFromFile("picture\\genji\\genji.png");
    My_sprite.setTexture(my_texture);
    My_sprite.setPosition(pos_x, pos_y);
    is_attacking = 0;
//  drogen_index = 0;
    //for die
    dead_texture[0].loadFromFile("picture\\genji\\genji_dy0.png");
    dead_texture[1].loadFromFile("picture\\genji\\genji_dy1.png");
    dead_texture[2].loadFromFile("picture\\genji\\genji_dy2.png");
    is_alive = 1;
    is_dying = 0;
    dead_index = 0;
    life = 100;
    dragon_index = 0;
    drogen_alive = 0;
    int Attack = 20;
    drogen_pos[1] = {190, -50};
    drogen_pos[2] = {200, -10};
    drogen_pos[3] = {220, 30};
    drogen_pos[4] = {240, 70};
    drogen_pos[5] = {250, 100};
    drogen_pos[6] = {230, 130};
    drogen_pos[7] = {200, 150};

    drogen_angle[1] = 120;
    drogen_angle[2] = 20;
    drogen_angle[3] = 20;
    drogen_angle[4] = 20;
    drogen_angle[5] = 20;
    drogen_angle[6] = 20;
    drogen_angle[7] = 20;
}

GenJi::~GenJi()
{
    //dtor
}

void GenJi::get_energy(int n){
    if(!is_dragon_ready&&!drogen_alive){
        dragon_energy+=n; //-----------------------------
        if(dragon_energy>=100){
            dragon_energy=100;
            is_dragon_ready=1;
        }
    }
}

void GenJi::move(){
    if(reload_delay>=0){
        reload_delay--;
        if(reload_delay<=0){
            is_reload = 0;
            shuriken_num = 24;
        }
    }
    if(drogen_alive){
        my_drogen->My_sprite.move(speed);
    }
    My_sprite.move(speed);
}

sf::Sprite GenJi::get(){
    return My_sprite;
}

void GenJi::drogen_kill(){
    is_attacking = 0;
    drogen_alive=0;
    is_dragon_ready=0;
}

void GenJi::hurt(int dam){
    life-=dam;
    if(life<0){
        is_dying = 1;
        is_alive = 0;
    }
}

void GenJi::left_shuriken(float dx, float dy, float genjix, float genjiy, Weapon & myWeapon){
    //if(!is_reload){
        Shuriken_p =  new Shuriken(dx, dy, genjix, genjiy);
        myWeapon.add_Shuriken(Shuriken_p);
        shuriken_num-=1;
        if(shuriken_num<=0){
            reload();
        }
    //}
}

void GenJi::right_shuriken(float dx, float dy, float genjix, float genjiy, Weapon & myWeapon){
    if(!is_reload){
        Shuriken_p =  new Shuriken(dx, dy, genjix, genjiy);
        myWeapon.add_Shuriken(Shuriken_p);
        Shuriken_p =  new Shuriken(dx, dy, genjix, genjiy, 1);
        myWeapon.add_Shuriken(Shuriken_p);
        Shuriken_p =  new Shuriken(dx, dy, genjix, genjiy, 2);
        myWeapon.add_Shuriken(Shuriken_p);
        shuriken_num-=3;
        if(shuriken_num<=0){
            reload();
        }
    }
}

void GenJi::draw_drogen(sf::Vector2f pos){
    dragon_energy = 0;
    my_drogen->drogen_music.play();
    my_drogen->My_sprite.setPosition(pos.x-30, pos.y+60);
    drogen_alive = 1;
    drogen_time = 5000;
}

void GenJi::drogen_attack(){
    if(drogen_delay<0){
        dragon_index += 1;
        if(dragon_index == 8){
            my_drogen->My_sprite.setPosition(My_sprite.getPosition());
            my_drogen->My_sprite.move(-20,55);
            my_drogen->My_sprite.rotate(120);
        }
        else if(dragon_index > 15){
            drogen_delay = 20;
            is_attacking = 0;
            dragon_index = 0;
        }
        else if(dragon_index < 8){
            my_drogen->My_sprite.setPosition(My_sprite.getPosition()+drogen_pos[dragon_index]);
            my_drogen->My_sprite.rotate(drogen_angle[dragon_index]);
        }
    }
}

void GenJi::dead(){
    dead_index++;
    if(dead_index<4){
        My_sprite.setTexture(dead_texture[dead_index-1]);
    }
    else{
        is_dying = 0;
    }
}

void GenJi::relife(int n){
    life+=n;
    if(life>100){
        life=100;
    }
}

void GenJi::reload(){
    reload_M.play();
    is_reload =1;
    reload_delay = 400;
}

