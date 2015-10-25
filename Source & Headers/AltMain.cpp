// 1.1

/*
#include "Defines.h"
#include "SaveState.h"


Graphics graphics;


void halt() // Para não usar funções dependentes de um ou outro sistema, como <Windows.h>::system("pause")...
{
	int input;
	scanf("%d",&input);
}

void MainLoop(void)
{

}



int main () 
{
	SaveState ss;
	//ss.load_file();	
	
	//printf("\n");
	printf("Temples:\n\tForest\t%d\n\tFire\t%d\n\tWater\t%d\n\tSpirit\t%d\n\tShadow\t%d\n\tLight\t%d\n\nHearts: %.2f\nHeart Containers: %d\nMP: %.2f\nMax MP: %.2f\nMax Stamina: %.2f\nRupees: %d\n", 
		ss.forest(), ss.fire(), ss.water(), ss.spirit(), ss.shadow(), ss.light(), 
		ss.get_hearts(), ss.get_heart_containters(), ss.get_mp(), ss.get_max_mp(), 
		ss.get_max_stamina(), ss.get_rupees());

	
	 // Problema!
	graphics.CreateMainWindow(800, 600, "Projeto Exemplo");
	
	graphics.SetBackgroundColor(12,12,12);
	graphics.SetMainLoop(MainLoop);
	graphics.StartMainLoop();
	
	halt();
	return 0;
};
*/