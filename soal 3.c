#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 8
#define FACT 40320  // 8! = 40320 (jumlah permutasi maksimum)

typedef struct {
    int arr[MAXN];
    int steps;
} State;

int n, k;
int factorial[MAXN + 1];
int visited[FACT];  // untuk menandai konfigurasi yang sudah dikunjungi

// fungsi untuk menghitung faktorial
void compute_factorial() {
    factorial[0] = 1;
    for (int i = 1; i <= MAXN; ++i)
        factorial[i] = factorial[i - 1] * i;
}

// fungsi untuk mengkodekan permutasi menjadi angka unik (lexicographic order index)
int perm_to_index(int *perm) {
    int idx = 0;
    int used[MAXN + 1] = {0};
    for (int i = 0; i < n; ++i) {
        int smaller = 0;
        for (int j = 1; j < perm[i]; ++j) {
            if (!used[j]) smaller++;
        }
        idx += smaller * factorial[n - i - 1];
        used[perm[i]] = 1;
    }
    return idx;
}

// fungsi untuk memeriksa apakah sudah urut
int is_sorted(int *arr) {
    for (int i = 0; i < n; ++i) {
        if (arr[i] != i + 1) return 0;
    }
    return 1;
}

// fungsi BFS
int bfs(int *start) {
    State queue[FACT];
    int front = 0, back = 0;

    State init;
    memcpy(init.arr, start, sizeof(int) * n);
    init.steps = 0;

    queue[back++] = init;
    visited[perm_to_index(start)] = 1;

    while (front < back) {
        State curr = queue[front++];

        if (is_sorted(curr.arr)) {
            return curr.steps;
        }

        for (int i = 0; i <= n - k; ++i) {
            State next;
            memcpy(next.arr, curr.arr, sizeof(int) * n);

            // reverse K elements from i to i+k-1
            for (int j = 0; j < k / 2; ++j) {
                int tmp = next.arr[i + j];
                next.arr[i + j] = next.arr[i + k - 1 - j];
                next.arr[i + k - 1 - j] = tmp;
            }

            int idx = perm_to_index(next.arr);
            if (!visited[idx]) {
                visited[idx] = 1;
                next.steps = curr.steps + 1;
                queue[back++] = next;
            }
        }
    }

    return -1; // tidak bisa diurutkan
}

int main() {
    scanf("%d", &n);
    int start[MAXN];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &start[i]);
    }
    scanf("%d", &k);

    compute_factorial();

    memset(visited, 0, sizeof(visited));

    int result = bfs(start);
    printf("%d\n", result);
    return 0;
}
