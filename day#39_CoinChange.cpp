class Solution {
public:
    vector<int> dp;

    // Memoization
    int solve(vector<int>& coins, int amt){
        if (amt == 0){
            return 0;
        }
        if (amt < 0){
            return -1;
        }

        if (dp[amt] != INT_MAX) return dp[amt];
        int ans = INT_MAX;

        for (int i=0; i<coins.size(); i++){
            int recRes = solve(coins, amt-coins[i]);
            if (recRes != -1){
                ans = min(ans, recRes+1);
            }
        }

        if (ans == INT_MAX) return -1;

        dp[amt] = ans;
        return ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        dp.assign(amount+1, INT_MAX);

        // Recursion + Memoization
        // return solve(coins, amount); 

        // Tabulation
        dp[0] = 0;

        for (int i=1; i<=amount; i++) {
            for (int j=0; j<coins.size(); j++){
                if (i-coins[j] < 0) continue;

                if (dp[i-coins[j]] != INT_MAX){
                    dp[i] = min(dp[i], dp[i-coins[j]]+1);
                }
            }
        }
        
        if (dp[amount] == INT_MAX) return -1;
        return dp[amount];
    }
};
