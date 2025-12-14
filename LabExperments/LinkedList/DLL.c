#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *head = NULL;

// Create a new node
Node* createNode(int data) {
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}

// Insert at beginning
void insertAtBeginning(int data) {
    Node *newnode = createNode(data);

    if (head == NULL) {
        head = newnode;
        return;
    }

    newnode->next = head;
    head->prev = newnode;
    head = newnode;
}

// Insert at end
void insertAtEnd(int data) {
    Node *newnode = createNode(data);

    if (head == NULL) {
        head = newnode;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newnode;
    newnode->prev = temp;
}

// Insert at position (1-based)
void insertAtPosition(int data, int pos) {
    if (pos <= 1) {
        insertAtBeginning(data);
        return;
    }

    Node *newnode = createNode(data);
    Node *temp = head;
    int i = 1;

    while (temp != NULL && i < pos - 1) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        insertAtEnd(data);
        return;
    }

    newnode->next = temp->next;
    newnode->prev = temp;

    if (temp->next != NULL){
        temp->next->prev = newnode;
    }

    temp->next = newnode;
}

// Delete at beginning
void deleteAtBeginning() {
    if (head == NULL) return;

    Node *temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    free(temp);
}

// Delete at end
void deleteAtEnd() {
    if (head == NULL) return;

    Node *temp = head;

    if (temp->next == NULL) {
        head = NULL;
        free(temp);
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    free(temp);
}

// Delete at position
void deleteAtPosition(int pos) {
    if (pos <= 1) {
        deleteAtBeginning();
        return;
    }

    Node *temp = head;
    int i = 1;

    while (temp != NULL && i < pos) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) return;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    free(temp);
}

// Display list
void display() {
    Node *temp = head;

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int search(int target) {
    Node *temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == target) {
            printf("Element %d found at position %d\n", target, pos);
            return pos;
        }
        temp = temp->next;
        pos++;
    }
    printf("Element %d not found\n", target);
    return -1;
}


// MAIN FUNCTION
int main() {
    int choice, data, pos;

    while (1) {
        printf("\n--- SIMPLE DOUBLY LINKED LIST MENU ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at End\n");
        printf("6. Delete at Position\n");
        printf("7. Search Element\n");
        printf("8. Display List\n");
        printf("9. Exit\n");
        printf("--------------------------------------\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;

            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;

            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertAtPosition(data, pos);
                break;

            case 4:
                deleteAtBeginning();
                break;

            case 5:
                deleteAtEnd();
                break;

            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteAtPosition(pos);
                break;

            case 7:
                printf("Enter element to search: ");
                scanf("%d", &data);
                search(data);
                break;

            case 8:
                display();
                break;

            case 9:
                return 0;

            default:
                printf("Invalid option!\n");
        }
    }
}

