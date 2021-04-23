#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define DELIMITER '\0'
#define WHITE_SPACE ' '
#define NUMBER_OF_CONDITIONS 4

void shuffle_password(); // shuffles password to randomize order of different types of conditions
void exists(char *password); // checks if password exists already
void add_spaces(char *password, int length_of_password, int number_of_spaces); // modifies string with number of spaces given
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

int factorial(int number) {
    if (number == 0 || number == 1) return 1;
    return number * factorial(number-1);
}

void delete_password_pointer(char *pointer_to_password) {
    free(pointer_to_password);
}

void get_lowercase_letters(char *string, int *index_usable, int number_of_randoms) {
    for (int i=*(index_usable); i<number_of_randoms+(*index_usable); i++) {
        int random_number = rand()%26; // 0-25
        string[i] = random_number+97; // ascii table adding (97-122)
    }
    *index_usable += number_of_randoms;
    string[*index_usable] = DELIMITER;
}

void get_uppercase_letters(char *string, int *index_usable, int number_of_randoms) {
    for (int i=*(index_usable); i<number_of_randoms+(*index_usable); i++) {
        int random_number = rand()%26; // 0-25
        string[i] = random_number+65; // 65-90
    }
    *index_usable += number_of_randoms;
    string[*index_usable] = DELIMITER;
}

int get_rand_special_characters_num() {
    int ascii_array[] = {33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,58,59,60,61,62,63,64,91,92,93,94,95,96,123,124,125,126};
    int random_number = rand()%(15+7+6+4+1);

    return ascii_array[random_number];
}
void get_special_characters(char *string, int *index_usable, int number_of_randoms) {
    for (int i=*(index_usable); i<number_of_randoms+(*index_usable); i++) {
        int random_number = get_rand_special_characters_num();
        string[i] = random_number;
    }
    *index_usable += number_of_randoms;
    string[*index_usable] = DELIMITER;
}

void get_number_characters(char *string, int *index_usable, int number_of_randoms) {
    for (int i=*(index_usable); i<number_of_randoms+(*index_usable); i++) {
        int random_number = rand()%11;// 0-10
        string[i] = random_number+48; // 48-57
    }
    *index_usable += number_of_randoms;
    string[*index_usable] = DELIMITER;
}

// char *suggest_password(int length_of_password, bool contains_lowercase, bool contains_uppercase, bool contains_special_characters, bool contains_numbers, bool contains_spaces, char *password) {
//     //33-126 are possible symbols
//     // as we check the conditions in the parameters, remove the numbers allowed
//     // need to make a randomizer or import a randomizer library
//     // loop through length_of_password
//     // modify up current position of char array
//     // as of right now passing in char array but need to change to allocate memory for char and free pointer after in another function
//     char *suggesting_password = (char *)calloc(length_of_password, sizeof(char));

//     int count = 0;
//     if (contains_lowercase) count++;
//     if (contains_uppercase) count++;
//     if (contains_special_characters) count++;
//     if (contains_numbers) count++;
//     if (contains_spaces) count++;

//     int dividend = length_of_password/count;
//     int remainder = length_of_password%count;
//     int index_usable = 0;

//     if (contains_lowercase) get_lowercase_letters(suggesting_password, &index_usable, dividend);
//     if (contains_uppercase) get_uppercase_letters(suggesting_password, &index_usable, dividend);


//     return "";
// }




// get_password_strength()
    //counting number of boolean characters the user chose and length and use length! to count strength

int main() {
    char name[100];
    int index_usable = 0;

    // testing get_lowercase_letters
    get_lowercase_letters(name, &index_usable, 10);
    if (strlen(name) != 10) {
        printf("lowercase letters has an unexpected length of: %lu", strlen(name));
        return 1;
    }
    printf("get_lowercase_letters passed.\n");

    // testing get_upper_case_letters
    get_uppercase_letters(name, &index_usable, 10);
    if (strlen(name) != 20) {
        printf("uppercase letters has an unexpected length of: %lu\n", strlen(name));
        return 1;
    }
    printf("get_uppercase_letters passed.\n");

    // testing get_special_characters
    get_special_characters(name, &index_usable, 10);
    if (strlen(name) != 30) {
        printf("special characters has an unexpected length of: %lu\n", strlen(name));
        return 1;
    }
    printf("get_special_characters passed.\n");

    // testing get_number_characters
    get_number_characters(name, &index_usable, 10);
    if (strlen(name) != 40) {
        printf("number characters has an unexpected length of: %lu\n", strlen(name));
        return 1;
    }
    printf("get_number_characters passed.\n");

    
    printf("string: %s\n", name);
    return 0;
}