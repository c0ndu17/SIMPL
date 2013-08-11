#include <stdlib.h>
#include <stdio.h>
#include "scanner.c"

int main(int argc, char *argv[])
{
    FILE *input;
    input = fopen("test.txt", "r");
    init_scanner(input);
    return EXIT_SUCCESS;
}
