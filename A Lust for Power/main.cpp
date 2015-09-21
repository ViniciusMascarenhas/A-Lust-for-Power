#include "Includes.h"
#include "SaveState.h"

int main () 
{
	SaveState ss;
	ss.load_file();	
	
	//printf("\n");
	printf("Temples: %d\nHearts: %.2f\nHeart Containers: %d\nMP: %d\nMax MP: %d\nRupees: %d\n", ss.get_temples(), ss.get_hearts(), ss.get_heart_containters(), ss.get_mp(), ss.get_max_mp(), ss.get_rupees());
	
	return 0;
};
