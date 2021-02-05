#include <stdio.h>
#include <string.h>

#define MAX_LETTERS 40000
#define MAX_WORDS 10000
#define MAX_WORD_LENGHT 50

#pragma warning(disable:4996)
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS

char text[MAX_LETTERS];
char words[MAX_WORDS][MAX_WORD_LENGHT];

void main(int argc, char* argv[])
{
    int j = 0;
    fgets(text,sizeof(text),stdin);
    for (int i = 0; i < MAX_LETTERS; i++)
    {
        if (text[i] == ' ')
        {
            words[j][0] = ' ';
            j++;
            continue;
        }
        if (text[i] != ' ')
        {
            int l = 0;
            while (text[i] != ' ')
            {
                words[j][l] = text[i];
                l++;
                i++;
            }
            j++;
        }
    }
    for (int a = 1; a < argc; a++)
    {
        char * find;
        find = strchr(argv[a], '/');
        for (int m = 0; m < j; m++)
        {
            if (find == NULL)
            {
                int x = strcmp(argv[a], words[m]);
                if (x == 0)
                {
                    for (int y = 0; y < strlen(words[m]); y++)
                    {
                        words[m][y] = '*';
                    }
                }
            }
            else
            {
                char * token;
                char replace[10];
                token = strtok(argv[a], "/");
                do
                {
                    token = strtok(NULL, "/");
                    if (token == NULL)
                        break;
                    strcpy(replace, token);
                } while (token != NULL);
                token= strtok(argv[a], "/");
                int k = strcmp(token, words[m]);
                if (k==0)
                {
                    for (int c = 0; c < sizeof(replace);c++)
                    {
                        words[m][c] = replace[c];
                    }
                }
            }
        }
    }
    for (int m = 0; m < j; m++)
    {
        if (words[m][0] != ' ')
        {
            printf("%s ", words[m]);
        }
        else
        {
            printf(" ");
        }
    }
    printf("\n");
}