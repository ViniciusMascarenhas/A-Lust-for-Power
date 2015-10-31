#include "Sprite.h"

Sprite::Sprite (int w, int h)
{
	frame_width = w;
	frame_height = h;
};

Sprite::Sprite (int w, int h, const char* p)
{
	frame_width = w;
	frame_height = h;
	int count = 0;

	for (int i=0; p[i]!='\0'; i++)
		path[i] = p[i];
};

Sprite::Sprite (int w, int h, int sheet_X, int sheet_Y, int screen_X, int screen_Y)
{
	frame_width = w;
	frame_height = h;
	sheet_x = sheet_X;
	sheet_y = sheet_Y;
	screen_x = screen_X;
	screen_y = screen_Y;
};

void Sprite::set_frame_width (int w)
{
	frame_width = w;
};

void Sprite::set_frame_height (int h)
{
	frame_height = h;
};

void Sprite::load (const char* sub_folder_path, char* file_name)
{
	cat_path (path, sub_folder_path, file_name);
	LoadPNGImage (path);
};

void Sprite::load_direct (char* file_path)
{
	LoadPNGImage (file_path);
};

void Sprite::print_path()
{
	printf("\nSprite path:\n\t%s\n", path);
};

void Sprite::draw(Graphics* g)
{
	int cx = sheet_x * frame_width;
	int cy = sheet_y * frame_height;

	g->DrawImage2D(screen_x, screen_y, frame_width, frame_height, cx, cy, frame_width, frame_height, *this);
};

void Sprite::draw (iGraphics* i)
{
	int cx = sheet_x * frame_width;
	int cy = sheet_y * frame_height;

	i->DrawIMG(screen_x, screen_y, frame_width, frame_height, cx, cy, frame_width, frame_height, *this);
};

void Sprite::move (int x, int y)
{
	screen_x += x;
	screen_y += y;
};
		
void Sprite::move (int n, axis a)
{
	a == horizontal ? screen_x += n : screen_y += n;
};