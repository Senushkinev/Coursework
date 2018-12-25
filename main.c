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
#include "printTxt.h"

int main(){

        setlocale(LC_CTYPE, "");

        struct Text txt;
        int open;
        wchar_t choice[50];

        open = readText(&txt);

        if (open)
                return -1;

	deleteCopy(&txt);


	do{
		wprintf(L"\n");
                wprintf(L"Что вы хотите сделать с текстом?\n");
                wprintf(L"0 Выход\n");
                wprintf(L"1 Сделать транслитерацию всех кириллических символов в тексте.\n");
                wprintf(L"2 Вывести все специальные символы в порядке уменьшения их кода.\n");
                wprintf(L"3 Заменить все цифры в тексте их двоичным кодом.\n");
                wprintf(L"4 Удалить все предложения в которых есть нечетная цифра.\n");
                wprintf(L"5 Вывести текст\n");
		wprintf(L"\n");

                fgetws(choice, 50, stdin);
                if (wcslen(choice) != 2){
                        wprintf(L"Ошибка ввода команды. Команда должна находиться в промежутке от 0 до 5. Попробуйте снова.\n");
                        continue;
                }
                switch(choice[0]){
                case('0'):
                        return 0;
                case('1'):
                        transliterationTxt(&txt);
                        break;
                case('2'):
                        specialSymbols(&txt);
                        break;
                case('3'):
                        changeNumber(&txt);
                        break;
                case('4'):
                        deleteOdd(&txt);
                        break;
		case('5'):
			printTxt(&txt);
			break;
		default:
			wprintf(L"Ошибка ввода команды. Команда должна находиться в промежутке от 0 до 5. Попробуйте снова.\n");
                        continue;
                }

        }while ( choice[0] != L'0');

}
