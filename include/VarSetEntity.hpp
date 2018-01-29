#ifndef VAR_SET_ENTITY_H
#define VAR_SET_ENTITY_H

#include "Entity.hpp"

#include <string>

class VarSetEntity: public Entity
{
public:
    VarSetEntity(std::string _strexp);
    ~VarSetEntity() override;

    EntityType getType() override;

private:
    std::string var;
};

#endif
