#include <stdio.h>
#include <stdlib.h>

int sort(int arr[], int len);

int main(int argc, char *argv[])
{
    int length = argc - 1;
    int numbers[length];
    int counter = 0;

    for(int i = 1; i < argc; i++) {
        numbers[counter] = atoi(argv[i]);
        counter++;
    }

    sort(numbers, length);

    for (int i = 0; i < length; i++) {
        printf("%d\n", numbers[i]);
    }
    return 0;
}

int sort(int arr[], int len)
{
    int temp;

    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}