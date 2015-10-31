// 1.1

#include "TileBucket.h"
#include "Defines.h"

TileBucket::TileBucket()
{
	FILE * pFile;
	char mystring [100];

	char map_file_path[FILE_PATH_SIZE];
	cat_path (map_file_path, SH, "MapFileBG.txt");

	fopen_s (&pFile, map_file_path , "r");
	
	if (pFile == NULL) printf("Error opening background map file\n");
	else 
	{
		//...
		
		fclose (pFile);
	};

};