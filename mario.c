#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Defining Variables
    int n;
    int j;
    int i;
    int x;




    //Do and While loops, making sure the user cannot enter a negative number
    do
    {
        n = get_int("Height: ");

    }
    while (n < 0 || n > 23);
    //Repeats the loop for each number of rows
    for (i = 0; i < n; i++)
    {


        //creates the #'s and the space
        // varioble x and j are go the opposite ways as each other. When I increases, x decreases and j increases. Makes the pyramid-like structure
        for (x = 1 + i; x < n; x++)
        {
            printf(" ");
        }
        for (j = 1 + i; j > 0; j--)
        {
            printf("#");
        }


        printf("  ");
        for (j = 1 + i; j > 0; j--)
        {
            printf("#");
        }
        printf("\n");
    }


}
