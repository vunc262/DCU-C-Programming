#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int num = 0;

    for (int i = 1; i < argc; i++){
        int curNum = atoi(argv[i]);
        if (curNum > num){
            num = curNum;
        }
    }

    printf("%d\n", num);
}