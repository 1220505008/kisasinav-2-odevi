#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	//a) Dizinin boyutunu ve elemanlar�n� kullan�c�dan isteyiniz.
    int n,aranan,i;//gerekli de�i�kenleri tan�mlad�k
    printf("Dizinin boyutunu girin:");
    scanf("%d",&n);//dizinin boyutunu ifade eden say�y� klavyeden ald�k
    
    int dizi[n];//girilen say� de�erine g�re bir dizi tan�mlad�k
    printf("%d eleman girin:\n", n);
    for(i=0;i<n;i++){//girdi�imiz n de�eri kadar say� istememiz gerekti�inden bir d�ng� kurduk
        scanf("%d",&dizi[i]);//her d�ng�de dizinin elemanlar�n� klavyeden ald�k
    }
    
    //b) Dizide aranacak olan eleman� kullan�c�dan isteyiniz.
    printf("Aranacak elemani girin:");
    scanf("%d",&aranan);//aranacak eleman� klavyeden ald�k
    
    //c) Aran�lan eleman�n dizide olup olmad���n�n kontrol�n� Linear Search kullanarak yap�n�z.
    for(i=0;i<n;i++){//aranan eleman� bulmak i�in dizinin elemanlar�n� s�ras�yla kontrol edebilecek bir d�ng� yapt�k
        if(dizi[i]==aranan){//aranan eleman� dizide bulunca a�a��daki d�ng� devreye girecek ve eleman�n bulundu�u ifade edilecek
            printf("%d,dizinin %d indisinde bulundu\n",aranan,i);
            break;
        }
    }
    
    if(i==n){////aranan eleman bulunamazsa a�a��daki d�ng� devreye girecek ve eleman�n bulunamad��� ifade edilecek
        printf("%d dizide bulunamadi\n",aranan);
    }
    
    
    return 0;
}

