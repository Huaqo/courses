//// TODO ////

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int modulo = 0;
    int start = 0;
    long number = 0;

    // Promt for input
    number = get_long("Number: ");

    printf("%li\n", number);

    // Calculate checksum
    //for (int i = length; i < length; i-=2)
    //{
    //    printf("number[i]");
    //}


    // Check for card length and starting digits


    // If invalid Print INVALID\n

    if (modulo != 0)
    {
        printf("INVALID\n");
    }

    // Else
    else
    {
        // Print AMEX\n

        if (start == 34 || start == 37)
        {
            printf("AMEX\n");
        }

        // Print MASTERCARD\n
        else if (start == 51 || start == 52 || start == 53 || start == 54 || start == 55)
        {
            printf("MASTERCARD\n");
        }

        // Print VISA\n
        else if (start == 4)
        {
            printf("VISA\n");
        }
    }
}