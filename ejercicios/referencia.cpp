#include<stdio.h>


int suma(int a, int b, int &c);

main()
{

int a = 8, b = 8, c = 0;

suma(a,b,c);
printf("%d \n", c);

return 0;



}

int suma(int a, int b, int &c)
{
    
 c = a+b;
 
    
}

