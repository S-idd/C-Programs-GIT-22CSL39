// Online C compiler to run C program online
#include <stdio.h>
#define Max_Size 20 

int array[Max_Size];
int rear =-1;
int front =-1;

void enqueue (int x) {
    if (rear == Max_Size -1){
        printf("Queue Is Full");
    }else{
        if (rear ==-1){
            front++;
        }
        rear++;
        array[rear] = x;
    }
}

int dequeue (){
    int Removed ;
    if (front ==-1 || front > rear){
        printf("Queue is Empty ");
        return -1;
    }else{
        Removed = array[front];
        front++;
        if (front > rear){
            front =-1;
            rear =-1;
        }
    }
    return Removed;
}

void display () {
    
    for (int i = front ; i <=rear ;i++) {
        printf("%d  ",array[i]);
    }
    printf("\n");
}
int main() {
  
    int option ;
    
    int insertElement ;
    
    int removedElement ;
    
    do {
        printf("\n****Menu********\n");
        printf("\n1.Enqueue\n");
        printf("\n2.Dequeue\n");
        printf("\n3.Display\n");
        printf("\n4.Exit\n");
        printf("\n");
        printf("Enter Choice :");
        scanf("%d",&option);
        
        switch (option){
            case 1:
                    printf("Enter The Element That You Insert :");
                    scanf("%d",&insertElement);
                    enqueue(insertElement);
                    break;
            
            case 2: removedElement = dequeue();
                    if(removedElement == -1){
                        printf("Queue Is Empty ");
                    }else{
                        printf("The Removed Element From The Queue Is : %d",removedElement);
                    }
                    break;
            
            case 3:
                    display();
                    break;
            
            case 4 :
                    printf("\n Exited !!!!!\n");
                    break;
            
        }
        
    }while (option != 4);

    return 0;
}