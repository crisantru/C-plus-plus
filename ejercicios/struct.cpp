#include<stdio.h>
#include<stdlib.h>

main()
{
	int n,i;
	
	struct datosPersonales {
		char nombre [30];
		char apellidoP [20];
		char apellidoM [20];
		int edad;
		char carrera [20];
		char matricula [20];
		char universidad[20];
	};
	
	printf("Dame el numero de alumnos para registrar: \n");
	scanf("%d", &n);
	
	struct datosPersonales alumno[n];
	
	for(i = 0; i < n; i++)
	{
		printf("Ingresa el nombre del alumno: \n");
		gets(alumno[i].nombre);
		fflush(stdin);
		printf("Ingresa el apellido paterno del alumno: \n");
		gets(alumno[i].apellidoP);
		printf("Ingresa el apellido materno del alumno: \n");
		gets(alumno[i].apellidoM);
		printf("Ingresa la edad del alumno: \n");
		scanf("%d", &alumno[i].edad);
		printf("Ingresa la carrera del alumno: \n");
		gets(alumno[i].carrera);
		printf("Ingresa la matricula del alumno: \n");
		gets(alumno[i].matricula);
		printf("Ingresa la universidad del alumno: \n");
		gets(alumno[i].universidad);
		
		
	}
	
	return 0;
	
}
	
	
	
	
	
	
	
	
	
	
	
	
	


