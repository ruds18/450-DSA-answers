class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
     unordered_map<int,int>mp;
     Node* temp = head;
     mp[temp->data] = 1;
     while(temp->next){
         if(mp.count(temp->next->data)){
             temp->next = temp->next->next;
         }else{
             temp= temp->next;
             mp[temp->data] = 1;
         }
     }
     return head;
    }
};