#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    char nama[n][100], b[100];

    for(int i = 0; i < n; i++)
    {
    scanf("%s", nama[i]);
    }

    for(int i = 0;i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(strcmp(nama[i], nama[j]) > 0)
            {
                strcpy(b, nama[i]);
                strcpy(nama[i], nama[j]);
                strcpy(nama[j], b);
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        printf("%s\n", nama[i]);
    }
}