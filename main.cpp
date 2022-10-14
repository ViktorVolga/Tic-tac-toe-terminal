#include "Game.h"



int main(int argc, char* argv[]) {
	Game game;
	game.start();
	while (game._isGameOn) {
		game.showMainMenu();
	}	
}