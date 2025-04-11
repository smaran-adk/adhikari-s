/**
 * @file file_utils.h
 * @brief Header file for file utility functions used in the cryptoMagic utility
 * @author Smaran Adhikari
 * @date April 2025
 */

#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <stdbool.h>

 /**
  * @brief Generates the output filename based on the input filename and operation type
  * @param input_filename The input filename to process
  * @param is_encrypt True if encrypting (output will have .crp extension), false if decrypting (output will have .txt extension)
  * @return char* A newly allocated string containing the output filename, or NULL on error
  * @note The caller is responsible for freeing the returned string
  */
char* get_output_filename(const char* input_filename, bool is_encrypt);

#endif /* FILE_UTILS_H */ 