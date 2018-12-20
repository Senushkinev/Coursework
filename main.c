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
#include "changeNumber.h"
#include "transliterationTxt.h"


int main(){

	setlocale(LC_CTYPE, "");

	struct Text txt;

	readText(&txt);

	deleteCopy(&txt);

//	specialSymbols(&txt);
//
//	deleteOdd(&txt);
//	
//	changeNumber(&txt);

	transliterationTxt(&txt);

	//for (size_t i = 0; i < txt.buffLenght; i++ ){
	//	wprintf(L"%ls\n", txt.sentences[i].Sent);
	//}

}
