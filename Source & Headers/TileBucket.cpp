// 1.0

#include "TileBucket.h"
#include "Includes.h"

TileBucket::TileBucket()
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