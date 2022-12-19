Node* findIntersection(Node* head1, Node* head2)
{
   Node* dummyHead = new Node(-1);
   Node* dummyTail = dummyHead;
   
   while(head1 && head2){
       if(head1->data < head2->data){
           head1 = head1->next;
       }else if(head1->data > head2->data){
           head2 = head2->next;
       }else{
           Node* temp = new Node(head1->data);
           dummyTail->next = temp;
           dummyTail = dummyTail->next;
           
           head1 = head1->next;
           head2 = head2->next;
       }
   }
   
   return dummyHead->next;
}

// Method 2
Node* findIntersection(Node* head1, Node* head2)
{
   Node *temp =new Node(-1);

    Node *temp2=temp;

    

    Node *l1=head1,*l2=head2;

    while(l1 && l2){

        if(l1->data < l2->data)

            l1=l1->next;

        

        else if(l2->data<l1->data)

            l2=l2->next;

        

        else {

            temp->next=new Node(l1->data);

            temp=temp->next;

            l1=l1->next;

            l2=l2->next;

        }

    }

    return temp2->next;
    
}