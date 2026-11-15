#include <stdio.h>
#include <stdlib.h>

int productOfTwoVectors(int *vector1, int *vector2, int n);

int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);

    if (argc != 2 * n + 2) {
        return 1;
    }

    int *vector1 = malloc(sizeof(int) * n);
    int *vector2 = malloc(sizeof(int) * n);

    int index = 2;
    for (int i = 0; i < n; i++) {
        vector1[i] = atoi(argv[index]);
        vector2[i] = atoi(argv[index + n]);
        index += 1;
    }
    int result = productOfTwoVectors(vector1, vector2, n);
    printf("%d\n", result);
    return 0;
}

int productOfTwoVectors(int *vector1, int *vector2, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += vector1[i] * vector2[i];
    }
    return sum;
}