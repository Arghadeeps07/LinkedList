#include <stdio.h>
#include <stdlib.h>
struct Node
{
      int data;
      struct Node *next;
};
void linkedListTraversal(struct Node *ptr)
{
      while (ptr != NULL)
      {
            printf("Elment :%d\n", ptr->data);
            ptr = ptr->next;
      }
}
struct Node *insertAtFirst(struct Node *head, int data)
{
      struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
      ptr->next = head;
      ptr->data = data;
      return ptr;
}

struct Node *insertAtIndex(struct Node *head, int data, int index)
{
      struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
      struct Node *p = head;
      int i = 0;
      while (i != index - 1)
      {
            p = p->next;
            i++;
      }
      // p will be pointing the previous node
      ptr->data = data;
      ptr->next = p->next; // linking the new node ptr with the next node after it
      p->next = ptr;

      return head;
}
struct Node *insertAtEnd(struct Node *head, int data)
{
      struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
      ptr->data = data;
      struct Node *p = head;
      int i = 0;
      while (p->next != NULL)
      {
            p = p->next;
            i++;
      }
      p->next = ptr;
      ptr->next = NULL;

      return head;
}
struct Node *insertAfterNode(struct Node *head, struct Node *prvNode, int data)
{
      struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
      ptr->next = prvNode->next;
      ptr->data = data;
      return head;
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
      head = insertAfterNode(head, second, 10);

      printf("\n");
      linkedListTraversal(head);

      return 0;
}