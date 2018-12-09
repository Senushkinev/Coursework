#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include <wchar.h>
#include <wctype.h>
#include <locale.h>

#include "specialSymbols.h"

int comp ( const wchar_t *i, const wchar_t *j )
{
	return *j - *i;
}


void specialSymbols( struct Text *txt ){
	wchar_t* symbols;

	for ( size_t i = 0; i < txt->buffLenght; i++ )
	{
		size_t k = 0, size = 50;
		symbols = calloc( size, sizeof(wchar_t));

		for (size_t j = 0; j < txt->sentences[i].sentLenght; j++)
			{
			if ( !iswalnum( txt->sentences[i].Sent[j] ) )
			{	
				*( symbols + k ) = txt->sentences[i].Sent[j];
				k++;
			}
		}
		qsort( symbols, k,sizeof( wchar_t ), comp  );

		for ( size_t m = 0; m < k; m++ )
			wprintf(L"%c",*( symbols + m ));
		wprintf(L"\n");

		free( symbols );
	}
}
