// 1.1

#ifndef __Defines__
#define __Defines__

//#include "Graphics.h"
#include <string.h>
#include <stdio.h>

#define GABRIEL_PATH	""
#define JOQAUIM_PATH	""
#define LEONARDO_PATH	""
#define LUCCA_PATH		""
#define ROBERTO_PATH	""
#define VINICIUS_PATH	"\\\\Mac\\Home\\Projects\\A-Lust-for-Power\\"

#define PROJECT_PATH VINICIUS_PATH

#define TILE_SIZE (16)
#define MAX_RUPEES (999)

#define SH "Source & Headers\\"
#define CR "Resources\\Sprites\\Chars\\Raw\\"
#define CG "Resources\\Sprites\\Chars\\Grid\\"
#define TR "Resources\\Sprites\\Terrenos\\"

void path (char* ptr, const char* sub_folder_path, const char* file_name);

#endif /* defined(__Defines__) */