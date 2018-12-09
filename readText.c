#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include <wchar.h>
#include <wctype.h>
#include <locale.h>


struct Sentence {
	wchar_t* Sent;
	size_t sentLenght;
};

struct Text {
	struct Sentence *sentences;
	size_t buffLenght;
};




void readText( struct Text *txt ){
	
	
	
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

	txt->sentences = malloc (sizeBuff * sizeof(struct Sentence));
	txt->sentences[count].Sent = malloc(sizeSent * sizeof(wchar_t));
	
	c = fgetwc(file);
	
	do{
		
		while( index == 0 && ( c == ' ' || c == '\n' || c == '\t')){
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
	
	for (int i = 0; i < count; i++)
		wprintf(L"%ls [%ld]\n", txt->sentences[i].Sent, txt->sentences[i].sentLenght);
	
	printf("%ld\n",txt->buffLenght );	
	} 
