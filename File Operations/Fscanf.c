#include <stdio.h>

int main () {

	char FileData[30] ;

	

	FILE *fptr ;

	fptr = fopen ("D:\\College(GIT) C\\C-Programs-GIT-22CSL39\\File Operations\\Student.txt","r");

	if (fptr == NULL) {

		printf("Failed To Open The File !!!") ;

	}else{

		while (fscanf(fptr ,"%s",FileData) == 1) {

			printf("%s \n",FileData) ;
		
		}
	}

	fclose (fptr);
	return 0;
}