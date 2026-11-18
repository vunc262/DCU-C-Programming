#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    float data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *createNode(float number);
Node *pushBack(Node *head, float number);
Node *getTail(Node *head);
void printList(Node *tail);
void freeList(Node *head);

int main(int argc, char const *argv[])
{
    if (argc < 2) {
        return 1;
    }

    int number = atoi(argv[1]);
    if (argc != number + 2) {
        return 1;
    }

    Node *head = NULL;
    for (int i = 0; i < number; i++) {
        head = pushBack(head, atof(argv[i + 2]));
    }
    Node *tail = getTail(head);
    printList(tail);
    freeList(head);
    return 0;
}

Node *createNode(float number)
{
    Node *node = malloc(sizeof(Node));
    if (node == NULL) {
        return NULL;
    }
    node->data = number;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

Node *pushBack(Node *head, float number)
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
    newNode->prev = current;
    return head;
}

Node *getTail(Node *head)
{
    if (head == NULL) {
        return NULL;
    }
    Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    return current;
}

void printList(Node *tail) {
    Node *current = tail;
    while (current != NULL) {
        printf("%.2f\n", current->data);
        current = current->prev;
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