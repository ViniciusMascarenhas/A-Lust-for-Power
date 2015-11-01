#include "MapNode.h"

MapNode::MapNode (int cx, int cy, int x, int y)
{
	printf("MapNode constructor called with arguments %d, %d, %d and %d.\n", cx, cy, x, y);

	sheet_x = cx;
	sheet_y = cy;
	screen_x = x;
	screen_y = y;

	ptr = NULL;
};


void MapNode::set_ptr (MapNode* p)
{
	ptr = p;
};

void MapNode::new_ptr (int tx, int ty, int x, int y)
{
	printf("MapNode::new_ptr funcion called with arguments %d, %d, %d and %d.\n", tx, ty, x, y);
	ptr = new MapNode (tx, ty, x, y);
};

int MapNode::get_screen_x()
{
	return screen_x;
};

int MapNode::get_screen_y()
{
	return screen_y;
};

int MapNode::get_sheet_x()
{
	return sheet_x;
};

int MapNode::get_sheet_y()
{
	return sheet_y;
};