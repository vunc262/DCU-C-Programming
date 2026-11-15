#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415

int main(int argc, char *argv[])
{
    if(argc == 1){
        printf("No input given!\n");
        return 1;
    }

    if(argc == 2){
        printf("Two arguments needed!\n");
        return 1;
    }

    int radius = atoi(argv[1]);
    int height = atoi(argv[2]);

    if(radius < 0 || height < 0){
        printf("The radius or height cannot be negative\n");
        return 1;
    }

    float result = 2 * PI * radius * (radius + height);

    printf("%.2f\n", result);
    return 0;
}