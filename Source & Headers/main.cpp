#ifndef __Main__
#define __Main__
#include "SaveState.h"

SaveState save_state;
Graphics graphics;
Image medallions_image;

void MainLoop(void)
{
	/*
	graphics.DrawImage2D (10,10,300,300,0,0,300,300,
		medallions_image);

	graphics.SetColor (0,0,200);
	graphics.FillRectangle2D (400,300,650,550);
	
	graphics.SetLineWidth(6);
	graphics.DrawLine2D (460,60,700,90);
	*/

	save_state.graphics_print_table(graphics);
}

int main (void)
{
	save_state.print_table();	
	
	graphics.CreateMainWindow(1024, 768, "A Lust for Power");
	graphics.SetBackgroundColor(32,32,40);
	
	char medallions_path[512];
	path (medallions_path, CR, "Medallions.png");
//	printf("Test:\t\t%s\n\n", medallions_path);

	medallions_image.LoadPNGImage("Medallions.png");

	graphics.SetMainLoop(MainLoop);
	graphics.StartMainLoop();
	

	return 0;
}


/*
	void path (char* ptr, const char* sub_folder_path, const char* file_name)

	Pega o PROJECT_PATH la do define (em "Defines.h"), concatena com o subdiretorio do segundo argumento (que pode ser um nome inteiro como "Source & Headers\\" ou um atalho como SH -- que tambem esta no "Defines.h"), e depois concatena com o nome do arquivo do terceiro argumento (e.g. "Ganondorf.png"), e salva em um ponteiro para char pre-declarado e pre-alocado externamente.

*/

void path (char* ptr, const char* sub_folder_path, const char* file_name)
{
	strcpy(ptr,PROJECT_PATH);
	strcat(ptr,sub_folder_path);
	strcat(ptr,file_name);
};


#endif /* defined(__Main__) */