#include "VarSetEntity.hpp"

#include <iostream>

using namespace std;

VarSetEntity::VarSetEntity(string _strexp, unsigned int _xpos, unsigned int _ypos, sf::Font &font)
{
    strexp = _strexp;
    xpos = _xpos;
    ypos = _ypos;

    text.setString(strexp);
    text.setFont(font);
    text.setPosition(xpos*20, ypos*20);
    text.setFillColor(sf::Color::Black);
    text.setCharacterSize(20);
}

VarSetEntity::~VarSetEntity()
{
    cout << "~VarSetEntity() called" << endl;
}

EntityType VarSetEntity::getType()
{
    return EntityType::VarSet;
}

void VarSetEntity::draw(sf::RenderWindow *window)
{
    window->draw(text);
}
