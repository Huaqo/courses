#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
// The function grayscale takes three arguments: height and width, which are integers representing the dimensions of an image, and image, which is a two-dimensional array of type RGBTRIPLE representing the pixels of the image. The function converts the image to grayscale by setting the red, green, and blue components of each pixel to the mean of the original values. The result is stored back in the image array. The function uses nested loops to iterate over all pixels in the image. For each pixel, it calculates the mean of its red, green, and blue components using the formula (red + green + blue) / 3, and rounds the result to the nearest integer using the round function. Then it sets the red, green, and blue components of the pixel to the calculated mean. Finally, the function returns void, indicating that it does not return any value.
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int mean = (int) round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = mean;
            image[i][j].rgbtGreen = mean;
            image[i][j].rgbtBlue = mean;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepiaRed = (int) round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue) ;
            int sepiaGreen = (int) round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int sepiaBlue = (int) round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE og = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = og;
        }
    }
    return;
}



// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE og[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            og[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // inbetween
            if (i >= 1 && i < height - 1 && j >= 1 && j < width - 1)
            {
                image[i][j].rgbtRed = (int) round((og[i][j].rgbtRed +
                                                   og[i - 1][j - 1].rgbtRed +
                                                   og[i - 1][j].rgbtRed +
                                                   og[i - 1][j + 1].rgbtRed +
                                                   og[i][j - 1].rgbtRed +
                                                   og[i][j + 1].rgbtRed +
                                                   og[i + 1][j - 1].rgbtRed +
                                                   og[i + 1][j].rgbtRed +
                                                   og[i + 1][j + 1].rgbtRed) / 9.0);
                image[i][j].rgbtGreen = (int) round((og[i][j].rgbtGreen +
                                                     og[i - 1][j - 1].rgbtGreen +
                                                     og[i - 1][j].rgbtGreen +
                                                     og[i - 1][j + 1].rgbtGreen +
                                                     og[i][j - 1].rgbtGreen +
                                                     og[i][j + 1].rgbtGreen +
                                                     og[i + 1][j - 1].rgbtGreen +
                                                     og[i + 1][j].rgbtGreen +
                                                     og[i + 1][j + 1].rgbtGreen) / 9.0);
                image[i][j].rgbtBlue = (int) round((og[i][j].rgbtBlue +
                                                    og[i - 1][j - 1].rgbtBlue +
                                                    og[i - 1][j].rgbtBlue +
                                                    og[i - 1][j + 1].rgbtBlue +
                                                    og[i][j - 1].rgbtBlue +
                                                    og[i][j + 1].rgbtBlue +
                                                    og[i + 1][j - 1].rgbtBlue +
                                                    og[i + 1][j].rgbtBlue +
                                                    og[i + 1][j + 1].rgbtBlue) / 9.0);
            }

            // Corners
            // upper left corner
            if (i == 0 && j == 0)
            {
                image[i][j].rgbtRed = (int) round((og[i][j].rgbtRed +
                                                   og[i][j + 1].rgbtRed +
                                                   og[i + 1][j].rgbtRed +
                                                   og[i + 1][j + 1].rgbtRed) / 4.0);
                image[i][j].rgbtGreen = (int) round((og[i][j].rgbtGreen +
                                                     og[i][j + 1].rgbtGreen +
                                                     og[i + 1][j].rgbtGreen +
                                                     og[i + 1][j + 1].rgbtGreen) / 4.0);
                image[i][j].rgbtBlue = (int) round((og[i][j].rgbtBlue +
                                                    og[i][j + 1].rgbtBlue +
                                                    og[i + 1][j].rgbtBlue +
                                                    og[i + 1][j + 1].rgbtBlue) / 4.0);
            }
            // upper right corner
            if (i == 0 && j == width - 1)
            {
                image[i][j].rgbtRed = (int) round((og[i][j].rgbtRed +
                                                   og[i][j - 1].rgbtRed +
                                                   og[i + 1][j - 1].rgbtRed +
                                                   og[i + 1][j].rgbtRed) / 4.0);
                image[i][j].rgbtGreen = (int) round((og[i][j].rgbtGreen +
                                                     og[i][j - 1].rgbtGreen +
                                                     og[i + 1][j - 1].rgbtGreen +
                                                     og[i + 1][j].rgbtGreen) / 4.0);
                image[i][j].rgbtBlue = (int) round((og[i][j].rgbtBlue +
                                                    og[i][j - 1].rgbtBlue +
                                                    og[i + 1][j - 1].rgbtBlue +
                                                    og[i + 1][j].rgbtBlue) / 4.0);
            }

            // lower left corner
            if (i == height - 1 && j == 0)
            {
                image[i][j].rgbtRed = (int) round((og[i][j].rgbtRed +
                                                   og[i - 1][j].rgbtRed +
                                                   og[i - 1][j + 1].rgbtRed +
                                                   og[i][j + 1].rgbtRed) / 4.0);
                image[i][j].rgbtGreen = (int) round((og[i][j].rgbtGreen +
                                                     og[i - 1][j].rgbtGreen +
                                                     og[i - 1][j + 1].rgbtGreen +
                                                     og[i][j + 1].rgbtGreen) / 4.0);
                image[i][j].rgbtBlue = (int) round((og[i][j].rgbtBlue +
                                                    og[i - 1][j].rgbtBlue +
                                                    og[i - 1][j + 1].rgbtBlue +
                                                    og[i][j + 1].rgbtBlue) / 4.0);
            }

            // lower right corner
            if (i == height - 1 && j == width - 1)
            {
                image[i][j].rgbtRed = (int) round((og[i][j].rgbtRed +
                                                   og[i - 1][j - 1].rgbtRed +
                                                   og[i - 1][j].rgbtRed +
                                                   og[i][j - 1].rgbtRed) / 4.0);
                image[i][j].rgbtGreen = (int) round((og[i][j].rgbtGreen +
                                                     og[i - 1][j - 1].rgbtGreen +
                                                     og[i - 1][j].rgbtGreen +
                                                     og[i][j - 1].rgbtGreen) / 4.0);
                image[i][j].rgbtBlue = (int) round((og[i][j].rgbtBlue +
                                                    og[i - 1][j - 1].rgbtBlue +
                                                    og[i - 1][j].rgbtBlue +
                                                    og[i][j - 1].rgbtBlue) / 4.0);
            }

            // Sides
            // Upper side
            if (i == 0 && j > 0 && j < width - 1)
            {
                image[i][j].rgbtRed = (int) round((og[i][j].rgbtRed +
                                                   og[i][j - 1].rgbtRed +
                                                   og[i][j + 1].rgbtRed +
                                                   og[i + 1][j - 1].rgbtRed +
                                                   og[i + 1][j].rgbtRed +
                                                   og[i + 1][j + 1].rgbtRed) / 6.0);
                image[i][j].rgbtGreen = (int) round((og[i][j].rgbtGreen +
                                                     og[i][j - 1].rgbtGreen +
                                                     og[i][j + 1].rgbtGreen +
                                                     og[i + 1][j - 1].rgbtGreen +
                                                     og[i + 1][j].rgbtGreen +
                                                     og[i + 1][j + 1].rgbtGreen) / 6.0);
                image[i][j].rgbtBlue = (int) round((og[i][j].rgbtBlue +
                                                    og[i][j - 1].rgbtBlue +
                                                    og[i][j + 1].rgbtBlue +
                                                    og[i + 1][j - 1].rgbtBlue +
                                                    og[i + 1][j].rgbtBlue +
                                                    og[i + 1][j + 1].rgbtBlue) / 6.0);
            }

            // lower side
            if (i == height - 1 && j > 0 && j < width - 1)
            {
                image[i][j].rgbtRed = (int)round((og[i][j].rgbtRed +
                                                  og[i - 1][j - 1].rgbtRed +
                                                  og[i - 1][j].rgbtRed +
                                                  og[i - 1][j + 1].rgbtRed +
                                                  og[i][j - 1].rgbtRed +
                                                  og[i][j + 1].rgbtRed) / 6.0);
                image[i][j].rgbtGreen = (int)round((og[i][j].rgbtGreen +
                                                    og[i - 1][j - 1].rgbtGreen +
                                                    og[i - 1][j].rgbtGreen +
                                                    og[i - 1][j + 1].rgbtGreen +
                                                    og[i][j - 1].rgbtGreen +
                                                    og[i][j + 1].rgbtGreen) / 6.0);
                image[i][j].rgbtBlue = (int) round((og[i][j].rgbtBlue +
                                                    og[i - 1][j - 1].rgbtBlue +
                                                    og[i - 1][j].rgbtBlue +
                                                    og[i - 1][j + 1].rgbtBlue +
                                                    og[i][j - 1].rgbtBlue +
                                                    og[i][j + 1].rgbtBlue) / 6.0);
            }

            // left side
            if (i > 0 && i < height - 1  && j == 0)
            {
                image[i][j].rgbtRed = (int) round((og[i][j].rgbtRed +
                                                   og[i - 1][j].rgbtRed +
                                                   og[i - 1][j + 1].rgbtRed +
                                                   og[i][j + 1].rgbtRed +
                                                   og[i + 1][j].rgbtRed +
                                                   og[i + 1][j + 1].rgbtRed) / 6.0);
                image[i][j].rgbtGreen = (int) round((og[i][j].rgbtGreen +
                                                     og[i - 1][j].rgbtGreen +
                                                     og[i - 1][j + 1].rgbtGreen +
                                                     og[i][j + 1].rgbtGreen +
                                                     og[i + 1][j].rgbtGreen +
                                                     og[i + 1][j + 1].rgbtGreen) / 6.0);
                image[i][j].rgbtBlue = (int) round((og[i][j].rgbtBlue +
                                                    og[i - 1][j].rgbtBlue +
                                                    og[i - 1][j + 1].rgbtBlue +
                                                    og[i][j + 1].rgbtBlue +
                                                    og[i + 1][j].rgbtBlue +
                                                    og[i + 1][j + 1].rgbtBlue) / 6.0);
            }

            // right side
            if (i > 0 && i < height - 1 && j == width - 1)
            {
                image[i][j].rgbtRed = (int) round((og[i][j].rgbtRed +
                                                   og[i - 1][j - 1].rgbtRed +
                                                   og[i - 1][j].rgbtRed +
                                                   og[i][j - 1].rgbtRed +
                                                   og[i + 1][j - 1].rgbtRed +
                                                   og[i + 1][j].rgbtRed) / 6.0);
                image[i][j].rgbtGreen = (int) round((og[i][j].rgbtGreen +
                                                     og[i - 1][j - 1].rgbtGreen +
                                                     og[i - 1][j].rgbtGreen + og[i][j - 1].rgbtGreen +
                                                     og[i + 1][j - 1].rgbtGreen + og[i + 1][j].rgbtGreen) / 6.0);
                image[i][j].rgbtBlue = (int) round((og[i][j].rgbtBlue +
                                                    og[i - 1][j - 1].rgbtBlue +
                                                    og[i - 1][j].rgbtBlue +
                                                    og[i][j - 1].rgbtBlue +
                                                    og[i + 1][j - 1].rgbtBlue +
                                                    og[i + 1][j].rgbtBlue) / 6.0);
            }
        }
    }
    return;
}

//00 = [i - 1][j - 1]
//01 = [i - 1][j]
//02 = [i - 1][j + 1]
//10 = [i][j - 1]
//12 = [i][j + 1]
//20 = [i + 1][j - 1]
//21 = [i + 1][j]
//22 = [i + 1][j + 1]

// Dazwischen
//00 = [i - 1][j - 1]
//01 = [i - 1][j]
//02 = [i - 1][j + 1]
//10 = [i][j - 1]
//12 = [i][j + 1]
//20 = [i + 1][j - 1]
//21 = [i + 1][j]
//22 = [i + 1][j + 1]

//Ecke Links oben
//12 [i][j + 1]
//21 [i + 1][j]
//22 [i + 1][j + 1]

//Ecke Rechts oben
//10 [i][j - 1]
//20 [i + 1][j - 1]
//21 [i + 1][j]

//Ecke Links unten
//01 [i - 1][j]
//02 [i - 1][j + 1]
//12 [i][j + 1]

//Ecke Rechts unten
//00 [i - 1][j - 1]
//01 [i - 1][j]
//10 [i][j - 1]

// Seite oben
//10 [i][j - 1]
//12 [i][j + 1]
//20 [i + 1][j - 1]
//21 [i + 1][j]
//22 [i + 1][j + 1]

// Seite unten
//00 [i - 1][j - 1]
//01 [i - 1][j]
//02 [i - 1][j + 1]
//10 [i][j - 1]
//12 [i][j + 1]

// Seite links
//01 [i - 1][j]
//02 [i - 1][j + 1]
//12 [i][j + 1]
//21 [i + 1][j]
//22 [i + 1][j + 1]

// Seite rechts
//00 [i - 1][j - 1]
//01 [i - 1][j]
//10 [i][j - 1]
//20 [i + 1][j - 1]
//21 [i + 1][j]