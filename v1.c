#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct admin {
    char username[50];
    char password[50];
};

struct user {
    char username[50];
    char password[50];
    char email[100];
    char no_telp[50];
    char feedback[50];
    int saldo;
    int developer;
};

struct game {
    char judul[50];
    char genre[50];
    char deskripsi[256];
    char platform[50];
    char penggembang[50];
    char tanggalRilis[50];
    int harga;
    float rating;
};

FILE *fuser;
FILE *fadmin;
FILE *fdeveloper;
FILE *fgame;
FILE *ffeedback;
FILE *fpendapatan;

void MenuLogin() {
    int pilihan;

    printf("=== MAIN MENU ===\n");
    printf("1. Login Admin\n");
    printf("2. Login User\n");
    printf("3. Login Developer\n");
    printf("4. Registrasi User\n");
    printf("5. Logout\n");
    printf("Pilihan : "); scanf("%d", &pilihan);

    switch (pilihan) {
        case 1:
            system("cls");
            // ss
            break;
        case 2:
            system("cls");
            LoginUser();
            break;
        case 3:
            system("cls");
            //ss
            break;
        case 4:
            system("cls");
            RegistrasiUser();
            break;
        case 5:
            printf("\nTerimakasih sudah menggunakan program ini!\n");
            break;
        default:
            system("cls");
            printf("\nPilihan tidak valid! Coba lagi.\n\n");
            MenuLogin();
    }
}

void LoginAdmin(){

}

void LoginUser() {
    char username[50], password[50];
    struct user user;
    int percobaan = 0;
    const int max_percobaan = 3;

    getchar();

    printf("\n=== LOGIN USER ===\n");
    while (percobaan < max_percobaan) { 
        printf("Username: ");
        fgets(username, sizeof(username), stdin);
        username[strcspn(username, "\n")] = '\0';

        printf("Password: ");
        fgets(password, sizeof(password), stdin);
        password[strcspn(password, "\n")] = '\0';

        if(bacaUser(&user, username)) {
            if(strcmp(user.password, password) == 0) {
                printf("Login berhasil! Selamat datang, %s\n\n", username);
                MenuUser();
                return;
            } else {
                percobaan++;
                if(percobaan < max_percobaan) {
                    printf("Password salah. Sisa percobaan %d lagi.\n\n", max_percobaan - percobaan);
                }
            }
        } else {
            percobaan++;
            if(percobaan < max_percobaan) {
                printf("Username tidak ditemukan. Sisa percobaan %d lagi.\n\n", max_percobaan - percobaan);
            }
        }
    }
}

void LoginDeveloper(){

}

void RegistrasiUser(){
    char username[50], password[50];
        FILE *fp;
        struct user user;
        struct user temp_user;

        getchar();

        printf("\n=== REGISTRASI USER ===\n");
        printf("Masukkan username: ");
        fgets(username, sizeof(username), stdin);
        username[strcspn(username, "\n")] = '\0';

        printf("Masukkan password: ");
        fgets(password, sizeof(password), stdin);
        password[strcspn(password, "\n")] = '\0';

        strcpy(user.username, username);
        strcpy(user.password, password);
        user.saldo = 0.0;

        if (bacaUser(&temp_user, username)) {
            printf("Username sudah terdaftar. Silakan gunakan username lain.\n");
            return;
        }

        if (simpanUser(&user)) {
            printf("Registrasi berhasil!\n");
        } else {
            printf("Gagal melakukan registrasi.\n");
        }
    system("cls");
    printf("Registrasi berhasil! Silakan login untuk melanjutkan.\n\n");
    MenuLogin();
}

int bacaUser(struct user *user, char *username) {
    FILE *fuser;
    struct user temp_user;
    fuser = fopen("user.dat", "rb");

    if(!fuser) {
        return 0;
    }

    while(fread(&temp_user, sizeof(struct user), 1, fuser)) {
        if(strcmp(temp_user.username, username) == 0) {
            *user = temp_user;
            fclose(fuser);
            return 1;
        }
    }
    fclose(fuser);
    return 0;
}

int simpanUser(struct user *user) {
    FILE *fuser = fopen("user.dat", "ab");
    
    if(!fuser) {
        printf("\nGagal membuka file!\n");
        return 0;
    }

    int hasil = fwrite(user, sizeof(struct user), 1, fuser);
    fclose(fuser);
    return hasil == 1;
}

void MenuAdmin() {
    int pilihan;

    printf("=== MENU ADMIN ===\n");
    printf("1. List Akun User\n");
    printf("2. Melihat Pendapatan\n");
    printf("3. Riwayat Pembelian\n");
    printf("0. Exit\n");
    printf("Pilihan : "); scanf("%d", &pilihan);

    switch (pilihan) {
        case 1:
            system("cls");
            // ss
            break;
        case 2:
            system("cls");
            //ss
            break;
        case 3:
            system("cls");
            //ss
            break;
        case 0:
            system("cls");
            MenuLogin();
            break;
        default:
            printf("\nInput tidak valid.\n");
    }
}
void ListAkunUser(){

}
void KumulatifPendapatan(){

}
void RiwayatPembelian(){

}
void MenuUser(){
    int pilihan;

    printf("=== MENU USER ===\n");
    printf("1. Home Page\n");
    printf("2. Profile User\n");
    printf("3. Registrasi Developer\n");
    printf("0. Logout");
    printf("Pilihan : "); scanf("%d", &pilihan);

    switch (pilihan) {
        case 1:
            system("cls");
            HomePage();
            break;
        case 2:
            system("cls");
            //ss
            break;
        case 3:
            system("cls");
            //ss
            break;
        case 0:
            system("cls");
            MenuLogin();
            break;
        default:
            system("cls");
            printf("\nPilihan tidak valid! Coba lagi.\n\n");
            MenuLogin();
    }
}
void HomePage() {
    int pilihan;

    printf("=== HOME PAGE ===\n");
    printf("1. Store Page\n");
    printf("2. Wallet\n");
    printf("3. Profile\n");
    printf("4. Exit\n");
    printf("Pilihan : "); scanf("%d", &pilihan);

    switch (pilihan) {
        case 1:
            system("cls");
            StorePage();
            break;
        case 2:
            system("cls");
            Wallet();
            break;
        case 3:
            system("cls");
            ProfileUser();
            break;
        case 4:
            system("cls");
            MenuUser();
            break;
        default:
            system("cls");
            printf("\nPilihan tidak valid! Coba lagi.\n\n");
            HomePage();
    }
}
void StorePage(){
    FILE *fgame;
    struct game list_game[69];
    int jumlah_game = 0;
    int pilihan;

    fgame = fopen("games.dat", "rb");
    if(!fgame) {
        printf("\nGagal membuka file!\n");
        return;
    }

    while(fread(&list_game[jumlah_game], sizeof(struct game), 1, fgame)) {
        jumlah_game++;
    }
    fclose(fgame);

    // Bubble sort hehe
    for(int i = 0; i < jumlah_game; i++) {
        for(int j = 0; j < jumlah_game - i - 1; j++) {
            if(list_game[j].harga > list_game[j + 1].harga) {
                struct game temp = list_game[j];
                list_game[j] = list_game[j + 1];
                list_game[j + 1] = temp;
            }
        }
    }

    printf("=== STORE PAGE ===\n");
    for(int i = 0; i < jumlah_game; i++) {
        printf("%d. %s — Rp%d", i + 1, list_game[i].judul, list_game[i].harga);
    }

    printf("\n1. Searching\n");
    printf("2. Exit\n");
    printf("Pilihan : "); scanf("%d", &pilihan);

    switch (pilihan) {
        case 1:
            system("cls");
            Searching();
            break;
        case 2:
            system("cls");
            HomePage();
            break;
        default:
            system("cls");
            printf("\nPilihan tidak valid! Coba lagi.\n\n");
            StorePage();
            break;
    }
}

void ToLower(char *string) {
    for(int i = 0; string[i]; i++) {
        string[i] = tolower(string[i]);
    }
}

void Searching() {
    FILE *fgame;
    struct game games;
    char namaGame[50];
    char input_lower[50], game_lower[50];
    int ditemukan = 0;

    printf("=== SEARCH GAME ===\n");
    printf("Nama Game : ");
    fgets(namaGame, sizeof(namaGame), stdin);
    namaGame[strcspn(namaGame, "\n")] = '\0';

    strcpy(input_lower, namaGame);
    ToLower(input_lower);

    fgame = fopen("games.dat", "rb");
    if(!fgame) {
        printf("\nGagal membuka file!\n");
        return;
    }

    while(fread(&games, sizeof(struct game), 1, fgame)) {
        strcpy(game_lower, games.judul);
        ToLower(game_lower);

        if(strcmp(input_lower, game_lower) == 0) {
            ditemukan = 1;

            printf("\nGame ditemukan!\n");
            printf("Judul           : %s\n", games.judul);
            printf("Genre           : %s\n", games.genre);
            printf("Platform        : %s\n", games.platform);
            printf("Penggembang     : %s\n", games.penggembang);
            printf("Tanggal Rilis   : %s\n", games.tanggalRilis);
            printf("Harga           : %d\n", games.harga);
            printf("Rating          : %.1f\n", games.rating);

            fclose(fgame);

            if(!ditemukan) {
                printf("Game tidak tersedia!\n");
                system("cls");
                StorePage();
            }
        }
    }
}
void GamePage(){

}
void BeliGame(){

}
void FeedbackGame(){

}
void Wallet(){

}
void ProfileUser(){

}
void RegistrasiDeveloper(){

}
void MenuDeveloper(){

}
void TambahGame(){

}
void UpdateGame(){

}
void LihatFeedback(){

}

int main () {
    struct user user;

    MenuLogin();
    
return 0;
}
