#include <stdio.h>

#define Max_Size 20

int Array[Max_Size] ;

int front =-1;

int rear =-1;

int Is_full (){

	return (rear + 1) % Max_Size == front; 
}

int Is_Empty (){

	return front == -1;
}

void enqueue(int x){

	if (Is_full()){
		printf("The Queue Is Full");
	}else{
		if (Is_Empty()){
			front = 0;
		}
		rear = (rear+1) % Max_Size ;
		Array[rear] = x;
	}

}

int dequeue (){

	if (Is_Empty()){
		printf("Queue Is Empty ");
		return -1;
	}else{
		int x = Array[front];
		if (front == rear){
			front=-1;
			rear=-1;
		}else{
			front = (front +1) % Max_Size ;
		}
		return x;
	}


}

void display (){

	for (int i = front ;i <= rear ;i++) {
		printf("%d ," ,Array [ i ]);
	}
	printf("\n");
}	

int main (){

	int Option ;

	int Insert ;

	int Removed ;

	do  {

		printf("\n********Menu*********\n");
		printf("\n1.enqueue\n");
		printf("\n2.dequeue\n");
		printf("\n3.display\n");
		printf("\n4.Exit\n");

		printf("\n");

		printf("Enter Your Option :") ;
		scanf("%d",&Option);

		switch (Option){

			case 1: 
					printf("Enter The Value : ");
					scanf("%d",&Insert);
					enqueue(Insert);
					break ;

			case 2 : 
					Removed = dequeue();
					if (Removed!=-1){
						printf("The Element Removed Form The Queue Is :%d \n",Removed);
					}
					break;

			case 3 :
					display();
					break;

			case 4 :
					printf("Exitedd !!!");
					break;

			default :
					printf("Choose The Correct Option");

		}

	}while (Option !=4);

}