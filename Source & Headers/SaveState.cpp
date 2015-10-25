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
	file_good = false;
	
	char save_file_path[300];	// Pode aumentar o tamanho se precisar.
	strcpy_s(save_file_path, PROJECT_PATH);
	strcat_s(save_file_path, SH);
	strcat_s(save_file_path, "SaveFile.txt");

	fopen_s (&pFile, save_file_path , "r");
	
	if (pFile == NULL) printf("Error opening save file\n");
	else 
	{
		file_good = true;

		if (fgets(mystring, size, pFile) != NULL)
		{
			for (int i = 0; i < 6; i++)
			{
				temples[i] = mystring[i] == '1' ? true : false;
			};
		};

		if (!(forest() && fire() && water() && spirit() && shadow()))
		{
			temples[5] = false; // Se n�o passou dos primeiros 5 templos, o da Luz n�o pode ter sido passado.
		};
		
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

int SaveState::get_heart_containers()
{
	int n = 3;
	for (int i=0; i<17; i++)
	{
		heart_container[i] == true ? n++ : 0;
	};

	return n;
};

void SaveState::print_report()
{
	printf("Temples:\n\tForest\t%d\n\tFire\t%d\n\tWater\t%d\n\tSpirit\t%d\n\tShadow\t%d\n\tLight\t%d\n\n",
		forest(), fire(), water(), spirit(), shadow(), light() );

	printf ("Heart Containers (%d):\n\tForest\t[%d, %d, %d]\n\tFire\t[%d, %d, %d]\n\tWater\t[%d, %d, %d]\n\tSpirit\t[%d, %d, %d]\n\tShadow\t[%d, %d, %d]\n\tMerchant[%d, %d]\n\n", get_heart_containers(), heart_container[0],heart_container[1],heart_container[2],heart_container[3],heart_container[4],heart_container[5],heart_container[6],heart_container[7],heart_container[8],heart_container[9],heart_container[10],heart_container[11],heart_container[12],heart_container[13],heart_container[14],heart_container[15],heart_container[16],heart_container[17]);


	printf("Hearts: %.2f\nMP: %.2f\nMax MP: %.2f\nMax Stamina: %.2f\nRupees: %d\n", get_hearts(), get_mp(), get_max_mp(), get_max_stamina(), get_rupees());

	printf("Spells:\n\tFarore's Wind\t%d\n\tDin's Fire\t%d\n\tNayru's Love\t%d\n\n",spell[0], spell[1], spell[2]);

	printf("Easter Eggs:\n\tForest\t%d\n\tFire\t%d\n\tWater\t%d\n\tSpirit\t%d\n\tShadow\t%d\n\tLight\t%d\n\tHero\t%d\n\n\n",easter_egg[0],easter_egg[1],easter_egg[2],easter_egg[3],easter_egg[4],easter_egg[5],easter_egg[6]);
};

void pt(bool c) { c ? printf("\t") : 0; };

void SaveState::print_table()
{
	if (file_good)
	{
		bool c = true;

		printf("\n\n");
		pt(c); printf("Hearts:\t\t%5.2f\t/  %d\n",get_hearts(), get_heart_containers());
		pt(c); printf("Mana:\t\t%5.2f\t/  %.2f\n",get_mp(), get_max_mp());
		pt(c); printf("Stamina:\txx.xx\t/  %.2f\n",get_max_stamina());
		pt(c); printf("Rupees:\t\t%2d\t/  %d\n\n\n",get_rupees(), MAX_RUPEES);

		pt(c); printf("Temple\t\tCleared\t\tHearts\t\tEaster Egg\tSpell\n");
		pt(c); printf("---------------------------------------------------------------------------------\n");
		pt(c); printf("Forest\t\t%d\t\t[%d, %d, %d]\t%d\t\t%d (Farore's Wind)\n",
			forest(),
			heart_container[0],heart_container[1],heart_container[2],
			easter_egg[0],spell[0]);

		pt(c); printf("Fire\t\t%d\t\t[%d, %d, %d]\t%d\t\t%d (Din's Fire)\n",
			fire(),
			heart_container[3],heart_container[4],heart_container[5],
			easter_egg[1],spell[1]);

		pt(c); printf("Water\t\t%d\t\t[%d, %d, %d]\t%d\t\t%d (Nayru's Love)\n",
			water(),
			heart_container[6],heart_container[7],heart_container[8],
			easter_egg[2],spell[2]);

		pt(c); printf("Spirit\t\t%d\t\t[%d, %d, %d]\t%d\n",spirit(),
			heart_container[9],heart_container[10],heart_container[11],
			easter_egg[3],spell[0]);

		pt(c); printf("Shadow\t\t%d\t\t[%d, %d, %d]\t%d\n",shadow(),
			heart_container[12],heart_container[13],heart_container[14],
			easter_egg[4],spell[0]);

		pt(c); printf("Light\t\t%d\t\t[-------]\t%d\n",light(),
			easter_egg[5],spell[0]);

		pt(c); printf("Heart containers from Merchant:\t[%d  ,  %d]\n",
			heart_container[15], heart_container[16]);

		pt(c); printf("Hero's easter egg:\t\t\t\t%d\n",easter_egg[6]);
	

		printf("\n\n");
	};
};


void SaveState::graphics_print_table (Graphics g)
{
	if (file_good)
	{
		bool c = true;
		int x = 50;
		int y = 740;
		int h = 32;
		
		g.SetTextFont ("Consolas", 16, FONT_WEIGHT_NORMAL, false, false);

		g.DrawText2D (x,y,"\n\n"); y-= h;
		g.DrawText2D (x,y,"Hearts:\t\t%5.2f\t/  %d\n",get_hearts(), get_heart_containers()); y-= h;
		g.DrawText2D (x,y,"Mana:\t\t%5.2f\t/  %.2f\n",get_mp(), get_max_mp()); y-= h;
		g.DrawText2D (x,y,"Stamina:\txx.xx\t/  %.2f\n",get_max_stamina()); y-= h;
		g.DrawText2D (x,y,"Rupees:\t\t%2d\t/  %d\n\n\n",get_rupees(), MAX_RUPEES); y-= h;

		g.DrawText2D (x,y,"Temple\t\tCleared\t\tHearts\t\tEaster Egg\tSpell\n"); y-= h;
		g.DrawText2D (x,y,"---------------------------------------------------------------------------------\n"); y-= h;
		g.DrawText2D (x,y,"Forest\t\t%d\t\t[%d, %d, %d]\t%d\t\t%d (Farore's Wind)\n",
			forest(),
			heart_container[0],heart_container[1],heart_container[2],
			easter_egg[0],spell[0]); y-= h;

		g.DrawText2D (x,y,"Fire\t\t%d\t\t[%d, %d, %d]\t%d\t\t%d (Din's Fire)\n",
			fire(),
			heart_container[3],heart_container[4],heart_container[5],
			easter_egg[1],spell[1]); y-= h;

		g.DrawText2D (x,y,"Water\t\t%d\t\t[%d, %d, %d]\t%d\t\t%d (Nayru's Love)\n",
			water(),
			heart_container[6],heart_container[7],heart_container[8],
			easter_egg[2],spell[2]); y-= h;

		g.DrawText2D (x,y,"Spirit\t\t%d\t\t[%d, %d, %d]\t%d\n",spirit(),
			heart_container[9],heart_container[10],heart_container[11],
			easter_egg[3],spell[0]); y-= h;

		g.DrawText2D (x,y,"Shadow\t\t%d\t\t[%d, %d, %d]\t%d\n",shadow(),
			heart_container[12],heart_container[13],heart_container[14],
			easter_egg[4],spell[0]); y-= h;

		g.DrawText2D (x,y,"Light\t\t%d\t\t[-------]\t%d\n",light(),
			easter_egg[5],spell[0]); y-= h;

		g.DrawText2D (x,y,"Heart containers from Merchant:\t[%d  ,  %d]\n",
			heart_container[15], heart_container[16]); y-= h;

		g.DrawText2D (x,y,"Hero's easter egg:\t\t\t\t%d\n",easter_egg[6]); y-= h;
	

		g.DrawText2D (x,y,"\n\n"); y-= h;
	};
};



#endif