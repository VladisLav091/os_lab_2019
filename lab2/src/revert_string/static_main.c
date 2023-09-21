#include "revert_string.h"
#include <stdio.h>

int main() {
    char str[] = "Hello, World!";
    RevertString(str);
    printf("Reverted string: %s\n", str);
    return 0;
}