#include<stdio.h>

void copiaString(char *p, char *b);


main()
{
	char cadena1[30] = "hola mi nombre es Cristian", b[30];
	
	copiaString(cadena1, b);
	printf("%s", b);
	
	
	return 0;
}

void copiaString(char *p, char *b)
{
	
	int i;
	
	for(i = 0; i < 30; i++)
	{
		
		b[i] = p[i];		
	}
	
	
	
}
