#include<stdio.h>

struct Node
{
    /* data */
    int data;
    struct Node* next;
}*head, *p, *temp;

void insert(struct Node* head, int val) {
    p = (struct Node*)malloc(sizeof(struct Node));
    p->next = NULL;
    temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = p;
}
