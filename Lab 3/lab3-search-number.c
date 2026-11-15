#include <stdio.h>
#include <stdlib.h>

int search(int arr[], int num, int length);

int main(int argc, char *argv[])
{
    int numbers[50];
    int number1 = atoi(argv[1]);
    int counter = 0;

    for (int i = 2; i < argc; i++) {
        numbers[counter] = atoi(argv[i]);
        counter++;
    }

    int result = search(numbers, number1, counter);

    if (result == -1) {
        printf("%d not found\n", number1);
    }
    else {
        printf("Found %d at %d\n",number1, result);
    }
}

int search(int arr[], int num, int length)
{
    for (int i = 0; i < length; i++) {
        if (arr[i] == num) {
            return i;

        }
    }
    return -1;
}