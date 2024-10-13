#include<iostream>
#include<cstdlib>
#include<cstring>
#include<clocale>
using namespace std;

class Sezar{
	private:
		char metin[1024];
		char SifreliMetin[1024];
		char DesifreliMetin[1024];
		char Alfabe[27]="abcdefghijklmnoqprstuvywxz";
	public:
		void sifrele();
		void defisrele();
};


void Sezar:: sifrele(){
	cout<<"Metin: ";
	gets(metin);		//Kullan�c�dan metin ald�k
	int n=strlen(metin);	//Kullan�c�dan al�nan metnin boyutunu hesaplad�k
	metin[n]='\0'; //gets metoduyla ald���m�z metnin n. harfinde ters slash s�f�r ile kapatal�m enter'� da saymas�n diye 
	cout<<"Metin: "<<metin<<endl;
	int i=0; int j;
	while(i<n){ //0'dan ba�l�yor ya boyuttan k���k olmal� o y�zden
		int sonuc=0;
		for(j=0;j<26;j++){
			int indis=j;
			if(metin[i]==Alfabe[j]){ // metnin s�ra s�ra t�m alfabe harfleriyle denenmesi yap�l�yor
				sonuc=1;
				indis+=3; //Sezar �ifrelemenin mant��� her harfin �� sa��ndaki harf ile de�i�tirilmesidir 
				if(indis>=26)
				indis =indis%26; //son �� harfte +3 yap�nca ba�a d�nmeli o y�zden indisin 26'ya b�l�m�nden kalan deyip direkt ife girmeden hepsini hallettik
				SifreliMetin[i]=Alfabe[indis]; //�ifreleme i�lemini yapt�k
			}
			if(sonuc==0){
				SifreliMetin[i]=metin[i]; // ��mdi sen bunu yapmazsan mesela kullan�c� �zel karakter ya da say� girdi o �ifrelemeye dahil eldilmez oldu�u gibi ��kact�r
										   // Yani yukar�da alfabe i�inde bulamad���n her �eyin yerine oldu�u gibi �ifreli k�sma yaz demektir.
			}
			
		}
		i++;
	}
	SifreliMetin[i]='\0'; //i=n oldu�u zaman yine kapatal�m ki bo� kalan k�sm� enter olarak almas�n sa�ma de�erler �retilmesine sebep olur yapmazsan
	cout<<"Sifrelenmis hali: "<<SifreliMetin<<endl;
}

void Sezar::defisrele(){
	int n=strlen(SifreliMetin);
	int i=0;
	int j=0;
	while(i<n){
		int sonuc=0;
		for(j=0;j<26;j++){
			int indis=j;
			if(SifreliMetin[i]==Alfabe[j]){
				sonuc=1;
				indis-=3;
				if(indis<0)
				indis=indis+26;
				DesifreliMetin[i]=Alfabe[indis];
			}
			if(sonuc==0){
				DesifreliMetin[i]=SifreliMetin[i];
			}
		}
		i++;
	}
	DesifreliMetin[i]='\0';
	cout<<"DesifleriMetin: "<<DesifreliMetin<<endl;
	
}

int main(){
	Sezar sezar;
	sezar.sifrele();
	sezar.defisrele();
	
	return 0;
}
