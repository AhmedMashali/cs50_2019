#include <stdio.h>
#include <cs50.h>
#include <math.h>

int square(int n);

int main(void)
{
    int input = get_int("Input: ");
    printf("output: %i\n", square(input));
}
int square(int n)
{
    return n * n;
}