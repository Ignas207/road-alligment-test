#include <stdio.h>
#include "road_alligment.h"
/**
 * @brief Function that will output the distance from the border.
 * 
 * @param image image array
 * @param quadrant which quadrant we want to check (1 - 4)
 * @param X middle X cordinate
 * @param Y middle Y cordinate
 * @return int, distance from the border.
 */

int Get_distance(bool **image, int quadrant, int X, int Y)
{
    int distX, distY, dist;
    int i = X;
    int j = Y;

    dist = 0;
    distX = 0;
    distY = 0;

    //TODO: add a check where image[X][Y] == 1 -> we are in the track
    if(image[i][j] == true)
    {
        switch(quadrant)
        {
            case 1: //checking the first quadrant
            {
                while(image[i][j] == true)//if the pixel is white i.e. we are still on the track 
                {                      //we save the value
                    if(i < X*2)
                    {
                        distX++;
                        i++;
                    }
                    else
                        break;
                    
                    if(j > 0)
                    {
                        distY++;
                        j--;
                    }
                    else
                        break;

                }
                break;
            }

            case 2: //checking the second quadrant
            {
                while(image[i][j] == true)//if the pixel is white i.e. we are still on the track 
                {                      //we save the value
                    if(i > 0)
                    {
                        distX++;
                        i--;
                    }
                    else
                        break;
                    
                    if(j > 0)
                    {
                        distY++;
                        j--;
                    }
                    else
                        break;

                }
                break;
            }

            case 3: //checking the third quadrant
            {
                while(image[i][j] == true)//if the pixel is white i.e. we are still on the track 
                {                      //we save the value
                    if(i > 0)
                    {
                        distX++;
                        i--;
                    }
                    else
                        break;
                    
                    if(j < 2*Y)
                    {
                        distY++;
                        j++;
                    }
                    else
                        break;

                }
                break;
            }

            case 4: //checking the fourth quadrant
            {
                while(image[i][j] == true)//if the pixel is white i.e. we are still on the track 
                {                      //we save the value
                    if(i < 2*X)
                    {
                        distX++;
                        i++;
                    }
                    else
                        break;
                    
                    if(j < 2*Y)
                    {
                        distY++;
                        j++;
                    }
                    else
                        break;

                }
                break;
            }
        }
    }
    
    dist = (int)sqrt(distX*distX + distY*distY);

    return dist;
}


/**
 * @brief Function, that will give the X, Y cordinates 
 * 
 * @param image -> Boolean array
 * @param freshold -> comparison freshold
 * @param movX_prev -> Previous X cordinate
 * @param movY_prev -> Previous Y cordinate
 * @param movX -> Next Y cordinate
 * @param movY -> Next X cordinate
 */
void Alligment(bool *image[X_MID*2], int *freshold, double *movX_prev, double *movY_prev, double *movX, double *movY)
{
    int dist1, dist2, dist3, dist4;

    int temp1 = 0;
    int temp2 = 0;

    int d1 = 0;
    int d2 = 0;

    dist1 = Get_distance(image, 1, X_MID, Y_MID);
    dist2 = Get_distance(image, 2, X_MID, Y_MID);
    dist3 = Get_distance(image, 3, X_MID, Y_MID);
    dist4 = Get_distance(image, 4, X_MID, Y_MID);

    d1 = dist1 - dist3;
    d2 = dist2 - dist4;
    if(d1 > *freshold)
    {
        temp1 = *movX_prev;
        temp2 = *movY_prev,

        temp1 -= d1;
        temp2 -= d1;
    }
    else if((d1* -1) > *freshold)
    {
        temp1 = *movX_prev;
        temp2 = *movY_prev,

        temp1 += (d1* -1);
        temp2 += (d1* -1);
    }

    *movX = temp1;
    *movY = temp2;
}