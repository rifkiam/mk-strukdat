#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct drakor
{
    char kategori[100007];
    char nama[100007];
    char tahun[100007];
};

struct drakor album[100];

char str[100007];

void swap(int i, int j) {
    struct drakor cont;
    cont = album[i];
    album[i] = album[j];
    album[j] = cont;
}

// function to find the partition position
int partition(int low, int high) {

    int pvtindx = high;
    int i = (low - 1);

    for (int j = low; j < high; j++)
    {
        if (strcmp(album[j].kategori, album[pvtindx].kategori) >= 0)
        {
            if (strcmp(album[j].kategori, album[pvtindx].kategori) == 0)
            {
                if (strcmp(album[j].tahun, album[pvtindx].tahun) >= 0)
                {
                    if (strcmp(album[j].tahun, album[pvtindx].tahun) == 0)
                    {
                            if (strcmp(album[j].nama, album[pvtindx].nama) > 0)
                            {
                                i++;
                                swap(i,j);
                            } 
                    }
                    else 
                    {
                        i++;
                        swap(i,j);
                    }
                }
            }
            else 
            {
                i++;
                swap(i,j);
            }
            
        }
  }
  swap(i + 1, high);
  return (i + 1);
}

void quickSort(int low, int high) {
    if (low < high) {
        int pi = partition(low, high);
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

int main() {
    int j = 0;
    while (scanf("%s", str) != EOF)
    {   
        char *token;
        const char del[2] = ";";

        token = strtok(str, del);

        int i = 0;
        while (token != NULL)
        {
            if (i == 0)
            {
                strcpy(album[j].nama, token);
            }
            else if (i == 1)
            {
                strcpy(album[j].tahun, token);
            }
            else if (i == 2)
            {
                strcpy(album[j].kategori, token);
            }
            i++;

            token = strtok(NULL, del);
        }

        j++;
    }

    char cont[100007] = "p";
    quickSort(0, j);
    
    for (int q = j-1; q >= 0; q--)
    {
        if (strcmp(cont, album[q].kategori) != 0)
        {
            printf("================================\n");
            printf("Kategori: %s\n\n", album[q].kategori);
            strcpy(cont, album[q].kategori);
            q++;
        }
        else
        {
            printf("Nama: %s\n", album[q].nama);
            printf("Tahun-rilis: %s\n\n", album[q].tahun);
        }
    }

    printf("================================");
    return 0;    
}