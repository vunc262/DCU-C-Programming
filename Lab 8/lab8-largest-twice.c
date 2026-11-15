#include <stdio.h>
#include <stdlib.h>

int findLargest(int numbers[], int length);

int findSmallest(int numbers[], int length);

int main(int argc, char *argv[])
{
    int length = argc - 1;

    if (length <= 0) {
        return 1;
    }

    int *numbers = malloc(sizeof(int) * length);

    if (numbers == NULL) {
        return 1;
    }

    for (int i = 0; i < length; i++) {
        numbers[i] = atoi(argv[i + 1]);
    }

    int largest = findLargest(numbers, length);
    int smallest = findSmallest(numbers, length);

    if (smallest * 2 <= largest) {
        printf("%d\n", largest);
    }
    else {
        printf("0\n");
    }

    free(numbers);
    numbers = NULL;
    return 0;
}

int findLargest(int numbers[], int length) {
    int largest = numbers[0];

    for (int i = 0; i < length; i++) {
        if (numbers[i] > largest) {
            largest = numbers[i];
        }
    }
    return largest;
}

int findSmallest(int numbers[], int length) {
    int smallest = numbers[0];

    for (int i = 0; i < length; i++) {
        if (numbers[i] < smallest) {
            smallest = numbers[i];
        }
    }
    return smallest;
}