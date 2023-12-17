
#ifndef BACKGROUND_H
#define BACKGROUND_H
#include "entity.hpp"
#include "button.hpp"
#include "solid.hpp"
#include "SDL_mixer.h"
#include <iostream>
#include <vector>
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
class Background : public Entity
{
	friend class Mob; // �n��Mob�ΥH�U���i�H�����I���L��Solids
	
	protected:
		int solid_num;
		std::vector<Solid*> solids={};
		Mix_Music* music;
			
	public:
		Background( SDL_Renderer* , std::string , 
			int , int *, int *, int*, int*, const char** , 
			Mix_Music* );
		void display();
};

#endif 

