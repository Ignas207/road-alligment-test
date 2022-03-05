#include <stdio.h>
#include "testing.h"

int main(void)
{

    bool image[X][Y] = {false};

    Generator((void*)&image);
    Printing((void*)&image);

    return 0;
}


void Generator(void *image)
{
  bool **image2 = (bool*)&image;
    int i = 0;
    int j = 0;
    for(i = 0; i < X; i++)
    {
        for(j = 0; j < Y; j++)
        {
           if((i >= 10) && (i <= 20)) //filling a line of pixels
           {
                if((j > 8) && (j < 13))
                    *((*image2 +i) +j) = true;
           }
        }
        printf("\n");
    }
}


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
                printf("1 ");
            else
                printf("0 ");

            if((i == X/2) && (j == Y/2))
                printf("MID ");
        }
        printf("\n");
    }
}