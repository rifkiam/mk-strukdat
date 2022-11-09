#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct string
{
    char command[100];
};

struct string line[15];

int main() {
    int T;
    scanf("%d", &T);
    
    for (int i = 0; i < T; i++)
    {
        int j = 0;
        char str[100000];
        scanf("%s", &str);
        char *token;
        const char del[2] = ";";

        token = strtok(str, del);

        if (strcmp(token, "PRINT") == 0)
        {
            break;
        }

        while (token != NULL)
        {
            strcpy(line[j].command, token);
            j++;
            token = strtok(NULL, del);
        }

        if (strcmp(line[1].command, "include") == 0)
        {
            printf("#include<%s>\n", line[2].command);   
        }

        else if (strcmp(line[1].command, "function") == 0)
        {
            printf("int %s(){\n", line[2].command);
        }
        
        else if (strcmp(line[1].command, "variable") == 0)
        {
            if (strcmp(line[2].command, "integer") == 0)
            {
                printf("int %s;\n", line[3].command);
            }
            
            else if (strcmp(line[2].command, "character") == 0)
            {
                printf("char %s;\n", line[3].command);
            }
        }

        else if (strcmp(line[1].command, "scanf") == 0)
        {
            if (strcmp(line[2].command, "integer") == 0)
            {
                printf("scanf(\"%%d\",&%s);\n", line[3].command);
            }
            
            else if (strcmp(line[2].command, "character") == 0)
            {
                printf("scanf(\"%%c\",&%s);\n", line[3].command);
            }
        }

        else if (strcmp(line[1].command, "printf") == 0)
        {
            if (strcmp(line[2].command, "integer") == 0)
            {
                printf("printf(\"%%d\",%s);\n", line[3].command);
            }
            
            else if (strcmp(line[2].command, "character") == 0)
            {
                printf("printf(\"%%c\",%s);\n", line[3].command);
            }
        }
        
    }
    
    printf("return 0;\n}");
    

    return 0;
}