#ifndef __iGraphics__
#define __iGraphics__
#include "Graphics.h"
#include "Defines.h"

class iGraphics : public Graphics
{
public:
	void DrawIMG (Image i);
	void DrawIMG (int x, int y, int w, int h, Image i);
	void DrawIMG (int x, int y, int w, int h, int cx, int cy, int cw, int ch, Image i);
};

#endif