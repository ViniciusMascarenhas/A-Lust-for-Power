#ifndef __Main__
#define __Main__
#include "SaveState.h"
#include "LiveSprite.h"
#include "iGraphics.h"

SaveState save_state;
iGraphics iGraph;
Image Ganondorfs_castle;
LiveSprite Ganondorf (40, 40, 1, 0, 80, 190);
Sprite prize_table (83, 46, 0, 0, 18, 363);
Sprite easter_egg (49, 51, 0, 0, 18, 363);

void MainLoop(void)
{
	iGraph.DrawImage2D (0,0,736,448,0,0,736,448,Ganondorfs_castle);
	Ganondorf.draw (&iGraph);
	//Ganondorf.print_pos();
	
	for (int i=0; i<6; i++)
		if (1) //(save_state.get_easter_egg(i))
		{
			prize_table.set_position (19 + (SCREEN_WIDTH / 2) - ((3-i) * 109) - (30 * (3-i>0)), 368); //Último x = 605
			prize_table.draw (&iGraph);
			easter_egg.select_frame (i, 0);
			easter_egg.set_position (34 + (SCREEN_WIDTH / 2) - ((3-i) * 109) - (30 * (3-i>0)), 361);
			easter_egg.draw (&iGraph);
		};

	if (1) //(save_state.light())
	{
		int i = 5;
		prize_table.set_position (605, 308);
		prize_table.draw (&iGraph);
		easter_egg.select_frame (i+1, 0);
		easter_egg.set_position (34 + (SCREEN_WIDTH / 2) - ((3-i) * 109) - (30 * (3-i>0)), 301);
		easter_egg.draw (&iGraph);
	};
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
	prize_table.load (CS, "Prize Table.png");
	easter_egg.load (CO, "Easter Eggs.png");

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
	if ((key == 'f') && (state == KEY_STATE_DOWN))
		iGraph.SetFullscreen(true);

	if ((key == KEY_RIGHT) && (state == KEY_STATE_DOWN))
		Ganondorf.move (Ganondorf.get_current_speed(), horizontal);
	if ((key == KEY_DOWN) && (state == KEY_STATE_DOWN))
		Ganondorf.move (Ganondorf.get_current_speed(), vertical);
	if ((key == KEY_LEFT) && (state == KEY_STATE_DOWN))
		Ganondorf.move (-Ganondorf.get_current_speed(), horizontal);
	if ((key == KEY_UP) && (state == KEY_STATE_DOWN))
		Ganondorf.move (-Ganondorf.get_current_speed(), vertical);

	if ((key == ' ') && (state == KEY_STATE_DOWN))
	{
		Ganondorf.toggle_dashing();
	};
	

	if ((key == 'v') && (state == KEY_STATE_DOWN))
		exit(0);
};

void halt()
{
	getchar();
};

#endif /* defined(__Main__) */