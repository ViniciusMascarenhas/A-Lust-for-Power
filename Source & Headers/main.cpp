// 1.1

#include "Includes.h"
#include "SaveState.h"

int main () 
{
	SaveState ss;
	//ss.load_file();	
	
	//printf("\n");
	printf("Temples:\n\tForest\t%d\n\tFire\t%d\n\tWater\t%d\n\tSpirit\t%d\n\tShadow\t%d\n\tLight\t%d\n\nHearts: %.2f\nHeart Containers: %d\nMP: %.2f\nMax MP: %.2f\nMax Stamina: %.2f\nRupees: %d\n", 
		ss.forest(), ss.fire(), ss.water(), ss.spirit(), ss.shadow(), ss.light(), 
		ss.get_hearts(), ss.get_heart_containters(), ss.get_mp(), ss.get_max_mp(), 
		ss.get_max_stamina(), ss.get_rupees());
	
	return 0;
};
