#include <stdio.h>
#include <cs50.h>

void spaces(int s);

void hashes(int i);

int main(void)
{
    int h;
    
    do
    {
        h = get_int("Height: ");
    }
    while (h < 1 || h > 8);
    
    for (int i = 0; i < h; i++)
    {
        spaces(h - 1 - i);
        hashes(i);
        printf("  ");
        hashes(i);
        printf("\n");
    }
    
}

//spaces before first hashes
void spaces(int s)
{
    for (int j = s; j > 0 ; j--)
    {
        printf(" ");
    }
}

//making hashes
void hashes(int i)
{
    for (int j = 0; j <= i; j++)
    {
        printf("#");
    }
}
