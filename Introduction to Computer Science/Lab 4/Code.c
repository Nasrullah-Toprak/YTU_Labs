#include <stdio.h>

int main() {
	
	/*
	N: matrisin satir sayisi
	M: matrisin sutun sayisi
	i ve j donguler icin
	A matrisi kullanicinin girecegi matris
	yeni_i ve yeni_j: yolla devam ederken degisen degiskenler
	yol_no: Takip edilecek yolun numarasi
	sayac: yolun uzunlugunu bulmak
	bitis: eger kopukluk olursa donguden cikma ve sonucu yazdirmama
	*/
	int N, M, i, j;
	int A[100][100];
	int yeni_i, yeni_j, yol_no, sayac, bitis=0;

    //Matrisi kullanicidan talebi
    printf("Matrisin satir sayisini giriniz: ");
    scanf("%d",&N);
    printf("Matrisin sutun sayisini giriniz: ");
	scanf("%d",&M);
	
	printf("Matrisi giriniz: \n");
	for (i=0;i<N;i++){
		for (j=0;j<M;j++){
			scanf("%d",&A[i][j]);
		}
	}
	
	printf("\n");
	
	//Ilk sutunu taramak. Eger ilk sutundaki deger sifirdan farkli ise o zaman sayaci baslatmak	
	i=0;
	while (i<N){
		if (A[i][0] !=0){
			sayac = 1;
			yol_no = A[i][0];
			yeni_i=i;
			yeni_j=0;
			while (yeni_i<N && yeni_i>=0 && yeni_j<M && yeni_j>=0 && bitis==0){ //degiskenlerin matrisin disina cikmamasi icin onlem
				A[yeni_i][yeni_j]=0;
				//Sag kontrol:
				if(yeni_j+1<M && A[yeni_i][yeni_j+1]==yol_no){
					sayac++;
					yeni_j++;
				}
				//Sol kontrol:
				else if (yeni_j-1>=0 && A[yeni_i][yeni_j-1]==yol_no) {
					sayac++;
					yeni_j--;
				}
				//Yukari kontrol:
				else if (yeni_i-1>=0 && A[yeni_i-1][yeni_j]==yol_no) {
					sayac++;
					yeni_i--;
				}
				//Asagi kontrol:
				else if (yeni_i+1<N && A[yeni_i+1][yeni_j]==yol_no) {
					sayac++;
					yeni_i++;
				}
				//Sag yukari kontrol:
				else if (yeni_i-1>=0 && yeni_j+1<M && A[yeni_i-1][yeni_j+1]==yol_no) {
					sayac++;
					yeni_i--;
					yeni_j++;
				}
				//Sag asagi kontrol:
				else if (yeni_i+1<N && yeni_j+1<M && A[yeni_i+1][yeni_j+1]==yol_no){
					sayac++;
					yeni_i++;
					yeni_j++;
				}
				//Sol yukari kontrol:
				else if (yeni_i-1>=0 && yeni_j-1>=0 && A[yeni_i-1][yeni_j-1]==yol_no)  {
					sayac++; 
					yeni_i--;
					yeni_j--;
				}
				//Sol asagi kontrol:
				else if (yeni_i+1<N && yeni_j-1>=0 && A[yeni_i+1][yeni_j-1]==yol_no){
					sayac++;
					yeni_i++;
					yeni_j--;
				}
				//kopukluk varsa donguden cik
				else {
					bitis=1;
				}	
			}
			if (bitis!=0 && sayac>0 && yeni_j==M-1){ //Yolun sonuna varildigi an sonucu yazdirmak
				printf("Yol %d -> Uzunluk %d\n",yol_no,sayac);
			}
		}
		i++;
		bitis=0; // Eger bir onceki deger (yol_no) icin kopukluk olduysa bitis degerini tekrar sifirlamak		
	}
	
	return 0;
}

