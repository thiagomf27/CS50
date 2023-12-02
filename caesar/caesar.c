#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

bool only_digits(string s);
char rotate(char c, int n);


int main(int argc, string argv[])
{
    // if aren't 2 arguments (./caesar key) or aren't only digits or key is less than 0, show usage and return 1
    if ((argc != 2) || (only_digits(argv[1]) == false) || (atoi(argv[1]) < 0))
    {
        printf("Usage: ./caesar key\n");
        return (1);
    }

    int k = atoi(argv[1]);
    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");
    for (int i = 0; i < strlen(plaintext); i++)
    {
        char a = rotate(plaintext[i], k);
        printf("%c", a);
    }
    printf("\n");


}

bool only_digits(string s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        while (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

char rotate(char c, int n)
{
    if (isalpha(c))
    {
        if (islower(c))
        {
            c = c - 'a';
            c = (c + n) % 26;
            c = c + 'a';
        }
        else if (isupper(c))
        {
            c = c - 'A';
            c = (c + n) % 26;
            c = c + 'A';
        }
    }
    return c;
}