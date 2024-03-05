// Scrabble game

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

\\ Readability test based on Coleman-Liau index 

#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int word_count(string text);
int sentence_count(string text);
int letter_count(string text);

int main(void)
{
    string text = get_string("Text: ");
    int number_of_words = word_count(text);
    int number_of_sentences = sentence_count(text);
    int number_of_letters = letter_count(text);
    float avg_letters = (float)number_of_letters / (float)number_of_words * 100.0;
    float avg_sentences = (float)number_of_sentences / (float)number_of_words * 100.0;
    float grade = (0.0588 * avg_letters) - (0.296 * avg_sentences) - 15.8;
    if(grade < 1.5)
    {
        printf("Before Grade 1\n");
    }
    else if(grade >= 16.0)
    {
        printf("Grade 16+\n");
    }
    else
    {
        int final = round(grade);
        printf("Grade %i\n", final);
    }
}

int word_count(string text)
{
    int nwords = 1;
    for(int i = 0, length = strlen(text); i < length; i++)
    {
        if (text[i] == ' ')
        {
            nwords++;
        }
    }
    return nwords;
}

int sentence_count(string text)
{
    int nsentences = 0;
    for(int i = 0, length = strlen(text); i < length; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            nsentences++;
        }
    }
    return nsentences;
}

int letter_count(string text)
{
    int nletters = 0;
    for(int i = 0, length = strlen(text); i < length; i++)
    {
        if ((text[i] >= 'a' & text[i] <= 'z') || (text[i] >= 'A' & text[i] <= 'Z'))
        {
            nletters++;
        }
    }
    return nletters;
}

\\ Text encryptor using specified integer key

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

string encrypt(int key, string plain_text);

int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int key = atoi(argv[1]);
    if (key == 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        string plain_text = get_string("plaintext: ");
        string cipher_text = encrypt(key, plain_text);
        printf("ciphertext: %s\n", cipher_text);
    }
    return 0;
}


string encrypt(int key, string plain_text)
{
    for (int i = 0, length = strlen(plain_text); i < length; i++)
    {
        if ((plain_text[i] >= 'a' && plain_text[i] <= 'z') || (plain_text[i] >= 'A' && plain_text[i] <= 'Z'))
        {
            plain_text[i] += (key % 26);
        }
        else
        {
            return plain_text;
        }
    }
    return plain_text;
}

\\ Text encryptor using specified 26-character key

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

string encrypt(string key, string plain_text);

int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    string key = argv[1];
    if (strlen(key) != 26)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else
    {
        string plain_text = get_string("plaintext: ");
        string cipher_text = encrypt(key, plain_text);
        printf("ciphertext: %s\n", cipher_text);
    }
    return 0;
}

string encrypt(string key, string plain_text)
{
    string cipher_text = plain_text;
    for (int i = 0, length = strlen(plain_text); i < length; i++)
    {
        char current_char = plain_text[i];
        if (islower(current_char))
        {
            int plain_text_pos = current_char - 'a';
            cipher_text[i] = tolower(key[plain_text_pos]);
        }
        else if (isupper(current_char))
        {
            int plain_text_pos = current_char - 'A';
            cipher_text[i] = toupper(key[plain_text_pos]);
        }
        else
        {
            cipher_text[i] = current_char;
        }
    }
    return cipher_text;
}
