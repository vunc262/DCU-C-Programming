#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
    float inch = 2.54;
    int centimetres = atoi(argv[1]);
    float answer = 0;

    answer = centimetres/inch;

    printf("%.2f\n", answer);
    return (0);
}