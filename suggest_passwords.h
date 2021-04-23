
int factorial(int number);
/*

*/

void delete_password_pointer(char *pointer_to_password);
/*

*/

void get_lowercase_letters(char *string, int index_usable, int number_of_randoms); 
/*


// modifies a string of lowercase letters randomized to use
*/

void get_uppercase_letters(char *string, int *index_usable, int number_of_randoms); 
/* 

// modifies a string of uppercase letters randomized to use
*/

void get_special_characters(); 
/*

// modifies a string of special letters to use
*/

int get_rand_special_characters_num();
/* 

// get_special_characters helper to get a random special character
*/

void get_number_characters(char *string, int *index_usable, int number_of_randoms); 
/*

// modifies a string of numbers to use
*/