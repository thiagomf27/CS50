#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

bool not_repeat(string s);
char encrypt(string k, char c);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return (1);
    }

    string key = argv[1];

    if (strlen(key) != 26)
    {
        printf("key should have 26 letters\n");
        return (1);
    }

    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("key should have 26 letters\n");
            return (1);
        }
    }

    for (int i = 0; i < strlen(key); i++)
    {
        key[i] = tolower(key[i]);
    }
    if (not_repeat(key) == false)
    {
        printf("key should not repeat letters\n");
        return (1);
    }

    string plaintext = get_string("plaintext: ");

    printf("\n");
    printf("ciphertext: ");
    for (int i = 0; i < strlen(plaintext); i++)
    {
        char a = encrypt(key, plaintext[i]);
        printf("%c", a);
    }
    printf("\n");

}

bool not_repeat(string s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        for (int j = i + 1; j < strlen(s); j++)
        {
            if (s[j] == s[i])
            {
                return false;
            }
        }
    }
    return true;
}

char encrypt(string k, char p)
{
    if (islower(p))
    {
        char alphabetmin[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
        for (int i = 0; i < 26; i++)
        {
            if (alphabetmin[i] == p)
            {
                int index = i;
                p = tolower(k[index]);
                break;
            }
        }
    }
    if (isupper(p))
    {
        char alphabetmai[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
        for (int i = 0; i < 26; i++)
        {
            if (alphabetmai[i] == p)
            {
                int index = i;
                p = toupper(k[index]);
                break;
            }
        }
    }
    return p;
}