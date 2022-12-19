// Iterative

class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
       if(head == NULL || head->next == NULL)
            return head;
        
        //Three pointer approach
        Node* cur = head;
        Node* prev = NULL;
        Node* nxt = NULL;
        
        while(cur){
            nxt = cur->next;
            cur->next = prev;
            prev= cur;
            cur = nxt;
        }
        return prev;
    }
    
};