#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float avgcol;
    
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            avgcol = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.000);
            image[i][j].rgbtBlue  = avgcol;
            image[i][j].rgbtGreen = avgcol;
            image[i][j].rgbtRed   = avgcol;
        }
    }
    
    
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    
    int sepiaRed, sepiaGreen, sepiaBlue;
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sepiaRed   = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            sepiaBlue  = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
            
            if (sepiaRed > 255 || sepiaRed < 0)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = sepiaRed;
            }
            
            if (sepiaGreen > 255 || sepiaGreen < 0)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = sepiaGreen;
            }
            if (sepiaBlue > 255 || sepiaBlue < 0)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = sepiaBlue;
            }
            
            
        }
    }
    
    
    
    
    
    
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    
    RGBTRIPLE temp;
    
    
    for (int i = 0; i < height; i++)
    {
        
        for (int j = 0; j < width / 2; j++)
        {
        
            temp =  image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;
        }
    
    }
    

    
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int sumBlue;
    int sumGreen;
    int sumRed;
    float counter;
    
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            sumBlue = 0;
            sumGreen = 0;
            sumRed = 0;
            counter = 0.00;

            // looks at neighbour pixels and check if corner or limits of the image
            for (int k = -1; k < 2; k++)
            {
                if (j + k < 0 || j + k > height - 1)
                {
                    continue;
                }

                for (int h = -1; h < 2; h++)
                {
                    if (i + h < 0 || i + h > width - 1)
                    {
                        continue;
                    }

                    
                    sumBlue += image[j + k][i + h].rgbtBlue;
                    sumGreen += image[j + k][i + h].rgbtGreen;
                    sumRed += image[j + k][i + h].rgbtRed;
                    counter++;
                }
            }

            // save the new pixels in a temporarty image array
            temp[j][i].rgbtBlue = round(sumBlue / counter);
            temp[j][i].rgbtGreen = round(sumGreen / counter);
            temp[j][i].rgbtRed = round(sumRed / counter);
        }
    }

   
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            // save the new pixels in the original image array
            image[j][i].rgbtBlue = temp[j][i].rgbtBlue;
            image[j][i].rgbtGreen = temp[j][i].rgbtGreen;
            image[j][i].rgbtRed = temp[j][i].rgbtRed;
        }
    }
}