#include <stdio.h>
#include <stdlib.h>

// 그림 그리면서 하면 구현하기 

typedef struct NODE {
    int data;
    struct NODE* next;
}node;

node* head;

void Insert(int index, int data);

void Print();

void Insert(int index, int data)
{
    node* new_node = (node*)malloc(sizeof(node));

    new_node -> next = NULL;
    new_node -> data = data;

    if (head == NULL){
        head = new_node;
        return;
    }
    else{
        node* temp = head;
        int num = 0;
        while (index >= num){
            if (index == 0){
                new_node -> next = temp;
                head = new_node;
                break;
            }
            else{
                if (index == num+1){
                new_node -> next = temp -> next;
                temp -> next = new_node;
                break;
                }
            }
            temp = temp -> next;
            num += 1;

        }
    }
    return;
}

void Print(){
    node* curr = head;

    while(curr -> next != NULL){
        printf("%d\n", curr->data);
        curr = curr->next;
    } 
    printf("%d\n", curr -> data);
}

int main()
{
    // 헤드(시작)노드 생성
    // 메모리 동적 할당
    head = NULL;

    Insert(0, 6);
    Insert(1, 7);
    Insert(0, 7);
    Insert(0, 8);
    Insert(1, 20);
    Insert(0, 10);
    Insert(4, 50);
    Insert(0, 20);
    Print();

}