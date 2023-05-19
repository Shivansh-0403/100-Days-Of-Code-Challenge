/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head==NULL || head->next==NULL){
            return false;
        }
        
        ListNode* temp = head;
        map<ListNode*, bool> m;

        while (temp!=NULL){
            if (m[temp] == true){
                return true;
            }

            m[temp] = true;
            temp = temp->next;
        }
        return false;
    }
};
