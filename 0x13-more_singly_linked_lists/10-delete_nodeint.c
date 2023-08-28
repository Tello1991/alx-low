#include <stdio.h>
#include <stdlib.h>

typedef struct listint_t {
    int data;
    struct listint_t *next;
} listint_t;

void deleteNodeAtIndex(listint_t **head, int index) {
    if (*head == NULL) {
        return; // List is empty
    }

    if (index == 0) {
        listint_t *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    listint_t *prev = NULL;
    listint_t *current = *head;
    int count = 0;

    while (current != NULL && count < index) {
        prev = current;
        current = current->next;
        count++;
    }

    if (current == NULL) {
        return; // Index is out of bounds
    }

    prev->next = current->next;
    free(current);
}

void printList(listint_t *head) {
    listint_t *current = head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

int main() {
    // Create a sample linked list
    listint_t *node1 = malloc(sizeof(listint_t));
    node1->data = 1;
    
    listint_t *node2 = malloc(sizeof(listint_t));
    node2->data = 2;
    
    listint_t *node3 = malloc(sizeof(listint_t));
    node3->data = 3;
    
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;

    // Print the original linked list
    printf("Original linked list: ");
    printList(node1);

    // Delete node at index 1
    deleteNodeAtIndex(&node1, 1);

    // Print the modified linked list
    printf("Linked list after deletion: ");
    printList(node1);

    // Free memory
    free(node1);
    free(node2);
    free(node3);

    return 0;
}
