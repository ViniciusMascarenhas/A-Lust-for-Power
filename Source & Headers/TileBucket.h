// 1.0

#ifndef __Load_test__TileBucket__
#define __Load_test__TileBucket__

#include "Defines.h"

//Graphics graphics;
//Image Tileset;	// global scope



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

void TileBucket::Rect (int tx, int ty, int x, int y, int w, int h)
{
	//
	
	
};

void TileBucket::Row (int tx, int ty, int x, int y, int w)
{
	//
};

void TileBucket::Col (int tx, int ty, int x, int y, int h)
{
	//
};



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



#endif /* defined(__Load_test__TileBucket__) */


