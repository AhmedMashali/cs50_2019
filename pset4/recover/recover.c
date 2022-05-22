#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int main(int argc, char *argv[])
{
    //check if the arguments are entered correctly
    if (argc != 2)
    {
        return 1;
    }

    //openning the memory card
    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        return 1;
    }
    
    //buffer for every 512 bytes
    unsigned char bytes[512];
    int c = 0;
    bool open = false;

    FILE *pptr;


    while (fread(bytes, 512, 1, file) == 1)
    {
        //check for the beginning of JPEG 
        if (bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff && (bytes[3] & 0xf0) == 0xe0)
        {
            //for the first JPEG
            if (open == false)
            {
                char filename[8];
                sprintf(filename, "%03i.jpg", c);
                c += 1;
                FILE *ptr = fopen(filename, "a");
                pptr = ptr;
                open = true;
                fwrite(bytes, 512, 1, pptr);
            }
            //when there is a JPEG file is opened
            else
            {
                fclose(pptr);
                char filename[8];
                sprintf(filename, "%03i.jpg", c);
                c += 1;
                FILE *ptr = fopen(filename, "a");
                pptr = ptr;
                open = true;
                fwrite(bytes, 512, 1, pptr);
            }

        }
        // keep writing in the JPEG file if there is no JPEG header
        else
        {
            if (open == true)
            {
                fwrite(bytes, 512, 1, pptr);
            }
        }
        //printf("8\n");
    }

    fclose(file);
    return 0;
}