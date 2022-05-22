#include <cs50.h>
#include <stdio.h>

int main (void)
{
    long number = get_long("Number: ");
    int count = 1;
    int sum1 = 0;
    int sum2 = 0;
    int sum = 0;
    int digitNumber;
    int digitNumber2;
    int muldigit;
    
    while(number)
    {
        digitNumber2 = digitNumber;
        
        digitNumber = number % 10;
        number /= 10;
        
        if (count % 2 != 0)
        {
            sum1 += digitNumber;
        }
        else
        {
            muldigit = digitNumber * 2;
            
            while (muldigit)
            {
                sum2 += muldigit % 10;
                muldigit /= 10; 
            }
        }
        count += 1;

    }
    sum = sum1 + sum2;
    
    if (sum % 10 != 0)
    {
        printf("INVALID\n");
    }
    else
    {
        if (count == 16 && digitNumber == 3)
        {
            if (digitNumber2 == 4 || digitNumber2 == 7)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (count == 17 && digitNumber == 5)
        {
            if (digitNumber2 > 0 && digitNumber2 < 6)
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if ((count == 17 || count == 14) && digitNumber == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    
}