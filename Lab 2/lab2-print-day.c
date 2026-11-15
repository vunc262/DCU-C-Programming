#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    const char *days[] = {"Sunday", "Monday", "Tuesday", "Wednesday",
                          "Thursday", "Friday", "Saturday"};

    if (argc == 2 && atoi(argv[1]) >= 1 && atoi(argv[1]) <= 7) {
        printf("%s\n", days[atoi(argv[1]) - 1]);
    }
    return 0;
}