
//Manejo de archivos
/*
a = append
r = read
w = write


*/

#include<stdio.h>

struct rec
{
	int x, y, z;
	
};

main()
{
	int i;
	FILE *ptr_myfile;
	struct rec my_record;
	
	
	ptr_myfile=fopen("text.bin", "rb");
	
	
	if (!ptr_myfile)
	{
		printf("Unable to open file!!!");
		return 1;
		
	}
	
	for (i = 9; i >= 0; i--)
	{
		fseek(ptr_myfile, sizeof(struct rec) *i, SEEK_SET);
		fread(&my_record, sizeof(struct rec), 1, ptr_myfile);
		printf("%d\n", my_record.x);
		
	}
	
	fclose(ptr_myfile);
	return 0;
	
}
