#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float sum(int *a, int *b);
float difference(int *a, int *b);
float product(int *a, int *b);
float devision(int *a, int *b);
float power(int *a, int *b);
float naturalLog(int *a, int *b);

int main(int argc, char *argv[])
{
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    float result = sum(&a, &b);
    printf("%.2f\n", result);

    result = difference(&a, &b);
    printf("%.2f\n", result);

    result = product(&a, &b);
    printf("%.2f\n", result);

    result = devision(&a, &b);
    printf("%.2f\n", result);

    result = power(&a, &b);
    printf("%.2f\n", result);

    result = naturalLog(&a, &b);
    printf("%.2f\n", result);

    return 0;
}

float sum(int *a, int *b)
{
    return *a + *b;
}

float difference(int *a, int *b)
{
    return *a - *b;
}

float product(int *a, int *b)
{
    return *a * *b;
}

float devision(int *a, int *b)
{
    return (float) *a / *b;
}

float power(int *a, int *b)
{
    return pow(*a, *b);
}

float naturalLog(int *a, int *b)
{
    return log(*a) + log(*b);
}