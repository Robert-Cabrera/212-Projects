#include <iostream>
#include "doublyLinkedList.hpp"

//Floyd's Algorithm to find a loop in a linked list

bool cycle_finder(Node *head)
{
    
Node *slow = head;
Node *fast = head;

while(slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
            return true;
    }

return false;

}

