#ifndef VAR_SET_ENTITY_H
#define VAR_SET_ENTITY_H

#include "Entity.hpp"

#include <string>

class VarSetEntity: public Entity
{
public:
    VarSetEntity(std::string _strexp, unsigned int xpos, unsigned int ypos, sf::Font &font);
    ~VarSetEntity() override;

    EntityType getType() override;
    void draw(sf::RenderWindow *window) override;

private:
    std::string var;
    sf::Text text;
};

#endif
