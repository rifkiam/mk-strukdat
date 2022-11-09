#include <stdio.h>
#include <string.h>
 
int main()
{

    char gfg[100] = " Geeks - for - geeks - Contribute";
 
    const char s[4] = "-";
    char* tok;
 
    tok = strtok(gfg, s);
 
    // Checks for delimiter
    while (tok != 0) {
        printf(" %s\n", tok);

        tok = strtok(0, s);
    }
    return (0);
}