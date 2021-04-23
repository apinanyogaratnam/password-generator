
void *caesar_encrypt(char *password, int shift);
/*  
Given password, modify password by a value of shift using ascii table. To use comparing input 
encrypted password and current encrpyted password, create a temp char *.

// has a limit to how many characters to shift by
*/

char *caesar_decrypt(char *encrypted_key, int shift);
/*
Given password, modify password by a value of shift using ascii table. To use comparing input 
encrypted password and current encrpyted password, create a temp char *.

// has a limit to how many characters to shift by
*/

void hash_encrypt(char *password, int length_of_password, int *empty_hash_array);
/*
Given password, modify password and modify empty_hash_array with given password's encrypted hash.

// to compare encrypted password to user input, encrypt the user input and compare with 
// the encrpyted password's hash
*/
