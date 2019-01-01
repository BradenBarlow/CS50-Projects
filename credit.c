#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
int main(void)
{
    string s;
    int x = 0;
    int p = 0;
    //Checks the input to see if the first digit is a number. Loops if it isn't a number.
    do
    {
        s = get_string("Credit: ");
        x = strlen(s);
        p = s[0] - 48;
    }
    while (p != 1 && p != 2 && p != 3 && p != 4 && p != 5 && p != 6 && p != 7 && p != 8 && p != 9 && p != 0);
    //Defines variables used in the algorithum later on
    int o = 0;
    int i = 0;
    int r = 0;
    int l = 0;
    //checks the first and second digit in the string, converts the ascii to real integer, q and b, by subtracting 48
    int b = s[0] - 48;
    int q = s[1] - 48;
    //Loops for the Luhn's algorithum for the amount of digits within the string
    for (i = x - 1; i >= 0;)
    {
        int y = s[i];
        y = y - 48;
        int t = i;
        //checks to see if the digit's place in the sequence is even or odd depending on how long the string is
        if ((x % 2 == 0 && t % 2 == 0) || (x % 2 != 0 && t % 2 != 0))
        {
            r = y * 2;
            if (r >= 10)
            {
                r = r - 9;
                o = o + r;
                i -= 1;
            }
            else
            {
                o = o + r;
                i -= 1;
            }
        }
        else
        {
            l = l + y;
            i--;
        }
    }
    //Checks to see if the number meets the requirements of the card type
    int h = 0;
    h = o + l;
    //Checks for requirements of AMEX card
    if (h % 10 == 0 && b == 3 && (q == 4 || q == 7) && x == 15)
    {
        printf("AMEX\n");
    }
    //Checks for requirements of VISA card
    else if (h % 10 == 0 && b == 4 && (x == 13 || x == 16))
    {
        printf("VISA\n");
    }
    //Checks for requirements for MASTERCARD card
    else if (h % 10 == 0 && b == 5 && (q == 1 || q == 2 || q == 3 || q == 4 || q == 5) && x == 16)
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
}