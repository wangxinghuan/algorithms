#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Huffnode{
    int weight;
    char ch;
    char code[20];
    struct Huffnode * left_child;
    struct Huffnode * right_child;
}HuffMan;

typedef struct node{
    HuffMan * data;
    struct node * next;
}ListNode;

typedef struct {
    ListNode * front;
    ListNode * rear;
}Queue;

//creat empty queue
Queue * creat_Empty_Queue(){
    ListNode * HList;
    Queue * HQueue;
    HList = (ListNode *)malloc(sizeof(ListNode));
    HList -> next = NULL;
    HQueue = (Queue *)malloc(sizeof(Queue));
    HQueue -> front = HQueue -> rear = HList;

    return HQueue;
}

//enter queue in turn
int enter_Queue(Queue * head, HuffMan * data){
    ListNode * temp;
    temp = (ListNode * )malloc(sizeof(ListNode));
    temp -> data = data;
    temp -> next = NULL;
    head -> rear -> next = temp; //tail pointer deal
    head -> rear = temp;

    return 0;
}


//ordered enter huffman node
int order_Enter_Queue(Queue * head, HuffMan * p){ 
    ListNode * m = head -> front -> next;
    ListNode * n = head -> front;
    ListNode * temp ;

    while ( m ) {
        if ( m -> data -> weight <= p -> weight) {
            m = m -> next;
            n = n -> next;
        }
        else {
            break;
        }
    }

    //insert into the last node
    if ( m == NULL ) {
        temp = (ListNode *)malloc(sizeof(ListNode));
        temp -> data = p;
        temp -> next = NULL;
        n -> next = temp;
        head -> rear = temp;
        return 0;
    }

    //insert into the middle node
    temp = (ListNode *)malloc(sizeof(ListNode));
    temp -> data = p;
    n -> next = temp;
    temp -> next = m;

    return 0;
}

int _is_empty_queue(Queue * head){
    if ( head -> front -> next -> next == NULL ) {
        return 1;
    }
    else
        return 0;
}

int is_empty_queue(Queue * head){
    if (head -> front == head -> rear) {
        return 1;
    }
    else
        return 0;
}

//delete from the queue
HuffMan * delete_Queue( Queue * head){
    ListNode * temp;
    temp = head -> front;
    head -> front = temp -> next;
    free(temp);
    temp = NULL;
    return head -> front -> data;
}

HuffMan * creat_huffman_tree(Queue * head){
    HuffMan * right;
    HuffMan * left;
    HuffMan * current;

    while ( !_is_empty_queue(head) ) {
        left = delete_Queue(head);
        right = delete_Queue(head);
        current = (HuffMan *)malloc(sizeof(HuffMan));
        current -> weight = left -> weight + right -> weight;
        current -> left_child = left;
        current -> right_child = right;
        order_Enter_Queue(head, current);
    }
    return head -> front -> next -> data;
}

int HuffManCode(HuffMan * root, FILE  * fp){
    HuffMan * current = NULL;
    Queue * queue = NULL;
    queue = creat_Empty_Queue();
    enter_Queue(queue, root);

    while ( ! is_empty_queue(queue)){
        current = delete_Queue(queue);
        if ( current -> right_child == NULL && current -> left_child == NULL && current != root) {
            printf("%c %d %s \n", current -> ch, current -> weight, current -> code);
            
            fprintf(fp, "%c %s\n", current -> ch, current -> code);
        }
        if ( current -> right_child == NULL && current -> left_child == NULL && current == root) {
            strcpy(current -> code, "0");
           printf("%c %d %s \n", current -> ch, current -> weight, current -> code);
            fprintf(fp, "%c %s\n", current -> ch, current -> code);
        }
        if (current -> left_child) {
                strcpy(current -> left_child -> code, current -> code);
            strcat(current -> left_child -> code, "0");
            enter_Queue(queue, current -> left_child);
        }
        if (current -> right_child) {
                strcpy(current -> right_child -> code, current -> code);
            strcat(current -> right_child -> code, "1");
            enter_Queue(queue, current -> right_child);
        }
    } 
    return 0;
}

int count_file_charactor(FILE * fp, Queue * head){
    char c;
    int count;
    HuffMan  * temp;

    c = fgetc(fp);
    if(c == EOF){
        printf("Empty file\n");
        exit(1);
    }
    temp = (HuffMan *)malloc(sizeof(HuffMan));
    temp -> weight = 1;
    temp -> ch = c;
    order_Enter_Queue(head, temp);
    count = 1;
    ListNode * list_temp = head -> front -> next;
    while ( (c = fgetc(fp)) != EOF) {
        if (c == '\n') {
        list_temp = head -> front -> next;
            continue;
        }
        for ( ; list_temp != NULL; ) {
            if ( c == list_temp -> data -> ch ) {
                list_temp -> data -> weight++;
                break;
            }
            list_temp = list_temp -> next;
        }
        if ( list_temp != NULL) {
        list_temp = head -> front -> next;
            continue;
        }
        if(list_temp == NULL){
            temp = (HuffMan *)malloc(sizeof(HuffMan));
            temp -> weight = 1;
            temp -> ch = c;
            order_Enter_Queue(head, temp);
            count++;
        }
        list_temp = head -> front -> next;
    }
    return count;
}

int main(int argc, char *argv[])
{
    FILE * fp_in;
    FILE * fp_out;
    int num;
    Queue * queue;
    HuffMan *  root;
    char filename[20];

    printf("Enter the file name : \n");
    scanf("%s",filename);
    fp_in = fopen(filename, "r");
    fp_out = fopen("table.txt","w");
    queue = creat_Empty_Queue();
    num  = count_file_charactor(fp_in,queue);
    printf("%d\n", num);
    root = creat_huffman_tree(queue);
    HuffManCode(root,fp_out);
          
    fclose(fp_in);
    fclose(fp_out);
    return 0;
}
