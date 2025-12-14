#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->prev = newnode->next = NULL;
    return newnode;
}

// Insert at end
void insertEnd(struct Node** head, int data) {
    struct Node* newnode = createNode(data);

    if (*head == NULL) {
        *head = newnode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
    newnode->prev = temp;
}

// Merge list2 into list1
struct Node* mergeLists(struct Node* head1, struct Node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    struct Node* temp = head1;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;
    head2->prev = temp;

    return head1;
}

// Sort DLL using Bubble sort (swap data)
void sortList(struct Node* head) {
    int swapped;
    struct Node *ptr1, *ptr2;

    if (head == NULL) return;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != NULL) {
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
    } while (swapped);
}

// Find middle using slow–fast pointer
int findMiddle(struct Node* head) {
    struct Node *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}

// Print DLL
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node *list1 = NULL, *list2 = NULL, *merged = NULL;

    int n1, n2, data;

    printf("Enter number of elements in List1: ");
    scanf("%d", &n1);
    printf("Enter elements for List1:\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &data);
        insertEnd(&list1, data);
    }

    printf("Enter number of elements in List2: ");
    scanf("%d", &n2);
    printf("Enter elements for List2:\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &data);
        insertEnd(&list2, data);
    }

    merged = mergeLists(list1, list2);

    printf("\nCombined List: ");
    printList(merged);

    sortList(merged);

    printf("Sorted List: ");
    printList(merged);

    int middle = findMiddle(merged);
    printf("Middle Element = %d\n", middle);

    return 0;
}