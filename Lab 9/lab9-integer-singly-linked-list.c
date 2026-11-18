#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *createNode(int data);
Node *pushBack(Node *head, int data);
void printList(Node *head);
void freeList(Node *head);

int main(int argc, char const *argv[])
{
    if (argc < 2) {
        return 1;
    }

    int n = atoi(argv[1]);
    if (argc != n + 2) {
        return 1;
    }

    Node *head = NULL;
    for (int i = 0; i < n; i++) {
        head = pushBack(head, atoi(argv[i + 2]));
    }

    printList(head);
    freeList(head);
    return 0;
}

Node *createNode(int data)
{
    Node *node = malloc(sizeof(Node));
    if (node == NULL) {
        return NULL;
    }
    node->data = data;
    node->next = NULL;
    return node;
}

Node *pushBack(Node *head, int data)
{
    Node *new_node = createNode(data);
    if (new_node == NULL) {
        return head;
    }
    if (head == NULL) {
        return  new_node;
    }
    Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    return head;
}

void printList(Node *head)
{
    for (Node *current = head; current != NULL; current = current->next) {
        printf("%d\n", current->data);
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