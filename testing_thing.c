#include <stdio.h>
#include "testing.h"

int main(void)
{

    //bool image[Y][X] = {false};

    
    bool **image = NULL;

    //bool **image3;


    int movX, movY;
    int freshold = 2;
    movX = movY = 0;


    Mem_assign((void*)&image, X, Y);
    
    puts("You working?");
 //   puts("do you compile?");
    
    
    Generator((void*)&image, 1);
    printf("\nGenerated picture:\n");
    Printing((void*)image, 0, 0);
    printf("\n\nModified picture:\n");
//    Get_distance((void*)&image, X/2, Y/2, &freshold, &movX, &movY);
//    Printing((void*)&image, movX, movY);
    

   Mem_free((void**)&image, X, Y);

    return 0;
}

/**
 * @brief Will generate a boolean image
 * 
 * @param image Boolean image
 * @param which 0 -> middle point is on false value;
 *              1 -> middle point is on true value
 */
void Generator(void **image, int which)
{
  bool **image2 = (bool**)*image;
    int i = 0;
    int j = 0;
    for(i = 0; i < Y; i++)
    {
        for(j = 0; j < X; j++)
        {
            switch(which)
            {
                case 0: //starting on false
                    if((i >= 10) && (i <= 20)) //filling a line of pixels
                    {
                            if((j > 5) && (j < 15))
                                *(*(image2 +i) +j) = 1;
                    }
                    break;

                case 1: //starting on true 
                    if((j >= 20) && (j <= 25)) //filling a line of pixels
                    { //TODO: modify these values
                            if((i > 7) && (i < 13))
                            {
                                *(*(image2 +i) +j) = 1; //why is this not working?
                            }
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
    bool **image2 = (bool*)image;

    int i = 0;
    int j = 0;

    int midY = Y/2 + movY;
    int midX = X/2 + movX;

    printf("M coordinates: (%d;%d)\n", midX, midY);

    for(i = 0; i < Y; i++)
    {
        for(j = 0; j < X; j++)
        {
            
            if(*(*(image2 +i) +j) == true)
            {
                printf("# ");
                //printf("(%d;%d) ", i, j);
            }
            else
                printf(". ");

            if((i == midX) && (j == midY))
            {
                printf("M");
            }
        }
        printf("\n");
    }
}


int Mem_assign(void **image, int x, int y)
{

    bool **temp = NULL;
    int i = 0;

    //temp = ((bool*)*image);

    temp = (bool*)calloc((size_t)y, sizeof(bool));
    if(temp == NULL)
    {
        puts("Memory allocation failed!");
        Mem_free((void*)&temp, x, y);
        return EXIT_FAILURE;
    }

    for(i = 0; i < y; i++)
    {
        *(temp + i) = (bool*)calloc((size_t)x, sizeof(bool));
        
        if(*(temp + i) == NULL)
        {
            puts("Memory allocation failed!");
            Mem_free((void*)&temp, x, y);
            return EXIT_FAILURE;
        }
        
    }

    *image = ((void*)temp);
    return 0;
}



void Mem_free(void **image, int x, int y)
{
    int i = 0;
    void **temp = *image;
    //bool **temp = NULL;

   // temp = (bool**)&image;

    for(i = 0; i < y; i++)
    {
        if(*(temp + i) != NULL)
            SafeFree((temp + i));
    }

    //SafeFree(&temp);
}


void SafeFree(void **data)
{
    if(data != NULL && *data != NULL)
    {
        free(*data);
        *data = NULL;
    }
}
