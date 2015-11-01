#include "Sprite.h"

Sprite::Sprite()
{

};

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

int Sprite::get_frame_width()
{
	return frame_width;
};

int Sprite::get_frame_height()
{
	return frame_height;
};

int Sprite::get_cx()
{
	return sheet_x * frame_width;
};

int Sprite::get_cy()
{
	return sheet_y * frame_height;
};

int Sprite::get_x()
{
	return screen_x;
};

int Sprite::get_y()
{
	return screen_y;
};

void Sprite::select_frame (int x, int y)
{
	sheet_x = x;
	sheet_y = y;
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

void Sprite::print_pos ()
{
	printf ("(sheet_x = %d , sheet_y = %d , screen_x = %d , screen_y = %d , w = %d , h = %d)\n", sheet_x, sheet_y, screen_x, screen_y, frame_width, frame_height);
};

void Sprite::set_position (int x, int y)
{
	screen_x = x;
	screen_y = y+frame_height;
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
	static int last_step_right_leg = false;

	screen_x += x;
	screen_y += y;

	if (x > 0)
	{
		if (sheet_y != 3)
		{
			sheet_x = 0;
			sheet_y = 3;
		};

		if (sheet_y == 3)
		{
			if (sheet_x == 0)
			{
				if (last_step_right_leg)
					sheet_x = 1;
				else
					sheet_x = 2;
				last_step_right_leg = !last_step_right_leg;
			}
			else
				sheet_x = 0;
		};
	}
	else if (x < 0)
	{
		if (sheet_y != 1)
		{
			sheet_x = 0;
			sheet_y = 1;
		};

		if (sheet_y == 1)
		{
			if (sheet_x == 0)
			{
				if (last_step_right_leg)
					sheet_x = 1;
				else
					sheet_x = 2;
				last_step_right_leg = !last_step_right_leg;
			}
			else
				sheet_x = 0;
		};
	}
	else if (y > 0)
	{
		if (sheet_y != 0)
		{
			sheet_x = 0;
			sheet_y = 0;
		};

		if (sheet_y == 0)
		{
			if (sheet_x == 0)
			{
				if (last_step_right_leg)
					sheet_x = 1;
				else
					sheet_x = 2;
				last_step_right_leg = !last_step_right_leg;
			}
			else
				sheet_x = 0;
		}
	}
	else if (y < 0)
	{
		if (sheet_y != 2)
		{
			sheet_x = 0;
			sheet_y = 2;
		};

		if (sheet_y == 2)
		{
			if (sheet_x == 0)
			{
				if (last_step_right_leg)
					sheet_x = 1;
				else
					sheet_x = 2;
				last_step_right_leg = !last_step_right_leg;
			}
			else
				sheet_x = 0;
		};
	};
};
		
void Sprite::move (int n, axis a)
{
	a == horizontal ? move(n,0) : move(0,n);
};