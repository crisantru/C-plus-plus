#include<stdio.h>

main()
{
	int a[10]={1,2,3,4,5,6,7,8,9,10}, i;
	
	int *p;
	
	p = a;
	//p = &a[0] otra forma correcta
	
	// * apunta al valor de la direccion
   //	printf("%i \n", *p);
	
	for(i = 0; i<10; i++)
	{
		
		printf("%i", *p);
		p++;
		
	}
	
	return 0;
	
}
