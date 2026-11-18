#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *createNode(int number);
Node *pushBack(Node *head, int number);
Node *getTail(Node *head);
Node *popBack(Node *tail);
void printList(Node *head);
void freeList(Node *head);

int main(int argc, char const *argv[])
{
    if (argc < 2) {
        return 1;
    }

    int number = atoi(argv[1]);
    if (argc != number + 4) {
        return 1;
    }

    Node *head = NULL;
    for (int i = 0; i < number; i++) {
        head = pushBack(head, atoi(argv[i + 2]));
    }
    Node *tail = getTail(head);
    tail = popBack(tail);
    tail = popBack(tail);
    if (tail == NULL) {
        head = NULL;
    }
    head = pushBack(head, atoi(argv[number + 2]));
    head = pushBack(head, atoi(argv[number + 3]));
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
    node->prev = NULL;
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

Node *popBack(Node *tail)
{
    if (tail == NULL) {
        return NULL;
    }
    if (tail->prev == NULL) {
        free(tail);
        return NULL;
    }
    Node *current = tail;
    tail = tail->prev;
    tail->next = NULL;
    free(current);
    return tail;
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