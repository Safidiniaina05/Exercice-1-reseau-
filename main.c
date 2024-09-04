#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "prototype.h"

int main()
{
    int a, b, c,  d, x, y, z, o;
    char chaine[100], chaine1[100];
    getData(chaine, a, b, c, d, chaine1, x, y, z, o);
    calcul(chaine , a, b, c, d, chaine1, x, y, z, o);
    return 0;
}