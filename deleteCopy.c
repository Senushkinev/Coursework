#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <wchar.h>
#include <wctype.h>
#include <locale.h>

#include "deleteCopy.h"

void deleteCopy( struct Text *txt ){

        for ( size_t i = 0; i < txt->buffLenght - 1; i++ )
        {
                for ( size_t j = i + 1; j < txt->buffLenght; j++ )
                {
                        if ( txt->sentences[i].sentLenght == txt->sentences[j].sentLenght)
                        {		     
				if ( wcscasecmp( txt->sentences[i].Sent, txt->sentences[j].Sent ) == 0 )
                                {
                                free( txt->sentences[j].Sent );
                                txt->sentences[j].Sent = NULL;
                                memmove(txt->sentences+j, txt->sentences+j+1, (txt->buffLenght-j) * sizeof(struct Sentence));
				txt->buffLenght--;
				j--;
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

