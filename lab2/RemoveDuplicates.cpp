Node* RemoveDuplicates(Node *head)
{
  // This is a "method-only" submission. 
  // You only need to complete this method. 
    
    Node *ptr = head,*temp=NULL,*tmp=NULL;
    
    while(ptr!=NULL && ptr->next!=NULL)
    {
        temp = ptr->next;
        ptr->next=NULL;
        
        while(temp!=NULL && ptr->data == temp->data)
        {
            tmp=temp;
            temp=temp->next;
            
            tmp->next=NULL;
            delete(tmp);
        }
        ptr->next = temp;
        ptr = temp;
    }
    
    return head;
}