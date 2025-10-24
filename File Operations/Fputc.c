#include <stdio.h>

int main () {

	//File Pointer 

	FILE *fprt = fopen ("D:\\College(GIT) C\\C-Programs-GIT-22CSL39\\File Operations\\Student.txt","a") ; 

	char name [30] ;

	printf("Enter Your Name :");

	scanf("%s",name) ;

	if (fprt == NULL) {

		printf("Failed Write In File !!!");
	}

	for (int i = 0 ; name [ i ]!= '\0' ;i++) {

		fputc (name[i],fprt);
	}

	fclose (fprt) ;

	return 0 ;

}