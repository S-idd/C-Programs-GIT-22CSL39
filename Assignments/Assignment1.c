#include <stdio.h>
#define MAX 50

int stack1[MAX], stack2[MAX];
int top1 = -1, top2 = -1;

// Stack operations
void push1(int x) { stack1[++top1] = x; }
void push2(int x) { stack2[++top2] = x; }

int pop1() { return stack1[top1--]; }
int pop2() { return stack2[top2--]; }

int isEmpty1() { return top1 == -1; }
int isEmpty2() { return top2 == -1; }

// Queue operations
void enqueue(int x) {
    push1(x);
    printf("%d enqueued\n", x);
}

int dequeue() {
    int item;

    if (isEmpty1() && isEmpty2()) {
        printf("Queue is Empty!\n");
        return -1;
    }

    if (isEmpty2()) {
        while (!isEmpty1()) {
            push2(pop1());
        }
    }

    item = pop2();
    printf("%d dequeued\n", item);
    return item;
}

void display() {
    int i;

    if (isEmpty1() && isEmpty2()) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue elements: ");

    // Print stack2 (top to bottom)
    for (i = top2; i >= 0; i--)
        printf("%d ", stack2[i]);

    // Print stack1 (bottom to top)
    for (i = 0; i <= top1; i++)
        printf("%d ", stack1[i]);

    printf("\n");
}

int main() {
    int choice, x;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &x);
                enqueue(x);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}