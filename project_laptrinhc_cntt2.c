#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct {
	char accountId[20];
	char fullName[50];
	char phone[15];
	double balance;
	int status;
} Account;

Account list[MAX];
int currentSize = 0;

void deleteNewLine(char *str) {
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}/*Ham xoa ki tu xuong dong sau khi dung fgets*/

void createAccount (){
	if (currentSize >= MAX){
		printf("Danh sach da day. Khong the nhap them\n");
		return;
	}
	
	Account acc;
	
}

typedef struct {
	char transId[20];
	char senderId[20];
	char receiverId[20];
	double amount;
	char type[10];
	char date[20];
};

int main (){
	int choice;
	do{
		printf("+-------------------------------------+\n");
	printf("|----------QUAN LY GIAO DICH----------|\n");
	printf("+-------------------------------------+\n");
	printf("|%-37s|\n","1. Them tai khoan moi");
	printf("|%-37s|\n","2. Cap nhat thong tin");
	printf("|%-37s|\n","3. Quan ly trang thai (Khoa/Xoa)");
	printf("|%-37s|\n","4. Tra cuu (Tim kiem)");
	printf("|%-37s|\n","5. Danh sach (Phan trang)");
	printf("|%-37s|\n","6. Sap xep danh sach");
	printf("|%-37s|\n","7. Giao dich chuyen khoan");
	printf("|%-37s|\n","8. Lich su giao dich");
	printf("|%-37s|\n","9. Thoat chuong trinh");
	printf("+-------------------------------------+\n");
		printf("Moi ban nhap lua chon: \n");
		scanf("%d", &choice);
	}
	while (choice !=9);
	return 0;	
}

