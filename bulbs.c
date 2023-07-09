#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // Ask user for a message
    string message = get_string("Message: \n");

    // initialize ascii
    for (int i = 0, j = strlen(message); i < j; i++)
    {
        int BINARY[] = {0, 0, 0, 0, 0, 0, 0, 0,};

        int decimals = message [i];


        // ASCII to binary
        int k = 0;
        while (decimals > 0)
        {
            BINARY[k] = decimals % 2;
            decimals = decimals / 2;
            k++;
        }
        // print binary in reverse
        for (int n = BITS_IN_BYTE - 1; n >= 0; n--)
        {
            print_bulb(BINARY[n]);
        }
        printf("\n");
    }
}

void print_bulb(int bit)
{

    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }

}

