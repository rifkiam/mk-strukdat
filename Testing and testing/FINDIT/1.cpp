#include <stdio.h>

int main() {
    int m, x, h, s, total = 0;
    scanf("%d %d %d %d", &m, &x, &h, &s);

    for (int i = 0; i < h; i++)
    {
        m += x;
        total += m;
    }

    if (s - total < 0)
    {
        printf("TIDAK");
    }
    
    else if (s - total >= 0)
    {
        printf("YA %d", s - total);
    }
    
    return 0;
}