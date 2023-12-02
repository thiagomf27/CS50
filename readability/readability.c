#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int letter(int l, string s);
int word(int w, string s);
int sentence(int sen, string s);

int main(void)
{
    int letters = 0, words = 0, sentences = 0;

    string text = get_string("Text: ");

    letters = letter(letters, text);
    printf("%i\n", letters);

    words = word(words, text);
    printf("%i\n", words);

    sentences = sentence(sentences, text);
    printf("%i\n", sentences);

    // Coleman-Liau index
    float L = ((float)letters / (float)words) * 100.0;
    float S = ((float)sentences / (float)words) * 100.0;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int x = round(index);

    if (x >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (x < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", x);
    }

}

int letter(int l, string s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (isalpha(s[i]))
        {
            l++;
        }
    }
    return l;
}

int word(int w, string s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == ' ')
        {
            w++;
        }
    }
    return w + 1;
}

int sentence(int sen, string s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if ((s[i] == '.') || (s[i] == '!') || (s[i] == '?'))
        {
            sen++;
        }
    }
    return sen;
}
