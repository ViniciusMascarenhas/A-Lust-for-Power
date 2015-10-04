// 1.1

#include "SaveState.h"

SaveState::SaveState() { load_file(); };

//void save_file();


void SaveState::load_file()
{
	FILE * pFile;
	char mystring[100];
	int size = 10;
	
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
		
		if (fgets (mystring , size , pFile) != NULL) hearts = atof(mystring);
		
		if (fgets (mystring , size , pFile) != NULL) heart_containers = atoi(mystring);
	
		if (fgets (mystring , size, pFile) != NULL) mp = atof(mystring);
		
		if (fgets (mystring , size, pFile) != NULL) max_mp = atof(mystring);

		if (fgets(mystring, size, pFile) != NULL) max_stamina = atof(mystring);

		if (fgets (mystring , size, pFile) != NULL) rupees = atoi(mystring);
		
		
		fclose (pFile);
	};
	
};

bool SaveState::get_temple(int t)		{ return temples[t]; };
float SaveState::get_hearts()			{ return hearts; };
int SaveState::get_heart_containters()	{ return heart_containers; };
float SaveState::get_mp()					{ return mp; };
float SaveState::get_max_mp()				{ return max_mp; };
float SaveState::get_max_stamina()		{ return max_stamina; };
int SaveState::get_rupees()				{ return rupees; };

bool SaveState::forest()	{ return (temples[0]); };
bool SaveState::fire()		{ return (temples[1]); };
bool SaveState::water()		{ return (temples[2]); };
bool SaveState::spirit()	{ return (temples[3]); };
bool SaveState::shadow()	{ return (temples[4]); };
bool SaveState::light()		{ return (temples[5]); };





