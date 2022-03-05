#include <stdio.h>
#include "testing.h"
int main(void)
{

    bool image[X][Y] = {false};

    Generator(&image);

    return 0;
}


void Generator(bool **image)
{
    printf("This is working!\n");
}