class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
      Node* fast = head;
      Node* slow = head;
      Node* temp = NULL;
      
      while(fast){
        fast = fast->next;
        if(fast){
        fast = fast->next;
        slow = slow->next;
        
          if(fast == slow){
              slow = head;
              while(slow != fast){
                  slow = slow->next;
                  fast = fast->next;
              }
              temp = slow;
              while(temp->next != slow){
                  temp= temp->next;
              }
              temp->next=NULL;
           
          }
      }
      }
    }
};