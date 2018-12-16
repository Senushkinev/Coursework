#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include <wchar.h>
#include <wctype.h>
#include <locale.h>

#include "readText.h"
#include "deleteCopy.h"
#include "specialSymbols.h"
#include "deleteOdd.h"

int main(){

	setlocale(LC_CTYPE, "");

	struct Text txt;

	readText(&txt);

	deleteCopy(&txt);

//	specialSymbols(&txt);

	deleteOdd(&txt);
	for (size_t i = 0; i < txt.buffLenght; i++)
                wprintf(L"%ls [%ld]\n", txt.sentences[i].Sent, txt.sentences[i].sentLenght);
        wprintf(L"Предложений после считывания:[%ld]\n", txt.buffLenght);
        wprintf(L"--------------------------------------------------------------------------\n");
}
