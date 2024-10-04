#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int words(string s);
int letters(string s);
int sentences(string s);

int main(void)
{
    string text = get_string("Text: ");

    double word = words(text);
    double letter = letters(text);
    double sentence = sentences(text);

    float L = ((letter / word) * 100);
    float S = ((sentence / word) * 100);
    int index = round(0.0588 * (L) -0.296 * (S) -15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

// ABC DEF GHI => 65 66 67 0

int words(string s)
{
    int word = 1;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] == ' ')
        {
            word++;
        }
    }
    return word;
}

int letters(string s)
{
    int letter = 0;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (isalpha(s[i]))
        {
            letter++;
        }
    }
    return letter;
}

int sentences(string s)
{
    int j = 0, sentence = 0;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] == '.' || s[i] == '?' || s[i] == '!')
        {
            sentence++;
        }
    }
    return sentence;
}
