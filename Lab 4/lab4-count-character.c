#include <stdio.h>

int countChar(char *str, char letter);

int main (int argc, char *argv[])
{
    if (argc != 3) {
        printf("0\n");
        return 1;
    }

    char *letter = argv[1];
    char *letters = argv[2];
    int result = countChar(letters, *letter);

    printf("%d\n", result);
    return 0;
}

int countChar(char *str, char letter)
{
    int counter = 0;

    while (*str != '\0') {
        if (*str == letter) {
            counter++;
        }
        str++;
    }

    return counter;
}
