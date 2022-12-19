// Single Pointer Approach

Node *removeDuplicates(Node *head)
{
 if(head == NULL || head->next == NULL) return head;
 Node* cur = head;
 
 while(cur && cur->next){
     if(cur->data == cur->next->data){
         Node* temp = cur->next;
         cur->next = temp->next;
         delete temp;
     }else{
         cur = cur->next;
     }
 }
 return head;
}

// 2 pointer approach
Node *removeDuplicates(Node *head)
{
  if(head  == NULL || head->next == NULL) return head;
  
  Node* prev = head , *cur = head->next;
  
  while(cur){
      if(prev->data == cur->data){
          Node* temp = cur;
          prev->next = temp->next;
          cur = cur->next;
          delete temp;
      }else{
          prev = prev->next;
          cur = cur->next;
      }
  }
  return head;
  
}