#include "Hero.h"
#include "Miicre.h"

Hero::Hero()
{
    //ctor
}

Hero::~Hero()
{
    //dtor
}

void Hero::add_Genji(){
    Genji_p = new GenJi(50, 200);
}

void Hero::add_micre(){
    Miicre* a = new Miicre();
    micre_list.push_back(a);
}

void Hero::restart(){
    Genji_p = new GenJi(50,200);
}
