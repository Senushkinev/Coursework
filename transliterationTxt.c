#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include <wchar.h>
#include <wctype.h>
#include <locale.h>

#include "transliterationTxt.h"

void transliterationTxt( struct Text *txt ){

        wchar_t* buffer;
        size_t tmpSize = 150;
        size_t k = 0;
        int flag;
        
	wchar_t arr1[20][3] = {L"ya", L"yo", L"yu", L"zh",L"ch", L"sh",L"kh",L"e`", L"``",L"cz",L"y`",L"Ya", L"Yo", L"Yu", L"Zh",L"Ch", L"Sh",L"Kh",L"E`",L"Cz" };
        wchar_t arr2[21] = L"яёюжчшхэъцыЯЁЮЖЧШХЭЦ";
        wchar_t arr3[2][52] = { L"abcdefghijklmnopqrstuvxz`ABCDEFGHIJKLMNOPQRSTUVXZ", L"абцдефгхийклмнопщрстувхзьАБЦДЕФГЧИЙКЛМНОПЩРСТУВЧЗ"};
        																				 		


        buffer = malloc( tmpSize * sizeof(wchar_t) );


        for ( size_t i = 0; i < txt->buffLenght; i++ )
        {

                for ( size_t j = 0; j < txt->sentences[i].sentLenght; j++ )
                {
                        if ( k + 3 == tmpSize )
                {
                        tmpSize +=20;
                        buffer = realloc ( buffer, tmpSize * sizeof( wchar_t ));
                }

                        if (txt->sentences[i].Sent[j] == L'щ')
                        {

                                buffer[k] = L's';
                                k++;
                                buffer[k] = L'h';
                                k++;
                                buffer[k] = L'h';
                                k++;

                        }
                        else if (txt->sentences[i].Sent[j] == L'Щ')
                        {
                        	buffer[k] = L'S';
                                k++;
                                buffer[k] = L'h';
                                k++;
                                buffer[k] = L'h';
                                k++;
                        }
                        else
                        {
                                buffer[k] = txt->sentences[i].Sent[j];
                                k++;
                        }
                }

                buffer[k] = L'\0';
                k = 0;

                for ( size_t j = 0; j < wcslen(buffer); j++ )
                {
                        if ( k + 2 == tmpSize )
                        {
                                tmpSize +=20;
                                txt->sentences[i].Sent= realloc(txt->sentences[i].Sent, tmpSize * sizeof( wchar_t ));
                        }

                        for ( size_t f = 0; f < 20; f++ )
                        {
                                if (buffer[j] == arr2[f])
                                {
                                        txt->sentences[i].Sent[k++] = arr1[f][0];
                                        txt->sentences[i].Sent[k++] = arr1[f][1];
                                        flag = 1;
                                        continue;
                                }
			}
                        if (flag != 1 )
                        {
                        	txt->sentences[i].Sent[k] = buffer[j];
                                k++;
                        }
			flag = 0;
                        
                }
                txt->sentences[i].Sent[k] = L'\0';
                k = 0;

		for ( size_t j = 0; j < wcslen(txt->sentences[i].Sent); j++ )
    		{
    			for ( size_t f = 0; f < 52; f++ )
    			{
    				if (txt->sentences[i].Sent[j] == arr3[1][f])
    				{
    					txt->sentences[i].Sent[j] = arr3[0][f];
    				}
    			}
    		}

		txt->sentences[i].sentLenght = wcslen(txt->sentences[i].Sent);
        }
    }

