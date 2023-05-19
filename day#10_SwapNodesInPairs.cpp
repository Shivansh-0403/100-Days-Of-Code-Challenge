class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL){
            return NULL;
        }
        if (head->next == NULL){
            return head;
        }

        ListNode* temp1 = head;
        ListNode* temp2 = head->next;
        
        temp1->next = temp2->next;
        temp2->next = temp1;
      
        if (temp1->next!=NULL){
            temp1->next = swapPairs(temp1->next);
        }

        return temp2;
    }
};
