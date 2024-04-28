#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

const int BITS_IN_BYTE = 8;

int main(void)
{
    string text = get_string("Text: ");

    // Loop over every character

    int i = 0;
    int l = 0;
    double rest = 0;
    double zahl;
    int len = 0;
    int bi;
    int n = 0;
    int m = 0;

    for (i = 0, len = strlen(text); i < len; i++)
    {
        zahl = text[i];
        bi = 0;
        for (l = 0; l < BITS_IN_BYTE; l++)
        {
            zahl = (zahl - (rest * pow(10, -1))) / 2.0 ;
            rest = (zahl - floor(zahl)) * 10;

            if (rest > 0)
            {
                bi = bi + pow(10, l);
            }
            else
            {
                continue;
            }
        }

        if (bi >= 1000000 && bi <= 1111111)
        {
            char test[bi];
            sprintf(test, "0%d", bi);
            //printf("%s",test);
            for (n = 0, m = strlen(test); n < m; n++)
            {
                if (test[n] == 48)
                {
                    // Dark emoji
                    printf("\U000026AB");
                }
                else if (test[n] == 49)
                {
                    // Light emoji
                    printf("\U0001F7E1");
                }
            }
        }
        else if (bi >= 100000 && bi <= 111111)
        {
            char test[bi];
            sprintf(test, "00%d", bi);
            //printf("%s",test);
            for (n = 0, m = strlen(test); n < m; n++)
            {
                if (test[n] == 48)
                {
                    // Dark emoji
                    printf("\U000026AB");
                }
                else if (test[n] == 49)
                {
                    // Light emoji
                    printf("\U0001F7E1");
                }
            }
        }
        printf("\n");
    }
}