#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct test{
    char str2[100];
};

struct test varCase[10];

void solve(){
    for (int j = 0; j < 5; j++)
    {
        //printf( "%s\n", varCase[j].str2);
    }
    
    
    if (strcmp(varCase[1].str2, "include") == 0)
    {
       printf("#include");
       printf("<");
       printf("%s", varCase[2].str2);
       printf(">\n");
    }

    else if (strcmp(varCase[1].str2, "function") == 0)
    {
        printf("int main(){\n");
    }

    else if (strcmp(varCase[1].str2, "variable") == 0)
    {
        if (strcmp(varCase[2].str2, "integer") == 0)
        {
            printf("int ");
        } 

        else 
        {
            printf("char ");
        }
        
        printf("%s;\n", varCase[3].str2);
    }

    else if (strcmp(varCase[1].str2, "scanf") == 0)
    {
        if (strcmp(varCase[2].str2, "integer") == 0)
        {
            printf("scanf(\"%%d\",&%s);\n", varCase[3].str2);
        }

        else 
        {
            printf("scanf(\"%%c\",&%s);\n", varCase[3].str2);
        }
    }

    else if (strcmp(varCase[1].str2, "printf") == 0)
    {
        if (strcmp(varCase[2].str2, "integer") == 0)
        {
            printf("printf(\"%%d\",%s);\n", varCase[3].str2);
        }

        else 
        {
            printf("printf(\"%%c\",%s);\n", varCase[3].str2);
        }
    }   
}

int main(){
    int x;
    scanf("%d", &x);

    for (int i = 0; i < x; i++){
        int j = 0;
        char str[1000000];
        scanf("%s", &str);

        char *token;
        const char s[2] = ";";
   
        token = strtok(str, s);

        if (strcmp(token, "PRINT") == 0)
        {
            break;
        }
        
        while( token != NULL ) {
            strcpy(varCase[j].str2, token);
            j++;
            token = strtok(NULL, s);
        }

        solve();

    }

    printf("return 0;\n}");
    
}