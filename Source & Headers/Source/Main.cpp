#ifndef __Main__
#define __Main__

#include "SaveState.h"
#include "LiveSprite.h"
#include "iGraphics.h"
#include "MapBuilder.h"
#include "SpriteNode.h"

SaveState save_state;
MapBuilder map_builder;
iGraphics iGraph;
Image Ganondorfs_castle;
LiveSprite Ganondorf (40, 40, 1, 0, 80, 190);
Sprite portal (270, 270);
Sprite medallion (50, 50);
Sprite easter_egg (83, 58); //49, 51
Sprite forest_map (TILE_SIZE, TILE_SIZE);
Sprite Epona (48, 31);
Sprite heart (22, 19);

SpriteNode sprite_list_head;

bool see_generated_map = false;

void load_images()
{
	char Ganondorfs_castle_path[FILE_PATH_SIZE];
	//cat_path (Ganondorfs_castle_path, "Level Design\\Casa do Ganondorf\\", "Casa do Ganondorf.png");
	cat_path (Ganondorfs_castle_path, CO, "Castle with organ and statues.png");
	Ganondorfs_castle.LoadPNGImage(Ganondorfs_castle_path);
	
	Ganondorf.load (CO, "Ganondorf.png");
	Ganondorf.select_frame (0, 2);
	Ganondorf.set_position ((SCREEN_WIDTH - Ganondorf.get_frame_w()) / 2 - 8, 345);
	portal.load (CO, "Portals.png");
	medallion.load (CO, "Medallions.png");
	easter_egg.load (CO, "Easter_Eggs.png");
	forest_map.load(TR, "Floresta 1.png");
	heart.load (CO, "Heart.png");

	Epona.load (CO, "Epona.png");
	Epona.set_position (160, 200);
	Epona.select_frame (1, 0);
	printf("%d\n",Epona.get_screen_y());
	
};

void main_loop()
{
	iGraph.DrawImage2D (0,0,736,448,0,0,736,448,Ganondorfs_castle);
	//Ganondorf.draw (&iGraph);
	//Ganondorf.print_pos();
	sprite_list_head.insert_node (&Ganondorf, 5);

	int portal_y = 280;

	for (int i=0; i<5; i++)
	{
		portal.select_frame (i,0);
		portal.set_position (-70 + i*120, portal_y);
		//portal.draw (&iGraph);
		sprite_list_head.insert_node (&portal, 5);
	};

		portal.select_frame (save_state.get_phase()+5, 0);
		portal.set_position (-70 + 5*120, portal_y);
		//portal.draw (&iGraph);
		sprite_list_head.insert_node (&portal, 5);

	for (int i=0; i<6; i++)
	{
		if (save_state.get_temple(i))
		{
			medallion.select_frame (i, 0);
			medallion.set_position (38 + i*120, 220);
			//medallion.draw (&iGraph);
			sprite_list_head.insert_node (&medallion, 1);
		};
	};

	for (int i=0; i<6; i++)
		if (save_state.get_easter_egg(i))
		{
			easter_egg.select_frame (i, 0);
			easter_egg.set_position (19 + (SCREEN_WIDTH / 2) - ((3-i) * 109) - (30 * (3-i>0)), 414); //Último x = 605
			//prize_table.draw (&iGraph);
			sprite_list_head.insert_node (&easter_egg, 5);
		};

	if (save_state.light())
	{
		int i = 5;
		//easter_egg.set_position (605, 354);
		//sprite_list_head.insert_node (&easter_egg, 5);
		easter_egg.select_frame (i+1, 0);
		easter_egg.set_position (605, 352);
		sprite_list_head.insert_node (&easter_egg, 5);
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



	//Epona.draw (&iGraph);
	//Epona.set_position ((SCREEN_WIDTH - Epona.get_frame_w()) / 2 - 12, 345);
	sprite_list_head.insert_node (&Epona, 5);


	for (int i=0; i<3; i++)
	{
		heart.set_position (28*i + 20, 20);
		heart.select_frame (0, 0);
		sprite_list_head.insert_node (&heart, 10);
	};
	

	iGraph.draw_point (SCREEN_WIDTH/2, 280);
	


	sprite_list_head.draw_list (&iGraph);
	sprite_list_head.print_node_line();
	sprite_list_head.clear();
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