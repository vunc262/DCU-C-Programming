#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float findLargest(float numbers[], int length);

float findSecondLargest(float largest, float numbers[], int length);

int main(int argc, char *argv[])
{
    int length = argc - 1;
    float *numbers = malloc(sizeof(float) * length);

    if (numbers == NULL) {
        return 1;
    }

    for (int i = 0; i < length; i++) {
        numbers[i] = atof(argv[i + 1]);
    }

    float largest = findLargest(numbers, length);
    float result = findSecondLargest(largest, numbers, length);

    printf("%.1f\n", result);
    free(numbers);
    numbers = NULL;
    return 0;
}

float findLargest(float numbers[], int length)
{
    float largest = numbers[0];

    for (int i = 0; i < length; i++) {
        if (numbers[i] > largest) {
            largest = numbers[i];
        }
    }
    return largest;
}

float findSecondLargest(float largest, float numbers[], int length)
{
    float secondLargest = 0;

    for (int i = 0; i < length; i++) {
        if (numbers[i] > secondLargest && numbers[i] < largest) {
            secondLargest = numbers[i];
        }
    }
    return secondLargest;
}