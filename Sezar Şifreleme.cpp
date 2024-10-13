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
	gets(metin);		//Kullanýcýdan metin aldýk
	int n=strlen(metin);	//Kullanýcýdan alýnan metnin boyutunu hesapladýk
	metin[n]='\0'; //gets metoduyla aldýðýmýz metnin n. harfinde ters slash sýfýr ile kapatalým enter'ý da saymasýn diye 
	cout<<"Metin: "<<metin<<endl;
	int i=0; int j;
	while(i<n){ //0'dan baþlýyor ya boyuttan küçük olmalý o yüzden
		int sonuc=0;
		for(j=0;j<26;j++){
			int indis=j;
			if(metin[i]==Alfabe[j]){ // metnin sýra sýra tüm alfabe harfleriyle denenmesi yapýlýyor
				sonuc=1;
				indis+=3; //Sezar þifrelemenin mantýðý her harfin üç saðýndaki harf ile deðiþtirilmesidir 
				if(indis>=26)
				indis =indis%26; //son üç harfte +3 yapýnca baþa dönmeli o yüzden indisin 26'ya bölümünden kalan deyip direkt ife girmeden hepsini hallettik
				SifreliMetin[i]=Alfabe[indis]; //Þifreleme iþlemini yaptýk
			}
			if(sonuc==0){
				SifreliMetin[i]=metin[i]; // ÞÝmdi sen bunu yapmazsan mesela kullanýcý özel karakter ya da sayý girdi o þifrelemeye dahil eldilmez olduðu gibi çýkactýr
										   // Yani yukarýda alfabe içinde bulamadýðýn her þeyin yerine olduðu gibi þifreli kýsma yaz demektir.
			}
			
		}
		i++;
	}
	SifreliMetin[i]='\0'; //i=n olduðu zaman yine kapatalým ki boþ kalan kýsmý enter olarak almasýn saçma deðerler üretilmesine sebep olur yapmazsan
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
