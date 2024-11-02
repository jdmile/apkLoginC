// main.c
#include <stdio.h>
#include <string.h>
#include "user.h"
#include "user.c"

void printMenu() {
    printf("\n--- Aplikasi Login Sederhana ---\n");
    printf("1. Register\n");
    printf("2. Login\n");
    printf("0. Keluar\n");
    printf("Pilih opsi: ");
}

int main() {
    int choice;
    char username[50];
    char password[50];

    while (1) {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Masukkan username baru: ");
                scanf("%s", username);
                printf("Masukkan password baru: ");
                scanf("%s", password);

                if (registerUser(username, password)) {
                    printf("Registrasi berhasil!\n");
                } else {
                    printf("Registrasi gagal. Username sudah digunakan atau terjadi kesalahan.\n");
                }
                break;

            case 2:
                printf("Masukkan username: ");
                scanf("%s", username);
                printf("Masukkan password: ");
                scanf("%s", password);

                if (loginUser(username, password)) {
                    printf("Login berhasil! Selamat datang, %s!\n", username);
                } else {
                    printf("Login gagal. Username atau password salah.\n");
                }
                break;

            case 0:
                printf("Terima kasih telah menggunakan aplikasi.\n");
                return 0;

            default:
                printf("Pilihan tidak valid!\n");
        }
    }
    return 0;
}
