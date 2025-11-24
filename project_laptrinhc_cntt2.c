#include <stdio.h>
#include <string.h>
#define MAX 100

struct Account {
    char accountId[20];
    char fullName[50];
    char phone[15];
    double balance;
    int status; // 1: dang hoat dong, 0: khoa
};

struct Account user[MAX] = {
    {"1", "Phuong Dong", "0886634987", 0.00, 1},
    {"2", "Nguyen Hung", "0919675834", 0.00, 1},
    {"3", "Quoc Trung", "09887778534", 0.00, 0},
    {"4", "Sy Nhan", "0919945989", 0.00, 1},
};
int size = 4;

struct Transaction {
    char transId[20];
    char senderId[20];
    char receiverId[20];
    double amount;
    char type[10];  // vi du: "CK", "NT", ...
    char date[20];
};

struct Transaction trans[MAX];
int transSize = 0;

// Xoa ky tu xuong dong sau khi dung fgets
void deleteNewLine(char *str) {
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

// Xoa bo dem stdin khi dung scanf
void clearStdin() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Tim index tai khoan theo accountId
int findIndex(const char *id) {
    for (int i = 0; i < size; i++) {
        if (strcmp(user[i].accountId, id) == 0) {
            return i;
        }
    }
    return -1;
}

void createAccount() {
    int currentSize;
    printf("Nhap so tai khoan muon them: ");
    if (scanf("%d", &currentSize) != 1) {
        printf("Nhap sai dinh dang!\n");
        clearStdin();
        return;
    }

    if (currentSize <= 0 || size + currentSize > MAX) {
        printf("So luong khong hop le (toi da %d, dang co %d)!!!\n", MAX, size);
        return;
    }

    clearStdin();

    for (int i = 0; i < currentSize; i++) {
        int idx = size + i;
        printf("\n|%-39s|\n", "Nhap thong tin tai khoan");

        printf("Nhap ma tai khoan: ");
        fgets(user[idx].accountId, sizeof(user[idx].accountId), stdin);
        deleteNewLine(user[idx].accountId);

        printf("Nhap ho va ten chu tai khoan: ");
        fgets(user[idx].fullName, sizeof(user[idx].fullName), stdin);
        deleteNewLine(user[idx].fullName);

        printf("Nhap so dien thoai: ");
        fgets(user[idx].phone, sizeof(user[idx].phone), stdin);
        deleteNewLine(user[idx].phone);

        printf("Nhap so du: ");
        if (scanf("%lf", &user[idx].balance) != 1) {
            printf("Nhap sai dinh dang so du!\n");
            clearStdin();
            user[idx].balance = 0.0;
        }
        clearStdin();

        user[idx].status = 1;
    }

    size += currentSize;
    printf("\nDa them tai khoan thanh cong! Tong so tai khoan: %d\n", size);
}

void UpdateInfo() {
    char changeId[20];

    printf("Cap nhat thong tin.\n");
    clearStdin();  // Xoa '\n' con lai sau scanf lua chon menu

    printf("Nhap ID can sua: ");
    fgets(changeId, sizeof(changeId), stdin);
    deleteNewLine(changeId);

    int idx = findIndex(changeId);
    if (idx == -1) {
        printf("Error: Khong tim thay tai khoan!\n");
        return;
    }

    // Khong duoc sua accountId va balance truc tiep
    printf("Current Name: %s. New Name: ", user[idx].fullName);
    fgets(user[idx].fullName, sizeof(user[idx].fullName), stdin);
    deleteNewLine(user[idx].fullName);

    printf("Current Phone: %s. New Phone: ", user[idx].phone);
    fgets(user[idx].phone, sizeof(user[idx].phone), stdin);
    deleteNewLine(user[idx].phone);

    printf("-> Success: Cap nhat thong tin xong!\n");
}

void printMenu() {
    printf("+-------------------------------------+\n");
    printf("|----------QUAN LY GIAO DICH----------|\n");
    printf("+-------------------------------------+\n");
    printf("|%-37s|\n", "1. Them tai khoan moi");
    printf("|%-37s|\n", "2. Cap nhat thong tin");
    printf("|%-37s|\n", "3. Quan ly trang thai (Khoa/Xoa)");
    printf("|%-37s|\n", "4. Tra cuu (Tim kiem)");
    printf("|%-37s|\n", "5. Danh sach (Phan trang)");
    printf("|%-37s|\n", "6. Sap xep danh sach");
    printf("|%-37s|\n", "7. Giao dich chuyen khoan");
    printf("|%-37s|\n", "8. Lich su giao dich");
    printf("|%-37s|\n", "9. Thoat chuong trinh");
    printf("|%-37s|\n", "10. Hien thi danh sach tai khoan");
    printf("+-------------------------------------+\n");
}

void showAccountList() {
    if (size == 0) {
        printf("Chua co tai khoan nao!\n");
        return;
    }

    printf("+-----------------------------------------------------------------------------------+\n");
    printf("| %-4s | %-6s | %-20s | %-15s | %-11s | %-10s |\n",
           "STT", "Ma TK", "Ho ten", "So dien thoai", "So du", "Trang thai");
    printf("+-----------------------------------------------------------------------------------+\n");

    for (int i = 0; i < size; i++) {
        printf("| %-4d | %-6s | %-20s | %-15s | %-11.2lf | %-10s |\n",
               i + 1,
               user[i].accountId,
               user[i].fullName,
               user[i].phone,
               user[i].balance,
               user[i].status == 1 ? "Hoat dong" : "Khoa");
    }

    printf("+-----------------------------------------------------------------------------------+\n");
}

int main() {
    int choice;
    do {
        printMenu();
        printf("Moi ban nhap lua chon: ");
        if (scanf("%d", &choice) != 1) {
            printf("Nhap sai dinh dang, vui long nhap so!\n");
            clearStdin();
            continue;
        }

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                UpdateInfo();
                break;
            case 9:
                printf("Thoat chuong trinh...\n");
                break;
            case 10:
                showAccountList();
                break;
            default:
                printf("Chuc nang chua duoc cai dat hoac khong hop le.\n");
                break;
        }
    } while (choice != 9);

    return 0;
}
