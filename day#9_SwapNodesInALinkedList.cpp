class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        if (head==NULL || head->next==NULL){
            return head;
        }
        
        int size = 0;
        ListNode* temp = head;
        ListNode* prev = NULL;
        while (temp!=NULL){
            size++;
            prev = temp;
            temp = temp->next;
        }

        if (size == k){
            swap(head->val, prev->val);
            return head;
        }

        int num = size-k+1;
        temp = head;
        prev = NULL;
        ListNode* swap1 = NULL;
        ListNode* swap2 = NULL;

        for (int i=1; i<=max(num, k); i++){
            if (i == min(k, num)){
                swap1 = temp;
            }
            prev = temp;
            temp = temp->next;
        }

        swap2 = prev;

        int val = swap1->val;
        swap1->val = swap2->val;
        swap2->val = val;

        return head;
    }
};
