#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

#include <string>

enum class EntityType
{
    Plot,
    Evaluation,
    VarSet
};

class Entity
{
public:
    //Entity(std::string _strexp);
    virtual ~Entity();

    virtual EntityType getType() = 0;
    virtual void draw(sf::RenderWindow *window) = 0;

protected:
    std::string strexp;
    unsigned int xpos;
    unsigned int ypos;
};

#endif
