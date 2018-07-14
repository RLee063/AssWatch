#ifndef HERO_H
#define HERO_H
#include "GenJi.h"
#include "Shuriken.h"
#include "Fara.h"
#include "Enemy.h"
#include "Friend.h"
#include "Drogen.h"
#include "Miicre.h"
#include <list>

class Hero
{
    public:
        list<Fara*> fara_list;
        list<Miicre*> micre_list;
        GenJi * Genji_p;
        void add_Genji();
        void add_micre();
        void restart();
        Hero();
        virtual ~Hero();

    protected:

    private:
};

#endif // HERO_H
