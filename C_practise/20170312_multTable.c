#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>

int main(int argc, char const* argv[])
{
    int i, j;
    for (i = 1; i <= 9; i++) {
        for (j = 1; j <= i; j++){
            printf("%d * %d = %d", j, i, i*j);
        }
        printf("\n\n");
    }
    return 0;
}
