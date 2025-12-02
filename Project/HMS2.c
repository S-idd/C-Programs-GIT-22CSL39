#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age ;
    char disease[60];
} Patient;

typedef struct {
    Patient *patients; // dynamic array
    int front;
    int rear;
    int capacity;
} Queue;

// ----------------------------
// Initialize Circular Queue
// ----------------------------
void initQueue(Queue *q, int size) {
    q->patients = (Patient *)malloc(size * sizeof(Patient));

    if (q->patients == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    q->capacity = size;
    q->front = -1;
    q->rear = -1;
}

// ----------------------------
// Check if Queue is Empty
// ----------------------------
int isEmpty(Queue *q) {
    return (q->front == -1); // True : 1 False : 0
}

// ----------------------------
// Check if Queue is Full
// ----------------------------
int isFull(Queue *q) {
    return ((q->rear + 1) % q->capacity) == q->front; // True : 1 False : 0
}

// ----------------------------
// Enqueue (Add Patient)
// ----------------------------
void enqueue(Queue *q, char *name ,int age ,char *disease) {
    if (isFull(q)) {
        printf("Queue is FULL. Cannot add patient.\n");
        return;
    }

    if (isEmpty(q)) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % q->capacity;
    }

    strcpy(q->patients[q->rear].name, name);
    strcpy(q->patients[q->rear].disease,disease) ;
    q->patients[q->rear].age=age;
    printf("Patient '%s' added to the queue.\n", name);
}

// ----------------------------
// Dequeue (Treat Patient)
// ----------------------------
void dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("No patients waiting.\n");
        return;
    }

    printf("Treating patient: %s\n", q->patients[q->front].name);

    if (q->front == q->rear) {
        // Last patient removed → queue resets
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % q->capacity;
    }
}

// ----------------------------
// Display Queue
// ----------------------------
void displayQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("\nCurrent Waiting Patients:\n");

    int i = q->front;
    while (1) {
        printf("%d Patient Name : %s\n", (i+1),q->patients[i].name);
        printf("%d Patient disease diagnosing With : %s\n",(i+1),q->patients[i].disease);
        printf("%d Patient Age :%d\n",(i+1),q->patients[i].age);

        if (i == q->rear) break;
        i = (i + 1) % q->capacity;
    }
}

// ----------------------------
// Main Program
// ----------------------------
int main() {
    Queue q; //pointer Of struct Queue
    int size;

    printf("Enter maximum number of patients that can wait: ");
    scanf("%d", &size);

    initQueue(&q, size);

    int choice;
    char name[50];
    char disease[50];
    int age ;

    while (1) {
        printf("\n\n--- Hospital Emergency Room System ---\n");
        printf("PRESS 1 Add Patient (Enqueue)\n");
        printf("PRESS 2 Treat Patient (Dequeue)\n");
        printf("PRESS 3 Display Waiting Patients\n");
        printf("PRESS 4 Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter patient name: ");
                scanf("%s", name);
                printf("Enter The disease :");
                scanf("%s",disease);
                printf("Enter The age :");
                scanf("%d",&age);
                enqueue(&q, name,age,disease);
                break;

            case 2:
                dequeue(&q);
                break;

            case 3:
                displayQueue(&q);
                break;

            case 4:
                free(q.patients); // free dynamically allocated memory
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
}
