#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *name;
    float size;
} City;

typedef struct {
    char *name;
    City cities[3];
} Country;

void fillCountries(Country *countries, int length, char *argv[]);
City *findLargestCity(Country *country);
void printLargestCities(Country *countries, int length);

int main(int argc, char *argv[])
{
    int length = (argc - 1) / 7;

    if (length < 1) {
        return 1;
    }

    Country countries[length];

    fillCountries(countries, length, argv);
    printLargestCities(countries, length);

    return 0;
}

void fillCountries(Country *countries, int length, char *argv[])
{
    int index = 1;

    for (int i = 0; i < length; i++) {
        (countries + i)->name = argv[index];
        index++;

        for (int j = 0; j < 3; j++) {
            ((countries + i)->cities + j)->name = argv[index];
            ((countries + i)->cities + j)->size = atof(argv[index + 1]);
            index += 2;
        }
    }
}

City *findLargestCity(Country *country)
{
    City *largest = country->cities;

    for (int j = 1; j < 3; j++) {
        if ((country->cities + j)->size > largest->size) {
            largest = country->cities + j;
        }
    }
    return largest;
}

void printLargestCities(Country *countries, int length)
{
    for (int i = 0; i < length; i++) {
        printf("%s: %s\n", (countries + i)->name, findLargestCity(countries + i)->name);
    }
}