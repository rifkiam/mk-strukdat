//LINK SOAL: https://tlx.toki.id/problems/ksnp-2021/B1/

/*
Penjelasan singkat soal:
Diperintahkan untuk menentukan (seminimal mungkin) banyaknya apel dari apel yang tersedia 
sehingga total berat apel merah dan hijau bernilai sama

Format Masukan:
N, A, B
N = banyak masing-masing apel merah dan hijau
A = Berat apel merah
B = Berat apel hijau

Format Output:
Banyak total apel merah dan hijau yang diambil
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    long int N;
    int A, B;
    int i = 0, j = 0;
    scanf("%ld %d %d", &N, &A, &B);

    int C = A;
    int D = B;
    for (int h = 0; h < 2*N; h++)
    {
        if (C == D)
        {
            break;
        }
        else if (C < D)
        {
            C = C + A;
            i++;
            //printf("A %d %d\n", C, i);
        }
        else if (C > D)
        {
            D = D + B;
            j++;
            //printf("B %d %d\n", D, j);
        }
    }
    
    printf("%d", i + j + 2);
    return 0;
}

