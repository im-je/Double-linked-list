// C butuh header
#include<stdio.h>
#include<stdlib.h>
//membuat struct
struct Node  {
	int data;
	struct Node* kanan; //menunjuk ke kiri
	struct Node* kiri; // menunjuk ke kanan
};

struct Node* kepala; 
struct Node* ekor=NULL;
float size,jmlh;// untuk membantu mencatat jumlah data nantinya

// buat new node 
struct Node* GetNodebaru(int x) {
	struct Node* nodebaru
		= (struct Node*)malloc(sizeof(struct Node));
	nodebaru->data = x;
	nodebaru->kiri = NULL;
	nodebaru->kanan = NULL;
	return nodebaru;
}

//Inserts  Node pada kepala (bagian depan)
void InsertPadaKepala(int x) {
	struct Node* nodebaru = GetNodebaru(x);
	if(kepala == NULL) {
		kepala = ekor= nodebaru;
		return;
	}else{
	kepala->kiri = nodebaru;
	nodebaru->kanan = kepala; 
	kepala = nodebaru;
	size++; //mencatat jumlah data jika node di tambahkan melalui kepala
}
}

//Inserts Node pada ekor (belakang)
void InsertPadaEkor(int x) {
	struct Node* temp = kepala;
	struct Node* nodebaru = GetNodebaru(x);
	if(kepala == NULL) {
		kepala = nodebaru;
		return;
	}
	while(temp->kanan != NULL) temp = temp->kanan; // menuju node terakhir
	temp->kanan = nodebaru;
	nodebaru->kiri = temp;
	size++;//mencatat jumlah data jika node ditambahkan melalui ekor
}

//insert node pada tengah
void InsertPadaTengah(int x){
	struct Node* nodebaru = GetNodebaru(x);
		nodebaru->data;
		if(kepala==NULL){
			kepala=ekor=nodebaru;
			kepala->kiri=NULL;
			ekor->kanan=NULL;
		}
		else{
			struct Node *current=kepala, *temp=NULL;
		//mencari bagian tengah dari node
			jmlh=size/2; //jumlah node bagi 2 untuk mencari bagian tengah
			for(int i=1;i<jmlh;i++){
				current=current->kanan;
			}
			temp=current->kanan;
			temp->kiri=current;
			current->kanan=nodebaru;
			nodebaru->kiri=current;
			nodebaru->kanan=temp;
			temp->kiri=nodebaru;
		size++;//mencatat jumlah data jika node ditambahkan melalui tengah
		}
		
}

//Prints semua data
void Print() {
	struct Node* temp = kepala;
	printf(" List data Node: ");
	while(temp != NULL) {
		printf(" %d, ",temp->data);
		temp = temp->kanan;
	}
	printf("\n\n");
}
//main
int main() {
	int pilihan,data;
	char lagi;
	
	while(lagi!='n'){
	printf(" MENU PILIHAN 	:\n");
	printf(" 1. Insert node di depan.\n 2. Insert node di belakang.\n");
	printf(" 3. Insert node di tengah.\n 4. Tampilkan data \n");
	printf(" \n Masukan pilihan : ");
	scanf(" %d",&pilihan);
//	system("cls"); //membersihkan perintah sebelumnya
	
	if(pilihan==1){
		printf(" Masukan node	: ");
		scanf("%d",&data);
		InsertPadaKepala(data);
		Print();
		printf("\n Insert node ke bagian depan sukses \n\n");
	printf(" Memasukan node lagi ? (Y/N)	: ");
	scanf("%s",&lagi);
	}
	else if(pilihan==2){
		printf(" Masukan node	: ");
		scanf("%d",&data);
		InsertPadaEkor(data);
		Print();
		printf("\n Insert node ke bagian belakang sukses \n\n");
	printf(" Memasukan node lagi ? (Y/N)	: ");
	scanf("%s",&lagi);
	}else if(pilihan==3){
		printf(" Masukan node	: ");
		scanf("%d",&data);
		InsertPadaTengah(data);
		Print();
		printf("\n Insert node ke bagian tengah sukses \n\n");
	printf(" Memasukan node lagi ? (Y/N)	: ");
	scanf("%s",&lagi);
	}else if(pilihan==4){
			printf("\n Tampilkan node \n\n");
			Print();
	}else {
		printf(" \nPilihan Tidak Tersedia\n\n");
	}
}
}
