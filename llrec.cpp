#include "llrec.h"
#include <iostream>

using namespace std;
//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
    Node* tmp = head; 
    head = NULL;
    if (!tmp)
    {
        smaller = nullptr;
        larger = nullptr;
        return;
    }
    else if (tmp->val <= pivot)
    {
        smaller = tmp;
        llpivot(tmp->next, smaller->next, larger, pivot);
    }
    else if (tmp->val > pivot)
    {
        larger = tmp;
        llpivot(tmp->next, smaller, larger->next, pivot);
    }
}