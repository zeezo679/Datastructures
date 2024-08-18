#ifndef SINGLELINKED_H_INCLUDED
#define SINGLELINKED_H_INCLUDED

typedef struct node{
    int data;
    struct node *next;
} node;

node *insertH(int d, node *head){
    head = malloc(sizeof(node));
    head->data = d;
    head->next = NULL;
    return head;
}

node *insert(int d, node *ptr){
    node *temp = malloc(sizeof(node));
    temp->data = d;
    temp->next = NULL;

    ptr->next = temp;
    return temp;
}

int get(int d, node *head){
    node *ptr = head;
    while(ptr != NULL){
        if(ptr->data == d){
            return d;
        }
        ptr = ptr->next;
    }
}

node *insertB(int d, node *head){
    node *temp = malloc(sizeof(node));
    temp->data = d;
    temp->next = head;
    head = temp;
    return head;
}

void insertR(int d, int pos, node *ptr){
    int c = 0;
    node *temp = malloc(sizeof(node));
    temp->data = d;
    temp->next = NULL;
    while(c!=pos-2){
        c++;
        ptr = ptr->next;
    }
    temp->next = ptr->next;
    ptr->next = temp;
}

node* deleteFirst(node **head){
    node *temp = *head;
    *head = (*head)->next;
    free(temp);
    temp = NULL;
    return *head;
}

void deleteLast(node *ptr){
    node *temp = ptr;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    temp->next = NULL;
    free(temp->next);
}

void delPos(node **head, int pos){
    int c = 0;
    node *pre = *head;
    node *curr = *head;
    if(pos == 1){
        *head = curr->next;
        free(curr);
        curr = NULL;
    }
    else{
        while(c!=pos){
        c++;
        pre = curr;
        curr = curr->next;
        }
        pre->next = curr->next;
        free(curr);
        curr = NULL;
    }
}

void clear(node **head){
    node *pre = *head;
    while(*head != NULL){
        *head = (*head)->next;
         free(pre);
         pre = *head;
    }
}

node *rev(node *head){
    node *nex = NULL;
    node *pre = NULL;
    while(head != NULL){
        nex = head->next;
        head->next = pre;
        pre = head;
        head = nex;
    }
    head = pre;
    return head;
}

#endif // SINGLELINKED_H_INCLUDED
