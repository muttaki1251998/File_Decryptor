#include "header.h"

void free_list(Node *head)
{
    Node *new_head = head;
    Node *old_node = NULL;

    while(new_head != NULL)
    {
        old_node = new_head;
        new_head = new_head->next;
        free(old_node);
    }
}