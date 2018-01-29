#include <iostream>
#include "Mattcad.hpp"

using namespace std;

int main()
{
	Mattcad *screen = new Mattcad;

	screen->createEntity("t = 6", 3, 3);

	while(screen->isOpen())
		;
	
	delete screen;

	return 0;
}
