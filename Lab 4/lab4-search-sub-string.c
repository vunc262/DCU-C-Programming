#include <stdio.h>

int main(int argc, char *argv[])
{
    char *str, *sub, *p, *a, *b;
    
    if (argc < 3) {
        return 1;
    }

    str = argv[1];
    sub = argv[2];

    for (p = str; *p; p++) {
        a = p;
        b = sub;

        while (*a && *b && *a == *b) {
            a++;
            b++;
        }

        if (*b == '\0') {
            printf("%ld %ld\n", (long)(p - str), (long)(a - str - 1));
            return 0;
        }
    }

    return 0;
}