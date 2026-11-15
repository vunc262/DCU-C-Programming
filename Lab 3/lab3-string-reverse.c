#include <stdio.h>
#include <string.h>

void reverse(char *str);

int main(int argc, char *argv[])
{
    char output[50];
    strcpy(output, argv[1]);
    reverse(output);
    printf("%s\n", output);
}

void reverse(char *str)
{
    int i = 0, j = strlen(str)-1;
    char t;

    while(i < j) {
        t = str[i];
        str[i] = str[j];
        str[j] = t;
        i++;
        j--;
    }
}