#include <stdio.h>

int main() {
    int kurawal, siku, biasa, sudut;
    char kurung[20];
    scanf("%s", &kurung);
    printf("%s", kurung);

    for (int i = 0; i < 20; i++)
    {
        if (kurung[i] == '(')
        {
            for (int j = i + 1; j < 20; j++)
            {
                
            }
        }

        else if (kurung[i] == '{')
        {
            for (int j = i + 1; j < 20; j++)
            {
                
            }
        }
        
        else if (kurung[i] == '[')
        {
            for (int j = i + 1; j < 20; j++)
            {
                
            }
        }

        else if (kurung[i] == '<')
        {
            for (int j = i + 1; j < 20; j++)
            {
                
            }
        }

        else
        {
            printf("0");
            break;
        }
    }

    printf("")

    return 0;

}

