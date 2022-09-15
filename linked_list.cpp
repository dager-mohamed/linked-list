#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;
};
node *head = NULL;

void InsertNode(int value);
void displayNode();
void deleteNode(int value);
void InsertBeg(int value);
void DeleteBeg();
void DeleteLast();
int main(){
    // IT IS A TEST CODE ONLY -->
    InsertNode(10);
    InsertNode(15);
    InsertNode(20);
    InsertNode(25);
    InsertNode(30);
    displayNode();
    cout << "-------------------------" << endl;
    DeleteLast();
    displayNode();
    return 0;
}


void InsertNode(int value){
    node *new_node, *last;
    
    new_node = new node;
    new_node->data = value;

    if(head == NULL){
        head = new_node;
        new_node->next = NULL;
    }else{
        last = head;
        while(last->next != NULL){
            last = last->next;
        }
        last->next = new_node;
        new_node->next = NULL;
    }


}

void displayNode(){
    node *nodes;

    if(head == NULL){
        cout << "linked list is empty!" << endl;
    }else{
        nodes = head;
        while(nodes != NULL){
            cout << nodes->data << " \n" ;
            nodes = nodes->next;
        }
    }
}

void deleteNode(int value){
    node *node, *prev;
    node = head;
    prev = head;
    if(head == NULL){
        cout << "There is no linked lists to delete!" << endl;
    }else{
        
        if(node->data == value){
            head = node->next;
            free(node);
            cout << "deleted!" << endl;
            return;
        }

        while(node->data != value){
            prev = node;
            node = node->next;
        }
        prev->next = node->next;
        free(node);
    }
}

void InsertBeg(int value){
    node *node_new;
    node_new = new node;

    node_new->data = value;
    node_new->next = head;
    head = node_new;
}

void DeleteBeg(){
    node *node_d;
    node_d = new node;
    if(head == NULL) return;
    node_d = head;
    head = node_d->next;
    free(node_d);
    return;
}
void DeleteLast(){
    node *node_d;
    if(head == NULL) return;
    node_d = head;
    while(node_d->next->next != NULL){
        node_d = node_d->next;
    }
    free(node_d->next);
    node_d->next = NULL;
    return;
}