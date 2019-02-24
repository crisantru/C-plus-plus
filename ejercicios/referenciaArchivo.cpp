#include<stdio.h>

void abre(FILE int &fp);

main()
{
      
   FILE *fp;
   
   //fp = abre();
   abre(fp);
   
   fclose(fp);
   
   return 0;
      

       
      
}

void abre(FILE int &fp)
{
     fp =fopen("log.txt", "r+");
     
     if(!fp)
	 {
          printf("No existe el archivo \n");
          printf("Vuelve a ejecutar el programa \n");
          ptr_myfile=fopen("log.txt", "w");
    
    
    	  return 1; 
	 }
     
     return 0;
     
     
}
