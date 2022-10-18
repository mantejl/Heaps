#include "llrec.h"
#include <iostream>

using namespace std;
//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
    // creating temp node to store head
    Node* tmp = head; 
    head = NULL;
    if (!tmp)
    {
        smaller = nullptr;
        larger = nullptr;
        return;
    }
    // checking if val of head is less than pivot 
    else if (tmp->val <= pivot)
    {
        // recursive call with larger
        smaller = tmp;
        llpivot(tmp->next, smaller->next, larger, pivot);
    }
    // checking if val of head is greater than pivot
    else if (tmp->val > pivot)
    {
        // recursive call with larger
        larger = tmp;
        llpivot(tmp->next, smaller, larger->next, pivot);
    }
}