//print "hello, world"
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("hello, world\n");
}

//print "hello, <name>"
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("What's your name? ");
    printf("hello, %s\n", name);
}

//recreate Nintendo’s Super Mario Brothers's pyramid using hashes (#), allowing users to state height of pyramid
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

//return minimum number of coins (25, 10, 5, or 1 cent-coins) to make up stated amount of change in cents
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
