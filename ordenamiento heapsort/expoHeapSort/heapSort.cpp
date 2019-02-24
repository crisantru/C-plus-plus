#include <iostream>
#define max 100
using namespace std;

int main()
{
	int A[max],j,item,temp,i,k,n;
	cout<<"Ingresa la cantidad de elementos del arreglo: ";
	cin>>n;
	for(i=1;i<=n;i++)
		cin >> A[i];
	cout<<"Valor de i: "<<i<<endl;
	for(k=n;k>0;k--)
	{	
		cout<<"Valor de K: "<<k<<endl;
		for(i=1;i<=k;i++)
		{
			cout<<"Iteracon de i: "<<i<<endl;
			item=A[i];
			cout<<"Valor de item: "<<item<<endl;
			j=i/2;
			cout<<"Valor de j: "<<j<<endl;
			while(j>0 && A[j]<item)
			{
				A[i]=A[j];
				i=j;
				j=j/2;
			}
			A[i]=item;
			cout<<"A["<<i<<"]: "<<A[i]<<endl;
			cout<<"Salio de el ciclo de I"<<endl<<endl;
		}
		temp=A[1];
		A[1]=A[k];
		A[k]=temp;
	}
	cout<<"El orden es:"<<endl;
	for(i=1;i<=n;i++)
		cout<<A[i] <<"  ";
	return 0;
}
