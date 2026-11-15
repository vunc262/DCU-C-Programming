#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[])
{
    int length = argc - 1;
    int nums[length];
    int a = 0;

    for(int i = 0; i < length; i++){
        nums[i] = atoi(argv[i + 1]);
    }

    for (int i = 0; i < length; i++) {
        if (nums[i] % 2 == 0) {
            printf("%d - %d\n", i, nums[i]);
            a = 1;
        }
    }

    if (a == 0){
        printf("Not found!\n");
    }
    return 0;
}