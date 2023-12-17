#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "level.hpp"
#include "button.hpp"
#include <string>
string monster_image[5] = {"","","","",""};
int monster_x[5] = { , , , , };
int monster_y[5] = { , , , , };
int monster_w[5] = { , , , , };
int monster_h[5] = { , , , , };


enum GameState
{
	s_menu = 0;
	s_playing = 1;
	s_pausing = 2;
	s_next_Level = 3;
}

enum Monster
{
	_constant = 0;
	_trigonalmetric = 1;
	_exponential = 2;
	_logarithm = 3;
	_polynomial = 4;
	monster_num = 5;
}
class Gamemanager
{
	private:
		SDL_Window* g_window;
	    SDL_Renderer* g_renderer;
	    Uint64 startTime;
	    SDL_Event e;
	    const Uint8 *key_state = SDL_GetKeyboardState(NULL);
	    
	    std::vector<Level*> levels;
	    Level CurrentLevel;
	    Menu themenu;
	    Pause thepause;
	    
	    GameState currentstate;
	    quit = false;
	    
	    Player* penguin; // Player�̭��h�@�� bool �ܼ� invisible �bPlayer.render()���ɭԥ�Player class�����M�w�n���nrender�X��
	    std::vector<Fodder> monsters; //�s���P�� Fodder�� 
	    
		 
	public:
		Gamemanager
		void initSDL();
		void closeSDL();
		void handleEvents();
		void render();
		void run();
		void loadLevel();
}
#endif
