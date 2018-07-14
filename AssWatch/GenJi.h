#ifndef GENJI_H
#define GENJI_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Shuriken.h"
#include "Friend.h"
#include "Drogen.h"
#include "Weapon.h"
using namespace std;
class GenJi
{
    public:
        GenJi(float, float);
        virtual ~GenJi();
        //for collide
        int Attack;
        //music
        sf::Music reload_M;
        sf::Music Right_shuriken;
        sf::Music Shoot_enemy;
        sf::Music Shoot_bullet;
        sf::Music Got_hurt1;
        sf::Music Left_shuriken;
        //drogen
        int shuriken_num;
        int drogen_delay;
        int dragon_energy;
        int dragon_index;
        bool is_dragon_ready;
        bool is_attacking;
        int drogen_time = 0;
        sf::Vector2f drogen_pos[8];
        int drogen_index;
        bool drogen_alive;
        void get_energy(int );
        void draw_drogen(sf::Vector2f);
        void drogen_attack();
        void drogen_kill();
        Drogen * my_drogen;
        int drogen_angle[8];
        //life
        int life;
        void hurt(int);
        void relife(int);
        bool is_alive;
        //sprite
        sf::Texture my_texture;
        sf::Sprite My_sprite;
        virtual sf::Sprite get();
        //shuriken
        bool is_reload;
        int is_create_shuriken = 0;
        int is_create_shuriken_right = 0;
        Shuriken * Shuriken_p;
        void reload();
        int reload_delay;
        //list<Shuriken*> shuriken_list;
        void left_shuriken(float, float, float , float, Weapon &);
        void right_shuriken(float, float, float, float, Weapon &);
        //move
        sf::Vector2f speed;
        float speed_max = 2;
        void move();
        //for die
        sf::Texture dead_texture[3];
        int dead_index;
        bool is_dying;
        void dead();
    protected:

    private:
};

#endif // GENJI_H
