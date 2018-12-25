#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include <wchar.h>
#include <wctype.h>
#include <locale.h>

#include "printTxt.h"

void printTxt( struct Text *txt ){
	
	wprintf(L"\n");
	for (size_t i = 0;i < txt->buffLenght; i++)
		wprintf(L"%ls [%ld]\n", txt->sentences[i].Sent, txt->sentences[i].sentLenght);
}
