class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()){
            return NULL;
        }
        ListNode* head = new ListNode();
        ListNode* mainHead = head;
        while (true){
            int idx = 0;
            int mn = INT_MAX;
            bool flag = true;
            for (int j=0; j<lists.size(); j++){
                if (lists[j] == NULL){
                    continue;
                }
                flag = false;
                if (lists[j]->val < mn){
                    idx = j;
                    mn = lists[j]->val;
                }
            }

            if (flag){
                break;
            }
            lists[idx] = lists[idx]->next;
            ListNode* temp = new ListNode(mn);
            head->next = temp;
            head = head->next;
        }

        return mainHead->next;
    }
};
