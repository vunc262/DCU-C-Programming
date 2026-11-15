#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *name;
    char *capital;
    float population;
    int size;
} Country;

int main(int argc, char *argv[])
{
    Country country;
    country.name = argv[1];
    country.capital = argv[2];
    country.population = atof(argv[3]);
    country.size = atoi(argv[4]);

    printf("%s\n", country.name);
    printf("%s\n", country.capital);
    printf("%.2f million people\n", country.population);
    printf("%d km2\n", country.size);

    return 0;
}