// user.c
#include <stdio.h>
#include <string.h>
#include "user.h"

#define DATA_FILE "users.dat"

// Fungsi untuk mengecek apakah pengguna sudah terdaftar
bool userExists(const char *username) {
    FILE *file = fopen(DATA_FILE, "rb");
    if (!file) return false;

    User temp;
    while (fread(&temp, sizeof(User), 1, file)) {
        if (strcmp(temp.username, username) == 0) {
            fclose(file);
            return true;
        }
    }
    fclose(file);
    return false;
}

// Fungsi untuk mendaftarkan pengguna baru
bool registerUser(const char *username, const char *password) {
    if (userExists(username)) {
        printf("Username '%s' sudah terdaftar.\n", username);
        return false;
    }

    FILE *file = fopen(DATA_FILE, "ab");
    if (!file) {
        printf("Gagal membuka file.\n");
        return false;
    }

    User newUser;
    strncpy(newUser.username, username, sizeof(newUser.username) - 1);
    strncpy(newUser.password, password, sizeof(newUser.password) - 1);

    fwrite(&newUser, sizeof(User), 1, file);
    fclose(file);
    return true;
}

// Fungsi untuk login pengguna
bool loginUser(const char *username, const char *password) {
    FILE *file = fopen(DATA_FILE, "rb");
    if (!file) {
        printf("Gagal membuka file.\n");
        return false;
    }

    User temp;
    while (fread(&temp, sizeof(User), 1, file)) {
        if (strcmp(temp.username, username) == 0 && strcmp(temp.password, password) == 0) {
            fclose(file);
            return true;
        }
    }
    fclose(file);
    return false;
}
