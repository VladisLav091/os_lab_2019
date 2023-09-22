#include "revert_string.h"
#include <string.h>
#include <stdio.h>
void RevertString(char *str)
{
    printf("Reverted1:\n");
    printf("Reverted:\n");
	int length = strlen(str);
    int i;
    for (i = 0; i < length / 2; i++)
    {
        // Меняем символы местами, начиная с начала и конца строки
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

