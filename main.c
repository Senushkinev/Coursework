#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include <wchar.h>
#include <wctype.h>
#include <locale.h>

#include "readText.h"
#include "deleteCopy.h"
#include "struct.h"

int main(){

	setlocale(LC_CTYPE, "");

	struct Text txt;

	readText(&txt);

	wprintf(L"____________________________________________________________________________________________________________\n");

	deleteCopy(&txt);

	for (size_t i = 0; i < txt.buffLenght; i++)
		wprintf(L"%ls [%ld]\n", txt.sentences[i].Sent, txt.sentences[i].sentLenght);

	wprintf(L"Предложений после удаления дубликатов стало: %ld\n", txt.buffLenght);
}

