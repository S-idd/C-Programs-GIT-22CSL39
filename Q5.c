#include <stdio.h>

int main () {

	int n ;

	printf("Enter The Number :") ;

	scanf("%d" ,&n) ;

	if ( n % 2 == 0) {

		printf("The Number Is Even:%d \n" , n) ;

	}else {

		printf("The Number Is Odd: %d \n",n) ;
	}
}