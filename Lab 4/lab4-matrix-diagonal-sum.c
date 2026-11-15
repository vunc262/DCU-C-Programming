#include <stdio.h>
#include <stdlib.h>

int get_main_diagonal_sum(char *args[], int n);

int main(int argc, char *argv[])
{
    if (argc < 2) {
        return 1;
    }

    int n = atoi(*(argv + 1));

    if (argc != n * n + 2) {
        return 1;
    }

    printf("%d\n", get_main_diagonal_sum(argv, n));
    return 0;
}

int get_main_diagonal_sum(char *args[], int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += atoi(*(args + 2 + i * n + i));
    }

    return sum;
}