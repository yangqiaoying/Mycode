#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define MAX_SIZE 101
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))
void sort(int[], int);   //seclect function

int main(int argc, char const* argv[])
{
    int i, j, num;
    int list[MAX_SIZE];

    srand((unsigned int)time(NULL));    //Generate random seed based on current system time
    printf("Please Enter the number of numbers to generate: ");
    scanf("%d", &num);
    if (num < 1 || num > MAX_SIZE) {
        fprintf(stderr, "Input out of range!");
        exit(1);
    }
    for (i = 0; i < num; i++) {
         list[i] = rand() % 1000;
         printf("%d ", list[i]);
    }
    printf("\n");
    sort(list, num);
    printf("Sorted array:\n");
    for (i = 0; i < num; i++)
        printf("%d ", list[i]);
    printf("\n");
    return 0;
}

void sort(int list[], int num)
{
     int i, j, min, temp;
     for (i = 0; i < num - 1; i++) {
         for (j = i + 1; j < num; j++) {
             if (list[i] > list[j])
                 SWAP(list[i], list[j], temp);
         }
     }
}
