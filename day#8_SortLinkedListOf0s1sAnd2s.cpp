class Solution
{
    public:
    void insertAtTail(Node* &tail, Node* temp){
        tail->next = temp;
        tail = temp;
    }
    
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        Node* zeroHead = new Node(-1);
        Node* zeroTail = zeroHead;
        Node* oneHead = new Node(-1);
        Node* oneTail = oneHead;
        Node* twoHead = new Node(-1);
        Node* twoTail = twoHead;
        
        Node* temp = head;
        while (temp != NULL){
            if (temp->data == 0){
                insertAtTail(zeroTail, temp);
            }
            else if (temp->data == 1){
                insertAtTail(oneTail, temp);
            }
            else if (temp->data == 2){
                insertAtTail(twoTail, temp);
            }
            temp = temp->next;
        }
        
        if (oneHead->next != NULL){
            zeroTail->next = oneHead->next;
        }
        else {
            zeroTail->next = twoHead->next;
        }
        
        oneTail->next = twoHead->next;
        twoTail->next = NULL;
        head = zeroHead->next;
        
        delete zeroHead;
        delete oneHead;
        delete twoHead;
        
        return head;
    }
};
