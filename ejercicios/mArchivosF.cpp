//Manejo de Archivos
#include<stdio.h>

struct datosPersonales
{
	char nombre[30];
	char apellidoP[20];
	char apellidoM[20];
	char escuela[20];
	int edad;
	char matricula[15];
	int tel;
	char carrera[20];

	};

main()
{
	int i,n;
	FILE *ptr_myfile;

	struct datosPersonales alumno, alumno2;

	ptr_myfile=fopen("log.txt", "r+");

	if(!ptr_myfile)
	{
      printf("No existe el archivo \n");
      printf("Vuelve a ejecutar el programa \n");
      ptr_myfile=fopen("log.txt", "w");


	  return 1;


	}

	printf("Dame la cantidad de alumnos para ingresar: ");
	scanf("%d", &n);

	for(i=0; i < n; i++)
	{

        printf("Ingresa el nombre del alumno: \n");
        scanf("%s", alumno.nombre);
        printf("Ingresa el nombre del apellido Paterno: \n");
        scanf("%s", alumno.apellidoP);
        printf("Ingresa el nombre del apellido Materno: \n");
        scanf("%s", alumno.apellidoM);
        printf("Ingresa el nombre de tu escuela: \n");
        scanf("%s", alumno.escuela);
        printf("Ingresa tu edad: \n");
        scanf("%d", &alumno.edad);
        printf("Ingresa tu matricula: \n");
        scanf("%s", alumno.matricula);
        printf("Ingresa tu numero de tel.: \n");
        scanf("%d", &alumno.tel);
        printf("Ingresa tu carrera: \n");
        scanf("%s", alumno.carrera);


        //printf("%s, %s, %s, %s, %d, %s, %d, %s", alumno.nombre, alumno.apellidoP, alumno.apellidoM, alumno.escuela, alumno.edad, alumno.matricula, alumno.tel, alumno.carrera );

		fseek(ptr_myfile, sizeof(struct datosPersonales) * i, SEEK_SET);
		fwrite(&alumno, sizeof(struct datosPersonales), 1, ptr_myfile);


		}


    for(i=0; i < n; i++)
    {

        fseek(ptr_myfile, sizeof(struct datosPersonales) * i, SEEK_SET);
        fread(&alumno2, sizeof(struct datosPersonales), 1, ptr_myfile);
        printf("Registros Guardados \n");
        printf("%s \n", alumno2.nombre);
        printf("%s \n", alumno2.apellidoP);
        printf("%s \n", alumno2.apellidoM);
        printf("%s \n", alumno2.escuela);
        printf("%d \n", alumno2.edad);
        printf("%s \n", alumno2.matricula);
        printf("%d \n", alumno2.tel);
        printf("%s \n", alumno2.carrera);


    }

    fclose(ptr_myfile);
	return 0;




	}
