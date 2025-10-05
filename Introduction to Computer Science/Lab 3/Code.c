#include <stdio.h>
#include <stdlib.h>

int main()
{
    //N: ucaklarin sayisi - k: dakika araligi - i: for dongusunde kullanilacak degisken
    int N,k,i;

    //N, k degerelerini kullanicidan talebi. Not N degeri pozitif ve sifirdan farki olmalidir:
    printf("Ucaklarin sayisini giriniz: ");
    scanf("%d",&N);
    while(N<=0){
        printf("Ucaklarin sayisini tekrar pozitif olarak giriniz: \n");
        scanf("%d",&N);
    }

    printf("\nIki ucak arasinda kalkis icin verilen dakika araligini giriniz: ");
    scanf("%d",&k);

    //ucakno: girilen ucaklarin numaralari - klkzmn: ucaklarin kalkis zamanlari
    int ucakno[N], klkzmn[N];

    //ucakno ve klkzmn dizilerin kullanicidan talebi:
    printf("\nUcaklarin numaralarini giriniz: \n");
    for(i=0;i<N;i++){
            scanf("%d",&ucakno[i]);
    }
    printf("\nUcaklarin kalkis zamanlarini giriniz ustteki ucaklarin sirasiyla giriniz: \n");
    for(i=0;i<N;i++){
        scanf("%d",&klkzmn[i]);
    }

    //klkzmn1: 1. piste atanan ucagin 1. pistten kalkis zamanini gosterir
    //klkzmn2: 2. piste atanan ucagin 2. pistten kalkis zamanini gosterir
    //sayac1: 1. pistin index
    //sayac2: 2. pistin index
    //gec1 1. pistteki ucagin kac dk gec kalkacagini gosterir
    //gec2 2. pistteki ucagin kac dk gec kalkacagini gosterir
    int Pist1[N],klkzmn1[N],Pist2[N],klkzmn2[N];
    int sayac1=0,sayac2=0;
    double gec1=0, gec2=0;


    // For Degiskeni:
    for(i=0;i<N;i++){
        //Ilk ucak 1. pistten verilen dk ucus yapacak
        if(sayac1==0){
            Pist1[sayac1]=ucakno[i];
            klkzmn1[sayac1]=klkzmn[i];
            sayac1++;
        }
        //Ikinci ucak 2. pistten verilen dk ucus yapacak
        else if(sayac2==0){
            Pist2[sayac2]=ucakno[i];
            klkzmn2[sayac2]=klkzmn[i];
            sayac2++;
        }
        //Eger ucak bir onceki ucak ile en az k suresi ile ucus yapacaksa en uygun piste atama yapilmasi.
		//Hangi iki pistte ucak daha once kalkiyorsa o piste atamak
        //ve mumkun oldugu kadar sureyi ertelememek
        //Eger bir sonraki ucak hemen ucacaksa (k suresinden daha az bir surede) o zaman ertelenir (bir alt kisimda)
        else if  (klkzmn[i] >= (klkzmn1[sayac1 - 1] + k) || klkzmn[i] >= (klkzmn2[sayac2 - 1] + k)) {
            if(klkzmn2[sayac2-1] > klkzmn1[sayac1-1]){
                Pist1[sayac1]=ucakno[i];
                klkzmn1[sayac1]=klkzmn[i];
                sayac1++;
                }
            else if(klkzmn2[sayac2-1] < klkzmn1[sayac1-1]){
                Pist2[sayac2]=ucakno[i];
                klkzmn2[sayac2]=klkzmn[i];
                sayac2++;
                }
                else{
                    if(sayac1>sayac2){
                        Pist2[sayac2]=ucakno[i];
                        klkzmn2[sayac2]=klkzmn[i];
                        sayac2++;
                    }
                    else{
                        Pist1[sayac1]=ucakno[i];
                        klkzmn1[sayac1]=klkzmn[i];
                        sayac1++;
                    }
                }
            }
        //k dakika araligindan daha az bir surede yapacak olan ucuslarin ertelenmesi ve gecikme dk (gec1 1. pistte gecikme ve gec2 2. pistte gecikme dakiklaridir) hesaplanmasi:
        else if (sayac1>sayac2){
            Pist2[sayac2]=ucakno[i];
            klkzmn2[sayac2]=klkzmn2[sayac2-1]+k;
            gec2 = gec2 + (klkzmn2[sayac2] - klkzmn[i]);
            sayac2++;
        }
        else{
            Pist1[sayac1]=ucakno[i];
            klkzmn1[sayac1]=klkzmn1[sayac1-1]+k;
            gec1 = gec1 + (klkzmn1[sayac1] - klkzmn[i]);
            sayac1++;
        }
    } //for dongusu bitisi

    // ortalama hesaplama (kesirli sayi oldugundan dolayi double kullandim)
    double ort1, ort2;
    ort1 = gec1/(sayac1);
    if(sayac2 != 0){
        ort2 = gec2/(sayac2);
    }


    // Sonuclari ekrana yazdirma

    printf("\nPist1_Ucaklar: ");
    for (i = 0; i < sayac1; i++) {
        printf("%d ", Pist1[i]);
    }

    printf("\nPist1_Saatler: ");
    for (i = 0; i < sayac1; i++) {
        printf("%d ", klkzmn1[i]);
    }

    printf("\nPist1 Ortalama Gecikme: %.4f\n", ort1);

    printf("\n\nPist2_Ucaklar: ");
    for (i = 0; i < sayac2; i++) {
        printf("%d ", Pist2[i]);
    }
    printf("\nPist2_Saatler: ");
    for (i = 0; i < sayac2; i++) {
        printf("%d ", klkzmn2[i]);
    }
    printf("\nPist2 Ortalama Gecikme: %.4f\n", ort2);

    return 0;
}
