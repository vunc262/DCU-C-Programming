#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *createNode(int number);
Node *pushBack(Node *head, int number);
Node *insertAfter(Node *head, int number, int position);
void printList(Node *head);
void freeList(Node *head);

int main(int argc, char const *argv[])
{
    if (argc != 3) {
        return 1;
    }
    int numbers[] = {8, 7, 3, 4, 5, 6, 9, 2, 14, 12};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    Node *head = NULL;
    for (int i = 0; i < size; i++) {
        head = pushBack(head, numbers[i]);
    }
    head = insertAfter(head, atoi(argv[2]), atoi(argv[1]));
    printList(head);
    freeList(head);
    return 0;
}

Node *createNode(int number)
{
    Node *node = malloc(sizeof(Node));
    if (node == NULL) {
        return NULL;
    }
    node->data = number;
    node->next = NULL;
    return node;
}

Node *pushBack(Node *head, int number)
{
    Node *newNode = createNode(number);
    if (newNode == NULL) {
        return head;
    }
    if (head == NULL) {
        return newNode;
    }

    Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

Node *insertAfter(Node *head, int number, int position)
{
    Node *current = head;
    while (current != NULL && current->data != position) {
        current = current->next;
    }
    if (current == NULL) {
        return head;
    }
    Node *newNode = createNode(number);
    if (newNode == NULL) {
        return head;
    }
    Node *temp = current->next;
    current->next = newNode;
    current->next->next = temp;
    return head;
}

void printList(Node *head)
{
    Node *current = head;
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}

void freeList(Node *head)
{
    Node *current = head;
    while (current != NULL) {
        Node *next = current->next;
        free(current);
        current = next;
    }
}