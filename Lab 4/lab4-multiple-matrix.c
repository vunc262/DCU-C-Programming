#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int m1, n1, m2, n2;
    char **a, **b;
    int i, j, k, sum;

    if (argc < 3) {
        return 1;
    }

    m1 = atoi(argv[1]);
    n1 = atoi(argv[2]);

    if (argc < 5 + m1 * n1) {
        return 1;
    }

    m2 = atoi(argv[3 + m1 * n1]);
    n2 = atoi(argv[4 + m1 * n1]);

    if (n1 != m2 || argc != 5 + m1 * n1 + m2 * n2) {
        return 1;
    }

    a = argv + 3;
    b = argv + 5 + m1 * n1;

    for (i = 0; i < m1; i++) {
        for (j = 0; j < n2; j++) {
            sum = 0;
            for (k = 0; k < n1; k++) {
                sum += atoi(*(a + i * n1 + k)) * atoi(*(b + k * n2 + j));
            }
            printf("%d", sum);
            if (j < n2 - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}