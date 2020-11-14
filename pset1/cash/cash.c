// Problem set 1 - Cash
// Make a greedy algoritm 

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float owed;
  
    do 
    {                                     
        owed = get_float("Cash owed\n");
    }
    while (owed < 0);
  
    int cents = round(owed * 100);          // Converts dollars to rounded cents
    int coins = 0;
  
    while (cents >= 25)                      // Counts 1 coin for every 25 cents and updates remaining cents
    {
        coins++;
        cents -= 25;
    }
 
    while (cents >= 10)
    {
        coins++;
        cents -= 10;
    }
 
    while (cents >= 5)
    {
        coins++;
        cents -= 5;
    }
  
    while (cents >= 1)
    {
        coins++;
        cents -= 1;
    }
    
    printf("%i\n", coins);
}