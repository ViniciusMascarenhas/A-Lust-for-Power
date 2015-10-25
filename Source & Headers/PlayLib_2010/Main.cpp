
#include "C:\\Users\\Admin\\Downloads\\PlayLib_2010\\PlayLib_2010\\Graphics.h"

Graphics graphics;

void MainLoop(void)
{

}

int main (void)
{
	graphics.CreateMainWindow(800, 600, "Projeto Exemplo");
	
	graphics.SetBackgroundColor(12,12,12);
	graphics.SetMainLoop(MainLoop);
	graphics.StartMainLoop();

	return 0;
}
