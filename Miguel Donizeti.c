#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#define pi 3.14159265359

int main(){
    float seno[91],cosseno[91],angulo[91], sen=0, rad=0,ang=0,cos=0;
    int maior=0, menor=0,i=0,j=0;

    FILE *psen;
    FILE *ptrigo;
    FILE *psencos;

    ptrigo = fopen("trigo.txt", "r");

    do
	{
		fscanf(ptrigo, "%f %f %f\n", &angulo[i], &seno[i], &cosseno[i]);
		i++;

	}while(! feof(ptrigo));
        fclose(ptrigo);

    psen = fopen("seno.txt", "r");
    psencos = fopen("senocosseno.txt", "w");

    do
	{
        fscanf(psen,"%f \n", &sen);
        //caso for valor redondo
        if (seno[i] == sen)
		{
            for(i=0,cos=0,ang=0,rad=0;i<91;i++)
			{
                if(sen == seno[i])
				{
                    rad= (angulo[i]*pi)/180;
                    sen = seno[i];
                    cos = cosseno[i];
                    fprintf(psencos, "%f %f %f \n", rad, sen, cos);

              	  break;
                }
        	}
        }

        else if(seno[i] != sen)
		{
            for(i=0;i<91;i++)
			{
                if(sen < seno[i])
				{
                    ang = ((seno[i]-sen) / (seno[i]-seno[i-1]));
                    cos = cosseno[i] - ang*(cosseno[i]-cosseno[i-1]);
                    rad = ((i-ang)*pi)/180;
                    fprintf(psencos,"%f %f %f \n", rad, sen, cos);
                    break;
           		}
            }

		}
    }while(! feof(psen));
        fclose(psen);
        fclose(psencos);
}
