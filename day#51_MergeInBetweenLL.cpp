class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* startPrev = new ListNode(0);
        ListNode* endNext = new ListNode(0);
        int count = 0;

        ListNode* prev = NULL;
        ListNode* temp = list1;
        while (temp != NULL){
            if (count == a){
                startPrev = prev;
            }
            if (count == b){
                endNext = temp->next;
            }

            count++;
            prev = temp;
            temp = temp->next;
        }

        startPrev->next = list2;

        temp = list2;
        ListNode* temp2 = NULL;
        while (temp != NULL){
            temp2 = temp;
            temp = temp->next;
        }

        temp2->next = endNext;

        return list1;
    }
};
