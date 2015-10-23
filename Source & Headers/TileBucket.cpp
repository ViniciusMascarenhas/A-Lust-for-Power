// 1.1

#include "TileBucket.h"
#include "Includes.h"

TileBucket::TileBucket()
{
	FILE * pFile;
	char mystring [100];

	char map_file_path[300];	// Pode aumentar o tamanho se precisar.
	strcpy_s(map_file_path, FILE_PATH);
	strcat_s(map_file_path, "MapFileBG.txt");

	//Tileset.LoadPNGImage("____.png");

	fopen_s (&pFile, map_file_path , "r");
	
	if (pFile == NULL) printf("Error opening map file\n");
	else 
	{
		//...
		
		fclose (pFile);
	};

};