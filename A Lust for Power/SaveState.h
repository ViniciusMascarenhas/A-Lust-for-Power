#ifndef __Load_test__SaveState__
#define __Load_test__SaveState__

#include "Includes.h"

class SaveState
{
private:
	int temples;
	float hearts;
	int heart_containers;
	int mp;
	int max_mp;
	int rupees;
	
public:
	
	SaveState ();
	
	//void save_file();
	void load_file();
	
	int get_temples();
	float get_hearts();
	int get_heart_containters();
	int get_mp();
	int get_max_mp();
	int get_rupees();
	
	bool forest();
	bool fire();
	bool water();
	bool spirit();
	bool shadow();
	bool light();
};

#endif /* defined(__Load_test__SaveState__) */