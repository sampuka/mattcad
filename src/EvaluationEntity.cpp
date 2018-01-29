#include "EvaluationEntity.hpp"

#include <iostream>

using namespace std;

EvaluationEntity::EvaluationEntity(string _strexp, unsigned int _xpos, unsigned int _ypos, sf::Font &font)
{
    strexp = _strexp;
    xpos = _xpos;
    ypos = _ypos;

    text.setString(strexp + result);
    text.setFont(font);
    text.setPosition(xpos*20, ypos*20);
    text.setFillColor(sf::Color::Black);
    text.setCharacterSize(20);
}

EvaluationEntity::~EvaluationEntity()
{
    cout << "~EvaluationEntity() called" << endl;
}

EntityType EvaluationEntity::getType()
{
    return EntityType::Evaluation;
}

void EvaluationEntity::draw(sf::RenderWindow *window)
{
    window->draw(text);
}
