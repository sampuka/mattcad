#include <iostream>
#include "Mattcad.hpp"

using namespace std;

int main()
{
	Mattcad *screen = new Mattcad;

	screen->createEntity("tg := 62", 3, 3);
	screen->createEntity("tg*2 =", 3, 5);

	while(screen->isOpen())
		;
	
	delete screen;

	return 0;
}
