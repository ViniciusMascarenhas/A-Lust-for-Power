// 1.0

#include "SaveState.h"

SaveState::SaveState() { load_file(); };

//void save_file();


void SaveState::load_file()
{
	FILE * pFile;
	char mystring [100];
	
	
	pFile = fopen (FILE_PATH "file.txt" , "rw");
	
	if (pFile == NULL) printf("Error opening file");
	else 
	{
		if (fgets (mystring , 5 , pFile) != NULL) temples = atoi(mystring);		
		if (fgets (mystring , 5 , pFile) != NULL) hearts = atof(mystring);
		fgets(mystring, 5, pFile);		
		if (fgets (mystring , 5 , pFile) != NULL) heart_containers = atoi(mystring);
		if (fgets (mystring , 5 , pFile) != NULL) mp = atoi(mystring);
		
		if (fgets (mystring , 5 , pFile) != NULL) max_mp = atoi(mystring);
		
		if (fgets (mystring , 5 , pFile) != NULL) rupees = atoi(mystring);
		
		
		fclose (pFile);
	};
	
};

int SaveState::get_temples() { return temples; };
float SaveState::get_hearts() { return hearts; };
int SaveState::get_heart_containters() { return heart_containers; };
int SaveState::get_mp() { return mp; };
int SaveState::get_max_mp() { return max_mp; };
int SaveState::get_rupees() { return rupees; };

bool SaveState::forest() { return (temples>0); };
bool SaveState::fire() { return (temples>1); };
bool SaveState::water() { return (temples>2); };
bool SaveState::spirit() { return (temples>3); };
bool SaveState::shadow() { return (temples>4); };
bool SaveState::light() { return (temples>5); };





