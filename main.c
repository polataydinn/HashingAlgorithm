#include <stdio.h>

int *hashEncrypt(int *i);

void fileReadAndConvertHash(char filePath[], FILE *fp, FILE *fw);

void writeHashesToTextFile(FILE *fw, int *pInt);

int a = 0;
int hashVeri[100];
int hash2[100];
int *hashed;

int main() {
    char veri[100] = {'a', 'y', 'd', 'i', 'n'};
    char filePath[500] = "C:\\Users\\polat\\CLionProjects\\algoritmaAnaliziProje\\kelimeler.txt";
    FILE *fp;
    FILE *fw;
    fileReadAndConvertHash(filePath, fp,fw);
}

void fileReadAndConvertHash(char filePath[], FILE *fp, FILE *fw) {
    fp = fopen(filePath, "r");
    fw = fopen("..\\hashedWords.txt", "w");
    int gecici;
    if (fp == NULL) {
        printf("Dosya boş yada hatalı");
    } else {
        int b = 0;
        while (hash2[b] != -1) {
            do {
                gecici = (int) fgetc(fp);
                if (gecici!= 10) {
                    hash2[b] = gecici;
                }
                b++;
            } while (gecici != 10 && gecici !=-1);
            hashed = hashEncrypt(hash2);
            writeHashesToTextFile(fw, hashed);
            b = 0;
        }
        fclose(fw);
        fclose(fp);
    }
}

void writeHashesToTextFile(FILE *fw, int *pInt) {
    if (fw == NULL) {
        printf("Dosya olusturma basarisiz..");
    } else {
        int k= 0;
        while (pInt[k] != 0) {
            fprintf(fw,"%c",pInt[k]);
            k++;
        }
        fprintf(fw,"\n");
    }
}

int *hashEncrypt(int *i) {
    if (i[a] != -1 && i[a] != 0) {
        int deger = i[a];
        if (deger >= 41 && deger < 80) {
            deger = deger + 46;
            char charDonustur = (char) deger;
            hashVeri[a] = charDonustur;
            a++;
        }
        if (deger >= 80 && deger <= 126) {
            deger = deger - 46;
            char charDonustur = (char) deger;
            hashVeri[a] = charDonustur;
            a++;
        }
        hashEncrypt(i);
    } else {
        a = 0;
        printf("Islem Basarili\n\nhashed veri = ");
        return hashVeri;
    }
}
