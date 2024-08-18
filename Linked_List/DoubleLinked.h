#ifndef DOUBLELINKED_H_INCLUDED
#define DOUBLELINKED_H_INCLUDED

typedef struct node {
    int data;
    struct node *prev;
    struct node *next;
} node ;

node *insertHead(int d, node *head){
    node *temp = malloc(sizeof(node));
    temp->data = d;
    temp->prev = NULL;
    temp->next = NULL;
    head = temp;
    return temp;
};

node *insertEnd(int d, node *head){
    node *temp = malloc(sizeof(node));
    temp->data = d;
    temp->next = NULL;
    temp->prev = NULL;

    node *ptr = head;
    while(ptr->next != NULL) ptr = ptr->next;

    ptr->next = temp;
    temp->prev = ptr;
    return head;
}

node *insertBeg(int d, node *head){
    node *temp = malloc(sizeof(node));
    temp->data = d;
    temp->prev = NULL;
    temp->next = NULL;
    temp->next = head;
    head->prev = temp;
    head = temp;
    return head;
}



node *addAt(int pos, int d, node *head){
    if(pos == length(head)){
        printf("Exception error: Must not insert at end\n");
        return;
    }
    node* newNode = malloc(sizeof(node));
    newNode->data = d;
    newNode->next = NULL; newNode->prev = NULL;

    node* ptr = head;

    int cnt = 0;
    while(cnt != pos-1){
        ptr = ptr->next;
        cnt++;
    }

    node *afterNode = ptr->next;
    ptr->next = newNode;
    newNode->prev = ptr;
    afterNode->prev = newNode;
    newNode->next = afterNode;
    return head;
}

int length(node *head){
    node *ptr = head;
    int cnt = 0;
    while(ptr != NULL){
        ptr = ptr->next;
        cnt++;
    }
    return cnt;
}

node* createList(int length, node *head){
    printf("Enter the First Node to continue: ");
    int x; scanf("%d", &x);
    head = insertHead(x, head);
    for(int i = 1; i<=length-1;i++){
        printf("Enter node %d: ", i+1);
        int x; scanf("%d", &x);
        head = insertEnd(x, head);
    }
    return head;
}

void printList(node *head){
    node *ptr = head;
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

node *pop_first(node *head){
    node *ptr = head;
    head = ptr->next;
    free(ptr);
    head->prev = NULL;
    return head;
}

node *pop_behind(node *head){
    node *ptr1 = head;
    while(ptr1->next != NULL) ptr1 = ptr1->next;
    node *ptr2 = ptr1->prev;
    free(ptr1);
    ptr2->next = NULL;
    return head;
}

node *delete_at(int pos, node *head){
    node* ptr = head;

    int cnt = 0;
    while(cnt != pos-1){
        ptr = ptr->next;
        cnt++;
    }
    node *temp = ptr;
    temp->prev->next = ptr->next;
    temp->next->prev = ptr->prev;
    free(ptr);
    return head;
}

node *reverse_list(node *head){
    node *curr = head;
    node *behind = NULL;
    while(curr != NULL){
        behind = curr->prev;
        curr->prev = curr->next;
        curr->next = behind;
        curr = curr->prev;
    }
    head = behind->prev;
    return head;
}


#endif // DOUBLELINKED_H_INCLUDED
