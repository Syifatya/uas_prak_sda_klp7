#include <stdio.h>

// Fungsi untuk menghitung jumlah faktor dari N
int hitungFaktor(int n) {
    if (n == 1) return 1; // hanya memiliki satu faktor

    int count = 0;
    for (int i = 1; ; i++) {
        if (i * i > n) break;

        if (n % i == 0) {
            if (i * i == n)
                count += 1; // Faktor kembar
            else
                count += 2; // Dua faktor berbeda
        }
    }

    return count;
}

int main() {
    int T, N;

    printf("Jumlah bilangan bulat: ");
    scanf("%d", &T);

    // Array untuk menyimpan hasil sementara
    char hasil[T][6];  // Menyimpan "YA" atau "BUKAN"

    for (int i = 0; i < T; i++) {
        printf("Masukkan nilai ke-%d: ", i + 1);
        scanf("%d", &N);

        int jumlahFaktor = hitungFaktor(N);

        if (jumlahFaktor <= 4)
            sprintf(hasil[i], "YA");
        else
            sprintf(hasil[i], "BUKAN");
    }

    // Menampilkan semua hasil setelah semua input selesai
    printf("\nOutput:\n");
    for (int i = 0; i < T; i++) {
        printf("%s\n", hasil[i]);
    }

    return 0;
}