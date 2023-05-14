#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int compare(const void*a,const void*b) {//elemanlarý karþýlaþtýrmak için bir fonksiyon tanýmladýk
    int x = *(const int*)a;//a isimli iþaretçinin gösterdiði bellek adresindeki int tipindeki deðeri okuyarak, x isimli bir deðiþkene atadýk
    int y = *(const int*)b;//b isimli iþaretçinin gösterdiði bellek adresindeki int tipindeki deðeri okuyarak, y isimli bir deðiþkene atadýk
    if (x < y) return -1;//x < y ise -1 döndür
    else if (x > y) return 1;//x > y ise 1 döndür
    else return 0;//x=y ise 0 döndür
}

int binary_search(int dizi[],int aranan,int sol,int sag){//sýraladýðýmýz dizide aranan sayýyý bulana kadar ortanca elemaný kontrol eden fonksiyon tanýmladýk
    if(sag>=sol){//Eðer sað>=sol ise aranan elemanýn dizide olabileceði bir aralýk var demektir. Bu nedenle, aramaya devam edilir
        int orta=sol+(sag-sol)/2;//"orta" deðiþkeni, arama aralýðýndaki elemanlarý karþýlaþtýrmak için kullanýlýr ve böylece aranan elemanýn sol veya sað yarýsýnda olup olmadýðý belirlenir
        if(dizi[orta]==aranan){//Eðer orta noktasýndaki eleman aranan deðerle eþitse, fonksiyon orta noktanýn dizindeki indeksini döndürür
            return orta;
        }
        if(dizi[orta]>aranan){//Eðer orta noktasýndaki eleman aranan deðerden büyükse, arama sol tarafa devam eder
            return binary_search(dizi, aranan, sol, orta - 1);
        }
        return binary_search(dizi, aranan, orta + 1, sag);//Eðer orta noktasýndaki eleman aranan deðerden küçükse, arama sað tarafa devam eder
    }
    return -1;//Eðer aranan deðer dizide bulunamazsa, fonksiyon -1 döndürür
}

int main() {
    int dizi[]={4,8,3,84,47,76,9,24,68};//bize verilen dizi
    int uzunluk=sizeof(dizi)/sizeof(dizi[0]);//dizinin eleman sayýsýný hesapladýk
    qsort(dizi,uzunluk,sizeof(int),compare);//bu fonksiyon ile elemanlarý küçükten büyüðe doðru sýraladýk
    int aranan;//aranacak sayý tanýmladýk
    printf("Lutfen aranacak sayiyi giriniz: ");
    scanf("%d", &aranan);//aranacak sayýyý klavyeden aldýk

    int sonuc=binary_search(dizi,aranan,0,uzunluk-1);
    if (sonuc == -1) {//sýralanmýþ dizi içinde aranan sayý bulunamazsa
        printf("Aranan sayi dizide bulunamadi.");//aranan sayýnýn dizide bulunamadýðýný ifade ettik
    } else {//sýralanmýþ dizi içinde aranan sayý bulunursa
        printf("Aranan sayi dizinin %d. indeksinde bulundu.", sonuc);//bulunduðu dizin numarasýný (indeksini) döndürdük
    }
    return 0;
}

