#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <wchar.h>
#include <wctype.h>
#include <locale.h>

#include "readText.h"

int readText( struct Text *txt ){
	
	FILE *file;
	wchar_t c;
	size_t count = 0, index = 0, sizeSent = 250, sizeBuff = 20;

	wchar_t *fileUser = calloc(80, sizeof(wchar_t));
	char *fileName = calloc(80 ,sizeof(wchar_t));
	
	wprintf(L"Откуда считать текст ?\n");

	fgetws(fileUser, 80 * sizeof(wchar_t), stdin);
	fileUser[wcslen(fileUser)-1] = '\0';

	wcstombs(fileName, fileUser, 80 * sizeof(wchar_t));


	file = fopen( fileName, "r" );

   	if (errno == 2) {
        	wprintf(L"Вы ввели неправильное название файла или файла не существует.\n\t\tПрограмма завершена\n");
       		return 1;
    		}

	txt->sentences = malloc (sizeBuff * sizeof(struct Sentence));
	txt->sentences[count].Sent = malloc(sizeSent * sizeof(wchar_t));
	
	c = fgetwc(file);
	
	do{
		
		while( iswspace(c) && index == 0 ){
			c = fgetwc(file);
		}

		txt->sentences[count].Sent[index] = c;	
		index++;
		
		if (index + 2 == sizeSent){
			sizeSent += 50;
			txt->sentences[count].Sent = realloc(txt->sentences[count].Sent, sizeSent * sizeof(wchar_t));
		}
		
			
		if (  c == '.' ){
			txt->sentences[count].Sent[index] = '\0';
			txt->sentences[count].sentLenght = wcslen(txt->sentences[count].Sent);
			count++;
			
			txt->sentences[count].Sent = malloc(sizeSent * sizeof(wchar_t));
			if ( count == sizeBuff ){
				sizeBuff += 10;
				txt->sentences = realloc (txt->sentences, sizeBuff * sizeof(struct Sentence));
				}	
			index = 0;
		}

		c = fgetwc(file);
		
	}while ( c != WEOF );


	fclose (file);

	txt->buffLenght = count;	
	return 0;
	} 
