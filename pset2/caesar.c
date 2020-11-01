//C50 Pset2 Caesar. Cyphering a plaintext with a key


#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int main(int argc, string arcv[])
{
    //checks if only 1 argument is provided
    if (argc == 2)
    {
        // loops through the key, if not entairily digit kills the program
        for (int i = 0; i < strlen(arcv[1]); i++)
        {
            if (!isdigit(arcv[1][i]))
            {
                printf("Usage: ./caesar key\n"); 
                return 1;
            }
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
    //Gets the plaintext
    string plaintext = get_string("plaintext: ");
    
    printf("ciphertext: ");
    
    //Loops through the plaintext
    for (int j = 0; j < strlen(plaintext); j++)
    {
        //Prints the char intact if it not a letter
        if (!isalpha(plaintext[j]))
        {
            printf("%c", plaintext[j]);
        }
        //Prints the char with the key applied
        if (isupper(plaintext[j]))
        {
            int ci = (plaintext[j] - 65 +  atoi(arcv[1])) % 26;  
            printf("%c", ci + 65);
        }
      
        if (islower(plaintext[j]))
        {
            int ci = (plaintext[j] - 97 +  atoi(arcv[1])) % 26;  
            printf("%c", ci + 97);
        }
    }
    //Prints a new line
    printf("\n");  
}



