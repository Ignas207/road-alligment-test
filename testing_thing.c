#include <stdio.h>
#include "testing.h"

int main(void)
{

    bool image[X][Y] = {false};

    Generator((void*)&image, 0);
    printf("\nGenerated picture:\n");
    Printing((void*)&image);
    printf("\n\nModified picture:\n");

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
                    if((i >= 10) && (i <= 20)) //filling a line of pixels
                    { //TODO: modify these values
                            if((j > 8) && (j < 13))
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
void Printing(void *image)
{
    bool **image2 = (bool*)&image;
    int i = 0;
    int j = 0;

     for(i = 0; i < X; i++)
    {
        for(j = 0; j < Y; j++)
        {
            
            if(*((*image2 +i) +j) == true)
                printf("# ");
            else
                printf(". ");

            if((i == X/2) && (j == Y/2))
                printf("M");
        }
        printf("\n");
    }
}