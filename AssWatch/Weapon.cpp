#include "Weapon.h"
#include "Shuriken.h"
Weapon::Weapon()
{

    is_create_shuriken_time=0;
    is_create_shuriken=0;
    is_create_shuriken_right=0;
    //ctor
}

Weapon::~Weapon()
{
    //dtor
}

void Weapon::add_Shuriken(Shuriken * a){
    shuriken_list.push_back(a);
}

void Weapon::add_rockfire(Rockfire * a){
    rockfire_list.push_back(a);
}

void Weapon::add_friend_rockfire(Rockfire * a){
    friend_rockfire_list.push_back(a);
}
