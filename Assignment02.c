#include <stdio.h>

int Add (int Array[],int n) {

	int Sum = 0 ;

	for (int i = 0; i < n ;i++) {

		Sum+=Array [ i ] ;

	}
	return Sum ;
}

int Sub(int Array[] ,int n) {

	int Sub = 0 ;

	for (int i = 0; i < n ;i++) {

		Sub-=Array [ i ] ;

	}

	return Sub ;

}

int Mul (int Array[] ,int n) {

	int Pro = 1 ;

	for (int i = 0; i < n ;i++) {

		Pro*=Array [ i ] ;

	}

	return Pro ;
}


int main (){

	int Array[ 5 ] = {4,5,6,7,8} ;

	int n =  5 ;

	for (int i = 0 ; i <  n ; i++) {

		printf(" %d ,",Array [ i ]) ;
	}
	printf("\n") ;

	char ch  ;

	printf("****Menu**** \n") ;

	printf("1.Addition \n") ;

	printf("2.Subtraction \n") ;

	printf("3. Multiplication \n") ;

	printf("Enter Choice :") ;

	scanf("%c" ,&ch) ;


	int (*AddFunctiontptr) (int [] ,int ) =  &Add;

	int (*SubFunctionptr) ( int [] ,int )  = &Sub ;

	int (*MulFunctionptr) (int [] ,int )  = &Mul ;

	switch (ch) {

		case '1' : printf("Addition : %d \n" ,AddFunctiontptr (Array ,n)) ;
				   break ; 

		case '2' : printf("Subtraction : %d" ,SubFunctionptr (Array ,n)) ;
				   break ; 

		case '3' : printf("Multiplication : %d" ,MulFunctionptr (Array ,n)) ;
				   break ; 

		default : printf("Select Correct Option ") ;
				  break ;
	}

}