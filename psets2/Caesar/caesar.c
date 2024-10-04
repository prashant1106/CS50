#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void caesar(int key, string p);

int main(int argc, string args[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else if (argc == 2)
    {
        for (int i = 0, n = strlen(args[1]); i < n; i++)
        {
            if (isalpha(args[1][i]))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
        string plaintext = get_string("plaintext: ");
        int key = atoi(args[1]);
        printf("ciphertext: ");
        caesar(key, plaintext);
    }
}

void caesar(int key, string p)
{
    for (int i = 0, n = strlen(p); i < n; i++)
    {
        if (!isalpha(p[i]))
        {
            printf("%c", p[i]);
            continue;
        }
        int offset = isupper(p[i]) ? 65 : 97;

        int cyphertext = (p[i] - offset + key) % 26;

        printf("%c", cyphertext + offset);
    }
    printf("\n");
}

