#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include <wchar.h>
#include <wctype.h>
#include <locale.h>

#include "deleteCopy.h"

void deleteCopy( struct Text *txt ){
        int count = 0;

        for ( size_t i = 0; i < txt->buffLenght; i++ )
        {
                for ( size_t j = i + 1; j < txt->buffLenght - 1; j++ )
                {
                        if ( txt->sentences[i].sentLenght == txt->sentences[j].sentLenght)
                        {
                                        if ( wcscasecmp( txt->sentences[i].Sent, txt->sentences[j].Sent ) == 0 )
                                        {
                                        free( txt->sentences[j].Sent );
                                        txt->sentences[j].Sent = NULL;
                                        memmove(txt->sentences+j, txt->sentences+j+1, (txt->buffLenght-j) * sizeof(struct Sentence));
                                        count++;
                                        }
                        }
                }
        }


        txt->buffLenght = txt->buffLenght - count;

        struct Sentence *tempPoint = realloc(txt->sentences, (txt->buffLenght) * sizeof(struct Sentence));

                if (tempPoint)
                        txt->sentences = tempPoint;
                else
        	        wprintf(L" Realloc не смог найти память под новый массив указателей\n ");

}

