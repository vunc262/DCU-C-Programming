#include <stdio.h>

char find_most_frequent(char *str);

int main(int argc, char *argv[])
{
    if (argc != 2) {
        return 1;
    }

    char result = find_most_frequent(argv[1]);

    printf("%c\n", result);
    return 0;
}

char find_most_frequent(char *str)
{
    int counts[256] = {0};
    int max = 0;
    char res = '\0';

    while (*str) {
        unsigned char c = *str;
        if (c >= 'A' && c <= 'Z')
        {
            c += 32;
        }
        if (c != ' ')
        {
            counts[c]++;
        }
        str++;
    }

    for (int i = 0; i < 256; i++) {
        if (counts[i] > max) {
            max = counts[i];
            res = (char)i;
        }
    }
    return res;
}