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

Account user[MAX] = {
{1, "Phuong Dong", "0886634987", 0.00, 1},
{2, "Nguyen Hung", "0919675834", 0.00, 1},
{3, "Quoc Trung", "09887778534", 0.00, 0},
{4, "Sy Nhan", "0919945989", 0.00, 1},
};
int size = 4;

void deleteNewLine(char *str) {
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}/*Ham xoa ki tu xuong dong sau khi dung fgets*/

void createAccount (){
	int currentSize;
	printf("Nhap so tai khoan muon them: "\n);
	scanf("%d", &newSize);
	if (currentSize > MAX || currentSize <= 0){
		printf("Khong hop le!!!\n");
		return;
	}
	for( int i=0; i < currentSize; i++ ){
		printf("|%-39s|\n", "Nhap thong tin tai khoan\n");
		printf("Nhap ma tai khoan: "\n);
		fgets(user[i].accountId, sizeof(user[i].accountId), stdin);
		deleteNewLine(user[i].accountId);
		printf("Nhap ho va ten chu tai khoan: "\n);
		fgets(user[i].fullName, sizeof(user[i].fullName), stdin);
		deleteNewLine(user[i].fullName);
		printf("Nhap so dien thoai: \n");
		fgets(user[i].phone, sizeof(user[i].phone), stdin);
		deleteNewLine(user[i].phone);
		printf("Nhap so du: \n");
		scanf("%d", &user[i].balance);
		fflush(stdin);
	}
	size = currentSize;
	printf("Da them tai khoan thanh cong!!!\n");
}

typedef struct {
	char transId[20];
	char senderId[20];
	char receiverId[20];
	double amount;
	char type[10];
	char date[20];
};

void printMenu (){
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
}

int main (){
	int choice;
	do{
	
	printf("Moi ban nhap lua chon: \n");
	scanf("%d", &choice);
	}
	while (choice !=9);
	return 0;	
}


