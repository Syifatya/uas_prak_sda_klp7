#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000
#define MIN_N 1
#define MAX_N 1000000

// Definisi struktur queue
typedef struct {
    char data[MAX_SIZE][6]; // Menyimpan hasil "YA" atau "BUKAN"
    int front;
    int rear;
} Queue;

// Inisialisasi queue
void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

// Enqueue: tambahkan hasil ke dalam queue
void enqueue(Queue *q, const char *value) {
    q->rear = (q->rear + 1) % MAX_SIZE;
    strcpy(q->data[q->rear], value);
}

// Fungsi untuk menghitung jumlah faktor tanpa math.h
int hitungFaktor(int n) {
    if (n == 1)
        return 1;

    int count = 0;
    for (int i = 1;; i++) {
        if (i * i > n)
            break;

        if (n % i == 0) {
            if (i * i == n)
                count += 1; // faktor kembar
            else
                count += 2; // dua faktor berbeda
        }
    }

    return count;
}

// Fungsi validasi input N agar berada dalam range [MIN_N, MAX_N]
int inputValidN(int nomorInput) {
    int n;
    do {
        printf("Masukkan nilai ke-%d: ", nomorInput);
        if (scanf("%d", &n) != 1) {
            // Jika input bukan integer
            printf("Input tidak valid. Harus berupa bilangan bulat.\n");
            while (getchar() != '\n'); // Bersihkan buffer
        } else if (n < MIN_N || n > MAX_N) {
            printf("Nilai harus antara %d dan %d.\n", MIN_N, MAX_N);
        } else {
            break; // Input valid
        }
    } while (1);

    return n;
}

int main() {
    int T;
    Queue hasil;
    initQueue(&hasil);

    // Input jumlah bilangan dengan validasi
    printf("Jumlah bilangan bulat: ");
    scanf("%d", &T);

    // Validasi bahwa T berada dalam batas 1 <= T <= 1000
    while (T < 1 || T > 1000) {
        printf("Jumlah bilangan harus antara 1 dan 1000. \nMasukkan lagi: ");
        scanf("%d", &T);
    }

    // Input setiap N dengan validasi
    for (int i = 1; i <= T; i++) {
        int N = inputValidN(i);

        int jmlFaktor = hitungFaktor(N);

        if (jmlFaktor <= 4)
            enqueue(&hasil, "YA");
        else
            enqueue(&hasil, "BUKAN");
    }

    // Tampilkan semua hasil sekaligus di akhir
    printf("\nOutput:\n");
    for (int i = hasil.front; i <= hasil.rear; i++) {
        printf("%s\n", hasil.data[i]);
    }

    return 0;
}
