#include <stdio.h>
#include <conio.h>
 
int main(){
    int a, b, i, j;
    
    printf("Matris Satir Sayisi Giriniz: ");
    scanf("%d", &a);
    printf("Matris Sutun Sayisi Giriniz: ");
    scanf("%d", &b);
    
    int matris[a][b], matrisT[b][a];
    
    // Matris'e elemanlarý kullanýcýdan alma
    for(i=0; i<a; i++)
        for(j=0; j<b; j++){
            printf("%dx%d elemanini giriniz: ", i+1, j+1);
            scanf("%d", &matris[i][j]);
        }
        
    //Matrisin Transpozunu alma
    for(i=0; i<a; i++){
        for(j=0; j<b; j++){
            matrisT[j][i] = matris[i][j];
        }
    }
        
    // Matris elemanlarýný ekrana yazdýrma
    for(i=0; i<a; i++){
        for(j=0; j<b; j++){
            printf("%d ", matris[i][j]);
        }
        printf("\n");
    }
    // Matrisin Transpozunun Ekrana Yazdýrma
    printf("Transpozu\n");
    for(i=0; i<b; i++){
        for(j=0; j<a; j++){
            printf("%d ", matrisT[i][j]);
        }
        printf("\n");
    }
    
    getch();
    return 0;
}
