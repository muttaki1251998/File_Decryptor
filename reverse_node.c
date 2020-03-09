#include "header.h"

void reverse(Node **head_ref)
{
    Node *prev = NULL;
    Node *current = *head_ref;
    Node *next = NULL;

    while(current != NULL)
    {
        next = current->next;
        /* Reverse the current node */
        current->next = prev;
        /* Move pointers one position ahead */
        prev = current;
        current = next;
    }
    *head_ref = prev;
}
