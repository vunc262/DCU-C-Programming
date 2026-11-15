#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[])
{
    int count = 0;

    for(int i = 1; i < argc; i++){
        if(atoi(argv[i]) % 2 != 0){
            count += 1;
        }
    }

    printf("%d\n", count);
    return 0;
}