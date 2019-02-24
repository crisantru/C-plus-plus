#include<stdio.h>

main()
{
	int i = 5;
	
	//declaran apuntadores de tipo entero
	int *p , *q;
	
	// se le asigna la direccion de i a el apuntador p, por medio de &
	// ya no es necesario poner * porq son el mismo tipo de dato (int) 
	p = &i;
	
	//se le asigna la direccion de p a q que es la misma que tiene i
	q = p;
	
	printf("direccion de i: %i \n", &i);
	printf("direccion de p: %i \n" , p);
	printf("direccion de q: %i \n", q);
	
}
