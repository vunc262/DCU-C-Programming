#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float multiply(float param1, float param2);
float divide(float param1, float param2);

int main(int argc, char *argv[])
{
    if(argc < 4){
        printf("invalid\n");
        return 1;
    }

    float n1 = atof(argv[2]);
    float n2 = atof(argv[3]);

    if(strcmp(argv[1], "divide") == 0){
        if(n2 == 0.0){
            printf("invalid\n");
            return 1;
        }
        float result = divide(n1, n2);
        printf("%f\n", result);
    }

    if(strcmp(argv[1], "multiply") == 0){
        float result = multiply(n1, n2);
        printf("%f\n", result);
    }
    return 0;
}

float multiply(float param1, float param2)
{
    return param1 * param2;
}

float divide(float param1, float param2)
{
    return param1 / param2;
}