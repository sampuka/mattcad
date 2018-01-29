#ifndef EVALUATION_ENTITY_H
#define EVALUATION_ENTITY_H

#include "Entity.hpp"

class EvaluationEntity: public Entity
{
public:
    EvaluationEntity(std::string _strexp, unsigned int _xpos, unsigned int _ypos, sf::Font &font);
    ~EvaluationEntity() override;

    EntityType getType() override;
    void draw(sf::RenderWindow *window) override;

private:
    std::string result;
    sf::Text text;
};

#endif
