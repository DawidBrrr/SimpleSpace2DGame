
#include "Game.h"


int main()
{
	//Initialize srand
	std::srand(static_cast<unsigned>(time(NULL)));
	//Initialize Game Engine
	Game game;
	//GameLoop
	while (game.running())
	{
		//Update
		game.update();
		//Render
		game.render();
	}



	//End of application
	return 0;
}



