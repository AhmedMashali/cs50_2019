#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale

void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float average = 0;
    int rounded = 0;

    //traversing through every pixel in the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //calculate the average
            average = image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue;
            average /= 3;
            rounded = (int) round(average);
            //set the new value of channels
            image[i][j].rgbtRed = rounded;
            image[i][j].rgbtGreen = rounded;
            image[i][j].rgbtBlue = rounded;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmp;
    //traversing through every pixel in the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0, l = width - 1; j < (width / 2); j++, l--)
        {
            // exchanging the vlaues of pixels
            tmp = image[i][j];
            image[i][j] = image[i][l];
            image[i][l] = tmp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //new data type to create a copy of the image, why?
    //to get all the average values of the original image before changing any of them
    typedef struct
    {
        int Red;
        int Blue;
        int Green;
    }
    temp;
    temp image2[height][width];

    float r_average = 0;
    float g_average = 0;
    float b_average = 0;

    int c = 0;

    //traversing through every pixel in the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //traversing through the pixel's neighbour edges
            for (int n = i - 1; n < i + 2; n++)
            {
                for (int m = j - 1; m < j + 2; m++)
                {
                    if (n < height && n >= 0 && m < width && m >= 0)
                    {
                        r_average += image[n][m].rgbtRed;
                        g_average += image[n][m].rgbtGreen;
                        b_average += image[n][m].rgbtBlue;
                        c += 1;

                    }
                }
            }

            //calculate the average
            r_average /= c;
            g_average /= c;
            b_average /= c;


            //setting the new values to the copied image
            image2[i][j].Red = (int) round(r_average);
            image2[i][j].Green = (int) round(g_average);
            image2[i][j].Blue = (int) round(b_average);

            r_average = 0;
            g_average = 0;
            b_average = 0;

            c = 0;

        }
    }


    //changing the values of the channels of the original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = image2[i][j].Red;
            image[i][j].rgbtBlue = image2[i][j].Blue;
            image[i][j].rgbtGreen = image2[i][j].Green;
        }
    }


    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    //new data type to create a copy of the image, why?
    //to get all the average values of the original image before changing any of them
    typedef struct
    {
        int rgbtRed;
        int rgbtGreen;
        int rgbtBlue;
    }
    temp;
    temp image2[height][width];

    //convlution matrix Gx
    int Gx[3][3];
    Gx[0][0] = -1;
    Gx[0][1] = 0;
    Gx[0][2] = 1;
    Gx[1][0] = -2;
    Gx[1][1] = 0;
    Gx[1][2] = 2;
    Gx[2][0] = -1;
    Gx[2][1] = 0;
    Gx[2][2] = 1;

    //convlution matrix Gy
    int Gy[3][3];
    Gy[0][0] = -1;
    Gy[0][1] = -2;
    Gy[0][2] = -1;
    Gy[1][0] = 0;
    Gy[1][1] = 0;
    Gy[1][2] = 0;
    Gy[2][0] = 1;
    Gy[2][1] = 2;
    Gy[2][2] = 1;

    int rx = 0;
    int gx = 0;
    int bx = 0;

    int ry = 0;
    int gy = 0;
    int by = 0;

    float new_value = 0;

    //traversing through every pixel in the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //traversing through the pixel's neighbour edges with n and m
            //traversing through the convlution matrices with K abd Q
            for (int n = i - 1, K = 0; n < i + 2; n++, K++)
            {
                for (int m = j - 1, Q = 0; m < j + 2; m++, Q++)
                {
                    if (n < height && n >= 0 && m < width && m >= 0)
                    {
                        //getting Gx and Gy values for every channel
                        rx += image[n][m].rgbtRed * Gx[K][Q];
                        gx += image[n][m].rgbtGreen * Gx[K][Q];
                        bx += image[n][m].rgbtBlue * Gx[K][Q];

                        ry += image[n][m].rgbtRed * Gy[K][Q];
                        gy += image[n][m].rgbtGreen * Gy[K][Q];
                        by += image[n][m].rgbtBlue * Gy[K][Q];

                    }

                }
            }


            //calcualte the new values of the channels and setting these values on the copied image
            new_value = sqrt((rx * rx) + (ry * ry));
            if (new_value > 255)
            {
                new_value = 255;
            }
            image2[i][j].rgbtRed = (int)round(new_value);

            new_value = sqrt((gx * gx) + (gy * gy));
            if (new_value > 255)
            {
                new_value = 255;
            }
            image2[i][j].rgbtGreen = (int)round(new_value);

            new_value = sqrt((bx * bx) + (by * by));
            if (new_value > 255)
            {
                new_value = 255;
            }
            image2[i][j].rgbtBlue = (int)round(new_value);

            rx = 0;
            gx = 0;
            bx = 0;

            ry = 0;
            gy = 0;
            by = 0;

        }
    }

    //changing the values of the original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = image2[i][j].rgbtRed;
            image[i][j].rgbtBlue = image2[i][j].rgbtBlue;
            image[i][j].rgbtGreen = image2[i][j].rgbtGreen;
        }
    }

    return;
}
