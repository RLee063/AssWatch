#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Enemy
{
    public:
        Enemy();
        virtual ~Enemy();
        virtual sf::Sprite get()=0;
    protected:

    private:
};

#endif // ENEMY_H
