/**
 * @file cryptoMagic.c
 * @brief Main implementation of the cryptoMagic encryption/decryption utility
 * @author Smaran Adhikari
 * @date April 2025
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cryptoMagic.h"
#include "file_utils.h"

#define MAX_FILENAME 256

int main(int argc, char* argv[]) {
    if (argc != 2 && argc != 3) {
        fprintf(stderr, "Usage: %s [-encrypt|-decrypt] <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char* inputFile;
    char* outputFile;
    int encrypt = 1;  // Default to encrypt mode

    if (argc == 3) {
        // Two arguments provided: mode and filename
        if (strcmp(argv[1], "-encrypt") == 0) {
            encrypt = 1;
        }
        else if (strcmp(argv[1], "-decrypt") == 0) {
            encrypt = 0;
        }
        else {
            fprintf(stderr, "Error: Invalid option '%s'\nUse -encrypt or -decrypt.\n", argv[1]);
            return EXIT_FAILURE;
        }
        inputFile = argv[2];
    }
}
 else {
     // One argument provided: filename (default to encrypt)
     inputFile = argv[1];
    }

    if (strlen(inputFile) == 0 || strlen(inputFile) >= MAX_FILENAME - 5) {
        fprintf(stderr, "Error: Invalid or too long filename.\n");
        return EXIT_FAILURE;
    }

    outputFile = get_output_filename(inputFile, encrypt);
    if (!outputFile) {
        return EXIT_FAILURE;
    }

    int result;
    if (encrypt) {
        result = encryptFile(inputFile, outputFile);
    }
    else {
        result = decryptFile(inputFile, outputFile);
    }

    free(outputFile);
    return result == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}