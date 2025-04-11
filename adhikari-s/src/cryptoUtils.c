/**
 * @file cryptoUtils.c
 * @brief Implementation of encryption and decryption functions for the cryptoMagic utility
 * @author Smaran Adhikari
 * @date April 2025
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cryptoMagic.h"

#define MAX_LINE 120
#define MAX_ENCRYPTED_LINE 255
 /**
  * @brief Encrypts a file according to the specified encryption scheme
  * @param inputFile Path to the input file to encrypt
  * @param outputFile Path to the output file where encrypted content will be written
  * @return int Returns 0 on success, non-zero on failure
  */
int encryptFile(const char* inputFile, const char* outputFile) {
    FILE* input = fopen(inputFile, "r");
    if (!input) {
        fprintf(stderr, "Error: Cannot open source file '%s' for reading\n", inputFile);
        return 1;
    }

    FILE* output = fopen(outputFile, "w");
    if (!output) {
        fprintf(stderr, "Error: Cannot create output file '%s' for writing\n", outputFile);
        fclose(input);
        return 1;
    }

    char line[MAX_LINE + 1];
    while (fgets(line, sizeof(line), input)) {
        for (int i = 0; line[i] != '\0'; i++) {
            if (line[i] == '\t') {
                fputs("TT", output);  // Encode tabs
            }
            else if (line[i] == '\n') {
                fputc('\n', output);  // Preserve newlines
            }
            else {
                int transformedChar = line[i] - 16;
                if (transformedChar < 32) {
                    transformedChar = (transformedChar - 32) + 144;
                }
                fprintf(output, "%02X", transformedChar);
            }
        }
    }

    fclose(input);
    fclose(output);
    return 0;
}