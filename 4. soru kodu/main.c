#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


struct node {//baðlý listenin düðümlerinin tanýmlanmasý için bir struct yapýsý oluþturduk
    int data;
    struct node *next;
};

struct node *head = NULL;//bu, baðlý listemizin baþlangýç düðümüne iþaret eden bir iþaretçi tanýmlar. Baþlangýçta, liste boþ olduðundan, iþaretçi NULL olarak ayarladýk


void ekleme(int veri) {//baðlý listeye eleman ekleme iþlemi yaptýk
    struct node *yeniDugum=(struct node*)malloc(sizeof(struct node));
    yeniDugum->data=veri;//yeniDugum iþaretçisi ile iþaret edilen bellek bloðunun data adlý elemanýna, veri adlý deðiþkenin deðerini atadýk
    yeniDugum->next=head;//yeniDugum iþaretçisi ile iþaret edilen bellek bloðunun next adlý elemanýna, head iþaretçisinin deðerini atadýk
    head=yeniDugum;//head iþaretçisinin deðerine, yeniDugum iþaretçisinin deðerini atadýk
    printf("%d degeri basariyla eklendi.\n",veri);
    printf("\n");//1satýr boþluk
}

void silme() {//baðlý listeden eleman silme iþlemi yaptýk
    if (head==NULL){//eðer head=NULL ise,yani liste boþ ise, ekrana "Liste bos." yazdýrdýk ve fonksiyondan çýktýk
        printf("Liste bos.\n");
        return;
    }
    struct node *temp=head;//geçici bir deðiþken olan temp iþaretçisinin, head iþaretçisinin deðerini tutmasýný saðladýk
    head=head->next;//head iþaretçisine, listenin ikinci elemanýnýn adresini atadýk
    printf("%d degeri silindi.\n",temp->data);
    printf("\n");//1 satýr boþluk
    free(temp);//bellek yönetimi için ayrýlan alaný serbest býraktýk
}

void goster() {//baðlý listeden eleman gösterme iþlemi yaptýk
    struct node *temp=head;
    if (temp==NULL){//temp=NULL ise listede eleman yoktur
        printf("Liste bos.\n");//"Liste boþ" mesajýný ekrana yazdýrdýk ve iþlem yapmayý sonlandýrdýk
        printf("\n");//1satýr boþluk
		return;
    }
    printf("Liste elemanlari:");
    while (temp!=NULL){//Döngü, temp=NULL olmadýðý sürece devam eder ve her adýmda temp iþaretçisi,iþaret ettiði düðümün veri elemanýný ekrana yazdýrdýk ve bir sonraki düðüme geçmek için next iþaretçisini kullandýk
        printf("%d ",temp->data);//elemanlarý yazdýrdýk
        printf("\n");//1 satýr boþluk
        temp=temp->next;//temp iþaretçisinin þu an iþaret ettiði düðümden bir sonraki düðüme geçtik
    }
    printf("\n");//1 satýr boþluk býraktýk
}

int main() {
    int secim,veri;//deðiþkenleri tanýmladýk
    while(1){//biz programdan çýkýþ istemediðimiz sürece döngü sonsuza kadar devam eder
        printf("Lutfen asagidaki islemlerden birini seciniz:\n");
       	printf("\n");//1 satýr boþluk
	    printf("1.Ekleme\n2.Silme\n3.Goruntuleme\n4.Cikis\n");//iþlemleri yazdýrdýk
        printf("\n");//1 satýr boþluk
        printf("Seciminiz:");
		scanf("%d", &secim);//istenilen seçimi belirten sayýyý klavyeden aldýk
        printf("\n");//1satýr boþluk
		
		switch(secim){//seçim deðerine göre bir switch case tanýmladýk
            case 1://1 seçilirse
                printf("Eklemek istediginiz degeri giriniz:");
                scanf("%d",&veri);//eklenecek sayýyý klavyeden aldýk
                ekleme(veri);//klavyedeen alýnan deðerle ekleme fonksiyonunu çalýþtýrdýk
                break;
                
            case 2://2 seçilirse
                silme();//silme fonksiyonu çalýþtýrdýk
                break;
                
            case 3://3 seçilirse
                goster();//göster fonksiyonunu çalýþtýrdýk
                break;
                
            case 4://4 seçilirse
                printf("Programdan cikildi.\n");
                exit(0);//programý sonlandýrdýk
                
            default://1-4 harici sayý girilirse
                printf("Hatali secim. Lutfen tekrar deneyin.\n");
        }
        
    }
    return 0;
}

