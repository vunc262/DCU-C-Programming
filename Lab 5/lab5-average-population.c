#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *name;
    char *capital;
    float population;
    int size;
} Country;

void fill_countries(Country *countries, int length, char *argv[]);
float average_population(Country *countries, int length);

int main(int argc, char *argv[])
{
    int length = (argc - 1) / 4;

    if (length < 1) {
        return 1;
    }

    Country countries[length];

    fill_countries(countries, length, argv);
    float result = average_population(countries, length);

    printf("Country\t\t\tCapital\t\t\tSize\t\t\tPopulation\n");

    for (int i = 0; i < length; i++) {
        printf("%s\t\t\t%s\t\t\t%d\t\t\t%.2f\n", countries[i].name, countries[i].capital, countries[i].size, countries[i].population);
    }

    printf("Population average: %.2f\n", result);

    return 0;
}

void fill_countries(Country *countries, int length, char *argv[])
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

float average_population(Country *countries, int length)
{
    float average = 0.0f;

    for (int i = 0; i < length; i++) {
        average += countries[i].population;
    }
    average /= length;
    return average;
}