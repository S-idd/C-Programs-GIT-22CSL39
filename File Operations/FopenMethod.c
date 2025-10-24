#include <stdio.h>

int main (){

	FILE *fptr ;

	char name [30];

	printf("Enter The Your Name :") ;

	scanf("%s",name) ;

	int Age ;

	printf("Enter Your Age :") ;

	scanf("%d",&Age) ;

	//fopen
	fptr = fopen ("D:\\College(GIT) C\\C-Programs-GIT-22CSL39\\File Operations\\Student.txt","a") ;

	fprintf(fptr, "Name:%s \nAge:%d\n",name,Age);

	fclose (fptr);
}