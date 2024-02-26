class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int ptr = prices[0];

        for (int i=1; i<prices.size(); i++){
            if (prices[i] > ptr){
                ans += prices[i]-ptr;
                ptr = prices[i];
            }
            else {
                ptr = prices[i];
            }
        }

        return ans;
    }
};
