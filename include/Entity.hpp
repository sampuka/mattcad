#ifndef ENTITY_H
#define ENTITY_H

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

protected:
    std::string strexp;
};

#endif
