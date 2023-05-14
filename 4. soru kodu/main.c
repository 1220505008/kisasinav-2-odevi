#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


struct node {//ba�l� listenin d���mlerinin tan�mlanmas� i�in bir struct yap�s� olu�turduk
    int data;
    struct node *next;
};

struct node *head = NULL;//bu, ba�l� listemizin ba�lang�� d���m�ne i�aret eden bir i�aret�i tan�mlar. Ba�lang��ta, liste bo� oldu�undan, i�aret�i NULL olarak ayarlad�k


void ekleme(int veri) {//ba�l� listeye eleman ekleme i�lemi yapt�k
    struct node *yeniDugum=(struct node*)malloc(sizeof(struct node));
    yeniDugum->data=veri;//yeniDugum i�aret�isi ile i�aret edilen bellek blo�unun data adl� eleman�na, veri adl� de�i�kenin de�erini atad�k
    yeniDugum->next=head;//yeniDugum i�aret�isi ile i�aret edilen bellek blo�unun next adl� eleman�na, head i�aret�isinin de�erini atad�k
    head=yeniDugum;//head i�aret�isinin de�erine, yeniDugum i�aret�isinin de�erini atad�k
    printf("%d degeri basariyla eklendi.\n",veri);
    printf("\n");//1sat�r bo�luk
}

void silme() {//ba�l� listeden eleman silme i�lemi yapt�k
    if (head==NULL){//e�er head=NULL ise,yani liste bo� ise, ekrana "Liste bos." yazd�rd�k ve fonksiyondan ��kt�k
        printf("Liste bos.\n");
        return;
    }
    struct node *temp=head;//ge�ici bir de�i�ken olan temp i�aret�isinin, head i�aret�isinin de�erini tutmas�n� sa�lad�k
    head=head->next;//head i�aret�isine, listenin ikinci eleman�n�n adresini atad�k
    printf("%d degeri silindi.\n",temp->data);
    printf("\n");//1 sat�r bo�luk
    free(temp);//bellek y�netimi i�in ayr�lan alan� serbest b�rakt�k
}

void goster() {//ba�l� listeden eleman g�sterme i�lemi yapt�k
    struct node *temp=head;
    if (temp==NULL){//temp=NULL ise listede eleman yoktur
        printf("Liste bos.\n");//"Liste bo�" mesaj�n� ekrana yazd�rd�k ve i�lem yapmay� sonland�rd�k
        printf("\n");//1sat�r bo�luk
		return;
    }
    printf("Liste elemanlari:");
    while (temp!=NULL){//D�ng�, temp=NULL olmad��� s�rece devam eder ve her ad�mda temp i�aret�isi,i�aret etti�i d���m�n veri eleman�n� ekrana yazd�rd�k ve bir sonraki d���me ge�mek i�in next i�aret�isini kulland�k
        printf("%d ",temp->data);//elemanlar� yazd�rd�k
        printf("\n");//1 sat�r bo�luk
        temp=temp->next;//temp i�aret�isinin �u an i�aret etti�i d���mden bir sonraki d���me ge�tik
    }
    printf("\n");//1 sat�r bo�luk b�rakt�k
}

int main() {
    int secim,veri;//de�i�kenleri tan�mlad�k
    while(1){//biz programdan ��k�� istemedi�imiz s�rece d�ng� sonsuza kadar devam eder
        printf("Lutfen asagidaki islemlerden birini seciniz:\n");
       	printf("\n");//1 sat�r bo�luk
	    printf("1.Ekleme\n2.Silme\n3.Goruntuleme\n4.Cikis\n");//i�lemleri yazd�rd�k
        printf("\n");//1 sat�r bo�luk
        printf("Seciminiz:");
		scanf("%d", &secim);//istenilen se�imi belirten say�y� klavyeden ald�k
        printf("\n");//1sat�r bo�luk
		
		switch(secim){//se�im de�erine g�re bir switch case tan�mlad�k
            case 1://1 se�ilirse
                printf("Eklemek istediginiz degeri giriniz:");
                scanf("%d",&veri);//eklenecek say�y� klavyeden ald�k
                ekleme(veri);//klavyedeen al�nan de�erle ekleme fonksiyonunu �al��t�rd�k
                break;
                
            case 2://2 se�ilirse
                silme();//silme fonksiyonu �al��t�rd�k
                break;
                
            case 3://3 se�ilirse
                goster();//g�ster fonksiyonunu �al��t�rd�k
                break;
                
            case 4://4 se�ilirse
                printf("Programdan cikildi.\n");
                exit(0);//program� sonland�rd�k
                
            default://1-4 harici say� girilirse
                printf("Hatali secim. Lutfen tekrar deneyin.\n");
        }
        
    }
    return 0;
}

