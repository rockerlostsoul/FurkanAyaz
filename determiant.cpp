#include<conio.h>
#include<math.h>
#define MAX 20 //Bu max de�eri matrisimiz i�in olu�turdu�umuz elemanlar�n de�eridir.Yani max 20 derseniz maksimum 20 sat�rl� veya 20 s�tunlu matris olu�turabilirsiniz anlam�na geliyor.
#include <locale.h>
int determinant(int a[MAX][MAX],int n);
int main() //Ana fonksiyonumuz.
{
setlocale(LC_ALL, "Turkish");  //T�rk�e karakter sorunu olmamas� i�in ekledi�imiz kod.
 int i,j,r,c,a[MAX][MAX],b[MAX][MAX],deter=0;
 
 printf("\nL�tfen matrisin sat�r say�s�n� giriniz= "); //Burada matrisimizin ka�a ka�l�k olaca��n� giriyoruz.S�tun ve sat�r say�s�n�n e�it olmas� yani kare matris olmas� gerekiyor.Aksi taktirde determinant hesaplanamaz.
 scanf("%d",&r);
 printf("\nL�tfen matrisin s�tun say�s�n� giriniz= ");
 scanf("%d",&c);
 if(r==c)
 {
 printf("\nL�tfen matrisin elemanlar�n� s�ras�yla Enter tu�una basarak giriniz=\n");
 for(i=0;i<r;i++) //Burada ise d�ng� yard�m�yla matrisimizin t�m elemanlar�n� d��ar�dan giriyoruz.
 {
 for(j=0;j<c;j++)
 {
 scanf("%d",&a[i][j]);
 }
 }
 deter=determinant(a,r); //Burada deter de�erimiz determinant(a,r) fonksiyonuna gidecek.Ard�ndan ordan al�nan sonu�la deter olarak ana fonksiyona geri d�necektir.
 printf("\nVerilen matris:\n");
 for(i=0;i<r;i++)
 {
 for(j=0;j<c;j++)
 {
 printf("%d\t",a[i][j]);
 }
 printf("\n");
 }
 printf("\nMatrisin determinant�: %d\n",deter); //Bu �ekilde determinant hesab�m�z yap�lm�� oldu.Burada determinant sonucumuz ekrana yazd�r�lacakt�r.
 }
 else
 {
 printf("\nHATA! Determinant�n hesaplanmas� i�in matrisin sat�r ve s�tun say�lar� e�it olmal�d�r.\n");
 }
getch();
 return 0;
}
int determinant(int a[MAX][MAX],int n) //�imdi geldik determinant hesaplayan fonksiyona.

{
 int deter=0,p,h,k,i,j,gecici[MAX][MAX];
 float gercekdeter;
 if(n==1)
 {
 return a[0][0];
 }
 else if(n==2)
 {
 deter=(a[0][0]*a[1][1]-a[0][1]*a[1][0]); //E�er 2x2 lik bir matris ise k��egenlerin �arp�m�yla determinant hesaplan�r.
 return deter;
 }
 else
 {
 for(p=0;p<n;p++) //Ama 2x2 lik �st� bir matris ise as�l i�lemler burada ba�l�yor.�stte de yazd���m�z gibi 3x3 ve daha �st� matrislerin determinantlar�n� matrisin maj�r� ve kofakt�r� ile hesaplayaca��z.
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
 gecici[h][k] = a[i][j]; //Burada matris elemanlar�m�z� determinant hesaplamak i�in gecici matrisimizin elemanlar�na at�yoruz.
 k++;
 if(k==n-1)
 {
 h++;
 k = 0;
 }
 }
 }

 
 deter=deter+a[0][p]*pow(-1,p)*determinant(gecici,n-1); //Burada ise as�l determinant hesab� yap�l�yor.determinant(gecici,n-1) bu ifadenin anlam� ise n say�s� kodlardaki s�tun say�s�d�r.�lk ba�ta mesela 3 olarak ba�lad�ysa burada -1 yap�l�yor ve 2x2 lik matrise d���yor.Haliyle burada direkt olarak k��egenler �arp�larak determinant hesab� yap�lm�� olacak.Tabii sonra t�m bu i�lemler toplanacak ve as�l determinant de�erimiz ortaya ��km�� olacakt�r.
   
 
 }
 return deter; //Fonksiyonu deter olarak d��ar� ��kart�yor.Ana fonksiyondan bu fonksyion �a��r�ld��� zaman deter de�eri yani determinant sonucu direkt olarak oraya gitmi� olacak.
 }
 
}
