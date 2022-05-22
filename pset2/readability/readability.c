#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    string x = get_string("Text: ");
    float letters = 0;
    float sentences = 0;
    float words = 1;
    float L;
    float S;
    double index;

    for (int i = 0, n = strlen(x); i < n; i++)
    {
        if (isspace(x[i]))
        {
            // getting the number of words
            words += 1;
        }
        else if (x[i] == '!' || x[i] == '?' || x[i] == '.')
        {
            // getting the number of sentences
            sentences += 1;
        }
        else if (isalpha(x[i]) || isalnum(x[i]))
        {
            // getting the number of words
            letters += 1;
        }
    }

    printf("letters: %f\n", letters);
    printf("words: %f\n", words);
    printf("sentences: %f\n", sentences);


    L = (letters * 100) / words;
    S = (sentences * 100) / words;

    // calculating the grade
    index = 0.0588 * L - 0.296 * S - 15.8;

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", (int) round(index));
    }
}