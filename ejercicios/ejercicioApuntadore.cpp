// copia de arreglos por medio de un puntero
#include<stdio.h>

main()
{
	int a[10]={1,2,3,4,5,6,7,8,9,10}, b[10], i;
	int *p;
	
	for(i = 0; i<10; i++)
	{
		// asigna los valores de a al puntero
		*p = a[i];
		// copia los valores del apuntador en el arreglo b
		b[i] = *p;
		
		//imprime vector b
		printf("%i", b[i]);
		
		
	}
	
	
	
	return 0;
	
}






