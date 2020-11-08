#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#define BLOCKSIZE 512

int main(int argc, char *argv[])
{
    
    if (argc != 2)
    {
        
        printf("Usage: ./recover image\n");
        return 1;
    }
    
    
    char *infile = argv[1];
    FILE *inputfile = fopen(infile, "r");
    if (inputfile == NULL)
    {
        printf("Unable to open\n");
        return 1;
    }
    
    
    char filename[8];
    uint8_t buffer[BLOCKSIZE];
    FILE *outputfile = NULL;
    int counter = 0;
    
    
    while (fread(buffer, sizeof(uint8_t), BLOCKSIZE, inputfile)  || feof(inputfile) == 0)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            sprintf(filename, "%03i.jpg", counter);
            outputfile = fopen(filename, "w");
            counter++;
        } 
        if (outputfile != NULL)
        {
            fwrite(buffer, sizeof(buffer), 1, outputfile);
        }
       
      
        
        
        
    }

    if (outputfile != NULL)
    {
        fclose(outputfile);
    }

    if (inputfile != NULL)
    {
        fclose(inputfile);
    }

}
