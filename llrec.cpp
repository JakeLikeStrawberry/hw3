#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot (Node*& head, Node*& smaller, Node*& larger, int pivot){
  
if (head == NULL){
  smaller = NULL;         //make sure current smaller node and current larger node are NULL
  larger = NULL;          
  return;
}

else{
  if (head->val <= pivot){
    smaller->val = head->val;               //copies value
    smaller->next = head;                     //because we aren't allocating or deallocating memory, we simply change pointers
    llpivot(head->next, smaller->next, larger, pivot);      //by temporarily setting smaller/larger next to head
    head = NULL;
    delete head;
  }
  else{                   //head val is > pivot
    larger->val = head->val;
    larger->next = head;
    llpivot(head->next, smaller, larger->next, pivot);
    head = NULL;
    delete head;                                                //ensures head is empty as we go through
  }
}

}


