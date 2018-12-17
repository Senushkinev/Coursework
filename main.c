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

int main(){

	setlocale(LC_CTYPE, "");

	struct Text txt;

	readText(&txt);

	deleteCopy(&txt);

	specialSymbols(&txt);

	deleteOdd(&txt);
	
	changeNumber(&txt);

}
