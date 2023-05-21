class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head==NULL)
            return NULL;
        
        ListNode* temp = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;

        while (temp!=NULL){
            if (temp->val == val && temp==head){
                head = head->next;
                temp = temp->next;
            }

            else if (temp->val == val && temp!=head){
                prev->next = temp->next;
                temp = temp->next;
            }
          
            else if (temp->val!=val){
                prev = temp;
                temp = temp->next;
            }
        }

        return head;
    }
};
