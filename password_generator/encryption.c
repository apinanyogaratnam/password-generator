#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "encryption.h"

#define DELIMITER '\0'

void *caesar_encrypt(char *password, int shift) {
    // loop through password until DELIMITER appears
    for (int i=0; *(password+i) != DELIMITER; i++) {
        *(password+i) = *(password+i) + shift;
    }
    return password;
}

void *caesar_decrypt(char *encrypted_key, int shift) {
    // loop through encrypted_key until DELIMITER appears
    for (int i=0; *(encrypted_key+i) != DELIMITER; i++) {
        *(encrypted_key+i) = *(encrypted_key+i) - shift;
    }
    return encrypted_key;
}

void hash_encrypt(char *password, int length_of_password, int *empty_hash_array) {
    // loop through password until DELIMITER appears
    for (int i=0; i<length_of_password; i++) {
        empty_hash_array[i] = password[i] ^ (password[length_of_password-1 - i] * 29);
    }
}

//int main() {
    // caesar_encrypt
    // char name[1024] = "hello world123456789";
    // printf("%s\n", caesar_encrypt(name, 3));
    // return 0;

    // int num = 2;
    // num = num << 1;
    // printf("num: %d\n", num);

    // hash_encrypt
    // int hash_array[6];
    // char *password = "hacked";
    // hash_encrypt(password, 6, hash_array);
    // for (int i=0; i<6; i++) {
    //     printf("hash for %c is: %d\n", *(password+i), hash_array[i]);
    // }
//}

// notes: 
    //using permutation with repitition we can calculate strength of password (how many tries it takes to brute force) formula: n^r   n = number of different possible characters, r = length of password