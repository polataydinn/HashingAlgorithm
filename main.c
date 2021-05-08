#include <stdio.h>
#include <string.h>

typedef enum {
    false, true
} bool;


int *hashEncrypt(int *i);

void fileReadAndConvertHash(char filePath[], FILE *fp, FILE *fw);

void writeHashesToTextFile(FILE *fw, int *pInt);

void hashDecrypt(FILE *filePointer, int *hWord);

void mainMenu();

int a = 0;
int hashVeri[100];
int hash2[100];
int *hashed;
int hashedWord[50];
char filePath[500];
FILE *fp = NULL;
FILE *fw = NULL;

int main() {
    mainMenu();
}

void mainMenu() {
    printf("********************************************\n");
    printf("*            Hashing Algoritmasi           *\n");
    printf("********************************************\n");
    printf("* 1-)Sifrelenecek Kelimelerin Konumunu Gir *\n");
    printf("* 2-)Girilen Kelimeleri Sifrele            *\n");
    printf("* 3-)Sifrelenmis Kelimeyi Sozlukte Ara     *\n");
    printf("* 4-)Cikis                                 *\n");
    printf("********************************************\n");
    int secim = 0;
    printf("Seciminizi Giriniz : ");
    scanf("%d", &secim);
    switch (secim) {
        case 1: {
            printf("\nLutfen Sifrelenmesini istediginiz kelime dosyasinin konumunu giriniz : ");
            scanf("%s", filePath);
            printf("\n\n\n\n");
            mainMenu();
            break;
        }
        case 2: {
            if (filePath[0] == 0) {
                printf("Dosya Secmediniz! Bir Onceki Menuden Dosya Seciniz.");
                printf("\n\n\n\n");
                mainMenu();
            } else {
                fileReadAndConvertHash(filePath, fp, fw);
                printf("Dosyadaki kelimeler basarili bir sekilde sifrelendi \n");
                printf("Ana dizinde bulunan hashedWords.txt dosyasina kaydedildi\n");
                printf("\n\n\n\n");
                mainMenu();
            }
            break;
        }
        case 3: {
            printf("Sozlukte aramak istediginiz sifrelenmis kelimeyi giriniz : ");
            scanf("%s", (char *) hashedWord);
            printf("\n\n\n Girdiginiz kelime sozlukte araniyor.....");
            hashDecrypt(fw, hashedWord);
            mainMenu();
            break;
        }
        case 4: {
            break;
        }
        default: {
            printf("\n\n\n\n");
            mainMenu();
            break;
        }
    }

}

void hashDecrypt(FILE *filePointer, int *
hWord) {
    filePointer = fopen("..\\hashedWords.txt", "r");
    int i = 0;
    int currentChar = fgetc(filePointer);
    while (currentChar != EOF) {
        char message[100] = "";
        char hash[100] = "";
        int messageIndex = 0;
        int hashIndex = 0;
        bool isHash = false;
        while (currentChar != '\n') {
            if (currentChar == ':') {
                isHash = true;
                i++;
                currentChar = fgetc(filePointer);
                continue;
            } else {}
            if (isHash) {
                hash[hashIndex] = (char) currentChar;
                hashIndex++;
            } else {
                message[messageIndex] = (char) currentChar;
                messageIndex++;
            }
            i++;
            currentChar = fgetc(filePointer);
        }
        i++;
        currentChar = fgetc(filePointer);
        if (strcmp((const char *) hWord, (const char *) hash) == 0) {
            printf("Hash bulundu : %s \n", message);
        }
    }
    fclose(filePointer);
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
                if (gecici != 10) {
                    hash2[b] = gecici;
                    fprintf(fw, "%c", hash2[b]);
                }
                b++;
            } while (gecici != 10 && gecici != -1);
            hashed = hashEncrypt(hash2);
            fprintf(fw, ":");
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
        int k = 0;
        while (pInt[k] != 0) {
            fprintf(fw, "%c", pInt[k]);
            k++;
        }
        fprintf(fw, "\n");
    }
}

int *hashEncrypt(int *i) {
    if (i[a] != -1 && i[a] != 0) {
        int deger = i[a];
        if (deger >= 41 && deger < 80) {
            deger = deger + 46;
            char convertChar = (char) deger;
            hashVeri[a] = convertChar;
            a++;
        }
        if (deger >= 80 && deger <= 126) {
            deger = deger - 46;
            char convertChar = (char) deger;
            hashVeri[a] = convertChar;
            a++;
        }
        hashEncrypt(i);
    } else {
        a = 0;
        return hashVeri;
    }
}

