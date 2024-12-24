#include<stdio.h>
struct shop{
	int id;
	int slsp;
	char name[40];
	float inpPritch;
	float outPritch;
};
void jung(struct shop pee[],int size);
void jungz(struct shop pee[],int size);
void jungen(struct shop pee[],int size,int n);
int main(){
	int n;
	int chose;
	int size=0;
	struct shop pee[50];
	do{
		printf("menu \n");
        printf("1. Nhap so luong va thong tin san pham\n");
        printf("2. hien thi thong tin san pham\n");
        printf("3. nhap san pham\n");
        printf("4. cap nhat thong tin san pham\n");
        printf("5. Sap xep san pham theo gia\n");
        printf("6. tim kiem san pham\n");
        printf("7. ban san pham\n");
        printf("8. Thoat\n");
        printf("Hay chon chuc nang (1-8): ");
        scanf("%d", &chose);
        switch(chose){
        	case 1:
        		printf("Moi ban nhap so luong san pham : ");
        		scanf("%d",&size);
        		jung(pee ,size);
        		break;
        	case 2:
        		jungz(pee,size);
        		break;
        	case 3:
        		break;
        	case 4:
        		break;
        	case 5:
        		break;
        	case 6:
        		break;
        	case 7:
        		break;
        	case 8:
        		break;	
        	default:
        		return 0;
		}
	}while(chose!=8);
  return 0;
}
	void jung(struct shop pee[],int size){
	int i;
	for(i=0;i<size;i++){
		printf("Moi ban nhap thong tin san pham %d \n",i+1);
		printf("Ma san pham : ");
		scanf("%d", &pee[i].id);
		fflush(stdin);
		printf("Ten san pham : ");
		fgets(pee[i].name,sizeof(pee[i].name),stdin);
		printf("So luong san pham: ");
        scanf("%d", &pee[i].slsp);
        printf("Gia nhap san pham:");
        scanf("%f", &pee[i].inpPritch);
        printf("Gia ban san pham: ");
        scanf("%f", &pee[i].outPritch);
        getchar();
	}
}
	void displaySt(struct shop pee[],int size){
	int i;
	for(i = 0;i < size;i++){
		printf("San phan %d :",i);
		printf("Ma san pham %d ", pee[i].id);
		printf("Ten san pham %d ", pee[i].name);
		printf("Gia san pham %d ", pee[i].outPritch);
		
	}
}
void moreSt(struct shop pee[],int size,int n){
	printf("Moi ban nhap vi tri muon them so luong");
	scanf("%d",&n);
	if(n < 0 || n > size){
		printf("Vi tri ban nhap khong co trong cua hang");
	}
	int i;
	n=pee;
	for(i=0;i<size;i++){
		printf("Them so luong san phan : ");
		scanf("%d", &pee[i].slsp);
		}
	return 0;
}
