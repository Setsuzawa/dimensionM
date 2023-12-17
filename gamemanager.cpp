#include "gamemanager.hpp"
void Gamemanager::initSDL()
{
	startTime = SDL_GetPerformanceCounter();
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    g_window = NULL;
    g_renderer = NULL;

    g_window = SDL_CreateWindow("DimensioM", 0, 0, SCREEN_WIDTH,
                                SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (g_window == NULL)
    {
        printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
    }
    g_renderer = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);

    if (g_renderer == NULL)
    {
        printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
    }
    else
    {
        // Initialize renderer color
        SDL_SetRenderDrawColor(g_renderer, 0xFF, 0xFF, 0xFF, 0xFF);

        // Initialize PNG loading
        int imgFlags = IMG_INIT_PNG;
        if (!(IMG_Init(imgFlags) & imgFlags))
        {
            printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
        }
    }
    //��l�ƪ��a 
	penguin = new Player(g_renderer, "../images/1.png", 30, 500, 100, 100, &e, 10, 300);
    penguin->set_source("../images/2.png", "../images/4.png", "../images/3.png");
    //��l�Ƥp�� 
    for( int i=0 ; i < monster_num ; i++)
    {
    	monster.push_back(new Fodder(g_renderer,monster_image[i],monster_x[i],monster_y[i],monster_w[i],monster_h[i],&e,0,/*mathkind*/));
	}
	//��l�����d
	themenu = Menu();
	loadLevel();
	thepause = Pause();
	currentstate = s_menu;
	CurrentLevel = 0;
}

void Gamemanager::closeSDL()
{
	//����
	// �ѩ�
	//  ������ 
}

void Gamemanager::handleEvents()
{
	SDL_PollEvent(&e);

    if (e.type == SDL_QUIT)
    {
        quit = true;
        return;
    }
    
	switch (currentstate) // ²��ӻ� handleEvent�O���ƾڡArender�O��� 
	{
		case (s_menu):
			if(!themenu.isStarted())
			{
				themenu.start();
			}
			themenu.handle_event(&e ,currentstate, quit);
			break;
		//	�YStart���s�Q���U �hLevel1.start();
		//	state = playing
		case (s_playing):
			if (!levels[CurrentLevel]->isStarted())
			{
				levels[CurrentLevel]->start();
			}
			levels[CurrentLevel]->handle_event(&e , currentstate, quit, );
			//player��handle event 
			break;
		//	�h handle : Level�̭����F��B����I���B�����B �M����ܥL�̪�x y �n���n��ܤ����� 
		//	�Y Pause ���s�Q���U �hstate = pause
		case (s_pausing) :
			thepause.handle_event(&e, currentstate , quit);
			//	�hhandle: ���s
		//	�Yresume�Q���U �h
		//	�Yrestart�Q���U �hlevel���m
		//	�YBack_to_menu�Q���U �hlevel.end() , state = menu; 
			break;
		case (s_next_level):
			CurrentLevel++;
			levels[currentlevel]->start();
			currentstate = s_playing;
			break;
	}
}

void Gamemanager::render()
{
	switch (currentstate)
	{
		case ( menu ):
			themenu.render();
			break;
		case ( playing ):
			levels[CurrentLevel].render(g_renderer); // ��V���d
            penguin->render(); // ��V���a
            break;
		case ( pause ) :
			thepause.render();
			break;
	}
}

void Gamemanager::run()
{
	initSDL();
	while(!quit)
	{
		handleEvents();
		render();
	}
	closeSDL();
}

void Gamemanager::loadLevel
{
	//�o�̬O�@���ʸ��J���d�A�O���c�����a�� 
	//level 1
		blablabla
	//level 2
		flaflafla
	//level 3
		olaolaola
}
