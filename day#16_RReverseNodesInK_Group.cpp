class Solution {
public:
    int sizeLL(ListNode* head){
        int size = 0;
        while (head!=NULL){
            size++;
            head = head->next;
        }
        return size;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head==NULL){
            return NULL;
        }
        if (sizeLL(head) < k){
            return head;
        }

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        int count = 0;
        while (count<k && curr!=NULL){
            count++;
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        if (next!=NULL){
            head->next = reverseKGroup(next, k);    // Recursion
        }
        return prev;
    }
};
