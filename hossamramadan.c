#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct User {
    char username[50];
    char password[50];
};

struct User users[10];
int userCount = 0;

void registerUser();
int login(char *username, char *password);

int main() {
    registerUser(); 

    char username[50];
    char password[50];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    if (login(username, password) == 1) {
        printf("Login Done.\n");
    } else {
        printf("Valid username or password.\n");
    }

    return 0;
}

void registerUser() {
    char username[50];
    char password[50];

    printf("Enter username for registration: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    addUser(username, password);
}

void addUser(char *username, char *password) {
    if (userCount >= 10) {
        printf("Maximum user limit reached.\n");
        return;
    }

    strcpy(users[userCount].username, username);
    strcpy(users[userCount].password, password);
    userCount++;
}

int login(char *username, char *password) {
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return 1;
        }
    }
    return 0;
}