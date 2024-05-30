#import <cs50.h>
#import <stdio.h>

int change, coins;

int main(void)
{
    change = get_int("Change owed: ");
    coins = 0;
    while (change != 0)
    {
        while (change >= 25)
        {
            change = change - 25;
            coins++;
        }
        while (change >= 25)
        {
            change = change - 25;
            coins++;
        }
        while (change >= 10)
        {
            change = change - 10;
            coins++;
        }
        while (change >= 5)
        {
            change = change - 5;
            coins++;
        }
        while (change >= 1)
        {
            change = change - 1;
            coins++;
        }
    }
    printf("%i\n", coins);
}