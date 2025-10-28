#include <stdio.h>
#include <stdlib.h>

#define Max_Size 50 

int Array [Max_Size];

int Top = -1;

void push (int x ) {

	if (Top >= Max_Size -1 ) {

		printf("Stack Is OverFlow");

		exit(1);

	}else{

		Top++;
		Array[Top] = x ;

	}

}

int Pop (){

	if (Top < 0){

		printf("The Stack Is Under Flow");

		exit(1);
	}else{

		int Removed_Element = Array [Top];

		Top--;

		return Removed_Element; 
	}

}

void Dispaly () {

	if (Top == -1) {

		printf("The Stack Is Empty !!");
		exit(1);
	}
	printf("Stack :");

	for (int i = 0 ;i <= Top ;i++){

		printf("%d ,",Array[i]);
	}
	printf("\n");
}

int main (){

	int Option ;

	int x ;

	int Element ;


	while (1) {

		printf("*******Menu******** \n");

		printf("1.Push \n");

		printf("2.Pop \n");

		printf("3.Dispaly \n");

		printf("4.Exit \n");

		printf("Enter The Operatation Do You Want To Perform :");

		scanf("%d",&Option);

		switch (Option) {

			case 1 : printf("Enter The Element That You Want To Enter In The Stack :");
				 scanf("%d",&x);
				 push(x);
				 break;

			case 2 :Element = Pop ();
					printf("\n");
					printf("The Poped Element From The Stack Is:%d" ,Element);
					break;

			case 3 :Dispaly();
				break;

			case 4 :printf("Extied !!! \n");
				exit(0);
				break;

			default :
				printf("Choose Valid Operatation \n");
				break;
		}

	}
}