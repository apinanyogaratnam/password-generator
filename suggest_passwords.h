
long factorial(long n);
/*

// get the factorial of n (n!)
*/

void delete_password_pointer(char *pointer_to_password);
/*

// deletes pointer for suggested password
*/

void add_lowercase_letters(char *string, int index_usable, int number_of_randoms); 
/*

// modifies a string of lowercase letters randomized to use
*/

void add_uppercase_letters(char *string, int *index_usable, int number_of_randoms); 
/* 

// modifies a string of uppercase letters randomized to use
*/

void add_special_characters(); 
/*

// modifies a string of special letters to use
*/

int get_rand_special_characters_num();
/* 

// get_special_characters helper to get a random special character
*/

void add_number_characters(char *string, int *index_usable, int number_of_randoms); 
/*

// modifies a string of numbers to use
*/

void add_spaces(char *password, int length_of_password, int number_of_spaces); 
/*

// modifies string with number of spaces given
*/

void shuffle_password(); 
/*

// shuffles password to randomize order of different types of conditions
*/

char *suggest_password(int length_of_password, bool contains_lowercase, bool contains_uppercase, \
                       bool contains_special_characters, bool contains_numbers, bool contains_spaces);
/*

// suggest a password given the conditions of the parameters

// given conditions:
    // contains uppercase
    // contains lowercase
    // contains numbers
    // contains special characters
    // contains spaces
    // length_of_string
*/

long get_password_strength(int length_of_password, bool contains_uppercase, bool contains_lowercase, bool contains_numbers, bool contains_special_characters, bool contains_spaces);
/*

//counting number of boolean characters the user chose and length and use length! to count strength
*/

long permutation(long n, long r);
/*

// Determines number of possible permutations can be applied given n and r
// P(n, r) = n^r  r = number of spots to be filled, n = possible items to fill the spots
*/
