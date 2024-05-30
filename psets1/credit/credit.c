#include <cs50.h>
#include <stdio.h>

// GLobal variables used
int card_size, error_number;

// function that will be used
int long_len(long card_number);
void card_name(long card_number);
void card_check(long card_number);
void check(long card_number);

// main function that calls check function and give it a value entered by user.
int main(void)
{
    long card_number = get_long("Number: ");
    check(card_number);
}
/* check function calls long_len function and checks wehter the card number length is appropriate or
a mistake/ false card. If card length is ok then it calls card_check function else return INVALID as
output.*/
void check(long card_number)
{
    card_size = long_len(card_number);

    if (card_size == 13 || card_size == 15 || card_size == 16)
    {
        card_check(card_number);
    }
    else
    {
        printf("INVALID\n");
    }
}

/* long_len function uses the lenght of input and divides it till it gives the integer 0 and couts
the number of times it has been divided by 10. For eg. if card no. is 1234 then it will will divide
1234 4 times as 1234 -> 123 -> 12 -> 1 -> 0, which is the required length of the card. */
int long_len(long input)
{
    int length;
    for (length = 0; input != 0; input /= 10)
        length++;
    return length;
}

void card_check(long input)
{
    long input1 = input;
    int luhn_sum = 0;
    for (int i = 0; input != 0; i++, input /= 10)
    {
        if (i % 2 == 0) // filter outs only even indexed number
        // like 12345 it will only take value 1+3+5 as they at index 4,2,0 respectively
        {
            luhn_sum += input % 10; // calculates sum of even placed number
        }
        else
        {
            int luhn_sum_odd_place = 2 * (input % 10); // doubles the odd indexed number
            luhn_sum += luhn_sum_odd_place % 10 + luhn_sum_odd_place / 10;
            /* this line takes the invidual sum of number if the 2*of indexed number is 2digits for
             * eg if no. is 8 at 1st place it's double would be 16 so this line prints out the value
             * as 7(i.e. 1+6) */
        }
    }
    if (luhn_sum % 10 == 0)
    {
        card_name(input1); // calls out the car_name function is card is valid
    }
    else
    {
        printf("INVALID\n");
    }
}

/* card_name function takes in the input of card number and then sorts the cards based on there card
 * number length then checks the initial no. on card and prints out the required card company name*/
void card_name(long card_number)
{
    if (long_len(card_number) == 13)
    {
        long card_number_len_13 = card_number;
        while (card_number_len_13 >= 99)
        {
            card_number_len_13 = card_number_len_13 / 10;
        }
        if (card_number_len_13 >= 40 && card_number_len_13 <= 49)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (long_len(card_number) == 15)
    {
        long card_number_len_15 = card_number;
        while (card_number_len_15 >= 99)
        {
            card_number_len_15 = card_number_len_15 / 10;
        }
        if (card_number_len_15 == 34 || card_number_len_15 == 37)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (long_len(card_number) == 16)
    {
        long card_number_len_16 = card_number;
        while (card_number_len_16 >= 99)
        {
            card_number_len_16 = card_number_len_16 / 10;
        }
        if (card_number_len_16 >= 40 && card_number_len_16 <= 49)
        {
            printf("VISA\n");
        }
        else if (card_number_len_16 >= 51 && card_number_len_16 <= 55)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}