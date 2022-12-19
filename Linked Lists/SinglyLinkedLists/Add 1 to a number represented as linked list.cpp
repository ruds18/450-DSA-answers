class Solution
{
    
    public:
    Node* reverse(Node * head){
        Node* cur = head;
        Node* prev = NULL;
        Node* nxt ;
        
        while(cur){
            nxt->next = cur ->next;
            cur->next = prev;
            prev = cur;
            cur = cur->next;
        }
        return prev;
    };
    
    Node* addOne(Node *head) 
    {
    //   if(!head->next) return head;
  
      Node* cur = reverse(head);
      
       while(1){
           cur->data +=1;
           
           if(cur->data < 10) return reverse(head);
           else cur->data = 0;
           
           if( cur->next == NULL) break;
           else cur = cur->next;
       }
       // Means all are in the form of 99 9999 99999..  like this
       cur->next= new Node(1);
       return reverse(head);
    }
};