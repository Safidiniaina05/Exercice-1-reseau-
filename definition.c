#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "prototype.h"

void getData(char chaine[100], int a, int b, int c, int d, char chaine1[100], int x, int y, int z, int o)
{
    while (sscanf(chaine, "%d.%d.%d.%d", &a, &b, &c, &d)!=4)
    {
        printf("Entrer l'addrress IP: ");
        scanf("%s", chaine);
    }
    printf("\n");
    while(sscanf(chaine1, "%d.%d.%d.%d", &x, &y, &z, &o)!=4  &&  (x!=255) || (y!=255 && y!=254 && y!=252 && y!=248 && y!=240 && y!=224 && y!=192 && y!=128) || (z!=255 && z!=254 && z!=252 && z!=248 && z!=240 && z!=224 && z!=192 && z!=128 )|| (o!=255 && o!=254 && o!=252 && o!=248 && o!=240 && o!=224 && o!=192 && o!=128))
        {
            printf("NB: L'adress de MSR ne doit contenir que l'un de ces chiffres: 255, 254, 252, 248, , 224, 192, 128\n\n");
            printf("Entrer Le masque de sous réseau (MSR): ");
            scanf("%s", chaine1);
            printf("\n");
        }
}

void calcul(char chaine[100], int a, int b, int c, int d, char chaine1[100], int x, int y, int z, int o)
{
    int g, l;
    int q=0, s=255, t, f=2;
    int tmp;
    int p=128, m=192, n=224, w=240, e=256;
    if (sscanf(chaine, "%d.%d.%d.%d", &a, &b, &c, &d)==4 && sscanf(chaine1, "%d.%d.%d.%d", &x, &y, &z, &o)==4)
        { 
            printf("IP: %d.%d.%d.%d\n", a, b, c, d);
            printf("MSR: %d.%d.%d.%d\n", x, y, z, o);

            if(x==255 && y==255 && z==255 && o==255)
                {
                    printf("\n@ Réseau: %d.%d.%d.%d\n", a, b, c, d);
                    printf("@ broadcast: %d.%d.%d.%d\n", s, s, s, s);
                }
            else if(x==255 && y==255 && z==255 && o==254)
                {
                    if(d%2==0)
                        {
                            printf("\n@ Réseau: %d.%d.%d.%d\n\n", a, b, c, d);
                        }
                    else
                        {
                            printf("\n@ Réseau: %d.%d.%d.%d\n\n", a, b, c, d-1);
                        }
                
                //    printf("@ broadcast: %d.%d.%d.%d\n", a, b, s, s);
                }
            else if(x==255 && y==255 && z==255 && o==252)
                {
                    if(d<=3)
                        {
                            printf("\n@ Réseau: %d.%d.%d.0\n", a, b, c);
                        }
                    else if(d>=pow(2,2) && d<pow(2,3))
                        {
                            printf("\n@ Réseau: %d.%d.%d.4\n\n", a, b, c);
                        }
                    else if(d>=pow(2,3) && d<=11 || (d>=13 && d<=15))
                        {
                            printf("\n@ Réseau: %d.%d.%d.8\n\n", a, b, c);
                        }
                    else if(d==12)
                        {
                            printf("\n@ Réseau: %d.%d.%d.%d\n\n", a, b, c, d);
                        }
                    else if(d>=pow(2,4) && d<pow(2,5) && d!=20 && d!=24 && d!=28)
                        {
                            printf("\n@ Réseau: %d.%d.%d.16\n\n", a, b, c);
                        }
                    else if(d==20)
                        {
                            printf("\n@ Réseau: %d.%d.%d.%d\n\n", a, b, c, d);
                        }
                    else if(d==24)
                        {
                            printf("\n@ Réseau: %d.%d.%d.%d\n\n", a, b, c, d);
                        }
                    else if(d==28)
                        {
                            printf("\n@ Réseau: %d.%d.%d.%d\n\n", a, b, c, d);
                        }              
                    else if(d>=pow(2,5) && d<pow(2,6) && d!=pow(2,5)+pow(2,4) && d!=pow(2,5)+pow(2,3) && d!=pow(2,5)+pow(2,4)+pow(2,3))
                        {
                            printf("\n@ Réseau: %d.%d.%d.32\n\n", a, b, c);
                        }
                    else if(d==pow(2,5)+pow(2,4) || d==pow(2,5)+pow(2,3) || d==pow(2,5)+pow(2,4)+pow(2,3))
                        {
                            printf("\n@ Réseau: %d.%d.%d.%d\n\n", a, b, c, d);
                        }
                    else if(d>=pow(2,6) && d<pow(2,7) && d!=pow(2,6)+pow(2,5) && d!=pow(2,6)+pow(2,4) && d!=pow(2,6)+pow(2,3) && d!=pow(2,6)+pow(2,5)+pow(2,4)+pow(2,3))
                        {
                            printf("\n@ Réseau: %d.%d.%d.64\n\n", a, b, c);
                        }
                    else if(d==pow(2,6)+pow(2,5) || d==pow(2,6)+pow(2,4) || d==pow(2,6)+pow(2,3) || d==pow(2,6)+pow(2,5)+pow(2,4)+pow(2,3))
                        {
                            printf("\n@ Réseau: %d.%d.%d.%d\n\n", a, b, c, d);
                        }
                    else if(d>=pow(2,7) && d<255 && d!=pow(2,7)+pow(2,6) && d!=pow(2,7)+pow(2,5) && d!=pow(2,7)+pow(2,4) && d!=pow(2,7)+pow(2,3) && d!=pow(2,7)+pow(2,6)+pow(2,5)+pow(2,4)+pow(2,3))
                        {
                            printf("\n@ Réseau: %d.%d.%d.128\n\n", a, b, c);       
                        }
                    else if(d==pow(2,7)+pow(2,6) || d==pow(2,7)+pow(2,5) || d==pow(2,7)+pow(2,4) || d==pow(2,7)+pow(2,3) || d==pow(2,7)+pow(2,6)+pow(2,5)+pow(2,4)+pow(2,3))
                        {
                            printf("\n@ Réseau: %d.%d.%d.%d\n\n", a, b, c, d);
                        }
                    else if(d==255)
                        {
                            printf("\n@ Réseau: %d.%d.%d.%d\n\n", a, b, c, o);
                        }
                    
                    //printf("@ broadcast: %d.%d.%d.%d\n", a, s, s, s);
                }

        }
}