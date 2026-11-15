#include <stdio.h>
#include <string.h>

char* find(char *arr[], int length);

int main(int argc, char *argv[])
{
    char *words[argc];
    int count = 0;

    for (int i = 1; i < argc; i++) {
        words[count] = argv[i];
        count++;
    }

    char *result = find(words, count);

    printf("%s\n", result);
    return 0;
}

char* find(char *arr[], int length)
{
    char *biggest = arr[0];

    for (int i = 0; i < length; i++) {
        if (strlen(arr[i]) > strlen(biggest)) {
            biggest = arr[i];
        }
    }
    return biggest;
}