#include<stdio.h>

#include <string.h>

// Function to validate login credentials
int validateLogin(const char *username, const char *password) {
    FILE *file = fopen("datasignup.txt", "r");
    if (file == NULL) {
        printf("Error opening credentials file.\n");
        return 0; // Indicate failure
    }

    char storedUsername[50];
    char storedPassword[50];

    while (fscanf(file, "%s %s", storedUsername, storedPassword) != EOF) {
        if (strcmp(storedUsername, username) == 0 && strcmp(storedPassword, password) == 0) {
            fclose(file);
            return 1; // Indicate success
        }
    }

    fclose(file);
    return 0; // Indicate failure
}

// Function to create a new user account
void signUp(const char *username, const char *password) {
    FILE *file = fopen("datasignup.txt", "a");
    if (file == NULL) {
        printf("Error opening credentials file.\n");
        return;
    }

    fprintf(file, "%s %s\n", username, password);
    fclose(file);

    printf("Account created successfully!\n");
}

int auth() {
    int choice;
    printf("Welcome to the Login/Signup System\n");
    printf("1. Login\n");
    printf("2. Signup\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        char username[50];
        char password[50];

        printf("Please enter your username: ");
        scanf("%s", username);

        printf("Please enter your password: ");
        scanf("%s", password);

        if (validateLogin(username, password)) {
            printf("Welcome, %s!\n", username);
        } else {
            printf("Invalid login credentials.\n");
        }
    } else if (choice == 2) {
        char username[50];
        char password[50];

        printf("Please choose a username: ");
        scanf("%s", username);

        printf("Please choose a password: ");
        scanf("%s", password);

        signUp(username, password);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}
