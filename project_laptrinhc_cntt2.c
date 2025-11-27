#include <stdio.h>
#include <string.h>
#define MAX_ACC 100
#define MAX_TRANS 1000

struct Account {
    char accountId[20];
    char fullName[50];
    char phone[15];
    double balance;
    int status; /* 1: dang hoat dong, 0: bi khoa */
};

struct Transaction {
    char transId[20];
    char senderId[20];
    char receiverId[20];
    double amount;
    char type[10];
    char date[20];
};

struct Account accounts[MAX_ACC] = {
    {"1", "Nguyen Van A", "0901000001", 5000000, 1},
    {"2", "Tran Thi B",   "0901000002", 1250000, 1},
    {"3", "Le Van C",     "0901000003", 300000, 0},
    {"4", "Pham Thi D",   "0901000004", 9900000, 1},
    {"5", "Hoang Van E",  "0901000005", 50000, 1},
    {"6", "Do Thi F",     "0901000006", 12000000, 1},
    {"7", "Ngo Van G",    "0901000007", 450000, 1},
    {"8", "Vu Thi H",     "0901000008", 880000, 1},
    {"9", "Dang Van I",   "0901000009", 0, 1},
    {"10", "Bui Thi K",    "0901000010", 6700000, 1},
    {"11", "Ly Van L",     "0901000011", 230000, 1},
    {"12", "Truong Thi M", "0901000012", 1500000, 0},
    {"13", "Dinh Van N",   "0901000013", 7800000, 1},
    {"14", "Lam Thi O",    "0901000014", 90000, 1},
    {"15", "Phan Van P",   "0901000015", 3400000, 1},
    {"16", "Cao Thi Q",    "0901000016", 120000, 1},
    {"17", "Ha Van R",     "0901000017", 5600000, 1},
    {"18", "Trinh Thi S",  "0901000018", 2100000, 1},
    {"19", "Mai Van T",    "0901000019", 4000000, 1},
    {"20", "Duong Thi U",  "0901000020", 890000, 1}
};
int accCount = 20; 

struct Transaction transactions[MAX_TRANS];
int transCount = 0; // chua co giao dich

void clearBuffer();
int findIndexById(char *id);
int isPhoneDuplicate(char *phone, char *excludeId);
// cac ham chuc nang phu 

void addAccount();
void updateAccount();
void lockAccount();
void searchAccount();
void listAccounts();
void sortAccounts();
void transferMoney();
void transactionHistory();

int main() {
    int choice;
    do {
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
    	printf("|%-37s|\n", "0. Thoat chuong trinh");
    	printf("+-------------------------------------+\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: 
				addAccount(); 
				break;
            case 2: 
				updateAccount(); 
				break;
            case 3: 
				lockAccount(); 
				break;
            case 4: 
				searchAccount(); 
				break;
            case 5: 
				listAccounts(); 
				break;
            case 6: 
				sortAccounts(); 
				break;
            case 7: 
				transferMoney(); 
				break;
            case 8: 
				transactionHistory(); 
				break;
            case 0: 
				printf("Thoat chuong trinh\n"); 
				break;
            default: 
				printf("Chuc nang khong hop le!\n");
        }
    } while (choice != 0);
    return 0;
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != '\0');
} // xoa kí tu xuong dong

int findIndexById(char *id) {
    int i;
    for (i = 0; i < accCount; i++) {
        if (strcmp(accounts[i].accountId, id) == 0) 
		return i;
    }
    return -1;
} // ham tìm kiem id

int isPhoneDuplicate(char *phone, char *excludeId) {
    int i;
    for (i = 0; i < accCount; i++) {
        if (strcmp(accounts[i].accountId, excludeId) != 0 && 
            strcmp(accounts[i].phone, phone) == 0) {
            return 1;
        }
    }
    return 0;
} // ham kiem tra trung lap

void addAccount() {
    struct Account newAcc;
    int valid = 0;
    
    if (accCount >= MAX_ACC) {
        printf("!! Danh sach da day.\n"); 
		return;
    }
    printf("\nThem tai khoan moi: \n");
    clearBuffer();

    while (!valid) {
        printf("Nhap ID: ");
        scanf("%s", newAcc.accountId);
        if (findIndexById(newAcc.accountId) != -1){
        	printf("!! ID da ton tai.\n");
		} 
        else {
        	valid = 1;
		}
    }
    clearBuffer();
    
    valid = 0;
    printf("Nhap Ho Ten: ");
    fgets(newAcc.fullName, 50, stdin);
    newAcc.fullName[strcspn(newAcc.fullName, "\n")] = 0;

    while (!valid) {
        printf("Nhap so dien thoai: ");
        scanf("%s", newAcc.phone);
        if (isPhoneDuplicate(newAcc.phone, "")){
        	printf("!! So dien thoai da ton tai.\n");
		} else {
			valid = 1;
		}
    }

    newAcc.balance = 0; 
	newAcc.status = 1; 
    accounts[accCount++] = newAcc;
    printf("=> Them thanh cong!!!\n");
}

void updateAccount() {
    char id[20], tempName[50], tempPhone[15];
    int idx;
    
    printf("\nCap nhat thong tin\n");
    printf("Nhap ID can sua: "); 
	scanf("%s", id);
    idx = findIndexById(id);
    if (idx == -1) { 
		printf("!! Khong tim thay ID.\n"); 
		return; 
		}
    clearBuffer();
    
    printf("Nhap Ten moi: %s): ", accounts[idx].fullName);
    fgets(tempName, 50, stdin);
    tempName[strcspn(tempName, "\n")] = 0;
    if (strlen(tempName) > 0) {
    	strcpy(accounts[idx].fullName, tempName);
	}
    printf("Nhap SDT moi (Hien tai: %s): ", accounts[idx].phone);
    scanf("%s", tempPhone);
    if (isPhoneDuplicate(tempPhone, accounts[idx].accountId)){
    	printf("So dien thoai da duoc su dung o tai khoan khac.\n");
	} 
    else {
        strcpy(accounts[idx].phone, tempPhone);
        printf("=> Cap nhat thanh cong!\n");
    }
}

void lockAccount() {
    char id[20];
    int idx;
    printf("\nThay doi trang thai tai khoan\n");
    printf("Nhap ID: ");
	scanf("%s", id);
    idx = findIndexById(id);
    if (idx != -1) {
        accounts[idx].status = !accounts[idx].status;
        printf("=> Trang thai moi: %s\n", accounts[idx].status ? "Hoat dong" : "Da khoa");
    } else printf("!! Khong tim thay ID.\n");
}

// ham chuyen doi ki chu chu
void convertToLower(char *src, char *dest) {
    int i = 0;
    while (src[i] != '\0') {
        if (src[i] >= 'A' && src[i] <= 'Z') {
            dest[i] = src[i] + 32;
        } else {
            dest[i] = src[i];
        }
        i++;
    }
    dest[i] = '\0';
}

/* F04: Tra cuu thong tin (Khong phan biet chu hoa/thuong) */
void searchAccount() {
    int choice;
    char keyword[50];      /* Tu khoa nguoi dung nhap */
    char keywordLower[50]; /* Tu khoa da chuyen ve chu thuong */
    char dataLower[50];    /* Du lieu (Ten/ID) da chuyen ve chu thuong */
    int i, found = 0;

    printf("\n--- TRA CUU THONG TIN ---\n");
    printf("1. Tim theo ID\n");
    printf("2. Tim theo Ten\n");
    printf("Chon phuong thuc (1 hoac 2): ");
    scanf("%d", &choice);
    clearBuffer();

    /* Nhap tu khoa */
    if (choice == 1) {
        printf("Nhap ID can tim: ");
        scanf("%s", keyword);
    } else if (choice == 2) {
        printf("Nhap Ten can tim: ");
        fgets(keyword, 50, stdin);
        keyword[strcspn(keyword, "\n")] = 0;
    } else {
        printf("!! Lua chon khong hop le.\n");
        return;
    }

    /* B1: Chuyen tu khoa nguoi dung nhap sang chu thuong */
    convertToLower(keyword, keywordLower);

    /* In header bang ket qua */
    printf("\n%-10s | %-25s | %-15s | %-15s | %-10s\n", 
           "ID", "Ho va Ten", "So Dien Thoai", "So Du", "Trang Thai");
    printf("--------------------------------------------------------------------------------------\n");

    /* B2: Duyet mang va so sanh */
    for (i = 0; i < accCount; i++) {
        int match = 0;
        
        if (choice == 1) {
            /* Tim theo ID: Chuyen ID trong data sang chu thuong de so sanh */
            convertToLower(accounts[i].accountId, dataLower);
            
            /* So sanh chinh xac */
            if (strcmp(dataLower, keywordLower) == 0){
            	match = 1;
			} 
        } else {
            /* Tim theo Ten: Chuyen Ten trong data sang chu thuong */
            convertToLower(accounts[i].fullName, dataLower);
            /* So sanh gan dung (tim chuoi con) */
            if (strstr(dataLower, keywordLower) != NULL){
            	match = 1;
			} 
        }

        if (match) {
            printf("%-10s | %-25s | %-15s | %-15.2lf | %-10s\n", 
                   accounts[i].accountId, 
                   accounts[i].fullName, 
                   accounts[i].phone, 
                   accounts[i].balance, 
                   accounts[i].status == 1 ? "Open" : "Lock");
            found = 1;
        }
    }
    printf("--------------------------------------------------------------------------------------\n");
    if (!found) printf("(Khong tim thay ket qua nao phu hop)\n");
}

/* F05: Hien thi danh sach phan trang, co so trang/tong so trang, chon y/n */
void listAccounts() {
    int i;
    int page = 1;
    int rowsPerPage = 10; /* So dong tren 1 trang */
    int totalPages;
    char choice;
    
    /* Tinh tong so trang: (Tong + so_dong - 1) / so_dong */
    if (accCount == 0) totalPages = 1;
    else totalPages = (accCount + rowsPerPage - 1) / rowsPerPage;

    while (page <= totalPages) {
        /* Xoa man hinh (tuong trung) bang cach xuong dong nhieu lan hoac in header moi */
        printf("\nDanh sach tai khoan(Trang %d / %d)\n", page, totalPages);
        printf("%-10s | %-20s | %-15s | %-15s | %-10s\n", 
               "ID", "Ho va Ten", "So Dien Thoai", "So Du", "Trang Thai");
        printf("----------------------------------------------------------------------------------\n");
        
        /* Tinh vi tri bat dau va ket thuc cua trang hien tai */
        int start = (page - 1) * rowsPerPage;
        int end = start + rowsPerPage;
        if (end > accCount) end = accCount; /* Gioi han khong vuot qua tong so */

        for (i = start; i < end; i++) {
            printf("%-10s | %-20s | %-15s | %-15.2lf | %-10s\n", 
                   accounts[i].accountId, 
                   accounts[i].fullName, 
                   accounts[i].phone, 
                   accounts[i].balance,
                   accounts[i].status == 1 ? "Dang hoat dong" : "Dang bi khoa");
        }
        printf("----------------------------------------------------------------------------------\n");
        
        /*thao tac chuyen trang */
        if (page == totalPages) {
            printf("[THONG BAO] Da hien thi het danh sach.\n");
            break; /* Het trang thi thoat vong lap */
        } else {
            printf("Tiep tuc xem trang sau? (y: Co, n: Khong): ");
            
            /* Doc ky tu va bo qua khoang trang/xuong dong thua */
            scanf(" %c", &choice); 
            
            if (choice == 'n' || choice == 'N') {
                break; /* Nguoi dung chon thoat */
            } else if (choice == 'y' || choice == 'Y') {
                page++; /* Tang so trang len 1 */
            } else {
                printf("Lua chon khong hop le, tu dong thoat xem.\n");
                break;
            }
        }
    }
}

void sortAccounts() {
    int choice, i, j;
    struct Account temp; //tao mang luu gia tri de luu tam gia tri khi sap xep doi vi tri
    printf("\nSap xep\n 1. Ten (A-Z)\n 2. So du (Giam dan)\n Chon: ");
    scanf("%d", &choice);
    for (i = 0; i < accCount - 1; i++) {
        for (j = i + 1; j < accCount; j++) {
            int swap = 0;
                if (choice == 1 && strcmp(accounts[i].fullName, accounts[j].fullName) > 0){
            	swap = 1;
			}
            if (choice == 2 && accounts[i].balance < accounts[j].balance) {
            	swap = 1;
			}
            if (swap){
                temp = accounts[i]; 
				accounts[i] = accounts[j]; 
				accounts[j] = temp;
            }
        }
    }
    printf("=> Da sap xep xong.\n");
}

void transferMoney() {
    char sId[20], rId[20];
    double amount;
    int sIdx, rIdx;
    struct Transaction t;
    
    printf("\nThuc hien giao dich\n");
    printf("ID Nguoi Gui: "); 
	scanf("%s", sId);
    printf("ID Nguoi Nhan: "); 
	scanf("%s", rId);
    
    sIdx = findIndexById(sId); 
	rIdx = findIndexById(rId);
    if (sIdx == -1 || rIdx == -1) { 
	printf("!! ID khong ton tai.\n"); 
	return; 
	}
    if (!accounts[sIdx].status || !accounts[rIdx].status) { 
		printf("!! Tai khoan bi khoa.\n"); 
	return; 
	}
    
    printf("Nhap so tien: "); 
	scanf("%lf", &amount);
    if (amount <= 0 || accounts[sIdx].balance < amount) { 
		printf("!! So du khong du.\n"); 
	return; 
	}
    
    accounts[sIdx].balance -= amount;
    accounts[rIdx].balance += amount;
    
    sprintf(t.transId, "TR%04d", transCount + 1);
    strcpy(t.senderId, sId); 
	strcpy(t.receiverId, rId);
    t.amount = amount; 
	strcpy(t.type, "Transfer"); 
	strcpy(t.date, "Today"); 
    transactions[transCount++] = t;
    
    printf("=> Chuyen tien thanh cong! Ma GD: %s\n", t.transId);
}

void transactionHistory() {
    char id[20];
    int i, found = 0;
    printf("\nLich su thanh toan\n");
    printf("Nhap ID can xem: "); scanf("%s", id);
    printf("%-10s %-10s %-10s %-15s %s\n", "Ma GD", "Gui", "Nhan", "So Tien", "Loai");
    for (i = 0; i < transCount; i++) {
        if (strcmp(transactions[i].senderId, id) == 0 || strcmp(transactions[i].receiverId, id) == 0) {
            printf("%-10s %-10s %-10s %-15.0lf %s\n", 
                transactions[i].transId, transactions[i].senderId, transactions[i].receiverId, 
                transactions[i].amount, transactions[i].type);
            found = 1;
        }
    }
    if (!found) printf("(Chua co giao dich nao)\n");
}
