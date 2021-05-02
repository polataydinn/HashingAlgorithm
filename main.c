#include <stdio.h>

int* hashEncrypt(int *i, int a,int k[]);

int main() {
    int a = 0;
    int veri[100] = {'a','y','d','i','n'};
    int hashVeri[100] ;
    int *hashed = hashEncrypt(veri,a,hashVeri);
    for (int i = 0; i < 5; ++i) {
        printf("%c",hashed[i]);
    }

}

int* hashEncrypt(int *i,int a,int k[]) {
    if(i[a]){
        int deger = i[a];
        if(deger >= 33 && deger < 80){
            deger = deger + 46;
            char charDonustur = (char) deger;
            k[a] = charDonustur;
            a++;
        }if(deger >= 80 && deger <= 126){
            deger = deger - 46;
            char charDonustur = (char) deger;
            k[a] = charDonustur;
            a++;
        }
        hashEncrypt(i,a,k);
    }else {
        printf("İşlem Başarılı\n\nhashed veri = ");
        return k;
    }
}
