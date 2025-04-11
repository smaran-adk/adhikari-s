/**
 * @file file_utils.c
 * @brief Implementation of file utility functions for the cryptoMagic utility
 * @author Smaran Adhikari
 * @date April 2025
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_utils.h"

#define MAX_FILENAME 256

 /**
  * @brief Generates the output filename based on the input filename and operation type
  * @param input_filename The input filename to process
  * @param is_encrypt True if encrypting (output will have .crp extension), false if decrypting (output will have .txt extension)
  * @return char* A newly allocated string containing the output filename, or NULL on error
  * @note The caller is responsible for freeing the returned string
  */
char* get_output_filename(const char* input_filename, bool is_encrypt) {
    if (!input_filename || strlen(input_filename) == 0 || strlen(input_filename) >= MAX_FILENAME) {
        fprintf(stderr, "Error: Invalid input filename\n");
        return NULL;
    }

    char* output_filename;
    const char* extension = is_encrypt ? ".crp" : ".txt";
    size_t len = strlen(input_filename) + strlen(extension) + 1;

    output_filename = (char*)malloc(len);
    if (!output_filename) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        return NULL;
    }

    // Find the last dot in the filename
    const char* last_dot = strrchr(input_filename, '.');

    if (last_dot) {
        // If there's an extension, replace it
        size_t base_len = last_dot - input_filename;
        strncpy(output_filename, input_filename, base_len);
        output_filename[base_len] = '\0';
    }
    else {
        // If no extension, just copy the filename
        strcpy(output_filename, input_filename);
    }

    // Append the new extension
    strcat(output_filename, extension);

    return output_filename;
}