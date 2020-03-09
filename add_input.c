#include "header.h"

Node *add_input(Node *head, char string)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->input_string = string;
    new_node->next = head;

    return new_node;
        
}
  