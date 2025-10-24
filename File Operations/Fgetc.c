#include <stdio.h>

int main () {
	
	//Create A pointer 
	FILE *fptr ;

	fptr = fopen ("D:\\College(GIT) C\\C-Programs-GIT-22CSL39\\File Operations\\Student.txt" ,"r" );

	if (fptr == NULL) {

		printf("Failed To Open The File ");

	}

	do {

		char Reader = fgetc(fptr);

		if (feof(fptr)) {

			break ;
		}

		printf("%c",Reader);

	}while (1);
	
	fclose (fptr) ;
	return 0 ;

}