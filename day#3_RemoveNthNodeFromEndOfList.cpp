/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head==NULL || head->next==NULL){
            head = NULL;
            return head;
        }

        ListNode* temp = head;
        int count = 0;
        while (temp!=NULL){
            temp = temp->next;
            count++;
        }
        
        int idx = count-n;

        if (idx == 0){
            return head->next;
        }

        ListNode* prevNode = NULL;
        ListNode* nextNode = head;

        for (int i=0;i<idx;i++){
            prevNode = nextNode;
            nextNode = nextNode->next;
        }

        prevNode->next = nextNode->next;

        return head;
    }
};
