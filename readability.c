#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    //Prompt user for Text and return with printf
    string text = get_string("Text: ");

    // printf("%s\n", text); was used to check text

    int count_letter = 0;
    int count_word = 1;
    int count_sentence = 0;

    // Set up counting letter length
    int letter_length = strlen(text);
    for (int i = 0; i < letter_length; i++)
    {
        if (isalpha(text[i]))
        {
            count_letter++;
        }
    }
    // printf("Letters: %i\n", count_letter);

    // Set up counting words
    int word_length = strlen(text);
    for (int i = 0; i < word_length; i++)
    {
        if (isspace(text[i]))
        {
            count_word++;
        }
    }
    // printf("Words: %i\n", count_word);

    // Set up counting sentences
    int sentence_length = strlen(text);
    for (int i = 0; i < sentence_length; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count_sentence++;
        }
    }
    // printf("Sentences: %i\n", count_sentence);

    // Calculate Grade
    // Grade formula: index = 0.0588 * L = 0.296 * S - 15.8
    float calculate_grade = (0.0588 * count_letter / count_word * 100) - (0.296 * count_sentence / count_word * 100) - 15.8;
    int formula = round(calculate_grade);

    // Print out grade
    if (formula < 1)
    {
        printf("Before Grade 1\n");
    }

    else if (formula > 16)
    {
        printf("Grade 16+\n");
    }

    else
    {
        printf("Grade %i\n", formula);
    }
}