#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
}node;
void linkedListTraversal(struct Node *ptr)
{
      while (ptr != NULL)
      {
            printf("Elment :%d\n", ptr->data);
            ptr = ptr->next;
      }
}
node* insertAtEnd(struct Node *head, int data)
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = data;
    ptr->next = NULL;

    if (head == NULL)
    {
        // If the list is empty, make the new node the head
        head = ptr;
    }
    else
    {
        // Find the last node and append the new node
        struct Node *p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = ptr;
    }
 return head;
}

int main(){
      node* head = NULL;
      char choise = 'y' ;
      int el,count = 0 ;

      while(choise == 'y' || choise == 'Y'){
            printf("Enter the data of the element:\n");
            scanf("%d",&el);
            count++;
            head = insertAtEnd(head, el);

            printf("Do you want to cotinue:(y/n)\n");
            scanf(" %c", &choise);

      }

      printf("The status of the linkedList:\n");
      printf("The number of elements in the linkedList is %d\n", count);

      linkedListTraversal(head);


return 0;
}
