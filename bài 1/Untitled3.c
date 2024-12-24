#include<stdio.h>
#include<stdlib.h>
struct Library {
    int id;
    char name[50];
    char author[50];
    float price;
};

void addBook(struct Library book[], int size);
void displayBook(struct Library book[], int size);
void moreBook(struct Library book[], int *size, int x);
void delBook(struct Library book[], int *size, int x);
void editBook(struct Library book[], int size, int x);
void searchBook(struct Library book[], int size, char name[]);
void sapXep(struct Library book[], int size, int choice);

int main() {
    char name[50];
    int size = 0;  
    int choice;
    int x;
    struct Library book[100];
    do {
        printf("*********MENU***********\n");
        printf("1. Moi ban nhap so luong va thong tin sach\n");
        printf("2. Hien thi thong tin sach\n");
        printf("3. Them sach vao vi tri\n");
        printf("4. Xoa sach theo ma\n");
        printf("5. Cap nhat thong tin theo ma sach\n");
        printf("6. Sap xep tang giam\n");
        printf("7. Tim kiem theo ten sach\n");
        printf("8. Thoat\n");
        printf("Moi ban chon chuc nang tu 1-8 : ");
        scanf("%d", &choice);

        if(choice < 1 || choice > 8) {
            printf("Moi ban nhap lai so luong phan tu\n");
        }

        switch(choice) {
            case 1:
                printf("Moi ban nhap so luong sach: ");
                scanf("%d", &size);
                addBook(book, size);
                break;
            case 2:
                displayBook(book, size);
                break;
            case 3:
                moreBook(book, &size, x);
                break;
            case 4:
                delBook(book, &size, x);
                break;
            case 5:
                printf("Nhap ma sach can cap nhat: ");
                scanf("%d", &x);
                editBook(book, size, x);
                break;
            case 6:
                sapXep(book, size, choice);  
                break;
            case 7:
                printf("Nhap ten sach can tim: ");
                getchar();  
                fgets(name, sizeof(name), stdin);
                searchBook(book, size, name);
                break;
            case 8:
                printf("Da thoat chuong trinh\n");
                break;
            default:
                printf("Du lieu sai, hay nhap lai du lieu\n");
                return 0;
        }
    } while(choice != 8);

    return 0;
}

void addBook(struct Library book[100], int size) {
	int i; 
    for(i = 0; i < size; i++) {
        fflush(stdin);
        printf("Moi ban nhap thong tin sach so %d\n", i + 1);
        printf("Ma sach: ");
        scanf("%d", &book[i].id);
        getchar();  
        printf("Ten sach: ");
        fgets(book[i].name, sizeof(book[i].name), stdin);
        printf("Ten tac gia: ");
        fgets(book[i].author, sizeof(book[i].author), stdin);
        printf("Gia sach: ");
        scanf("%f", &book[i].price);
    }
}

void displayBook(struct Library book[], int size) {
	int i; 
    for(i = 0; i < size; i++) {
        printf("ID sach: %d\n", book[i].id);
        printf("Ten sach: %s", book[i].name);
        printf("Ten tac gia sach: %s", book[i].author);
        printf("Gia sach: %.2f\n", book[i].price);
    }
}

void moreBook(struct Library book[], int *size, int x) {
    printf("Moi ban nhap vi tri them (1-%d): ", *size + 1);
    scanf("%d", &x);
    if (x < 1 || x > *size + 1) {
        printf("Vi tri khong hop le.\n");
        return;
    }
    int i; 
    for (i = *size; i >= x; i--) {
        book[i] = book[i - 1];
    }
    printf("Nhap ten sach: ");
    getchar();  
    fgets(book[x - 1].name, sizeof(book[x - 1].name), stdin);
    book[x - 1].name[strcspn(book[x - 1].name, "\n")] = 0; 
    printf("Nhap ten tac gia: ");
    fgets(book[x - 1].author, sizeof(book[x - 1].author), stdin);
    printf("Nhap ma sach: ");
    scanf("%d", &book[x - 1].id);

    (*size)++;
    printf("Sach da duoc them vao vi tri %d.\n", x);
}

void delBook(struct Library book[], int *size, int x) {
    printf("Moi ban nhap vi tri xoa (1-%d): ", *size);
    scanf("%d", &x);
    if (x < 1 || x > *size) {
        printf("Vi tri khong hop le.\n");
        return;
    }
    int i; 
    for (i = x - 1; i < *size - 1; i++) {
        book[i] = book[i + 1];
    }
    (*size)--;  
    printf("Sach da duoc xoa khoi vi tri %d.\n", x);
}

void editBook(struct Library book[], int size, int x) {
    printf("Nhap ma sach can cap nhat: ");
    scanf("%d", &x);

    int found = 0;
    int i; 
    for (i = 0; i < size; i++) {
        if (book[i].id == x) {
            found = 1;
            printf("Nhap ten sach moi: ");
            getchar();  
            fgets(book[i].name, sizeof(book[i].name), stdin);
            printf("Nhap ten tac gia moi: ");
            fgets(book[i].author, sizeof(book[i].author), stdin);
            printf("Nhap gia sach moi: ");
            scanf("%f", &book[i].price);
            printf("Cap nhat thong tin thanh cong.\n");
            break;
        }
    }
    if (!found) {
        printf("Sach voi ma %d khong tim thay.\n", x);
    }
}

void searchBook(struct Library book[], int size, char name[]) {
    int found = 0;
    int i; 
    for (i = 0; i < size; i++) {
        if (strstr(book[i].name, name)) {
            found = 1;
            printf("ID sach: %d\n", book[i].id);
            printf("Ten sach: %s", book[i].name);
            printf("Ten tac gia sach: %s", book[i].author);
            printf("Gia sach: %.2f\n", book[i].price);
        }
    }
    if (!found) {
        printf("Khong tim thay sach co ten '%s'.\n", name);
    }
}

void sapXep(struct Library book[], int size, int choice) {
    int sortChoice;
    printf("1. Sap xep tang dan\n");
    printf("2. Sap xep giam dan\n");
    printf("Hay chon chuc nang (1-2): ");
    scanf("%d", &sortChoice);

    switch (sortChoice) {
        case 1:
        	int i; 
            for (i = 0; i < size - 1;i++) {
                for (int j = i + 1; j < size; j++) {
                    if (book[i].id > book[j].id) {
                        struct Library temp = book[i];
                        book[i] = book[j];
                        book[j] = temp;
                    }
                }
            }
            displayBook(book, size);
            break;
        case 2:
            for (int  j = 0; j < size - 1; j++) {
                for (int j = i + 1; j < size; j++) {
                    if (book[i].id < book[j].id) {
                        struct Library temp = book[i];
                        book[i] = book[j];
                        book[j] = temp;
                    }
                }
            }
            displayBook(book, size);
            break;
        default:
            printf("Du lieu sai, vui long nhap lai.\n");
    }
}

