#define __testing
#include "suggest_passwords.c"

int main() {
    char name[100];
    int index_usable = 0;

    // testing add_lowercase_letters
    add_lowercase_letters(name, &index_usable, 10);
    if (strlen(name) != 10) {
        printf("lowercase letters has an unexpected length of: %lu", strlen(name));
        return 1;
    }
    printf("add_lowercase_letters passed.\n");

    // testing add_upper_case_letters
    add_uppercase_letters(name, &index_usable, 10);
    if (strlen(name) != 20) {
        printf("uppercase letters has an unexpected length of: %lu\n", strlen(name));
        return 1;
    }
    printf("add_uppercase_letters passed.\n");

    // testing add_special_characters
    add_special_characters(name, &index_usable, 10);
    if (strlen(name) != 30) {
        printf("special characters has an unexpected length of: %lu\n", strlen(name));
        return 1;
    }
    printf("add_special_characters passed.\n");

    // testing add_number_characters
    add_number_characters(name, &index_usable, 10);
    if (strlen(name) != 40) {
        printf("number characters has an unexpected length of: %lu\n", strlen(name));
        return 1;
    }
    printf("add_number_characters passed.\n");

    // testing add_spaces
    add_spaces(name, &index_usable, 10);
    if (strlen(name) != 50) {
        printf("spaces has an unexpected length of: %lu\n", strlen(name));
        return 1;
    }
    printf("add_spaces passed.\n");

    printf("original string: %s\n", name);
    shuffle_password(name, strlen(name));
    if (strlen(name) != 50) {
        printf("shuffled has an unexpected length of: %lu\n", strlen(name));
        return 1;
    }
    printf("shuffled string: %s\n", name);
    printf("shuffled passed.\n");

    printf("--------------------------------------\n");

    // testing suggest_password
    char *suggested_password = suggest_password(10, true, true, true, true, true);
    printf("string: %s\n", suggested_password);
    printf("suggest_password passed.\n");

    printf("number of possible passwords (strength): %ld\n", get_password_strength(strlen(suggested_password), true, true, true, true, true));

    return 0;
}