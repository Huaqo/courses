#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int size;
    int spaces;
    int hashes;

    // Asking for size
    do
    {
        size = get_int("Size: ");
    }
    while (size < 1 || size > 8);

    // Building
    for (int i = 0; i < size; i++)
    {

        // left spaces
        for (spaces = (size - i); spaces >= 2; spaces--)
        {
            printf(" ");
        }

        // hashes
        for (hashes = 0; hashes <= i; hashes++)
        {
            printf("#");
        }

        // middle spaces
        printf("  ");

        // hashes
        for (hashes = 0; hashes <= i; hashes++)
        {
            printf("#");
        }

        // next line
        printf("\n");

    }
}