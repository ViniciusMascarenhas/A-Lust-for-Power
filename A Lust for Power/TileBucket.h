// 1.0

#ifndef __Load_test__TileBucket__
#define __Load_test__TileBucket__

#include "Includes.h"

class TileBucket
{
private:
	
	int **matrix;
	
public:
	
	TileBucket();
	void Rect (int tx, int ty, int x, int y, int w, int h);
	void Row (int tx, int ty, int x, int y, int w);
	void Col (int tx, int ty, int x, int y, int h);
	void Sq (int tx, int ty, int x, int y, int s);
	void As_is (int tx, int ty, int x, int y, int w, int h);
	void Stretch (int tx, int ty, int x, int y, int rx, int ry, int w, int h);
};

TileBucket::TileBucket()
{
		
};

void TileBucket::Rect (int tx, int ty, int x, int y, int w, int h)
{
	//graphics.DrawImage2D(x, y, w * TILE, h * TILE, tx * TILE, ty * TILE, w * TILE, h * TILE, Image image);
};

#endif /* defined(__Load_test__TileBucket__) */


/*
Funções de construção de tile único:
Rect (tx, ty, w, h, x, y)
Row (tx, ty, w, x, y)
Col (tx, ty, h, x, y)
Sq (tx, ty, s, x, y)

Funções de construção de múltiplos tiles:
As_is (tx, ty, w, h, x, y)
Stretch (tx, ty, w, h, rx, ry, x, y)
*/

