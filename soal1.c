#include <stdio.h>

#define MAX 100000

int H[MAX];       // tinggi bebek
int stack[MAX];   // stack untuk simpan indeks
int count[MAX];   // jumlah bebek yang dapat diintip masing-masing bebek

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &H[i]);
    }

    long long total = 0;
    int top = -1;

    for (int i = 0; i < N; i++) {
        count[i] = 1; // setiap bebek pasti bisa melihat dirinya sendiri

        while (top >= 0 && H[stack[top]] <= H[i]) {
            count[i] += count[stack[top]];
            top--;
        }

        total += count[i];
        stack[++top] = i;
    }

    printf("%lld\n", total);
    return 0;
}
