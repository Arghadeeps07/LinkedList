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
node *reverse(node *head)
{
    node *pre = NULL;
    node *curr = head;
    node *forward = NULL;

    while (curr->next != NULL)
    {
        // breaking the link and again joining it in the new direction
        forward = curr->next;
        curr->next = pre;
        pre = curr;
        curr = forward;
    }
    return pre;
}
int main()
{

    node *head = NULL;
    head = insertAtend(head, 45);
    head = insertAtend(head, 6);
    head = insertAtend(head, 8);
    head = insertAtend(head, 9);
    head = insertAtend(head, 54);
    head = insertAtend(head, 99);
    head = insertAtend(head, 89);
    traverse(head);
    cout << endl;
    head = reverse(head);
    traverse(head);

    return 0;
}