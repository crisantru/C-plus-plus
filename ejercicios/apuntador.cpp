#include<stdio.h>

main()
{
	
	int a = 5;
	float b = 3.333;
	//declaracion de apuntador a entero
	int *p = &a;
	//declaracion de apuntador flotante
	float *q = &b;
	
	//valor inicial de a
	printf("%d \n", a);
	printf("%f \n", b);
	
	//modificando valor de a mediante puntero
	*p = 7;
	*q = 5.4;
	printf( "%d \n", a);
	printf( "%f", b);
	
	return 0;
	
	
}
