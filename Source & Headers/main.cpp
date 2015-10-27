#ifndef __Main__
#define __Main__
#include "SaveState.h"

SaveState save_state;
Graphics graphics;
Image image;
Image image_in_same_folder;

void MainLoop(void)
{
	//image.SetPosition (240,200,65,79);									// Usei isso com o outro protótipo de DrawImage2D.
	//image_in_same_folder.SetPosition (335,200,65,79);
	graphics.DrawImage2D (240,200,65,79,15,18,65,79,image);					// A do caminho completo, em uma pasta dedicada.
	graphics.DrawImage2D (335,200,65,79,15,18,65,79,image_in_same_folder);	// A da mesma pasta que o código do projeto.

	// Tudo isso aqui abaixo funciona. Deixei comentado para voltar a usar como teste.
	/*		graphics.SetColor (0,0,200);
			graphics.FillRectangle2D (400,300,650,550);
			graphics.SetLineWidth(6);
			graphics.DrawLine2D (460,60,700,90);
	*/
}

int main (void)
{
	//save_state.print_table();						// Exibe na tela o arquivo de exemplo SaveFile.txt.
	
	graphics.CreateMainWindow(640, 480, "A Lust for Power");
	graphics.SetBackgroundColor(32,32,40);
	
	char image_path[512];							// Para guardar o caminho completo do nome do arquivo de imagem.
	path (image_path, CR, "Ganon.png");				// Usa os defines em Defines.h para concatenar o caminho completo.
	if (0) printf("Test:\t\t%s\n\n", image_path);	// Exibe o caminho para verificar se está correto -- e está.
	image.LoadPNGImage(image_path);					// Problema aqui ou na chamada de Graphics::DrawImage2D(...).
	
	image_in_same_folder.LoadPNGImage("Ganon.png");	// Esta imagem está na mesma pasta do código do projeto.

	graphics.SetMainLoop(MainLoop);
	graphics.StartMainLoop();

	return 0;
}


/*
	void path (char* ptr, const char* sub_folder_path, const char* file_name)

	Pega o PROJECT_PATH lá do define (em "Defines.h"), concatena com o subdiretório do segundo argumento (que pode ser um nome inteiro como "Source & Headers\\" ou um atalho como SH -- que também está no "Defines.h"), então concatena com o nome do arquivo do terceiro argumento (e.g. "Ganondorf.png"), e por fim salva em um ponteiro para char pré-declarado e pré-alocado externamente.
*/

void path (char* ptr, const char* sub_folder_path, const char* file_name)
{
	strcpy(ptr,PROJECT_PATH);
	strcat(ptr,sub_folder_path);
	strcat(ptr,file_name);
};


#endif /* defined(__Main__) */