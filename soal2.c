#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_ARRAY 1000
#define MAX_OUTPUT 1000

int* arrays[MAX_ARRAY];
int sizes[MAX_ARRAY];
int capacities[MAX_ARRAY];

int outputs[MAX_OUTPUT];
int output_count = 0;

void init_array(int idx) {
    capacities[idx] = 4;
    sizes[idx] = 0;
    arrays[idx] = (int*)malloc(capacities[idx] * sizeof(int));
}

void add_element(int idx, int x, int y) {
    for (int i = 0; i < y; i++) {
        if (sizes[idx] == capacities[idx]) {
            capacities[idx] *= 2;
            arrays[idx] = (int*)realloc(arrays[idx], capacities[idx] * sizeof(int));
        }
        arrays[idx][sizes[idx]++] = x;
    }
}

int is_valid_index(int idx, int total_arrays) {
    return idx >= 0 && idx < total_arrays;
}

int main() {
    int Q;
    printf("Masukkan jumlah perintah:\n");
    if (scanf("%d", &Q) != 1 || Q < 1 || Q > 1000) {
        printf("Jumlah perintah tidak valid.\n");
        return 1;
    }

    printf("Masukkan perintah:\n");

    int total_arrays = 1;
    init_array(0);

    for (int i = 0; i < Q; i++) {
        char cmd[10];
        if (scanf("%s", cmd) != 1) {
            printf("Perintah tidak terbaca.\n");
            return 1;
        }

        if (strcmp(cmd, "add") == 0) {
            int L, X, Y;
            if (scanf("%d %d %d", &L, &X, &Y) != 3 || !is_valid_index(L - 1, total_arrays)) {
                printf("Format add tidak valid.\n");
                return 1;
            }
            add_element(L - 1, X, Y);
        } else if (strcmp(cmd, "new") == 0) {
            if (total_arrays >= MAX_ARRAY) {
                printf("Jumlah larik melebihi batas.\n");
                return 1;
            }
            init_array(total_arrays);
            total_arrays++;
        } else if (strcmp(cmd, "out") == 0) {
            int L, Z;
            if (scanf("%d %d", &L, &Z) != 2 || !is_valid_index(L - 1, total_arrays) || Z < 1 || Z > sizes[L - 1]) {
                printf("Format out tidak valid atau indeks di luar batas.\n");
                return 1;
            }
            outputs[output_count++] = arrays[L - 1][Z - 1];
        } else {
            printf("Perintah tidak dikenal: %s\n", cmd);
            return 1;
        }
    }

    printf("out:\n");
    for (int i = 0; i < output_count; i++) {
        printf("%d\n", outputs[i]);
    }

    for (int i = 0; i < total_arrays; i++) {
        free(arrays[i]);
    }

    return 0;
}
