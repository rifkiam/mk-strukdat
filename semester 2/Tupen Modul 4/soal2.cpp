#include <stdio.h>
#include <string.h>

struct UNMahasiswa
{
    char nama[100];
    int mat;
    int ipa;
    int bind;
    int bing;
};

struct namasiswa
{
    char siswa[100];
};

void cari(struct UNMahasiswa mhs[100], int a, int unMhs)
{
    struct namasiswa dicari[a];

    /*printf("%d", a);*/

    for(int j = 1; j <= a; j++)
    {
        scanf("%s", &dicari[j].siswa);
    }

    for(int j = 1; j <= a; j++)
    {
        int result = 0;
        /*int result = strcmp(dicari[j].siswa, mhs[j].nama);*/
        int l;
        for(int k = 1; k <= unMhs; k++)
        {
            if(strcmp(dicari[j].siswa, mhs[k].nama) == 0)
            {
                result = 1;
                l = k;
            }
        }

        if(result == 1)
        {
            printf("Nilai %s\n", dicari[j].siswa);
            printf("Matematika : %d\n", mhs[l].mat);
            printf("IPA : %d\n", mhs[l].ipa);
            printf("Bahasa Indonesia : %d\n", mhs[l].bind);
            printf("Bahasa Inggris : %d\n", mhs[l].bing);
        }

        if(result == 0)
        {
            printf("Nilai %s tidak ditemukan\n", dicari[j].siswa);
        }
    }
}

int main() {
    
    int unMhs;
    scanf("%d", &unMhs);
    struct UNMahasiswa mhs[unMhs];

    for(int i = 1; i <= unMhs; i++)
    {
        scanf("%s", &mhs[i].nama);
        scanf("%d", &mhs[i].mat);
        scanf("%d", &mhs[i].ipa);
        scanf("%d", &mhs[i].bind);
        scanf("%d", &mhs[i].bing);
    }

    int a;
    scanf("%d", &a);

    cari(mhs, a, unMhs);

    /*for(int i = 1; i <= unMhs; i++)
    {
        printf("%s\n", mhs[i].nama);
        printf("%d\n", mhs[i].mat);
        printf("%d\n", mhs[i].ipa);
        printf("%d\n", mhs[i].bind);
        printf("%d\n", mhs[i].bing);
    }*/
    

    return 0;
}