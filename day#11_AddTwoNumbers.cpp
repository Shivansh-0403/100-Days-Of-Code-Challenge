class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* ans = head;
        int carry = 0;
        int sum = 0;

        while (l1!=NULL || l2!=NULL){
            if (l1 == NULL){
                sum = l2->val + carry;
                l2 = l2->next;
            }
            else if (l2 == NULL){
                sum = l1->val + carry;
                l1 = l1->next;
            }

            if (l1!=NULL && l2!=NULL){
                sum = l1->val + l2->val + carry;
                l1 = l1->next;
                l2 = l2->next;
            }

            ListNode* temp = new ListNode(sum%10);
            carry = sum/10;
            head->next = temp;
            head = head->next;
        }

        if (carry>0){
            ListNode* temp = new ListNode(carry);
            head->next = temp;
        }
        return ans->next;
    }
};
