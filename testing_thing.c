#include <stdio.h>
#include "testing.h"

int main(void)
{

    bool image[X][Y] = {false};
    int movX, movY;
    int freshold = 2;
    movX = movY = 0;

    

    Generator((void*)&image, 1);
    printf("\nGenerated picture:\n");
    Printing((void*)&image, 0, 0);
    printf("\n\nModified picture:\n");
    Get_distance((void*)&image, X/2, Y/2, &freshold, &movX, &movY);
    Printing((void*)&image, movX, movY);


    return 0;
}

/**
 * @brief Will generate a boolean image
 * 
 * @param image Boolean image
 * @param which 0 -> middle point is on false value;
 *              1 -> middle point is on true value
 */
void Generator(void *image, int which)
{
  bool **image2 = (bool*)&image;
    int i = 0;
    int j = 0;
    for(i = 0; i < X; i++)
    {
        for(j = 0; j < Y; j++)
        {
            switch(which)
            {
                case 0: //starting on false
                    if((i >= 10) && (i <= 20)) //filling a line of pixels
                    {
                            if((j > 8) && (j < 13))
                                *((*image2 +i) +j) = true;
                    }
                    break;

                case 1: //starting on true 
                   // if((j > 20) && (j < 25)) //filling a line of pixels
                    { //TODO: modify these values
                            if((i > 10) && (i < 13))
                                *((*image2 +i) +j) = true;
                    }
                    break;
            }
        }
    }
}


/**
 * @brief Prints the boolean image
 * 
 * @param image our boolean image
 */
void Printing(void *image, int movX, int movY)
{
    bool **image2 = (bool*)&image;
    int i = 0;
    int j = 0;

    int midY = Y/2 + movY;
    int midX = X/2 + movX;

    for(i = 0; i < Y; i++)
    {
        for(j = 0; j < X; j++)
        {
            
            if(*((*image2 +i) +j) == true)
                printf("# ");
            else
                printf(". ");

            if((i == midX) && (j == midY))
                printf("M");
        }
        printf("\n");
    }
}