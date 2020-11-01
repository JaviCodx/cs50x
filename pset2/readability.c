#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count(string text);
int grading(int letters, int words, int sentences);

//Set an array for the counters to access from all functions
int counters[] = { 0, 1, 0};

int main(void)
{
// Gets text input and prints the number of letter,words and sentences
    string text = get_string("Text: ");
    count(text);
    printf("%i letter(s)\n%i word(s)\n%i sentence(s)\n", counters[0], counters[1], counters[2]);
    if (grading(counters[0], counters[1], counters[2]) < 1)
    {
        printf("Before Grade 1\n");
    }
    else if ((grading(counters[0], counters[1], counters[2]) >= 16))
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grading(counters[0], counters[1], counters[2]));
    }
}

// Counts letters, words and sentences
int count(string text)
{
    
    for (int i = 0; i < strlen(text); i++)
    {
        if (islower(text[i]) || isupper(text[i]))
        {
            counters[0]++;
        }
        else if (isspace(text[i]))
        {
            counters[1]++;
        }
        else if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            counters[2]++;
        }
        
       
    }
    return 0;
}

//Grades the text based on Coleman-Liau index
int grading(letters, words, sentences)
{
    float avgletters = ((float)letters / words) * 100;
    float avgsentences = ((float)sentences / words) * 100;
    float index = (0.0588 * avgletters)  - (0.296 * avgsentences) - 15.8;
    return round(index);
}
