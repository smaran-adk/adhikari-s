/**
 * @file cryptoMagic.h
 * @brief Header file for the cryptoMagic encryption/decryption utility
 * @Smaran Adhikari
 * @date April 2025
 */

#ifndef CRYPTOMAGIC_H
#define CRYPTOMAGIC_H

 /**
  * @brief Encrypts a file according to the specified encryption scheme
  * @param inputFile Path to the input file to encrypt
  * @param outputFile Path to the output file where encrypted content will be written
  * @return int Returns 0 on success, non-zero on failure
  */
int encryptFile(const char* inputFile, const char* outputFile);

/**
 * @brief Decrypts a file according to the specified decryption scheme
 * @param inputFile Path to the input file to decrypt
 * @param outputFile Path to the output file where decrypted content will be written
 * @return int Returns 0 on success, non-zero on failure
 */
int decryptFile(const char* inputFile, const char* outputFile);

#endif /* CRYPTOMAGIC_H */
