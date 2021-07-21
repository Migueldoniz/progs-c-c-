#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main ()
{
	char strings [100][100];
	int count;
	do{
        	printf ("Digite uma string: ");
        	scanf("%[^\n]",strings[count]);
            setbuf(stdin,NULL);
            if(strcmp(strings[count],"FIM")!=0)
            count++;
        }while((strcmp(strings[count],"FIM"))!=0);
	printf ("\n\n\nAs strings que voce digitou foram:\n\n");
	for (count=0;count<5;count++)
                printf ("%s\n",strings[count]);
        return(0);
}