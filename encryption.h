#include "encryption.c"


char *caesar_encrypt(char *password, int shift);
/*  


*/

// has a limit to how many characters to shift by

char *caesar_decrypt(char *encrypted_key, int shift);
/*


*/

// has a limit to how many characters to shift by

void hash_encrypt(char *password, int length_of_password, int *empty_hash_array);
/*


*/

// to compare encrypted password to user input, encrypt the user input and compare with the encrpyted password's hash


