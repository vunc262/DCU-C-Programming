#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int wordLength(char **words, int length);

int main(int argc , char *argv[])
{
    int length = argc - 1;

    if (length <= 0) {
        return 1;
    }

    char **words = malloc(length * sizeof(char *));

    if (words == NULL) {
        free(words);
        words = NULL;
        return 1;
    }

    for (int i = 0; i < length; i++) {
        words[i] = argv[i + 1];
    }

    int lWord = wordLength(words, length);

    for (int i = 0; i < length; i++) {
        if (strlen(words[i]) == lWord) {
            printf("%s\n", words[i]);
        }
    }

    free(words);
    words = NULL;
    return 0;
}

int wordLength(char **words, int length) {
    int longestWord = strlen(words[0]);

    for (int i = 1; i < length; i++) {
        if (strlen(words[i]) > longestWord) {
            longestWord = strlen(words[i]);
        }
    }
    return longestWord;
}

