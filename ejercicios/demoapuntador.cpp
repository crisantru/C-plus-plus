#include<stdio.h>

main()
{
	int a = 25;
	
	printf("a= %i \n",a);
	//imprime la direccion de la memoria de a
	printf("La direccion de memoria de a es: %d", &a);
	
	return 0;
}
