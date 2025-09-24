#include <stdio.h>

int main () {

	int n  ;

	printf("Enter The Number :") ;

	scanf("%d" ,&n) ;

	for (int i = 1 ; i <= 10 ; i++) {

		printf("%d X %d = %d \n" ,i , n  ,i * n) ;

	}

	printf("\n") ;
}