#ifndef TESTING
#define TESTING

#include "algorithm/road_alligment.h"
#include <stdbool.h>
#include <stdlib.h>
#include "spng/spng.h"

#define X 30
#define Y 40

void Generator(void **image, int which);
void Printing(void *image, int movX, int movY);

int Mem_assign(void **image, int x, int y);
void Mem_free(void **image, int x, int y);
void SafeFree(void **data);

#endif