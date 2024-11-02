// user.h
#ifndef USER_H
#define USER_H

#include <stdbool.h>

typedef struct {
    char username[50];
    char password[50];
} User;

// Fungsi untuk mendaftarkan pengguna baru
bool registerUser(const char *username, const char *password);

// Fungsi untuk login pengguna
bool loginUser(const char *username, const char *password);

// Fungsi untuk memeriksa apakah username sudah terdaftar
bool userExists(const char *username);

#endif
