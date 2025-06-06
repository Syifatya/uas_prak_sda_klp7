#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct stack{ //definisi stack
    int val;
    struct stack* next;
} stack;

stack* top = NULL;

//fungsi add menambah node bernilai x sebanyak y
void add(int y, int x){    
    for(int i = 0; i < y; i++){
        stack* newnode = (stack*) malloc(sizeof(struct stack));
        if (newnode == NULL) {
            printf("alokasi memori gagal\n\n");
            return; 
        }
        newnode->val = x;
        newnode->next = top;
        top = newnode;
    }

// mengecek dan menampilkan jumlah stack
    int count = 0;         
    stack* current = top;
    while(current != NULL){
        count++;
        current =  current->next;
    }
    printf("isi stack saat ini sebanyak: %d\n", count);
}

//fungsi menghapus stack
void del(int y){

    stack* current = top;
    if (current == NULL){
            printf("stack kosong");
    }
    else{
      for(int i = 1; i <= y; i++){
        top = top->next;
//untuk menampilkan stack pertama yg di pop
        if(i == 1){   
            printf("\ndel %d value\nstack pertama yg di pop : %d\n", y, current->val);
        }
        free(current);
        current = top;
      }    
    }
};

//fungsi untuk menambah dengan nilai d pada seluruh value stack
void adx(int d){

    stack* current = top;
    if(current == NULL){
        printf("stack kosong");
    }
    else{
        printf("\nisi stack ditambah %d", d);
        while(current != NULL){
            current->val = current->val + d;
            current = current->next;
        }
    }
};

//fungsi untuk mengurang dengan nilai d pada seluruh value stack
void dex(int d){

    stack* current = top;
    if(current == NULL){
        printf("stack kosong");
    }
    else{
        printf("\nisi stack dikurang %d", d);
        while(current != NULL){
            current->val = current->val - d;
            current = current->next;
        }
   }
};

//fungsi untuk menampilkan seluruh isi stack
void printlist(stack* top){
    if(top == NULL){
        printf("stack kosong");
    }
    else{
        printf("\nisi stack saat ini: ");
        while(top != NULL){
            printf("%d ", top->val);
            top = top->next;
            if(top == NULL)
            return;
        }
    }
}

int main(){
    int Q, y, x;
   printf("operasi implementasi soal 4:\n1. add untuk menambahkan\n2. del untuk menghapus\n3. adx untuk menambah seluruh value dalam stack dengan bilangan x\n4. dex untunk mengurang seluruh value dalam stack dengan bilangan x\n5. printlist untuk print seluruh isi dalam stack\n6. exit\n");
   printf("\nsilahkan pilih command atau angka\ncontoh : \nadd 3 (jumlah yg mau diisi) 2 (nilai yg mau diisi)\ndel 2(banyak nilai yang mau dihapus)\nadx 3(nilai yg ingin ditambah ke setiap value stack)\ndex 4(nilai yg ingin dikurang ke setiap value stack)\n");
   printf("jalankan sebanyak : ");
   scanf("%d", &Q);
   getchar(); 
   
   for(int i = 1; i<= Q; i++){

   printf("\nsilahkan pilih :");
    char pil[100];
    char cmd[20];
    fgets(pil, sizeof(pil), stdin);
    pil[strcspn(pil, "\n")] = 0;
    sscanf(pil, "%s %d %d", cmd, &y, &x);

   if (strcmp(cmd, "add") == 0 && y != 0) {
        add(y, x);
    }

    else if(strcmp(cmd, "del") == 0 || strcmp(pil, "2") == 0) {     
        del(y);
    }

    else if(strcmp(cmd, "adx") == 0 || strcmp(pil, "3") == 0){    
        adx(y);
    }

    else if(strcmp(cmd, "dex") == 0 || strcmp(pil, "4") == 0){
        dex(y);
    }

     else if(strcmp(cmd, "printlist") == 0 || strcmp(pil, "5") == 0){
        printlist(top);
    }

    else if(strcmp(cmd, "exit") == 0 ){
        system("cls");
        exit(0);
    }

    else{
        printf("command tidak dikenali");
    }
}

return 0;
}
