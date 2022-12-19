LinkedListNode<int>* moveToFront(LinkedListNode<int> *head) {

   LinkedListNode<int>* prev = head;
    LinkedListNode<int>* last = head;
    
    while(last->next){
        if(last != prev ) prev = prev->next;
        last = last->next;
    }
     
    last->next = head;
    prev->next = NULL;
    head = last;
    
    return head;
}