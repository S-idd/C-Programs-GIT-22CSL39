#include <stdio.h>

int main (){

	char ch ;

	int a ;

	int b  ;

	printf("**Menu**\n") ;

	printf("1.Addition \n") ;

	printf("2.Subtraction \n") ;

	printf("3.Mulitplication \n");

	printf("4.Division \n") ;

	printf("Enter Your Choice :") ;

	scanf("%c",&ch) ;

	printf("Enter The Value For A :") ;

	scanf("%d" ,&a) ;

	printf("Enter The Value For B :") ;

	scanf("%d",&b) ;

	//Creating The pointers 

	int *ptra = &a ;

	int *ptrb = &b;

	switch (ch){

		case '1' :printf("%d", *ptra + *ptrb );
				  break;
		case '2' :printf("%d", *ptra - *ptrb );
				  break;
		case '3' :printf("%d", *ptra  * *ptrb );
				  break;
		case '4' :printf("%d", *ptra / *ptrb );
				  break;
		default :
				printf("Select The Correct Output") ;
				break ;

	}

	return 0 ;
}