#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <wchar.h>
#include <wctype.h>
#include <locale.h>

#include "changeNumber.h"

void changeNumber( struct Text *txt ){

    wchar_t* binary;
    int count = 0;
    size_t k = 0;
    size_t sizeSent = 150;

    binary = calloc(4, sizeof(wchar_t));

    for ( size_t i = 0; i < txt->buffLenght; i++ )
    {
	k = 0;
	wchar_t* buffStr = malloc(sizeSent * sizeof(wchar_t));

	for ( size_t j = 0; j < txt->sentences[i].sentLenght; j++ )
        {
				
            	if (!iswdigit( txt->sentences[i].Sent[j] ) )
            	{
			if (k + 2 == sizeSent){
                                        sizeSent += 50;
                                        buffStr = realloc(buffStr, sizeSent * sizeof(wchar_t));
			}

                	buffStr[k] = txt->sentences[i].Sent[j];
              	 	k++;
		}

            	if ( iswdigit( txt->sentences[i].Sent[j] ) )
            	{
                	wchar_t numb = txt->sentences[i].Sent[j] - 48;
                	count = 0;

                	for ( int j = 3; j >= 0; j-- )
                	{
                    		if (k + 2 == sizeSent){
					sizeSent += 50;
                        		buffStr = realloc(buffStr, sizeSent * sizeof(wchar_t));
				}

				if ( count == 0 && ((numb >> j) & 1 ) == 0)
                        	continue;

		    		buffStr[k] = ((numb >> j) & 1 ) + 48;
		    		k++;
                    		count++;
                	}
            	}
        }

	buffStr[k] = L'\0';
	free(txt->sentences[i].Sent);
	txt->sentences[i].Sent = buffStr;
	txt->sentences[i].sentLenght = wcslen(buffStr);
    }
}

