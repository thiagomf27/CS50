#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    long number;
    int digits;

    number = get_long("Number: ");

    //long numbercp to don't lose number in the for loop
    long numbercp;
    numbercp = number;
    for (digits = 1; (numbercp = numbercp / 10) != 0; digits++);

    if (digits < 13 || digits > 16 || digits == 14)
    {
        printf("INVALID\n");
        exit(0);
    }

    // separating the digits of the number
    int yes1, yes2, yes3, yes4, yes5, yes6, yes7, yes8;
    int not1, not2, not3, not4, not5, not6, not7, not8;

    not1 = number % 10;
    yes1 = (number / 10) % 10;
    not2 = (number / 100) % 10;
    yes2 = (number / 1000) % 10;
    not3 = (number / 10000) % 10;
    yes3 = (number / 100000) % 10;
    not4 = (number / 1000000) % 10;
    yes4 = (number / 10000000) % 10;
    not5 = (number / 100000000) % 10;
    yes5 = (number / 1000000000) % 10;
    not6 = (number / 10000000000) % 10;
    yes6 = (number / 100000000000) % 10;
    not7 = (number / 1000000000000) % 10;
    yes7 = (number / 10000000000000) % 10;
    not8 = (number / 100000000000000) % 10;
    yes8 = (number / 1000000000000000) % 10;

    // checksum

    //multipliyng the numbers by 2
    yes1 = yes1 * 2;
    yes2 = yes2 * 2;
    yes3 = yes3 * 2;
    yes4 = yes4 * 2;
    yes5 = yes5 * 2;
    yes6 = yes6 * 2;
    yes7 = yes7 * 2;
    yes8 = yes8 * 2;

    // making the sum with the 2 possible digits
    int sum = yes1 % 10 + (yes1 / 10) % 10 + yes2 % 10 + (yes2 / 10) % 10 + yes3 % 10 + (yes3 / 10) % 10 + yes4 % 10 +
              (yes4 / 10) % 10 + yes5 % 10 + (yes5 / 10) % 10 + yes6 % 10 + (yes6 / 10) % 10 + yes7 % 10 + (yes7 / 10) % 10 + yes8 % 10 +
              (yes8 / 10) % 10;

    // adding the sum to the sum of the digits that weren’t multiplied by 2

    int result = sum + not1 + not2 + not3 + not4 + not5 + not6 + not7 + not8;

    // extracting the first numbers of number
    int firstnumber;
    int firstnumbervisa;
    if (digits == 13)
    {
        firstnumber = number / 1000000000000;
    }
    else if (digits == 15)
    {
        firstnumber = number / 10000000000000;
    }
    else
    {
        firstnumber = number / 100000000000000;
        firstnumbervisa = number / 1000000000000000;
    }

    // concluding the checksum and saying if the credit card is from VISA, AMEX, MASTERCARD or INVALID
    if ((result % 10 == 0) && (digits == 13 || digits == 16) && (firstnumber == 4 || firstnumbervisa == 4))
    {
        printf("VISA\n");
    }
    else if ((result % 10 == 0) && (digits == 15) && (firstnumber == 34 || firstnumber == 37))
    {
        printf("AMEX\n");
    }
    else if ((result % 10 == 0) && (digits == 16) && (firstnumber == 51 || firstnumber == 52 || firstnumber == 53 || firstnumber == 54
             || firstnumber == 55))
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

