#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{

    int BLOCK_SIZE = 512;
    typedef uint8_t BYTE;
    BYTE buffer[BLOCK_SIZE];

    FILE *file = fopen("card.raw", "r");

    if (argc != 2)
    {
        printf("Usage: ./recover card.raw\n");
        return 1;
    }

    while (fread(&buffer, 1, BLOCK_SIZE, file) == BLOCK_SIZE)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] ==  0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            printf("%i",buffer)
        }
    }

    fclose(file);
    return 0;
}