#include <stdio.h>
#include <stdlib.h>

int duplicate(int arr[], int count);

int main(int argc, char *argv[])
{
    int numbers[50];
    int count = 0;

    for(int i = 1; i < argc; i++) {
        numbers[count] = atoi(argv[i]);
        count++;
    }

    int result = duplicate(numbers, count);

    if (result != -1) {
        printf("%d\n", result);
    }
    else {
        printf("no duplicated number");
    }
}

int duplicate(int arr[], int count)
{
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if (arr[i] == arr[j]) {
                return arr[i];
            }
        }
    }
    return -1;
}