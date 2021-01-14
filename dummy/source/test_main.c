#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *fp; 
    fp = fopen("../server_data/file.txt", "r");
    
    char c;
    if(fp == NULL)
        {
            printf("ERROR");
        }

    while((c = fgetc(fp)) != EOF)
        {
            printf("%c", c);
        }
    fclose(fp);
    
}

        
