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

int Get_distance(void *image, int X, int Y)
{
    bool **imageB = (bool*)&image;

    int dist_Xp, dist_Xn, dist_Yp, dist_Yn = 0;
    int i = X;
    int j = Y;

    int choice = 0;
    int stop = 0;



    if(*(*(imageB + i) +j) == true) //if our middle point is in the red part
    {
        for(choice = 0; choice < 4; choice++)
        {
            i = X;
            j = Y;
            stop = 0;

            while((*(*(imageB + i) +j) == true) && (stop == 0))
            {
                switch(choice)
                {
                    case 0: //X negative distance
                        if(i < 2*X) //making sure we dont overflow
                        {
                            i++;
                            dist_Xn++;
                        }
                        else    //not sure if this will do anything
                            stop = 1;
                        break;

                    case 1: //X positive distance
                        if(i > 0) //making sure we dont underflow
                        {
                            i--;
                            dist_Xp++;
                        }
                        else
                            stop = 1;
                        break;

                    case 2: //Y negative distance
                        if(j > 0) //making sure we dont underflow
                        {
                            j--;
                            dist_Yn++;
                        }
                        else
                            stop = 1;
                        break;

                    case 3: //Y positive distance
                        if(j < 2*Y) //making sure we dont overflow
                        {
                            j++;
                            dist_Yp++;
                        }
                        else
                            stop = 1;
                        break;
                }
            }
        }
    }

    //TODO: add a condition where we start at FALSE

    
    //dist = (int)sqrt(distX*distX + distY*distY);

    return 0;
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
void Alligment(void *image, int *freshold, double *movX_prev, double *movY_prev, double *movX, double *movY)
{
    bool **imageB = (bool*)&image;

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