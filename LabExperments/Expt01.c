#include <stdio.h>

void Read_Array (int *ptr ,int size) { //1

	for (int i = 0 ; i < size ; i++) {

		scanf("%d" ,(ptr + i));
	}
}

void Display_Array (int *ptr ,int size) { //2

	for (int i = 0 ; i < size ;i++) {
		printf("%d ,",*(ptr +  i) );
	}
	printf("\n");
}

int Max (int *ptr ,int size) { //3

	int max = *ptr ;

	for (int i = 0 ; i < size ;i++) {

		if (*(ptr + i) > max) {

			max = *(ptr + i) ;

		}
	}
	return max ;
}

int Search (int *ptr ,int size ,int key ) { //4

	for (int i = 0 ; i < size ;i++) {
		if (*(ptr + i) == key) {
			return i ;
		}
	}

	return 0 ;

}

void Reverse_Array (int *ptr ,int size) { //5

	int ptr1 = 0 ;

	int ptr2 = size - 1;

	while (ptr1 < ptr2) {

		int temp = *(ptr + ptr1) ;

		*(ptr + ptr1) = *(ptr + ptr2) ;

		*(ptr + ptr2) = temp ;

		ptr1++;

		ptr2--;

	} 
}

int main (){

	int size ;

	printf("Enter The Size Of The Array :") ;

	scanf("%d" ,&size) ;

	int Array[size] ;

	int *ptr = Array ;

	int Option ;

	int key ;

	do{
	
		printf("****Menu**** \n") ;

		printf("1 -> Read_Array \n") ;

		printf("2 -> Display_Array \n") ;

		printf("3 -> Exit \n") ;

		printf("4 -> Maximum Element \n") ;

		printf("5 -> Search In Array \n") ;
		
		printf("6 ->Reverse An Array \n") ;

		printf("Enter The Option :") ;

		scanf("%d" ,&Option) ;

		if (Option == 5) {

			printf("Enter The Value That You Want to Search :") ;

			scanf("%d" ,&key) ;
		}

		switch (Option) {

			case 1: Read_Array (ptr ,size) ;
					break ;
			case 2: Display_Array (ptr ,size) ;
					break;
			case 3: printf("Exited The Programm !!!");
					break;

			case 4  :printf("The Maximum Element In The Array Is :%d \n",Max (ptr , size) ) ;
					break ;

			case 5 :printf("The Element Is Peresent At Index : %d \n" ,Search (ptr,size,key)) ;
					break ;

			case 6 :Reverse_Array (ptr ,size) ;
					printf("Reversed And Array Check By Displaying The Array \n") ;
					break ;
		}

	}while (Option != 3) ;


	return 0 ;

}