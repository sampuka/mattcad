#include "VarSetEntity.hpp"

#include <iostream>

using namespace std;

VarSetEntity::VarSetEntity(string _strexp)
{
    strexp = _strexp;
}

VarSetEntity::~VarSetEntity()
{
    cout << "~VarSetEntity() called" << endl;
}

EntityType VarSetEntity::getType()
{
    return EntityType::VarSet;
}
