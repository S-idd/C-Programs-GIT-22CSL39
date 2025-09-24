#include <stdio.h>

int main () {

	int a = 10 ;

	int b = 20 ;

	int c = 30 ;

	if (a > b && a > c) {

		printf("A Is Greater :%d \n" ,a) ;

	}else if (b > a && b > c) {

		printf("B Is Greater :%d \n",b);

	}else{
		printf("C Is Greater :%d \n" ,c) ;
	}

	return 0 ;
}