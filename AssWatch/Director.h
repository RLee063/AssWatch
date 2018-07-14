#ifndef DIRECTOR_H
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#define DIRECTOR_H
#include "Weapon.h"
#include "GenJi.h"
#include "Shuriken.h"
#include "Fara.h"
#include "Enemy.h"
#include "Friend.h"
#include "Miicre.h"
#include "Drogen.h"
#include "Hero.h"
class Director
{
    public:
        sf::Texture shuriken_tb;
        sf::Sprite Shuriken_tb;
        sf::Music bg;
        sf::Texture dragon_begin;
        sf::Sprite Dragon_begin;
        sf::Texture head;
        sf::Sprite Head;
        sf::Text shuriken_num;
        sf::Font game_over_font;
        sf::Text count_down;
        sf::Texture gameover;
        sf::Sprite Gameover;
        sf::Vector2f life_rect;
        sf::RectangleShape rectangle;
        sf::Text life_text;
        sf::Color Red;
        sf::Font altimate_font;
        sf::Text altimate_text;
        sf::Texture altimate;
        sf::Sprite Altimate;
        int dragon_begin_delay;
        void show_altimate();
        bool is_show_altimate;
        int is_pause;
        int fara_num;
        int creat_micre_time;
        int pause_delay;
        Hero myHero;
        Weapon myWeapon;
        long long time = 0;
        void refresh_text();
        void Pause();
        void Refresh();
        void Collide();
        void Update();
        void show_gameover();
        sf::Texture background;
        sf::Sprite Background;
        bool is_gameover;
        int count_down_num;
        bool is_restart;
		int delay;
        //================================================================================================
        //
        sf::Music neverdie;
        //temp number
        sf::FloatRect RockBox_F;
        sf::FloatRect DragonBox;
        sf::FloatRect GenjiBox;
        sf::FloatRect FaraBox;
        sf::FloatRect ShurikenBox;
        sf::FloatRect RockBox;
        sf::RenderWindow* window;




        //some p
        Drogen * drogen_p;
        Rockfire * Rockfire_p;
        Fara * Fara_p;
        Shuriken * Shuriken_p;
        GenJi * Genji_p;                          //initial GenJi



        Director();
        void Create();
        virtual ~Director();

    protected:

    private:
};

#endif // DIRECTOR_H
