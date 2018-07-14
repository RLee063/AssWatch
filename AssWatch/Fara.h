#ifndef FARA_H
#define FARA_H
#include <list>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "Enemy.h"
#include "Rockfire.h"
#include "Weapon.h"

using namespace std;
class Fara
{
    public:

        //for collide
        int Attack;
        //Music
        sf::Music altimate;
        sf::Sprite My_sprite;
        sf::Music fara_dead;
        sf::Music fara_get_hurt1;
        //rocket fire
        int fire_index;
        bool is_super_fire;
        void create_fire_nomal(Weapon&, float,float,float,float);
        void create_fire_super(Weapon&, float,float);
        int super_fire_index;
        Fara(float, float);
        //move
        void move(int);
        int move_smooth;
        //dead
        int life;
        sf::Texture dead_texture[4];
        int dead_index;
        int dead_index2;
        bool hurt(int);
        bool is_alive;
        bool is_dying;
        void dead();
        bool draw_dead();
        virtual ~Fara();


    protected:
        Rockfire * Rockfire_p;
        float xmax;
        float speed_in;
        float speed_ratio;
        sf::Texture my_texture;
        sf::Vector2f speed;
    private:
};

#endif // FARA_H
