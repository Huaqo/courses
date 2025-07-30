#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    FILE *img = NULL;
    BYTE buffer[512];
    int img_number = 0;
    char img_name[8];

    while (fread(&buffer, 512, 1, file) == 1)
    {
        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] ==  0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {

            if (!(img_number == 0))
            {
                fclose(img);
            }

            sprintf(img_name, "%03i.jpg", img_number);
            img = fopen(img_name, "w");
            img_number ++;

        }

        if (!(img_number == 0))
        {
            fwrite(&buffer, 512, 1, img);
        }

    }

    fclose(file);
    fclose(img);
    return 0;

}