class Solution {
private:
    ListNode* hasCycle(ListNode* head){
        if (head==NULL || head->next==NULL){
            return NULL;
        }
        if (head->next == head){
            return head;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        while (slow!=NULL && fast!=NULL){
            fast = fast->next;
            if (fast!=NULL){
                fast = fast->next;
            }

            slow = slow->next;

            if (slow == fast){
                return slow;
            }
        }
        return NULL;
    }
    
    
public:
    ListNode *detectCycle(ListNode *head) {
        if (head==NULL || head->next==NULL){
            return NULL;
        }
        if (head->next == head){
            return head;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        while (slow!=NULL && fast!=NULL){
            fast = fast->next;
            if (fast!=NULL){
                fast = fast->next;
            }

            slow = slow->next;

            if (slow == fast){
                break;
            }
        }

        if (slow==NULL || fast==NULL){
            return NULL;
        }

        ListNode* pointOfIntersection = fast;
        slow = head;

        while (slow != pointOfIntersection){
            slow = slow->next;
            pointOfIntersection = pointOfIntersection->next;
        }

        return slow;
    }
};
