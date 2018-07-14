#include "Miicre.h"

Miicre::Miicre()
{
    is_circle = 1;
    shooting_M.openFromFile("music\\micre\\shoot.ogg");
    highnoon_M.openFromFile("music\\micre\\highnoon.ogg");
    die_M.openFromFile("music\\micre\\die.ogg");
    highnoon_M.play();
    is_alive = 1;
    life = 150;
    is_aimming = 1;
    temp=0;
    lock_delay = 200;
    my_texture.loadFromFile("picture\\micre\\micre_aiming.png");
    My_sprite.setTexture(my_texture);
    float pos_y = rand()%(900-100+1)+100;
    My_sprite.setPosition(1920, pos_y);
    altimate_circle.loadFromFile("picture\\micre\\circle.png");
    Altimate_circle.setTexture(altimate_circle);
}

Miicre::~Miicre()
{
    //dtor
}

void Miicre::move(){
    if(My_sprite.getPosition().x>1500)
        My_sprite.move(-0.1,0);
    else{
        float ry = (rand()%(1+1+1)-1);
        My_sprite.move(0, ry);
    }
}

void Miicre::update(sf::Vector2f genjiPos, GenJi * p,sf::RenderWindow* window){
    if(is_aimming){
        Altimate_circle.setPosition(genjiPos.x-30+5+temp, genjiPos.y-50-10+temp);

        if(Altimate_circle.getScale().x<=0.3){
            if(lock_delay<0){

                is_aimming = 0;
                shoot(p);
                lock_delay = 20;
                altimate_circle.loadFromFile("picture\\micre\\circle.png");
                Altimate_circle.setTexture(altimate_circle);
                is_circle = 1;
                return;
            }
            else{
                if(is_circle){
                    Altimate_circle.setPosition(genjiPos.x+30,genjiPos.y-10);
                    altimate_circle.loadFromFile("picture\\micre\\lock.png");
                    Altimate_circle.setTexture(altimate_circle);
                    is_circle = 0;
                }

                lock_delay--;
            }
        }
        else{
            temp+=0.05;
            Altimate_circle.setScale(Altimate_circle.getScale().x-0.0005, Altimate_circle.getScale().y-0.0005);
        }
        window->draw(Altimate_circle);
    }
}

void Miicre::shoot(GenJi*p){
    shooting_M.play();
    p->hurt(30);
}

void Miicre::getGB(){
    MicreBox = My_sprite.getGlobalBounds();
}

void Miicre::hurt(int damage){
    life -= damage;
    if(life<0){
        is_alive = 0;
    }
}

void Miicre::die(){
    die_M.play();
}
