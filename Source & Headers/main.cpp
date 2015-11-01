#ifndef __Main__
#define __Main__

#include "SaveState.h"
#include "LiveSprite.h"
#include "iGraphics.h"
#include "MapBuilder.h"

SaveState save_state;
MapBuilder map_builder;
iGraphics iGraph;
Image Ganondorfs_castle;
LiveSprite Ganondorf (40, 40, 1, 0, 80, 190);
Sprite portal (270, 270);
Sprite medallion (50, 50);
Sprite prize_table (83, 46);
Sprite easter_egg (49, 51);
Sprite forest_map (TILE_SIZE, TILE_SIZE);
bool see_generated_map = true;

void load_images()
{
	char Ganondorfs_castle_path[FILE_PATH_SIZE];
	//cat_path (Ganondorfs_castle_path, "Level Design\\Casa do Ganondorf\\", "Casa do Ganondorf.png");
	cat_path (Ganondorfs_castle_path, CO, "Castle with organ and statues.png");
	Ganondorfs_castle.LoadPNGImage(Ganondorfs_castle_path);
	
	Ganondorf.load (CO, "Ganondorf.png");
	Ganondorf.select_frame (0, 2);
	Ganondorf.set_position ((SCREEN_WIDTH - Ganondorf.get_frame_width()) / 2 - 8, 345);
	portal.load (CO, "Portals.png");
	medallion.load (CO, "Medallions.png");
	prize_table.load (CS, "Prize Table.png");
	easter_egg.load (CO, "Easter Eggs.png");
	forest_map.load(TR, "Floresta 1.png");
};

void main_loop()
{
	iGraph.DrawImage2D (0,0,736,448,0,0,736,448,Ganondorfs_castle);
	Ganondorf.draw (&iGraph);
	//Ganondorf.print_pos();

	int portal_y = 10;

	for (int i=0; i<5; i++)
	{
		portal.select_frame (i,0);
		portal.set_position (-70 + i*120, portal_y);
		portal.draw (&iGraph);
	};

		portal.select_frame (save_state.get_phase()+5, 0);
		portal.set_position (-70 + 5*120, portal_y);
		portal.draw (&iGraph);

	for (int i=0; i<6; i++)
	{
		if (save_state.get_temple(i))
		{
			medallion.select_frame (i, 0);
			medallion.set_position (38 + i*120, 170);
			medallion.draw (&iGraph);
		};
	};
	
	for (int i=0; i<6; i++)
		if (save_state.get_easter_egg(i))
		{
			prize_table.set_position (19 + (SCREEN_WIDTH / 2) - ((3-i) * 109) - (30 * (3-i>0)), 368); //Último x = 605
			prize_table.draw (&iGraph);
			easter_egg.select_frame (i, 0);
			easter_egg.set_position (34 + (SCREEN_WIDTH / 2) - ((3-i) * 109) - (30 * (3-i>0)), 361);
			easter_egg.draw (&iGraph);
		};

	if (save_state.light())
	{
		int i = 5;
		prize_table.set_position (605, 308);
		prize_table.draw (&iGraph);
		easter_egg.select_frame (i+1, 0);
		easter_egg.set_position (34 + (SCREEN_WIDTH / 2) - ((3-i) * 109) - (30 * (3-i>0)), 301);
		easter_egg.draw (&iGraph);
	};


	if (see_generated_map)
	{
		MapNode* current_node = map_builder.get_list_head()->get_ptr();
		while (current_node != NULL)
		{
			forest_map.set_position (current_node->get_screen_x(), current_node->get_screen_y());
			forest_map.select_frame (current_node->get_sheet_x(), current_node->get_sheet_y());
			forest_map.draw (&iGraph);
			current_node = current_node->get_ptr();
		};
	};
};

int main (void)
{
	//save_state.print_table();
	
	if(1)
	{
		iGraph.CreateMainWindow (SCREEN_WIDTH, SCREEN_HEIGHT, "A Lust for Power");
		iGraph.SetKeyboardInput(KeyboardInput);
		iGraph.SetBackgroundColor (26,32,40);
		load_images();
		iGraph.SetMainLoop(main_loop);
		iGraph.StartMainLoop();
	};


	map_builder.delete_list();
	
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
	if (state == KEY_STATE_DOWN)
	{
		switch (key)
		{
			case 'f': iGraph.SetFullscreen (true); break;
			case (KEY_RIGHT): Ganondorf.move (Ganondorf.get_current_speed(), horizontal); break;
			case (KEY_DOWN): Ganondorf.move (Ganondorf.get_current_speed(), vertical); break;
			case (KEY_LEFT): Ganondorf.move (-Ganondorf.get_current_speed(), horizontal); break;
			case (KEY_UP): Ganondorf.move (-Ganondorf.get_current_speed(), vertical); break;
			case (' '): Ganondorf.toggle_dashing(); break;
			case ('m'): see_generated_map = !see_generated_map; break;
			case ('v'): exit(0); break;

			case ('t'): save_state.tweak_temple(0); break;
			case ('y'): save_state.tweak_temple(1); break;
			case ('u'): save_state.tweak_temple(2); break;
			case ('i'): save_state.tweak_temple(3); break;
			case ('o'): save_state.tweak_temple(4); break;
			case ('p'): save_state.tweak_temple(5); break;
		};

		if (key>='5' && key<='9')
			save_state.tweak_easter_egg (key-'5');
		if (key=='0')
			save_state.tweak_easter_egg (5);
	};
};

void halt()
{
	getchar();
};

#endif /* defined(__Main__) */