#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    int data;
    struct NODE* next;
}node;

int main()
{
    // 헤드(시작)노드 생성
    // 메모리 동적 할당
    node* head = (node*)malloc(sizeof(node));

    head -> next = NULL;

    node* node1 = (node*)malloc(sizeof(node));
    
    head -> next = node1;
    node1 -> data = 1;
    node1 -> next = NULL;

    node* node2 = (node*)malloc(sizeof(node));

    node1 -> next = node2;
    node2 -> data = 2;
    node2 -> next = NULL;

    node* curr = head->next;

    while(curr != NULL){
        printf("%d\n", curr->data);
        curr = curr->next;
    }

    free(head);
    free(node1);
    free(node2);

    return 0;

}