#include <stdio.h>
#include "testing.h"

int main(void)
{

    bool image[X][Y] = {false};

    Generator((void*)&image);

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
            if(*((*image2 +i) +j) == true)
                printf("1 ");
            else
                printf("0 ");
        }
        printf("\n");
    }

    //printf("i = %d\n", &i);
}