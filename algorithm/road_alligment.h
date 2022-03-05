#include <math.h>
#include <stdbool.h>

#ifndef ALLIGN
#define ALLIGN

#define X_MID 80
#define Y_MID 60
#define SPEED 1

int Get_distance(void *image, int quadrant, int X, int Y);

void Alligment(void *image, int *freshold, 
               double *movX_prev, double *movY_prev,
               double *movX, double *movY);


#endif