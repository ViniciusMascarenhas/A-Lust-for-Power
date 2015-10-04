// 1.1

#ifndef __Load_test__SaveState__
#define __Load_test__SaveState__

#include "Includes.h"

class SaveState
{
private:
	bool temples [6];
	float hearts;
	int heart_containers;
	float mp;
	float max_mp;
	float max_stamina;
	int rupees;
	
public:
	
	SaveState ();
	
	//void save_file();
	void load_file();
	
	bool get_temple(int t);
	float get_hearts();
	int get_heart_containters();
	float get_mp();
	float get_max_mp();
	int get_rupees();
	float get_max_stamina();
	
	bool forest();
	bool fire();
	bool water();
	bool spirit();
	bool shadow();
	bool light();
};

#endif /* defined(__Load_test__SaveState__) */