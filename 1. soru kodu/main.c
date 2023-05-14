#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	//a) Dizinin boyutunu ve elemanlarýný kullanýcýdan isteyiniz.
    int n,aranan,i;//gerekli deðiþkenleri tanýmladýk
    printf("Dizinin boyutunu girin:");
    scanf("%d",&n);//dizinin boyutunu ifade eden sayýyý klavyeden aldýk
    
    int dizi[n];//girilen sayý deðerine göre bir dizi tanýmladýk
    printf("%d eleman girin:\n", n);
    for(i=0;i<n;i++){//girdiðimiz n deðeri kadar sayý istememiz gerektiðinden bir döngü kurduk
        scanf("%d",&dizi[i]);//her döngüde dizinin elemanlarýný klavyeden aldýk
    }
    
    //b) Dizide aranacak olan elemaný kullanýcýdan isteyiniz.
    printf("Aranacak elemani girin:");
    scanf("%d",&aranan);//aranacak elemaný klavyeden aldýk
    
    //c) Aranýlan elemanýn dizide olup olmadýðýnýn kontrolünü Linear Search kullanarak yapýnýz.
    for(i=0;i<n;i++){//aranan elemaný bulmak için dizinin elemanlarýný sýrasýyla kontrol edebilecek bir döngü yaptýk
        if(dizi[i]==aranan){//aranan elemaný dizide bulunca aþaðýdaki döngü devreye girecek ve elemanýn bulunduðu ifade edilecek
            printf("%d,dizinin %d indisinde bulundu\n",aranan,i);
            break;
        }
    }
    
    if(i==n){////aranan eleman bulunamazsa aþaðýdaki döngü devreye girecek ve elemanýn bulunamadýðý ifade edilecek
        printf("%d dizide bulunamadi\n",aranan);
    }
    
    
    return 0;
}

