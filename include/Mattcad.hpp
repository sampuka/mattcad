#ifndef MATTCAD_H
#define MATTCAD_H

#include "Entity.hpp"

#include <SFML/Graphics.hpp>

#include <vector>
#include <thread>

class Mattcad
{
public:
    Mattcad();
    ~Mattcad();
    
    bool isOpen();
    
    void createEntity(std::string strexp, unsigned int xpos, unsigned int ypos);
  
private:
    void main_loop();
    std::thread *main_loop_thread;

    void initGraphics();
    sf::Texture bgtexture;
    sf::Sprite bgsprite;

    void drawScreen();
    
    std::vector<Entity*> ents;

    sf::RenderWindow *window;
  
};

#endif
