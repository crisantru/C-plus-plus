#include<stdio.h>

void suma(float c, float &x);

main()
{
	float c, x;
	
	printf("Dame el subtotal para darte el total con IVA: ");
	scanf("%f", &c);
	
	suma(c, x);
	
	printf("tu total es: %.2f", x);
	
	return 0;
	
	
	
}


void suma(float c, float &x)
{
	float i;
	
	i = c * .16;
	x = c + i;
	
	
}
