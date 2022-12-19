class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
         stack<int> st;
            struct node *temp=head;
            struct node *temp1=head;
            
            int num=k;
            
            while(temp!=NULL)
            {
                if(num!=0)
                {
                    st.push(temp->data);
                    temp=temp->next;
                    num--;
                }
                else{
                    while(!st.empty())
                    {
                        int top=st.top();
                        st.pop();
                        temp1->data=top;
                        temp1=temp1->next;
                        num++;
                    }
                }
            }
            
            while(!st.empty())
            {
                int top=st.top();
                st.pop();
                temp1->data=top;
                temp1=temp1->next;
                
            }
            return head;       
    }
};