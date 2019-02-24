//Programa con Apuntadores para paso de parametros por referencia

#include<stdio.h>

void imprimeCadena(char *);

main()
{
	

	char cadena[20] = "Hola a todos";
	
	imprimeCadena(cadena);
	
	return 0;
	
	
}

void imprimeCadena(char *p)
{ 
	int i = 0;
	
	for (i = 0; i < 20; i++)
	{
		printf("%c \n", p[i]);
		
	}
	
	
	
	
}
