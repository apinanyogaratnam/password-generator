#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
//#include <random> // learn how to use

#define DELIMITER '\0'
#define WHITE_SPACE ' '
#define NUMBER_OF_CONDITIONS 4



int factorial(int number) {
    if (number == 0 || number == 1) return 1;
    return number * factorial(number-1);
}

void *get_lowercase_letters(); // modifies a string of lowercase letters randomized to use

void *get_uppercase_letters(); // modifies a string of uppercase letters randomized to use

void *get_special_characters(); // modifies a string of special letters randomized to use

void *get_numbers(); // modifies a string of letters of special letters randomized to use

void *add_spaces(char *password, int length_of_password, int number_of_spaces); // modifies string with number of spaces given

char *suggest_password(int length_of_password, bool contains_lowercase, bool contains_uppercase, \
                       bool contains_special_characters, bool contains_numbers, bool contains_spaces, char *password);
/*

*/

// given conditions:
    // contains uppercase
    // contains lowercase
    // contains numbers
    // contains special characters
    // contains spaces

char *suggest_password(int length_of_password, bool contains_lowercase, bool contains_uppercase, bool contains_special_characters, bool contains_numbers, bool contains_spaces, char *password) {
    //33-126 are possible symbols
    // as we check the conditions in the parameters, remove the numbers allowed
    // need to make a randomizer or import a randomizer library
    // loop through length_of_password
    // modify up current position of char array
    // as of right now passing in char array but need to change to allocate memory for char and free pointer after in another function
    char *suggesting_password = (char *)calloc(length_of_password, sizeof(char));


    

}

// use ascii