class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head==NULL || head->next==NULL){
            return head;
        }
      
        ListNode* prev = NULL;
        ListNode* curr = head;
        map<int, bool> m;

        while (curr->next!=NULL){
            if (curr->val == curr->next->val){
                curr->next = curr->next->next;
                m[curr->val] = true;
            }
            else {
                curr = curr->next;
            }
        }

        curr = head;
        while (curr != NULL){
            if (m[curr->val]==true && curr==head){
                head = head->next;
                curr = curr->next;
            }
            else if (m[curr->val]==true && curr!=head){
                prev->next = curr->next;
                curr = curr->next;
            }
            else if (m[curr->val] == false){
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};
