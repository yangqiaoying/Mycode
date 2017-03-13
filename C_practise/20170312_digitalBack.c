#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>

int main(int argc, char const* argv[])
{
    int number, digit;
    printf("please input a number: \n");
    scanf("%d", &number);
    printf("The number of input in reverse order is: \n");
    while (number != 0){
        digit = number % 10;
        printf("%d", digit);
        number = number / 10;
    }
    printf("\n");
    return 0;
}
