#include <stdio.h>

#include "lib.h"


void hello(char* name) {
    printf("Hello, %s\n", name);
}

int fak(int num) {
    if (num<2)
        return 1;

    return num * fak(num-1);
}
