#include <cs50.h>
#include <stdio.h>

int main(void)

// Prompt for pyramid height, reprompt if input is not betweeen 1 and 8
{
    int(height);
    do
    {
        height = get_int("Pyramid Height: ");
    }
// use boolean expression to test for input
    while (height < 1 || height > 8);

// If input is valid, print number of boxes inputted in pyramid shape
// use a for loop for this for (initialization; condition; update)
    for (int i = 0; i < height; i++)
    {
        // Add spaces to code
        for (int k = height - 1; k > i; k--)
        {
            printf(" ");
        }

        // add hashtags
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}