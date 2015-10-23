#include "Graphics.h"
#include "SaveState.h"

Graphics graphics;

void MainLoop(void)
{

}

int main (void)
{
	SaveState ss;
	ss.load_file();
	ss.print_report();

	/*graphics.CreateMainWindow(800, 600, "Projeto Exemplo");
	
	graphics.SetBackgroundColor(12,12,12);
	graphics.SetMainLoop(MainLoop);
	graphics.StartMainLoop();
	*/
	return 0;
}
