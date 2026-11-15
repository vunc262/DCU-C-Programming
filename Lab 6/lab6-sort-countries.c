#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char *name;
    char *capital;
    int size;
    float population;
}Country;

void fillCountries(Country *countries, int length, char *argv[]);
void sortCountries(Country *countries, int length);

int main(int argc, char *argv[])
{
    int length = (argc - 1) / 4;

    if (length < 1) {
        return 1;
    }

    Country countries[length];

    fillCountries(countries, length, argv);
    sortCountries(countries, length);

    printf("Country\t\t\tCapital\t\t\tSize\t\t\tPopulation\n");
    for (int i = 0; i < length; i++) {
        printf("%s\t\t\t%s\t\t\t%d\t\t\t%.2f\n", countries[i].name, countries[i].capital, countries[i].size, countries[i].population);
    }
    return 0;
}

void fillCountries(Country *countries, int length, char *argv[])
{
    int index = 1;

    for (int i = 0; i < length; i++) {
        countries[i].name = argv[index];
        countries[i].capital = argv[index + 1];
        countries[i].population = atof(argv[index + 2]);
        countries[i].size = atoi(argv[index + 3]);
        index += 4;
    }
}

void sortCountries(Country *countries, int length)
{
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - 1 - i; j++) {
            if ((countries + j)->population < (countries + j + 1)->population) {
                Country temp = *(countries + j);
                *(countries + j) = *(countries + j + 1);
                *(countries + j + 1) = temp;
            }
        }
    }
}