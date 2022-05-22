#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    bool check = true;
    char key[26];
    //checking the number of arguments
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        check = false;
        return 1;
    }
    //checking the number key
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        check = false;
        return 1;
    }
    else
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            //creating key's array
            key[i] = toupper(argv[1][i]);
            
            //checking wheather all char in key is alphabetic or not
            if (isalpha(argv[1][i]) == false)
            {
                printf("Key must only contain alphabetic characters.\n");
                check = false;
                return 1;
            }
            //checking repeated chars in key
            for (int j = 0; j < i; j++)
            {
                if (argv[1][i] == key[j])
                {
                    printf("Key must not contain repeated characters.\n");
                    check = false;
                    return 1;
                }
            }
        }
    }
    if (check)
    {
        string x = get_string("plaintext:  ");
        
        string normal = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        
        for (int i = 0, m = strlen(x); i < m; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                if (x[i] == normal[j] || x[i] == tolower(normal[j]))
                {
                    if (islower(x[i]))
                    {
                        x[i] = key[j];
                        x[i] = tolower(x[i]);
                        break;
                    }
                    else
                    {
                        x[i] = key[j];
                        break;
                    }
                
                }
            }
        }
        printf("ciphertext: %s\n", x);
    }
    
}