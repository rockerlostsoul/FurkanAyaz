#include<conio.h>
#include<math.h>
#define MAX 20 //Bu max deðeri matrisimiz için oluþturduðumuz elemanlarýn deðeridir.Yani max 20 derseniz maksimum 20 satýrlý veya 20 sütunlu matris oluþturabilirsiniz anlamýna geliyor.
#include <locale.h>
int determinant(int a[MAX][MAX],int n);
int main() //Ana fonksiyonumuz.
{
setlocale(LC_ALL, "Turkish");  //Türkçe karakter sorunu olmamasý için eklediðimiz kod.
 int i,j,r,c,a[MAX][MAX],b[MAX][MAX],deter=0;
 
 printf("\nLütfen matrisin satýr sayýsýný giriniz= "); //Burada matrisimizin kaça kaçlýk olacaðýný giriyoruz.Sütun ve satýr sayýsýnýn eþit olmasý yani kare matris olmasý gerekiyor.Aksi taktirde determinant hesaplanamaz.
 scanf("%d",&r);
 printf("\nLütfen matrisin sütun sayýsýný giriniz= ");
 scanf("%d",&c);
 if(r==c)
 {
 printf("\nLütfen matrisin elemanlarýný sýrasýyla Enter tuþuna basarak giriniz=\n");
 for(i=0;i<r;i++) //Burada ise döngü yardýmýyla matrisimizin tüm elemanlarýný dýþarýdan giriyoruz.
 {
 for(j=0;j<c;j++)
 {
 scanf("%d",&a[i][j]);
 }
 }
 deter=determinant(a,r); //Burada deter deðerimiz determinant(a,r) fonksiyonuna gidecek.Ardýndan ordan alýnan sonuçla deter olarak ana fonksiyona geri dönecektir.
 printf("\nVerilen matris:\n");
 for(i=0;i<r;i++)
 {
 for(j=0;j<c;j++)
 {
 printf("%d\t",a[i][j]);
 }
 printf("\n");
 }
 printf("\nMatrisin determinantý: %d\n",deter); //Bu þekilde determinant hesabýmýz yapýlmýþ oldu.Burada determinant sonucumuz ekrana yazdýrýlacaktýr.
 }
 else
 {
 printf("\nHATA! Determinantýn hesaplanmasý için matrisin satýr ve sütun sayýlarý eþit olmalýdýr.\n");
 }
getch();
 return 0;
}
int determinant(int a[MAX][MAX],int n) //Þimdi geldik determinant hesaplayan fonksiyona.

{
 int deter=0,p,h,k,i,j,gecici[MAX][MAX];
 float gercekdeter;
 if(n==1)
 {
 return a[0][0];
 }
 else if(n==2)
 {
 deter=(a[0][0]*a[1][1]-a[0][1]*a[1][0]); //Eðer 2x2 lik bir matris ise köþegenlerin çarpýmýyla determinant hesaplanýr.
 return deter;
 }
 else
 {
 for(p=0;p<n;p++) //Ama 2x2 lik üstü bir matris ise asýl iþlemler burada baþlýyor.Üstte de yazdýðýmýz gibi 3x3 ve daha üstü matrislerin determinantlarýný matrisin majörü ve kofaktörü ile hesaplayacaðýz.
 {
 h = 0;
 k = 0;
 for(i=1;i<n;i++)
 {
 for( j=0;j<n;j++)
 {
 if(j==p)
 {
 continue; //Devam etme kodumuz.
 }
 gecici[h][k] = a[i][j]; //Burada matris elemanlarýmýzý determinant hesaplamak için gecici matrisimizin elemanlarýna atýyoruz.
 k++;
 if(k==n-1)
 {
 h++;
 k = 0;
 }
 }
 }

 
 deter=deter+a[0][p]*pow(-1,p)*determinant(gecici,n-1); //Burada ise asýl determinant hesabý yapýlýyor.determinant(gecici,n-1) bu ifadenin anlamý ise n sayýsý kodlardaki sütun sayýsýdýr.Ýlk baþta mesela 3 olarak baþladýysa burada -1 yapýlýyor ve 2x2 lik matrise düþüyor.Haliyle burada direkt olarak köþegenler çarpýlarak determinant hesabý yapýlmýþ olacak.Tabii sonra tüm bu iþlemler toplanacak ve asýl determinant deðerimiz ortaya çýkmýþ olacaktýr.
   
 
 }
 return deter; //Fonksiyonu deter olarak dýþarý çýkartýyor.Ana fonksiyondan bu fonksyion çaðýrýldýðý zaman deter deðeri yani determinant sonucu direkt olarak oraya gitmiþ olacak.
 }
 
}
