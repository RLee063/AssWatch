#ifndef FRIEND_H
#define FRIEND_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Friend
{
    public:
        Friend();
        virtual ~Friend();
        virtual sf::Sprite get()=0;
    protected:

    private:
};

#endif // FRIEND_H
