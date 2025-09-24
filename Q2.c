#include <stdio.h>

int main (){
	
	int a ;

	int b ;

	int c ;

	char option ;

	printf("**Menu** \n") ;

	printf("1.Addition \n") ;

	printf("2.Subtraction \n") ;

	printf("3.Mulitplication \n") ;

	printf("4.Divide \n") ;

	printf("Enter The option :") ;

	scanf("%c" ,&option) ;

	printf("Enter The Value For a :") ;

	scanf("%d" ,&a) ;

	printf("Enter The Value For b :") ;

	scanf("%d",&b);


	switch (option) {

		case '1' : c = a + b ;
				   printf("The Result : %d" ,c) ;
				   break ;

		case '2' : c = a - b ;
				   printf("The Result : %d" ,c) ;
				   break ;

		case '3' : c = a * b ;
				   printf("The Result : %d" ,c) ;
				   break ;

		case '4' : c = a % b ;
				   printf("The Result : %d" ,c) ;
				   break ;

		default :
				printf("Please Select Correct option") ;
				break ;
	}

	return 0 ;

}