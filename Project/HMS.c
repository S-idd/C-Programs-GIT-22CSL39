#include <stdio.h>

#include <stdlib.h>

#define MAX 20 

int front = -1;

int rear = -1;

int Queue[MAX] ;


int IsFull(){

	if (rear == MAX -1){
		return 0 ;
	}else{
		return 1;
	}
}

int IsEmpty (){

	if (front >= rear  || front == -1){
		return 0;
	}else{
		return 1;
	}
}


void enqueue (int value){

	if (IsFull()){
		printf("Queue Is Full");
	}else{

		if (IsEmpty() ){
			front = 0;
		}
		rear++;
		Queue[rear] = value ;
	}
}


int  dequeue (){

	int copy = 0 ;

	if (IsEmpty()){
		printf("Queue Is Empty");
	}else{
		copy = Queue[front];
		front++;
	}
	return copy ;
}

void display(){

	if (IsEmpty()){
		printf("Queue Is Empty\n");
	}
	for (int i = front ; i <= rear ;i++){
		printf("%d ",Queue[i]);
	}
	printf("\n");
}

int search (int Target ){

	for (int i = front ; i <= rear ; i++) {
		if (Queue[i] == Target){
			printf("Element Found At ");
			return Queue[i] ;
		}else{
			return -1 ;
		}
	}
}

int main (){

	int option , value , deletedElement , foundElement ,Target;

	do {
		printf("-----------MENU---------\n");
		printf("PRESS 1 Enqueue Element \n");
		printf("PRESS 2 Dequeue Element \n");
		printf("PRESS 3 Display Elements \n");
		printf("PRESS 4 Search Element \n");
		printf("PRESS 5 Exit \n");

		printf("Enter Your choice : ");
		scanf("%d" ,&option);

		switch (option){

			case 1 :
					printf("Enter The Element That You Want Enqueue In To Queue : ");
					scanf("%d",&value);
					enqueue(value);
					break ;

			case 2 :
					deletedElement = dequeue();
					printf("Deleted Element Form The Queue Is : %d \n" ,deletedElement);
					printf("Verify By  Display The Queue (PRESS 3)");			
					break;


			case 3 :
					display();

			case 4 :
					printf("Enter The Element That You Wan To Search In The Queue :");
					scanf("%d",&Target);
					foundElement = search(Target);
					if (foundElement != -1){
						printf("Element Found In Queue :%d \n",foundElement);
					}else{
						printf("Sorry Element Not Found ");
					}

			case 5 :
					printf("Exited !!!!\n");
					break ;

			default :
					printf("Invalid Choice Select Correct Choice !!");
					break;

		}



	}while (option != 5);


}