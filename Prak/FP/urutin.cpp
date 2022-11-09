#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct siswa
{
    int x; //NILAI MAT
    int y; //NILAI BHS
    char nama[22];
};

struct siswa urut[500001];

void swap(int i, int j) {
    struct siswa cont;
    cont = urut[i];
    urut[i] = urut[j];
    urut[j] = cont;
}

int partition(int low, int high) {

    int pvtindx = high;
    int pivot = urut[high].x + urut[high].y;
    int i = (low - 1);

    for (int j = low; j < high; j++) //sorting data menggunakan nilai dan nama
    {
        if (urut[j].x + urut[j].y <= pivot) //BANDINGKAN NILAI DENGAN PIVOT
        {
            if (urut[j].x + urut[j].y == pivot) //JIKA SAMA
            {
                if (urut[j].x <= urut[pvtindx].x) //BANDINGKAN NILAI MATEMATIKA
                {
                    if (urut[j].x == urut[pvtindx].x) //JIKA SAMA
                    {
                            if (strcmp(urut[j].nama, urut[pvtindx].nama) > 0) //BANDINGKAN NAMA KEDUANYA
                            {
                                i++;
                                swap(i,j); //DENGAN SWAPPING I, J, FUNCTION SWAP DIBUAT UNTUK MEMUAT STRUCT BERINDEX I DAN J
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
    int n;
    scanf("%d", &n);
    urut[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %s", &urut[i].x, &urut[i].y, &urut[i].nama);
    }
    quickSort(0, n-1);

    for (int i = n-1; i >= 0; i--)
    {
        printf("%d %d %s\n", urut[i].x, urut[i].y, urut[i].nama);
    }
    return 0;
}