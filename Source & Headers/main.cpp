#ifndef __Main__
#define __Main__
#include "SaveState.h"
#include "Sprite.h"
#include "iGraphics.h"

SaveState save_state;
iGraphics iGraph;
Image Ganondorfs_castle;
Sprite Ganondorf (40, 40, 1, 0, 80, 190);

void MainLoop(void)
{
	iGraph.DrawImage2D (0,0,736,448,0,0,736,448,Ganondorfs_castle);
	Ganondorf.draw (&iGraph);
};

int main (void)
{
	save_state.print_table();
	
	iGraph.CreateMainWindow (SCREEN_WIDTH, SCREEN_HEIGHT, "A Lust for Power");
	iGraph.SetKeyboardInput(KeyboardInput);
	iGraph.SetBackgroundColor (26,32,40);

	char Ganondorfs_castle_path[FILE_PATH_SIZE];
	cat_path (Ganondorfs_castle_path, "Level Design\\Casa do Ganondorf\\", "Casa do Ganondorf.png");
	printf("%s\n",Ganondorfs_castle_path);
	Ganondorfs_castle.LoadPNGImage(Ganondorfs_castle_path);
	
	Ganondorf.load (CO, "Ganondorf.png");
	
	iGraph.SetMainLoop(MainLoop);
	iGraph.StartMainLoop();




	halt();

	return 0;
};

void cat_path (char* ptr, const char* sub_folder_path, const char* file_name)
{
	strcpy(ptr,PROJECT_PATH);
	strcat(ptr,sub_folder_path);
	strcat(ptr,file_name);
};

void KeyboardInput(int key, int state, int x, int y)
{
	int move_amount = 8;

	if ((key == 'f') && (state == KEY_STATE_DOWN))
		iGraph.SetFullscreen(true);

	if ((key == KEY_RIGHT) && (state == KEY_STATE_DOWN))
		Ganondorf.move (move_amount, horizontal);
	if ((key == KEY_DOWN) && (state == KEY_STATE_DOWN))
		Ganondorf.move (move_amount, vertical);
	if ((key == KEY_LEFT) && (state == KEY_STATE_DOWN))
		Ganondorf.move (-move_amount, horizontal);
	if ((key == KEY_UP) && (state == KEY_STATE_DOWN))
		Ganondorf.move (-move_amount, vertical);

	if ((key == ' ') && (state == KEY_STATE_DOWN))
	{
		move_amount = (move_amount == 8 ? 12 : 8);
	};
	

	if ((key == 'v') && (state == KEY_STATE_DOWN))
		exit(0);
};

void halt()
{
	getchar();
};

#endif /* defined(__Main__) */