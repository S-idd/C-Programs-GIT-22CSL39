#include <stdio.h>

int main () {

	int a ;

	int b ;

	int c ;

	printf("Enter The Value For a:") ;

	scanf("%d" ,&a) ;

	printf("Enter The Value For b:") ;

	scanf("%d" ,&b) ;


	c = a ;

	a = b ;

	b = c ;

	printf("The Value For a :%d \n ",a) ;

	printf("The Value For b :%d \n ",b) ;

	return 0 ;

}