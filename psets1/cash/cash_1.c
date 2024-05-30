#include <stdio.h>
#include <cs50.h>

int main()
{
    int cents_owed;

    do
    {
        cents_owed = get_float("Change owed: ");
    }
    while (cents_owed <= 0); // forces user to enter +ve chenge owed

    int quarters = cents_owed / 25;    
    int dimes = (cents_owed % 25) / 10;
    int nickels = ((cents_owed % 25) % 10) / 5;
    int pennies = ((cents_owed % 25) % 10) % 5;

    printf("%i\n", quarters + dimes + nickels + pennies);
}