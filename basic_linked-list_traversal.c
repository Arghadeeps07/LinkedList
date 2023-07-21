#include <stdio.h>
#include <stdlib.h>
struct Node
{
      int data;
      struct Node *next;
};
void linkedListTraversal(struct Node *ptr)
{
      while (ptr)
      {
            printf("Elment :%d\n", ptr->data);
            ptr = ptr->next;
      }
}
int main()
{
      struct Node *head;
      struct Node *first;
      struct Node *second;
      struct Node *third;
      

      // memory allocation in heap

      head = (struct Node *)malloc(sizeof(struct Node));
      first = (struct Node *)malloc(sizeof(struct Node));
      second = (struct Node *)malloc(sizeof(struct Node));
      third = (struct Node *)malloc(sizeof(struct Node));

      head->data = 67;
      head->next = first;

      first->data = 78;
      first->next = second;

      second->data = 88;
      second->next = third;

      third->data = 88;
      third->next = NULL;

      linkedListTraversal(head);

      return 0;
}