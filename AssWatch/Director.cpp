#include "Director.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <string>
using namespace std;
using namespace sf;
Director::Director()
{
    is_show_altimate = 0;
    is_gameover = 0;
    shuriken_tb.loadFromFile("picture\\feibiao_num.png");
    Shuriken_tb.setTexture(shuriken_tb);
    Shuriken_tb.setPosition(60, 40);

    dragon_begin_delay = 500;
    dragon_begin.loadFromFile("picture\\dragon_begin.jpg");
    Dragon_begin.setTexture(dragon_begin);
    Dragon_begin.setPosition(100,50);

    creat_micre_time = 5000;
    fara_num =2;
    bg.openFromFile("music\\background.ogg");
    bg.play();
    bg.setLoop(1);
    neverdie.openFromFile("music\\neverdie.ogg");

    head.loadFromFile("picture\\head.png");
    Head.setTexture(head);
    Head.setPosition(70,850);

    is_restart= 0;
    rectangle.setOutlineColor(sf::Color::Green);
    rectangle.setFillColor(sf::Color::White);
    rectangle.setOutlineThickness(4);
    game_over_font.loadFromFile("Font\\OCRAStd.otf");
    count_down_num = 9;
    gameover.loadFromFile("picture\\gameover.jpg");
    Gameover.setTexture(gameover);
    Gameover.setPosition(150,70);
    Red=sf::Color::Red;
    sf::Color color1(20, 120, 30);
    sf::Color color2(4,4,4);

    altimate.loadFromFile("picture\\genji_altimate.png");
    Altimate.setTexture(altimate);
    Altimate.setPosition(700,700);

    altimate_font.loadFromFile("Font\\altimate.ttf");
    count_down.setFont(altimate_font);
    count_down.setCharacterSize(150);
    count_down.setColor(sf::Color::Green);
    count_down.setOutlineThickness(4);
    count_down.setOutlineColor(sf::Color::Black);
    count_down.setPosition(900,400);

    shuriken_num.setFont(altimate_font);
    shuriken_num.setCharacterSize(30);
    shuriken_num.setPosition(145,55);
    shuriken_num.setColor(color1);
    shuriken_num.setOutlineColor(color2);
    shuriken_num.setOutlineThickness(2);

    altimate_text.setFont(altimate_font);
    altimate_text.setString("%0");
    altimate_text.setCharacterSize(30);
    altimate_text.setPosition(950,950);
    altimate_text.setColor(color1);
    altimate_text.setOutlineColor(color2);
    altimate_text.setOutlineThickness(2);

    life_text.setFont(altimate_font);
    life_text.setCharacterSize(30);
    life_text.setPosition(220,860);
    life_text.setColor(color1);
    life_text.setOutlineColor(color2);
    life_text.setOutlineThickness(2);

    pause_delay=6;
    is_pause = 0;
    window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "AssWatch");
    background.loadFromFile("picture\\background.jpg");
    Background.setTexture(background);
    window->draw(Background);
    myHero.add_Genji();
	delay = 0;
    //ctor
}

Director::~Director()
{
    //dtor
}

void Director::show_altimate(){
    dragon_begin_delay--;
    if(dragon_begin_delay>=0){
        is_show_altimate = 1;
        if(dragon_begin_delay%10==0){
            Dragon_begin.setPosition(Dragon_begin.getPosition().x-5, Dragon_begin.getPosition().y);
        }
    }
    else{
        Dragon_begin.setPosition(100,50);
        dragon_begin_delay = 500;
        is_show_altimate = 0;
        Pause();
    }
}

void Director::Pause(){
    if(pause_delay>100){
        if(is_pause==0){
            is_pause=1;
            pause_delay=0;
        }
        else{
            is_pause=0;
            pause_delay=0;
        }
    }
}

void Director::Refresh(){
    pause_delay++;
    if(is_show_altimate){
        show_altimate();
        window->draw(Dragon_begin);
        window->display();
        return;
    }
    if(!is_pause)
    {
		if (delay++ % 700 != 0) {
			if (delay > 9999) delay = 1;
			return;
		}
        window->clear();
        Create();
        Collide();
        Update();
        refresh_text();
    }
    else if(is_gameover){
        show_gameover();
    }
    window->display();
    //test
}

void Director::show_gameover(){
    if(is_restart){
        neverdie.play();
        myHero.restart();
        is_gameover=0;
        count_down_num = 9;
        is_restart =0;
        Pause();
    }
    if(count_down_num<0){
        count_down.setPosition(450,400);
        count_down.setFont(game_over_font);
        char t[20] = "GAME OVER";
        string s =t;
        count_down.setString(s);
        window->draw(Gameover);
        window->draw(count_down);
    }
    else{
        time++;
        char t[3] = {};
        t[0] = count_down_num+48;
        string s = t;
        if(time%300==0){
            count_down_num--;
        }
        count_down.setString(s);
        window->draw(Gameover);
        window->draw(count_down);
    }
}

void Director::Create(){
        if(myHero.fara_list.size()<=fara_num&&time%200==0){                    //create fara
            float rx = rand()%(2100-1960+1)+1960;
            float ry = rand()%(900-100+1)+100;
            Fara_p = new Fara(rx, ry);
            myHero.fara_list.push_back(Fara_p);
        }
        // Create My fire
        if(myWeapon.is_create_shuriken>=0&&myWeapon.is_create_shuriken_time%25==0){
            if(myWeapon.is_create_shuriken==7){
                myHero.Genji_p->Left_shuriken.play();
            }
            if(myWeapon.is_create_shuriken==0){
                myWeapon.is_create_shuriken_time = 0;
            }

            if(myWeapon.is_create_shuriken > 4){
                float mx_shuriken = Mouse::getPosition(*window).x;            //get mouse position
                float my_shuriken = Mouse::getPosition(*window).y;

                float genjix = myHero.Genji_p->My_sprite.getPosition().x+80; //get genji position
                float genjiy = myHero.Genji_p->My_sprite.getPosition().y+20;

                myHero.Genji_p->left_shuriken(mx_shuriken-genjix, my_shuriken-genjiy, genjix, genjiy, myWeapon);
                myWeapon.is_create_shuriken --;
            }
            else{
                myWeapon.is_create_shuriken --;
            }
        }

        if(myWeapon.is_create_shuriken_right>=0&&myWeapon.is_create_shuriken_time%30==0){
            if(myWeapon.is_create_shuriken_right==0){
                myWeapon.is_create_shuriken_time=-1;
            }
            if(myWeapon.is_create_shuriken_right==3){
                //play music
                myHero.Genji_p->Right_shuriken.play();
                float mx_shuriken = Mouse::getPosition(*window).x;            //get mouse position
                float my_shuriken = Mouse::getPosition(*window).y;

                float genjix = myHero.Genji_p->My_sprite.getPosition().x+80; //get genji position
                float genjiy = myHero.Genji_p->My_sprite.getPosition().y+20;

                myHero.Genji_p->right_shuriken(mx_shuriken-genjix, my_shuriken-genjiy, genjix, genjiy, myWeapon);
                myWeapon.is_create_shuriken_right--;
            }
            else{
                myWeapon.is_create_shuriken_right--;
            }
        }
        // Create Enemy's fire
        if(1){                                            //the interval of fara's fire
            for(list<Fara*>::iterator i=myHero.fara_list.begin(); i!=myHero.fara_list.end(); i++){
                if((*i)->is_alive){
                    float mx = myHero.Genji_p->My_sprite.getPosition().x+10;          //get position of Genji
                    float my = myHero.Genji_p->My_sprite.getPosition().y+40;
                    float farax = (*i)->My_sprite.getPosition().x-5;       //get position of fara
                    float faray = (*i)->My_sprite.getPosition().y+70;
                    (*i)->create_fire_nomal(myWeapon, mx, my, farax, faray);
                }
                else if((*i)->is_super_fire){
                    float farax = (*i)->My_sprite.getPosition().x-5;       //get position of fara
                    float faray = (*i)->My_sprite.getPosition().y+70;
                    (*i)->create_fire_super(myWeapon,farax,faray);
                }
            }
        }
        //micre
    if((time+1)%creat_micre_time==0){
        myHero.add_micre();
    }
}

void Director::Update(){
    if(time%100==1&&creat_micre_time>2500){
        creat_micre_time--;
    }
        if((time+1)%5000==0){
            fara_num++;
        }
        time ++;
        if(myWeapon.is_create_shuriken_time>50)
            myWeapon.is_create_shuriken_time++;
        window->draw(Background);

        // for genji's dragon
        if(time%1000==0){
            myHero.Genji_p->relife(2);
        }

        if(myHero.Genji_p->is_alive){
            myHero.Genji_p->drogen_delay--;
            if(myHero.Genji_p->is_attacking&&time%5==0){
                myHero.Genji_p->drogen_attack();
            }
            if(myHero.Genji_p->drogen_alive){
                myHero.Genji_p->drogen_time --;
                if(myHero.Genji_p->drogen_time<0){
                    myHero.Genji_p->drogen_kill();
                }
                window->draw(myHero.Genji_p->my_drogen->My_sprite);
            }
        }
        // Draw&move genji
        window->draw(myHero.Genji_p->My_sprite);
        if(!myHero.Genji_p->is_dragon_ready&&time%200==1){
            myHero.Genji_p->get_energy(1);
        }
        if(myHero.Genji_p->is_alive)
        {
            myHero.Genji_p->move();
            myHero.Genji_p->speed.x = myHero.Genji_p->speed.x*0.99;
            myHero.Genji_p->speed.y = myHero.Genji_p->speed.y*0.99;
        }
        else{
            if(myHero.Genji_p->is_dying){
                myHero.Genji_p->dead();
            }
            else{
                is_gameover = 1;
                Pause();
            }

        }

        //draw shuriken
        for(list<Shuriken*>::iterator i=myWeapon.shuriken_list.begin(); i!=myWeapon.shuriken_list.end(); i++){
            window->draw((*i)->My_sprite);
            //move
            if((*i)->My_sprite.getPosition().x>2000||(*i)->My_sprite.getPosition().x<0||(*i)->My_sprite.getPosition().y<0||(*i)->My_sprite.getPosition().y>1080)
                {
                    delete *i;
                    i = myWeapon.shuriken_list.erase(i);
                    continue;
                }

            (*i)->move();
        }
        // Update fara & Rocket fire


        for(list<Fara*>::iterator i=myHero.fara_list.begin(); i!=myHero.fara_list.end(); i++){
            if((*i)->is_alive)
            {
                window->draw((*i)->My_sprite);
                (*i)->move(time);
                if((*i)->My_sprite.getPosition().y<0){
                    (*i)->My_sprite.move(0, 2);
                }
                else if((*i)->My_sprite.getPosition().y>800){
                    (*i)->My_sprite.move(0, -2);
                }
            }

            else{
                window->draw((*i)->My_sprite);
                if(time%20==0&&(*i)->is_dying){
                    (*i)->move(time);
                    if((*i)->draw_dead()){
                    }
                    else{
                        delete *i;
                        i = myHero.fara_list.erase(i);
                    }
                }
            }
        }
        //rocket fire
        for(list<Rockfire *>::iterator j=myWeapon.friend_rockfire_list.begin(); j!=myWeapon.friend_rockfire_list.end(); j++){
            window->draw((*j)->My_sprite);
            //move
            if((*j)->My_sprite.getPosition().x>2000||(*j)->My_sprite.getPosition().x<0||(*j)->My_sprite.getPosition().y<0||(*j)->My_sprite.getPosition().y>1080)
                {
                    delete *j;
                    j = myWeapon.friend_rockfire_list.erase(j);
                continue;
                }
            (*j)->move();
        }

        for(list<Rockfire *>::iterator j=myWeapon.rockfire_list.begin(); j!=myWeapon.rockfire_list.end(); j++){
            window->draw((*j)->My_sprite);
            //move
            if((*j)->My_sprite.getPosition().x>2000||(*j)->My_sprite.getPosition().x<0||(*j)->My_sprite.getPosition().y<0||(*j)->My_sprite.getPosition().y>1080)
                {
                    delete *j;
                    j = myWeapon.rockfire_list.erase(j);
                    continue;
                }
            (*j)->move();
        }
        //for micre
        for(list<Miicre *>::iterator i=myHero.micre_list.begin(); i!=myHero.micre_list.end();i++){
            if((*i)->is_alive){
                window->draw((*i)->My_sprite);
                (*i)->move();
                (*i)->update(myHero.Genji_p->My_sprite.getPosition(),myHero.Genji_p,window);
            }
            else{
                (*i)->die();
                delete *i;
                i = myHero.micre_list.erase(i);
            }
        }

        window->draw(Altimate);
        window->draw(altimate_text);
        window->draw(rectangle);
        window->draw(life_text);
        window->draw(Head);
        window->draw(shuriken_num);
        window->draw(Shuriken_tb);
}

void Director::refresh_text(){
    char j1[4];
    sprintf(j1, "%d", myHero.Genji_p->shuriken_num);
    string j2 = j1;
    shuriken_num.setString(j2);

    //
    char t1[4];
    sprintf(t1, "%d", myHero.Genji_p->life);

    string t2 = t1;
    life_text.setString(t2);

    //altimate
    if(myHero.Genji_p->dragon_energy<10){
        altimate_text.setPosition(888,890);
    }
    else if(myHero.Genji_p->dragon_energy==100){
        altimate_text.setPosition(870,890);
        altimate_text.setColor(Red);
    }
    else{
        altimate_text.setPosition(878,890);
    }
    char t[4];
    sprintf(t, "%d", myHero.Genji_p->dragon_energy);

    string tt = t;
    altimate_text.setString(tt);

    life_rect = sf::Vector2f(myHero.Genji_p->life*4,30);
    rectangle.setSize(life_rect);
    rectangle.setPosition(150, 920);
}

void Director::Collide(){
        GenjiBox = myHero.Genji_p->My_sprite.getGlobalBounds();
        DragonBox = myHero.Genji_p->my_drogen->My_sprite.getGlobalBounds();
        //for genji & rocket fire || rocket fire & dragon

            for(list<Rockfire *>::iterator j=myWeapon.rockfire_list.begin(); j!=myWeapon.rockfire_list.end(); j++){
                RockBox = (*j)->My_sprite.getGlobalBounds();
                if(RockBox.intersects(GenjiBox)){
                    delete *j;
                    j = myWeapon.rockfire_list.erase(j);
                    myHero.Genji_p->hurt(5);
                    //myHero.Genji_p->Got_hurt1.play();
                }
                if(myHero.Genji_p->drogen_alive&&RockBox.intersects(DragonBox)){
                    (*j)->speed=(-(*j)->speed);
                    myWeapon.add_friend_rockfire(*j);
                    //delete *j;
                    j = myWeapon.rockfire_list.erase(j);
                    myHero.Genji_p->Shoot_bullet.play();
                }
            }

        //for friend fire && fara && rock fire
            for(list<Rockfire *>::iterator j=myWeapon.friend_rockfire_list.begin(); j!=myWeapon.friend_rockfire_list.end(); j++){
                RockBox_F = (*j)->My_sprite.getGlobalBounds();
                for(list<Rockfire *>::iterator i=myWeapon.rockfire_list.begin(); i!=myWeapon.rockfire_list.end(); i++){
                    RockBox = (*i)->My_sprite.getGlobalBounds();
                    if(RockBox_F.intersects(RockBox)){
                        delete *j;
                        j = myWeapon.friend_rockfire_list.erase(j);
                        delete *i;
                        i = myWeapon.rockfire_list.erase(i);
                        myHero.Genji_p->Shoot_bullet.play();
                    }
                }
                for(list<Fara*>::iterator i=myHero.fara_list.begin(); i!=myHero.fara_list.end(); i++){
                    FaraBox = (*i)->My_sprite.getGlobalBounds();
                    if(FaraBox.intersects(RockBox_F)){
                        refresh_text();
                        myHero.Genji_p->get_energy(3);  //8888888888888888888888
                        delete *j;
                        j = myWeapon.friend_rockfire_list.erase(j);
                        myHero.Genji_p->Shoot_enemy.play();
                        (*i)->hurt(20);
                    }
                }
            }

        //for fara & shuriken || fara & dragon
        for(list<Shuriken*>::iterator i=myWeapon.shuriken_list.begin(); i!=myWeapon.shuriken_list.end(); i++){
            ShurikenBox = (*i)->My_sprite.getGlobalBounds();
            for(list<Fara*>::iterator j=myHero.fara_list.begin(); j!=myHero.fara_list.end(); j++){
                if((*j)->is_alive){
                    FaraBox = (*j)->My_sprite.getGlobalBounds();
                    if(FaraBox.intersects(ShurikenBox)){
                        refresh_text();
                        myHero.Genji_p->get_energy(3);
                        delete *i;
                        i = myWeapon.shuriken_list.erase(i);
                        myHero.Genji_p->Shoot_enemy.play();
                        (*j)->hurt(20);

                        if((*j)->is_alive){
                            //(*j)->fara_get_hurt1.play();
                        }
                    }
//                    if(myHero.Genji_p->drogen_alive&&FaraBox.intersects(DragonBox)){
//                        cout<<"1";  //flag
//                        myHero.Genji_p->Shoot_enemy.play();
//                        if((*j)->hurt(100)){
//                            (*j)->is_alive = 0;
//                        }
//                        if((*j)->is_alive){
//                            (*j)->fara_get_hurt1.play();
//                        }
//                    }
                }
            }
        }
        //for shuriken & rocket fire
        for(list<Shuriken*>::iterator i=myWeapon.shuriken_list.begin(); i!=myWeapon.shuriken_list.end(); i++){
            ShurikenBox = (*i)->My_sprite.getGlobalBounds();

                for(list<Rockfire *>::iterator j=myWeapon.rockfire_list.begin(); j!=myWeapon.rockfire_list.end(); j++){
                    RockBox = (*j)->My_sprite.getGlobalBounds();
                    if(RockBox.intersects(ShurikenBox)){
                        delete *j;
                        j = myWeapon.rockfire_list.erase(j);
                        delete *i;
                        i = myWeapon.shuriken_list.erase(i);
                        myHero.Genji_p->Shoot_bullet.play();
                    }
                }

        }

        //for shuriken & micre
        for(list<Shuriken*>::iterator i=myWeapon.shuriken_list.begin(); i!=myWeapon.shuriken_list.end(); i++){
            ShurikenBox = (*i)->My_sprite.getGlobalBounds();
            for(list<Miicre*>::iterator j=myHero.micre_list.begin(); j!=myHero.micre_list.end(); j++){
                (*j)->getGB();
                if(ShurikenBox.intersects((*j)->MicreBox)){
                        refresh_text();
                        myHero.Genji_p->get_energy(3);
                        delete *i;

                        i = myWeapon.shuriken_list.erase(i);
                        (*j)->hurt(10);
                        myHero.Genji_p->Shoot_enemy.play();
                }
            }
        }
}
