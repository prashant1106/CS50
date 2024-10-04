#import <cs50.h>
#import <ctype.h>
#import <stdio.h>
#import <string.h>

const string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void KEY_INPUT(string key);

int main(int argc, string argv[])
{
    if (argc == 1)
    {
        printf("Please enter a key!\n");
        return 1;
    }
    else if (argc != 2)
    {
        printf("Please provide one command line argument only.\n");
        return 1;
    }
    else if (argc == 2)
    {
        if (strlen(argv[1]) == 26)
        {
            for (int i = 0, n = strlen(argv[1]); i < n; i++)
            {

                if (!isalpha(argv[1][i]))
                {
                    printf("Key must contain only letters.\n");
                    return 1;
                }

                for (int j = i + 1, m = strlen(argv[1]); j < n; j++)
                {

                    if (toupper(argv[1][j]) == toupper(argv[1][i]))
                    {
                        printf("Key must not contain repeated alphabets.\n");
                        return 1;
                    }
                }
            }

            KEY_INPUT(argv[1]);
        }
        else
        {
            printf("key must contain 26 characters.\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
}

void KEY_INPUT(string key)
{
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");

    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (isalpha(plaintext[i]))
        {
            if (islower(plaintext[i]))
            {
                for (int j = 0, m = strlen(alpha); j < m; j++)
                {
                    if (toupper(plaintext[i]) == alpha[j])
                    {
                        printf("%c", tolower(key[j]));
                    }
                }
            }
            else if (isupper(plaintext[i]))
            {
                for (int j = 0, m = strlen(alpha); j < m; j++)
                {
                    if (plaintext[i] == alpha[j])
                    {
                        printf("%c", toupper(key[j]));
                    }
                }
            }
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}

