#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <wchar.h>
#include <wctype.h>
#include <locale.h>

#include "deleteOdd.h"

void deleteOdd( struct Text *txt ){

	for ( size_t i = 0; i < txt->buffLenght; i++ )
	{
		for ( size_t j = 0; j < txt->sentences[i].sentLenght; j++ )
		{
			if ( iswdigit( txt->sentences[i].Sent[j] ) )
			{
				if ( txt->sentences[i].Sent[j] % 2 )
				{
				free( txt->sentences[i].Sent );
                                txt->sentences[i].Sent = NULL;
                                memmove(txt->sentences+i , txt->sentences+i+1, (txt->buffLenght-i) * sizeof(struct Sentence));
				txt->buffLenght--;
				i--;
				break;
				}
			}
		}
	}


	struct Sentence *tempPoint = realloc(txt->sentences, (txt->buffLenght) * sizeof(struct Sentence));

	if (tempPoint)
		txt->sentences = tempPoint;
	else
		wprintf(L" Realloc не смог найти память под новый массив указателей\n ");

}
