#include "iGraphics.h"

void iGraphics::DrawIMG (Image i)
{
	DrawImage2D (i);
};

void iGraphics::DrawIMG (int x, int y, int w, int h, Image i)
{
	DrawImage2D (x, SCREEN_HEIGHT - y, w, h, i);
};

void iGraphics::DrawIMG (int x, int y, int w, int h, int cx, int cy, int cw, int ch, Image i)
{
	DrawImage2D (x, SCREEN_HEIGHT - y, w, h, cx, cy, cw, ch, i);
};


