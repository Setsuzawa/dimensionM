#include "level.hpp"

Level::void start()
{
	//�}�l���񭵼֡B���ݴX��
	//�⪱�a���n����m
	//��ܤ�r 
	 //If there is no music playing
	started = true;
    if( Mix_PlayingMusic() == 0 )
    {
        //Play the music
        Mix_PlayMusic( backgrounds.music, -1 );
    }
    
}

Level::void end()
{
	//��F�賣�R�� deallocate == NULL ������ 
	Mix_HaltMusic();
	started = false;
}

Level::void excute()
{
	blablabla
	checkcollision();
	blablabla
}


