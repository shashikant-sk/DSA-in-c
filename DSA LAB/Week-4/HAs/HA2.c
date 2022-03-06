

//DO NOT COMPY THIS NOT READY YET(YOU CAN IGNORE ONE PROBLEM , GOOD FOR YOU XD)





// Write a menu driven program to perform the following operations in a single circular linked list by using suitable user defined functions for each case.
// a) Traverse the list 
// b) Check if the list is empty 
// c) Insert a node at the certain position
// d) Delete a node at the certain position 
// e) Delete a node for the given key
// f) Count the total number of nodes 
// g) Search for an element in the linked list
// Verify & validate each function from main method.
// #include <stdio.h>
// #include <stdlib.h>

// struct node {
//     int data;
//     struct node *next;
// };

// void isEmpty(struct node *start){
//     if(start==NULL)printf("\nList is Empty!\n");
//     else printf("\nList is not Empty!\n");
// }
 
// void traverse(struct node *start)
// {
//     if (start == NULL)
//         printf("\nList is empty\n");
//     else {
//         struct node* temp=start;
//         printf("\nLast Node <->");
//         do {
//             printf(" %d <-> ", temp->data);
//             temp = temp->next;
//         } while (temp != start);
//         printf("First Node\n");
//     }
// }

// void insertPos(struct node **start,int pos,int data){
//     struct node *new_node = (struct node *)malloc(sizeof(struct node)),*temp=*start;
//     new_node->data = data;
//     if(*start == NULL){
//         *start = new_node;
//         new_node->next = *start;
//         return;
//     }
//     while(pos--){
//         temp = temp->next;
//     }
//     new_node->next=temp->next;
//     temp->next = new_node;
// }

// int main()
// {
//     struct node* start = NULL;
//     insertPos(&start,0,1);
//     insertPos(&start,0,2);
//     insertPos(&start,0,3);
//     insertPos(&start,0,4);
//     insertPos(&start,0,5);
//     traverse(start);
//     return 0;
// }