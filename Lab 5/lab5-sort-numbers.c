#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ascending(int length, int *arr);
void descending(int length, int *arr);

int main(int argc, char *argv[])
{
    int length = atoi(argv[1]);
    char *func = argv[2 + length];

    int count = 0;
    int arr[50];

    for (int i = 2; count < length; i++) {
        arr[count] = atoi(argv[i]);
        count++;
    }

    if (strcmp(func, "asc") == 0)
    {
        ascending(length, arr);
        printf("Sorted numbers:");

        for (int i = 0; i < length; i++) {
            printf(" %d", arr[i]);
        }

        printf("\n");
    }

    else if (strcmp(func, "desc") == 0)
    {
        descending(length, arr);
        printf("Sorted numbers:");

        for (int i = 0; i < length; i++) {
            printf(" %d", arr[i]);
        }
        printf("\n");
    }
    return 0;
}

void ascending(int length, int *arr)
{
    for (int i = 0; i < length; i++) {
        for (int j = i + 1; j < length; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void descending(int length, int *arr)
{
    for (int i = 0; i < length; i++) {
        for (int j = i + 1; j < length; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}