// scrabble game
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int point(string word);

int main(void)
{
    string player_one = get_string("Player 1: ");
    string player_two = get_string("Player 2: ");
    int points_pone = point(player_one);
    int points_ptwo = point(player_two);
    if(points_pone > points_ptwo)
    {
        printf("Player 1 wins!\n");
    }
    else if(points_pone < points_ptwo)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int point(string word)
{
    int sum = 0;
    for(int i = 0, length = strlen(word); i < length; i++)
    {
        char letter = toupper(word[i]);
        if (letter == 'A' || letter == 'E' || letter == 'I' || letter == 'L' || letter == 'N' || letter == 'O' || letter == 'R' || letter == 'S' || letter == 'T' || letter == 'U')
        {
            sum += 1;
        }
        else if (letter == 'D' || letter == 'G')
        {
            sum += 2;
        }
        else if (letter == 'B' || letter == 'C' || letter == 'M' || letter == 'P')
        {
            sum += 3;
        }
        else if (letter == 'F' || letter == 'H' || letter == 'V' || letter == 'W' || letter == 'Y')
        {
            sum += 4;
        }
        else if (letter == 'K')
        {
            sum += 6;
        }
        else if (letter == 'J' || letter == 'X')
        {
            sum += 8;
        }
        else if (letter == 'Q' || letter == 'Z')
        {
            sum += 8;
        }
        else
        {
            sum += 0;
        }
    }
    return sum;
}
