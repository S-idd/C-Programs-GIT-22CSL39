#include <stdio.h>

int main () {

	int  i ;

	int p ;

	printf("Enter The Principle :") ;

	scanf("%d",&p) ;

	int r ;

	printf("Enter The Rate Of Interest :") ;

	scanf("%d",&r) ;

	int t ;

	printf("Enter The Amount Fo Time :") ;

	scanf("%d",&t) ;

	i  = (p * r * t )/ 100;

	printf("The Simple Interest :%d \n" ,i) ;
}