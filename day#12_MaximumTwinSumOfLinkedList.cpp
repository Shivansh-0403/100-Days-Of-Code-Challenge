class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* temp = head;
        int ans = INT_MIN;
        vector<int> v;
        int sum = 0;
        while (temp!=NULL){
           
            v.push_back(temp->val);
            temp = temp->next;

        }
        
        for (int i=0; i<v.size(); i++){
            
            sum = v[i] + v[v.size()-1-i];
            ans = max(ans, sum);
            
        }
        
        return ans;
    }
};
