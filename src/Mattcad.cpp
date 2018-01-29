#include "Mattcad.hpp"
#include "Entity.hpp"
#include "VarSetEntity.hpp"
#include "EvaluationEntity.hpp"

#include <iostream>
#include <algorithm>
#include <regex>

using namespace std;

Mattcad::Mattcad()
{
    window = new sf::RenderWindow(sf::VideoMode(800, 600), "Mattcad v1");

    initGraphics();
    
    main_loop_thread = new thread(&Mattcad::main_loop, this);
}

Mattcad::~Mattcad()
{
    for (Entity *ent : ents)
	delete ent;
}

bool Mattcad::isOpen()
{
    return window->isOpen();
}

void Mattcad::createEntity(string strexp, unsigned int xpos, unsigned int ypos)
{
    cout << "Creating entity from string expression \"" << strexp << "\" at position (" << xpos << "," << ypos << ")." << endl;

    strexp.erase(std::remove(strexp.begin(), strexp.end(), ' '), strexp.end());

    regex rVarSet("((\\w)+):=(\\d+)");
    regex rEvaluation("((\\w|[*/\\+-])+)=");

    smatch match;

    if (regex_match(strexp, match, rVarSet))
    {
	cout << "Matched VarSet" << endl;
	ents.push_back(new VarSetEntity(strexp, xpos, ypos, expfont));
    }
    else if (regex_match(strexp, match, rEvaluation))
    {
	cout << "Matched Evaluation" << endl;
	ents.push_back(new EvaluationEntity(strexp, xpos, ypos, expfont));
    }
    else
    {
	cout << "No entity match" << endl;
    }
}

void Mattcad::main_loop()
{
    sf::Event event;
    while(window->isOpen())
    {
	while(window->pollEvent(event))
	{
	    switch (event.type)
	    {
	    case sf::Event::Closed:
		window->close();
		break;
		
	    case sf::Event::KeyPressed:
	    	cout << "KeyEvent" << endl;
		if (event.key.code == sf::Keyboard::Escape)
		    window->close();
		break;

	    default:
		break;
		//cout << "Unhandled event type" << endl;
	    }
	}
	
	//window->clear(sf::Color::White);
	drawScreen();
	window->display();
	sf::sleep(sf::milliseconds(100));
    }
}

void Mattcad::initGraphics()
{
    if(!bgtexture.create(20, 20))
	cout << "Error creating Texture for background" << endl;
    
    bgtexture.setRepeated(true);
    
    unsigned int width = 20;
    unsigned int height = 20;

    sf::Uint8 *bgpixels = new sf::Uint8[width * height * 4];

    //Draw the repeated background pattern
    for (unsigned int x = 0; x < width; x++)
    {
	for (unsigned int y = 0; y < height; y++)
	{
	    if (x == 0 || y == 0)
	    {
		bgpixels[(x + y * width) * 4 + 0] = 200;
		bgpixels[(x + y * width) * 4 + 1] = 200;
		bgpixels[(x + y * width) * 4 + 2] = 200;
		bgpixels[(x + y * width) * 4 + 3] = 255;
	    }
	    else
	    {
		bgpixels[(x + y * width) * 4 + 0] = 255;
		bgpixels[(x + y * width) * 4 + 1] = 255;
		bgpixels[(x + y * width) * 4 + 2] = 255;
		bgpixels[(x + y * width) * 4 + 3] = 255;
	    }
	}
    }

    bgtexture.update(bgpixels);
    bgsprite.setTexture(bgtexture);
    delete bgpixels;

    expfont.loadFromFile("Cabin-Regular.ttf");
}

void Mattcad::drawScreen()
{
    sf::Vector2u wsize = window->getSize();
    bgsprite.setTextureRect(sf::IntRect(0, 0, wsize.x, wsize.y));
    
    window->draw(bgsprite);

    for (Entity *ent : ents)
    {
	ent->draw(window);
    }
}
