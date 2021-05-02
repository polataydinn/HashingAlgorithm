#include <stdio.h>

int *hashEncrypt(int *i);
void fileReadAndConvertHash(char filePath[], FILE *fp);

int a = 0;
int hashVeri[100];
int hash2[100];
int *hashed;

int main() {
    int veri[100] = {'a', 'y', 'd', 'i', 'n'};

    char filePath[500] = "C:\\Users\\polat\\CLionProjects\\algoritmaAnaliziProje\\kelimeler.txt";
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    fileReadAndConvertHash(filePath, fp);
}

void fileReadAndConvertHash(char filePath[], FILE *fp) {
    fp = fopen(filePath, "r");
    if (fp == NULL) {
        printf("Dosya boş yada hatalı");
    }
    int b = 0;
    do {
        hash2[b] = (int) fgetc(fp);
        b++;
    } while (hash2[b - 1] != -1);

    hashed = hashEncrypt(hash2);
    for (int i = 0; i < 5; ++i) {
        printf("%c", hashed[i]);
    }


    fclose(fp);
}

int *hashEncrypt(int *i) {
    if (i[a] != 10) {
        int deger = i[a];
        if (deger >= 33 && deger < 80) {
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
        printf("İşlem Başarılı\n\nhashed veri = ");
        return hashVeri;
    }
}
