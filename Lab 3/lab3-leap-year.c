#include <stdio.h>
#include <stdlib.h>

int leap(int start, int stop, int arr[]);

int main(int argc, char *argv[])
{
    int first = atoi(argv[1]);
    int second = atoi(argv[2]);
    int possible = (second - first) / 4 + 1;
    int years[possible];
    int count = leap(first, second, years);

    for (int i = 0; i < count; i++) {
        printf("%d\n", years[i]);
    }
    return 0;
}

int leap(int start, int stop, int arr[])
{
    int found = 0;

    for (int year = start; year <= stop; year++) {
        if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
            arr[found] = year;
            found++;
        }
    }
    return found;
}