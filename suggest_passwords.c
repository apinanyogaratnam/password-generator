#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define DELIMITER '\0'
#define WHITE_SPACE ' '
#define NUMBER_OF_CONDITIONS 4


void exists(char *password); // checks if password exists already


long factorial(long n) {
    if (n == 0 || n == 1) return 1;
    return n * factorial(n-1);
}

long permutation(long n, long r) {
    return pow(n, r);
}

void delete_password_pointer(char *pointer_to_password) {
    free(pointer_to_password);
}

void add_lowercase_letters(char *string, int *index_usable, int number_of_randoms) {
    for (int i=*(index_usable); i<number_of_randoms+(*index_usable); i++) {
        int random_number = rand()%26; // 0-25
        string[i] = random_number+97; // ascii table adding (97-122)
    }
    *index_usable += number_of_randoms;
    string[*index_usable] = DELIMITER;
}

void add_uppercase_letters(char *string, int *index_usable, int number_of_randoms) {
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
void add_special_characters(char *string, int *index_usable, int number_of_randoms) {
    for (int i=*(index_usable); i<number_of_randoms+(*index_usable); i++) {
        int random_number = get_rand_special_characters_num();
        string[i] = random_number;
    }
    *index_usable += number_of_randoms;
    string[*index_usable] = DELIMITER;
}

void add_number_characters(char *string, int *index_usable, int number_of_randoms) {
    for (int i=*(index_usable); i<number_of_randoms+(*index_usable); i++) {
        int random_number = rand()%11;// 0-10
        string[i] = random_number+48; // 48-57
    }
    *index_usable += number_of_randoms;
    string[*index_usable] = DELIMITER;
}

void add_spaces(char *string, int *index_usable, int number_of_spaces) {
    for (int i=*(index_usable); i<number_of_spaces+(*index_usable); i++) {
        string[i] = WHITE_SPACE;
    }
    *index_usable += number_of_spaces;
    string[*index_usable] = DELIMITER;
}

void shuffle_password(char *string, int length_of_string) {
    int random_number;
    char temp;
    for (int i=0; i<length_of_string; i++) {
        random_number = rand()%length_of_string;
        temp = string[i];
        string[i] = string[random_number];
        string[random_number] = temp;
    }
}

char *suggest_password(int length_of_password, bool contains_lowercase, bool contains_uppercase, bool contains_special_characters, bool contains_numbers, bool contains_spaces) {
    // as we check the conditions in the parameters, remove the numbers allowed
    // need to make a randomizer or import a randomizer library
    // loop through length_of_password
    // modify up current position of char array
    // as of right now passing in char array but need to change to allocate memory for char and free pointer after in another function
    if (!contains_lowercase && !contains_uppercase && !contains_special_characters && !contains_numbers && !contains_spaces) {
        printf("Could not generate password with given input");
        return NULL;
    }
    if (length_of_password <= 0) {
        printf("Could not generate password with given input");
        return NULL;
    }
    char *suggesting_password = (char *)calloc(length_of_password, sizeof(char));
    if (!suggesting_password) {
        printf("No space on ram.\n");
        return NULL;
    }

    int count = 0;
    if (contains_lowercase) count++;
    if (contains_uppercase) count++;
    if (contains_special_characters) count++;
    if (contains_numbers) count++;
    if (contains_spaces) count++;

    int dividend = length_of_password/count;
    int remainder = length_of_password%count;
    int index_usable = 0;

    // fill up string
    if (contains_lowercase) add_lowercase_letters(suggesting_password, &index_usable, dividend);
    if (contains_uppercase) add_uppercase_letters(suggesting_password, &index_usable, dividend);
    if (contains_special_characters) add_special_characters(suggesting_password, &index_usable, dividend);
    if (contains_numbers) add_number_characters(suggesting_password, &index_usable, dividend);
    if (contains_spaces) add_spaces(suggesting_password, &index_usable, dividend);

    // early return if no remainders exist
    if (remainder == 0) return suggesting_password;

    // fill up remainder of string
    if (contains_lowercase) {
        add_lowercase_letters(suggesting_password, &index_usable, remainder);
    } else if (contains_uppercase) {
        add_uppercase_letters(suggesting_password, &index_usable, remainder);
    } else if (contains_special_characters) {
        add_special_characters(suggesting_password, &index_usable, remainder);
    } else if (contains_numbers) {
        add_number_characters(suggesting_password, &index_usable, remainder);
    } else {
        add_spaces(suggesting_password, &index_usable, remainder);
    }

    // shuffle password
    shuffle_password(suggesting_password, length_of_password);
    
    return suggesting_password;
}




long get_password_strength(int length_of_password, bool contains_uppercase, bool contains_lowercase, bool contains_numbers, bool contains_special_characters, bool contains_spaces) {
    if (length_of_password <= 0) {
        printf("Cannot determine strength of password with given requirements.\n");
        return -1;
    }
    if (!contains_lowercase && !contains_uppercase && !contains_special_characters && !contains_numbers && !contains_spaces) {
        printf("Cannot determine strength of password with given requirements.\n");
        return -1;
    }
    int count = 0;
    if (contains_lowercase) count++;
    if (contains_uppercase) count++;
    if (contains_special_characters) count++;
    if (contains_numbers) count++;
    if (contains_spaces) count++;

    int dividend = length_of_password/count;
    int remainder = length_of_password%count;

    long possible_permutaions = 1;
    if (contains_lowercase) {
        possible_permutaions *= permutation(26, dividend);
    }
    if (contains_uppercase) {
        possible_permutaions *= permutation(26, dividend);
    }
    if (contains_special_characters) {
        possible_permutaions *= permutation(32, dividend);
    }
    if (contains_numbers) {
        possible_permutaions *= permutation(10, dividend);
    }
    if (contains_spaces) {
        possible_permutaions *= permutation(1, dividend);
    }

    // early return if no remainder exists
    if (remainder == 0) return possible_permutaions;

    // check remaining letters
    if (contains_lowercase) {
        possible_permutaions *= permutation(26, remainder);
    } else if (contains_uppercase) {
        possible_permutaions *= permutation(26, remainder);
    } else if (contains_special_characters) {
        possible_permutaions *= permutation(32, remainder);
    } else if (contains_numbers) {
        possible_permutaions *= permutation(10, remainder);
    } else {
        possible_permutaions *= permutation(1, remainder);
    }

    return possible_permutaions;
}
