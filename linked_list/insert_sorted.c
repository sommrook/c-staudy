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

void InsertSorted(int data)
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
        node *before_temp = NULL;
        while (1){
            if (temp->data > data){
                if (before_temp == NULL){
                    new_node -> next = temp;
                    head = new_node;
                    break;
                }
                before_temp -> next = new_node;
                new_node -> next = temp;
                break;
            }
            if (temp->next == NULL){
                temp->next = new_node;
                break;
            }
            before_temp = temp;
            temp = temp -> next;
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
    
    InsertSorted(3);
    InsertSorted(0);
    InsertSorted(50);
    InsertSorted(10);
    InsertSorted(7);
    InsertSorted(8);
    InsertSorted(50);
    InsertSorted(30);
    InsertSorted(70);

    Print();

}