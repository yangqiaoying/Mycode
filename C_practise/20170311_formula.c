#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>
#include <math.h>

int main(int argc, char const* argv[])
{
    float a, b, c, d, x1, x2, r, p;
    printf("Please input a, b, c:\n");
    scanf("%f%f%f", &a, &b, &c);

    d = b * b - 4 * a * c;

    if (d > 0) {
        x1 = (-b + sqrt(d)) / (2 * a);
        x2 = (-b - sqrt(d)) / (2 * a);
        printf("The equation contains two roots: x1 = %.2f, x2 = %.2f\n", x1, x2);
    } else if (d == 0) {
        x1 = x2 = (-b) / (2 * a);
        printf("The equation contains one root: x1 = x2 = %.2f\n", x1);
    } else {
        r = (-b) / (2 * a);
        p = sqrt(fabs(d)) / (2 * a);
        printf("The equations with two complex roots: x1=%.2f+%.2fi\tx2=%.2f-%.2fi\n", r, p, r, p);
    }
    return 0;
}
