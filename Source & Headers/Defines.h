// 1.1

#ifndef __Defines__
#define __Defines__

//#include "Graphics.h"
#include <string.h>
#include <stdio.h>

/* Os #defines abaixo devem ter os caminhos para as pastas nas suas máquinas, incluindo
"\\" no final. Não mexer nos #defines dos coleguinhas! */

#define GABRIEL_PATH	""
#define JOQAUIM_PATH	""
#define LEONARDO_PATH	""
#define LUCCA_PATH		""
#define ROBERTO_PATH	""
#define VINICIUS_PATH	"C:\\Users\\Admin\\Documents\\GitHub\\A-Lust-for-Power\\"

/* No #define abaixo, trocar o símbolo da direita pela constante definida correspondente
ao caminho da pasta Source & Headers do projeto na sua máquina.
Quem usar mais de uma máquina deve criar defines adicionais nas linhas acima para trocar o símbolo
abaixo. Por exemplo: FULANO_DESKTOP_PATH, FULANO_LAPTOP_PATH, etc. */

#define PROJECT_PATH VINICIUS_PATH

#define TILE_SIZE (16)
#define MAX_RUPEES (99)

#define SH "Source & Headers\\"
#define CR "Resources\\Sprites\\Chars\\Raw\\"
#define CG "Resources\\Sprites\\Chars\\Grid\\"
#define TR "Resources\\Sprites\\Terrenos\\"

void path (char* ptr, const char* sub_folder_path, const char* file_name);

#endif /* defined(__Defines__) */