 #include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    // Get Text
    string text = get_string("Text: ");

    // Letter, word, sentence count
    double lettercount = 0;
    double wordcount = 1;
    double sentencecount = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if ((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122))
        {
            lettercount += 1;
        }
        else if (text[i] == 32)
        {
            wordcount += 1;
        }
        else if (text[i] == 33 || text[i] == 63 || text[i] == 46)
        {
            sentencecount += 1;
        }
        else
        {
            continue;
        }
    }

    // Calculate Index
    double L = lettercount / wordcount * 100.0;
    double S = sentencecount / wordcount * 100.0;
    double index = 0.0588 * L - 0.296 * S - 15.8;

    // Print conditions
    if (index <= 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int) round(index));
    }
}