// 1.1
#ifndef SaveStateCPP
#define SaveStateCPP

#include "SaveState.h"

SaveState::SaveState() { load_file(); };

//void save_file();


void SaveState::load_file()
{
	FILE * pFile;
	char mystring[100];
	int size = 18;
	
	char save_file_path[300];	// Pode aumentar o tamanho se precisar.
	strcpy_s(save_file_path, FILE_PATH);
	strcat_s(save_file_path, "SaveFile.txt");

	fopen_s (&pFile, save_file_path , "r");
	
	if (pFile == NULL) printf("Error opening save file\n");
	else 
	{
		if (fgets(mystring, size, pFile) != NULL)
		{
			for (int i = 0; i < 6; i++)
			{
				temples[i] = mystring[i] == '1' ? true : false;
			};
		};

		if (!(forest() && fire() && water() && spirit() && shadow()))
		{
			temples[5] = false; // Se não passou dos primeiros 5 templos, o da Luz não pode ter sido passado.
		};
		
		//fgets(mystring, size, pFile);

		//if (fgets (mystring , size , pFile) != NULL) heart_containers = atoi(mystring);
		if (fgets(mystring, size, pFile) != NULL)
		{
			for (int i = 0; i < 17; i++)
			{
				heart_container[i] = mystring[i] == '1' ? true : false;
			};
		};
	
		fgets (mystring , size, pFile);
		
		if (fgets (mystring , size , pFile) != NULL) hearts = atof(mystring);
		
		if (fgets (mystring , size, pFile) != NULL) mp = atof(mystring);
		
		if (fgets (mystring , size, pFile) != NULL) max_mp = atof(mystring);

		if (fgets(mystring, size, pFile) != NULL) max_stamina = atof(mystring);

		if (fgets (mystring , size, pFile) != NULL) rupees = atoi(mystring);

		if (fgets(mystring, size, pFile) != NULL)
		{
			for (int i = 0; i < 3; i++)
			{
				spell[i] = mystring[i] == '1' ? true : false;
			};
		};

		if (fgets(mystring, size, pFile) != NULL)
		{
			for (int i = 0; i < 7; i++)
			{
				easter_egg[i] = mystring[i] == '1' ? true : false;
			};
		};
		
		
		fclose (pFile);
	};
	
};

bool SaveState::get_temple(int t)		{ return temples[t];		};
float SaveState::get_hearts()			{ return hearts;			};
float SaveState::get_mp()				{ return mp;				};
float SaveState::get_max_mp()			{ return max_mp;			};
float SaveState::get_max_stamina()		{ return max_stamina;		};
int SaveState::get_rupees()				{ return rupees;			};

bool SaveState::forest()				{ return (temples[0]); };
bool SaveState::fire()					{ return (temples[1]); };
bool SaveState::water()					{ return (temples[2]); };
bool SaveState::spirit()				{ return (temples[3]); };
bool SaveState::shadow()				{ return (temples[4]); };
bool SaveState::light()					{ return (temples[5]); };


void SaveState::print_report()
{
	printf("Temples:\n\tForest\t%d\n\tFire\t%d\n\tWater\t%d\n\tSpirit\t%d\n\tShadow\t%d\n\tLight\t%d\n\n",
		forest(), fire(), water(), spirit(), shadow(), light() );

	printf ("Heart Containers (%d):\n\tForest\t[%d, %d, %d]\n\tFire\t[%d, %d, %d]\n\tWater\t[%d, %d, %d]\n\tSpirit\t[%d, %d, %d]\n\tShadow\t[%d, %d, %d]\n\tMerchant[%d, %d]\n\n", get_heart_containers(), heart_container[0],heart_container[1],heart_container[2],heart_container[3],heart_container[4],heart_container[5],heart_container[6],heart_container[7],heart_container[8],heart_container[9],heart_container[10],heart_container[11],heart_container[12],heart_container[13],heart_container[14],heart_container[15],heart_container[16],heart_container[17]);


	printf("Hearts: %.2f\nMP: %.2f\nMax MP: %.2f\nMax Stamina: %.2f\nRupees: %d\n", get_hearts(), get_mp(), get_max_mp(), get_max_stamina(), get_rupees());

	printf("Spells:\n\tFarore's Wind\t%d\n\tDin's Fire\t%d\n\tNayru's Love\t%d\n\n",spell[0], spell[1], spell[2]);

	printf("Easter Eggs:\n\tForest\t%d\n\tFire\t%d\n\tWater\t%d\n\tSpirit\t%d\n\tShadow\t%d\n\tLight\t%d\n\tHero\t%d\n\n\n",easter_egg[0],easter_egg[1],easter_egg[2],easter_egg[3],easter_egg[4],easter_egg[5],easter_egg[6]);
};


int SaveState::get_heart_containers()
{
	int n = 3;
	for (int i=0; i<17; i++)
	{
		heart_container[i] == true ? n++ : 0;
	};

	return n;
};


#endif