#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //variables
    int h, r, c, s;

    //height
    do
    {
        h = get_int("height: ");
    }
    while (h < 1 || h > 8);

//left side

    //row
    for (r = 0; r < h; r++)
    {
        //space
        for (s = 0; s < h - r - 1; s++)
        {
            printf(" ");
        }
        //column
        for (c = 0; c <= r; c++)
        {
            printf("#");
        }
        printf("  ");
        for (c = 0; c <= r; c++)
        {
            printf("#");
        }
        printf("\n");
    }
}
