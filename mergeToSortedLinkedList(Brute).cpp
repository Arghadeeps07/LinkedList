#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next = NULL;
};
node *insertAtend(node *head, int data)
{
    node *p = new node; // default constructor will be called
    p->data = data;
    if (!head)
    {
        head = p; // If the list is empty, the new node becomes the head
        return head;
    }
    // Now if the list is not empty
    node *ptr = head;
    while (ptr->next)
    {
        ptr = ptr->next;
    }
    ptr->next = p;
    return head;
}
void traverse(node *head) // This will traverse the the list and print it
{
    while (head)
    {
        cout << head->data << endl;
        head = head->next;
    }
}
struct node *merge(struct node *list1, struct node *list2)
{
    //if one is empty another will bw the answer
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    struct node dummy; // Create a dummy node to start the merged list
    struct node *current = &dummy;

    while (list1 && list2)
    {
        if (list1->data < list2->data)
        {
            current->next = list1;
            list1 = list1->next;
        }
        else
        {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }

    if (list1)
    {
        current->next = list1;
    }
    if (list2)
    {
        current->next = list2;
    }

    return dummy.next; // The next of dummy will be the actual head of the merged linked list
}

int main()
{

    node *head = NULL;
    head = insertAtend(head, 5);
    head = insertAtend(head, 6);
    head = insertAtend(head, 8);
    head = insertAtend(head, 9);
    head = insertAtend(head, 54);
    head = insertAtend(head, 99);
    head = insertAtend(head, 809);
    traverse(head);

    cout << endl;

    node *head2 = NULL;
    head2 = insertAtend(head2, 5);
    head2 = insertAtend(head2, 66);
    head2 = insertAtend(head2, 98);
    head2 = insertAtend(head2, 99);
    head2 = insertAtend(head2, 104);
    head2 = insertAtend(head2, 120);
    head2 = insertAtend(head2, 890);
    traverse(head);

    head = merge(head, head2);
    traverse(head);
    return 0;
}