#include<stdio.h>
#define _LINE_LENGTH 300
int main(void) 
{
    FILE *file;
    char line[_LINE_LENGTH];
    file = popen("dir", "r");
//    file = popen("test3.exe", "w");
    if (NULL != file)
    {
        while (fgets(line, _LINE_LENGTH, file) != NULL)
        {
            printf("line=%s\n", line);
        }
    }
    else
    {
        return 1;
    }
    pclose(file);
    return 0;
}
