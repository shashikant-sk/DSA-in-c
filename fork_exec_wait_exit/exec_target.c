#include<stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    for (int i = 0; i < argc; ++i) {
        printf("%s\n", argv[i]);
    }

    if (argc % 2 == 0)
        exit(0);
    else
        exit(1);
}