#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int answer = 0;
    int tryPoints = 5;
    int conversionPoints = 2;
    int penaltyPoints = 3;
    int dropGoalPoints = 3;

    tryPoints *= atoi(argv[1]);
    conversionPoints *= atoi(argv[2]);
    penaltyPoints *= atoi(argv[3]);
    dropGoalPoints *= atoi(argv[4]);
    answer = tryPoints + conversionPoints + penaltyPoints + dropGoalPoints;

    printf("%d\n", answer);
    return (0);
}