#include<stdio.h>

main()
{
	int x = 17, y;
	int *p;
	
	p = &x;
	
	//imprime el valor de x mediante *
	printf("El valor de x es: %i", *p);
	
	return 0;
	
	
}
