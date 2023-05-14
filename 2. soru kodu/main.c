#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int compare(const void*a,const void*b) {//elemanlar� kar��la�t�rmak i�in bir fonksiyon tan�mlad�k
    int x = *(const int*)a;//a isimli i�aret�inin g�sterdi�i bellek adresindeki int tipindeki de�eri okuyarak, x isimli bir de�i�kene atad�k
    int y = *(const int*)b;//b isimli i�aret�inin g�sterdi�i bellek adresindeki int tipindeki de�eri okuyarak, y isimli bir de�i�kene atad�k
    if (x < y) return -1;//x < y ise -1 d�nd�r
    else if (x > y) return 1;//x > y ise 1 d�nd�r
    else return 0;//x=y ise 0 d�nd�r
}

int binary_search(int dizi[],int aranan,int sol,int sag){//s�ralad���m�z dizide aranan say�y� bulana kadar ortanca eleman� kontrol eden fonksiyon tan�mlad�k
    if(sag>=sol){//E�er sa�>=sol ise aranan eleman�n dizide olabilece�i bir aral�k var demektir. Bu nedenle, aramaya devam edilir
        int orta=sol+(sag-sol)/2;//"orta" de�i�keni, arama aral���ndaki elemanlar� kar��la�t�rmak i�in kullan�l�r ve b�ylece aranan eleman�n sol veya sa� yar�s�nda olup olmad��� belirlenir
        if(dizi[orta]==aranan){//E�er orta noktas�ndaki eleman aranan de�erle e�itse, fonksiyon orta noktan�n dizindeki indeksini d�nd�r�r
            return orta;
        }
        if(dizi[orta]>aranan){//E�er orta noktas�ndaki eleman aranan de�erden b�y�kse, arama sol tarafa devam eder
            return binary_search(dizi, aranan, sol, orta - 1);
        }
        return binary_search(dizi, aranan, orta + 1, sag);//E�er orta noktas�ndaki eleman aranan de�erden k���kse, arama sa� tarafa devam eder
    }
    return -1;//E�er aranan de�er dizide bulunamazsa, fonksiyon -1 d�nd�r�r
}

int main() {
    int dizi[]={4,8,3,84,47,76,9,24,68};//bize verilen dizi
    int uzunluk=sizeof(dizi)/sizeof(dizi[0]);//dizinin eleman say�s�n� hesaplad�k
    qsort(dizi,uzunluk,sizeof(int),compare);//bu fonksiyon ile elemanlar� k���kten b�y��e do�ru s�ralad�k
    int aranan;//aranacak say� tan�mlad�k
    printf("Lutfen aranacak sayiyi giriniz: ");
    scanf("%d", &aranan);//aranacak say�y� klavyeden ald�k

    int sonuc=binary_search(dizi,aranan,0,uzunluk-1);
    if (sonuc == -1) {//s�ralanm�� dizi i�inde aranan say� bulunamazsa
        printf("Aranan sayi dizide bulunamadi.");//aranan say�n�n dizide bulunamad���n� ifade ettik
    } else {//s�ralanm�� dizi i�inde aranan say� bulunursa
        printf("Aranan sayi dizinin %d. indeksinde bulundu.", sonuc);//bulundu�u dizin numaras�n� (indeksini) d�nd�rd�k
    }
    return 0;
}

