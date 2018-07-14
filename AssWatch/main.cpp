#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <list>
#include "Director.h"
#include "GenJi.h"
#include "Shuriken.h"
#include "Fara.h"
#include "Enemy.h"
#include "Friend.h"
#include "Drogen.h"
#include "Hero.h"

#include "Weapon.h"

using namespace std;
using namespace sf;

int main()
{
//    sf::RectangleShape rectangle;
//    rectangle.setSize(sf::Vector2f(100, 50));
//    rectangle.setOutlineColor(sf::Color::Red);
//    rectangle.setOutlineThickness(5);
//    rectangle.setPosition(10, 20);

    Director myDirector;
    myDirector.myHero.add_Genji();
    while (myDirector.window->isOpen())
    {
        //temple time

        //initial some
        sf::Event event;
        if (myDirector.window->pollEvent(event))
        {
            if (event.type == Event::Closed){
                myDirector.window->close();
            }
        }

        {
            if (sf::Keyboard::isKeyPressed(Keyboard::D)){
                if(myDirector.myHero.Genji_p->My_sprite.getPosition().x + myDirector.myHero.Genji_p->speed.x <= 1700){
                    myDirector.myHero.Genji_p->speed.x=myDirector.myHero.Genji_p->speed_max;
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
                if(myDirector.myHero.Genji_p->My_sprite.getPosition().x - myDirector.myHero.Genji_p->speed.x >= 0){
                    myDirector.myHero.Genji_p->speed.x=-(myDirector.myHero.Genji_p->speed_max);
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
                if(myDirector.myHero.Genji_p->My_sprite.getPosition().y + myDirector.myHero.Genji_p->speed.y <= 800){
                    myDirector.myHero.Genji_p->speed.y=myDirector.myHero.Genji_p->speed_max;
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
                if(myDirector.myHero.Genji_p->My_sprite.getPosition().y - myDirector.myHero.Genji_p->speed.y >= 0){
                    myDirector.myHero.Genji_p->speed.y=-(myDirector.myHero.Genji_p->speed_max);
                }
            }
            //fire
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                if(myDirector.myHero.Genji_p->drogen_alive && !myDirector.myHero.Genji_p->is_attacking){
                    myDirector.myHero.Genji_p->is_attacking = 1;
                }

                else{
                    if(!myDirector.myHero.Genji_p->is_reload&&myDirector.myWeapon.is_create_shuriken_time<=0&&!myDirector.myHero.Genji_p->drogen_alive){
                            myDirector.myWeapon.is_create_shuriken_time = 150;
                            myDirector.myWeapon.is_create_shuriken = 7;

                    }
                }
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Right)){
                if(!myDirector.myHero.Genji_p->is_reload&&myDirector.myWeapon.is_create_shuriken_time<=0&&!myDirector.myHero.Genji_p->is_attacking){
                    myDirector.myWeapon.is_create_shuriken_time = 100;
                    myDirector.myWeapon.is_create_shuriken_right = 3;
                }
            }
            //skill

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
                if(myDirector.myHero.Genji_p->is_dragon_ready){
                    if(!myDirector.myHero.Genji_p->drogen_alive){
                        myDirector.myHero.Genji_p->draw_drogen(myDirector.myHero.Genji_p->My_sprite.getPosition());
                        myDirector.altimate_text.setColor(sf::Color::Green);
                        myDirector.Pause();
                        myDirector.show_altimate();
                    }
                }
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
                myDirector.Pause();
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
                if(myDirector.is_gameover){
                    myDirector.is_restart=1;
                }
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::R)){
                if(!myDirector.myHero.Genji_p->is_reload){
                    myDirector.myHero.Genji_p->reload();
                }
            }
        }
        // Clear screen

        myDirector.Refresh();
        /////////////////////////////////////////Create sprite/////////////////////////////////////////////

        //////////////////////////////////////////////////////////////////////////

        /////////////////////////////collide test/////////////////////////////////


        //////////////////////////////////////////////////////////////////////////


        /////////////////////////////Update the information///////////////////////////////
        // Draw background

        ///////////////////////////////////////////////////////////////////////////



        // Update the window
        //hand the time out of limited
        if(myDirector.time > 10000000){
            myDirector.time = 0;
        }
    }
    return EXIT_SUCCESS;
}
