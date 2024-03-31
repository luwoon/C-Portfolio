// Print "hello, world"

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("hello, world\n");
}


// Print "hello, <name>"

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("What's your name? ");
    printf("hello, %s\n", name);
}


// Recreate Nintendo’s Super Mario Brothers's pyramid using hashes (#), allowing users to state height of pyramid

#include <stdio.h>
#include <cs50.h>

void print_row(int length, int height);

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1);
    for (int i = 0; i < height; i++)
    {
        print_row(i + 1, height);
    }
}

void print_row(int length, int height)
{
    for (int j = 0; j < height - length; j++)
    {
        printf(" ");
    }
    for (int k = 0; k < length; k++)
    {
        printf("#");
    }
    printf("  ");
    for (int m = 0; m < length; m++)
    {
        printf("#");
    }
    printf("\n");
}


// Return minimum number of coins (25, 10, 5, or 1 cent-coins) to make up stated amount of change in cents

#include <cs50.h>
#include <stdio.h>

void print_ncoin(int change_owed);

int main(void)
{
    int change_owed;
    do
    {
        change_owed = get_int("Change owed: ");
    }
    while (change_owed < 0);
    print_ncoin(change_owed);
}

void print_ncoin(int change_owed)
{
    int ncoin = 0;
    while (change_owed >=25)
    {
        change_owed -= 25;
        ncoin++;
    }
    while (change_owed >=10)
    {
        change_owed -= 10;
        ncoin++;
    }
    while (change_owed >=5)
    {
        change_owed -= 5;
        ncoin++;
    }
    while (change_owed >=1)
    {
        change_owed -= 1;
        ncoin++;
    }
    printf("%i\n", ncoin);
}


// Check validity of Mastercard, Visa, and Amex numbers

#include <cs50.h>
#include <stdio.h>

int even_digit(long number);
int digit_sum(int product);
int all_digits(long number);

int main(void)
{
    long number = get_long("Number: ");
    int final_number = all_digits(number);
    if (final_number % 10 == 0)
    {
        if ((number >= 340000000000000 && number <= 349999999999999) || (number >= 370000000000000 && number <= 379999999999999))
        {
            printf("AMEX\n");
        }
        else if (number >= 5100000000000000 && number <= 5599999999999999)
        {
            printf("MASTERCARD\n");
        }
        else if ((number >= 4000000000000 && number <= 4999999999999) || (number >= 4000000000000000 && number <= 4999999999999999))
        {
            printf("VISA\n");
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

int even_digit(long number)
{
    int sum = 0;
    number /= 10;
    while (number > 0)
    {
        int product = (number % 10) * 2;
        sum += digit_sum(product);
        number /= 100;
    }
    return sum;
}

int digit_sum(int product)
{
    int sum = 0;
    while (product > 0)
    {
        sum += product % 10;
        product /= 10;
    }
    return sum;
}

int all_digits(long number)
{
    int sum = even_digit(number);
    while (number > 0)
    {
        int odd_digit = number % 10;
        sum += odd_digit;
        number /= 100;
    }
    return sum;
}
