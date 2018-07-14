#ifndef WEAPON_H
#define WEAPON_H
#define DIRECTOR_H
#include "Shuriken.h"
#include <list>
#include "Rockfire.h"
using namespace std;
class Weapon
{
    public:
        int is_create_shuriken_time;
        int is_create_shuriken;
        int is_create_shuriken_right;
        Weapon();
        virtual ~Weapon();

        list<Rockfire*> friend_rockfire_list;
        list<Shuriken*> shuriken_list;
        list<Rockfire*> rockfire_list;
        void add_friend_rockfire(Rockfire*);
        void add_Shuriken(Shuriken*);
        void add_rockfire(Rockfire*);
    protected:

    private:
};

#endif // WEAPON_H
