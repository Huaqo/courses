// ~ $ gcc main.c -o crc       
// ./crc 011100111110 11011

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the degree (highest exponent) of the generator polynomial
int calculate_degree(const char *bitstream, int len) {
    for (int i = 0; i < len; i++) {
        if (bitstream[i] == '1') {
            return len - i - 1;
        }
    }
    return -1;
}

// Function to append zeros to the bitstream
char* appendZerosToBitstream(const char *bitstream, int amount) {
    int originalLen = strlen(bitstream);
    char *newBitstream = (char *)malloc(originalLen + amount + 1);
    if (newBitstream == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    
    strcpy(newBitstream, bitstream);
    memset(newBitstream + originalLen, '0', amount);
    newBitstream[originalLen + amount] = '\0';
    
    return newBitstream;
}

// Function to perform bitwise XOR division
char* perform_xor_division(const char *bitstream, const char *generator) {
    int bitstreamLen = strlen(bitstream);
    int generatorLen = strlen(generator);

    // Copy the bitstream into a mutable buffer
    char *remainder = (char *)malloc(bitstreamLen + 1);
    if (remainder == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    strcpy(remainder, bitstream);

    for (int i = 0; i <= bitstreamLen - generatorLen; i++) {
        if (remainder[i] == '1') {  // Perform XOR only when leading bit is 1
            for (int j = 0; j < generatorLen; j++) {
                remainder[i + j] = (remainder[i + j] == generator[j]) ? '0' : '1';
            }
        }
    }

    // Extract the remainder from the last (generatorLen - 1) bits
    char *crc = (char *)malloc(generatorLen);
    if (crc == NULL) {
        printf("Memory allocation failed!\n");
        free(remainder);
        return NULL;
    }
    strcpy(crc, remainder + bitstreamLen - generatorLen + 1);
    free(remainder);

    return crc;
}

int main(int argc, char *argv[]) {
    if (argc == 3) {
        char *bitstream = argv[1];
        printf("Bitstream: %s\n", bitstream);
        char *generatorpolynom = argv[2];

        // Calculate how many zeros need to be appended
        int zerosToAppend = calculate_degree(generatorpolynom, strlen(generatorpolynom));
        if (zerosToAppend < 0) {
            printf("Invalid generator polynomial.\n");
            return 1;
        }

        // Append zeros to the bitstream
        char *zerodBitstream = appendZerosToBitstream(bitstream, zerosToAppend);
        if (zerodBitstream == NULL) {
            return 1;
        }

        printf("Modified bitstream (with zeros): %s\n", zerodBitstream);

        // Perform bitwise division
        char *crc = perform_xor_division(zerodBitstream, generatorpolynom);
        if (crc == NULL) {
            free(zerodBitstream);
            return 1;
        }

        printf("CRC remainder: %s\n", crc);
        printf("HDLC Header: %s\n",strcat(bitstream,crc));

        free(zerodBitstream);
        free(crc);

        return 0;
    } else {
        printf("Usage: %s <bitstream> <generator polynomial>\n", argv[0]);
        return 1;
    }
}
