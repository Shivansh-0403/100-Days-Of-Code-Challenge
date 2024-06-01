class Solution {
public:
    vector<vector<int>> dp;
    bool solve(vector<int> &nums, int it, int sum1, int sum2){
        if (it >= nums.size()){
            if (sum1 == sum2){
                return true;
            }
            return false;
        }

        if (dp[it][sum1] != -1){
            return dp[it][sum1];
        }

        bool res1 = solve(nums, it+1, sum1+nums[it], sum2);
        bool res2 = solve(nums, it+1, sum1, sum2+nums[it]);

        dp[it][sum1] = res1 || res2;
        // dp[it][sum2] = res1 || res2;
        return res1 || res2;
    }
    bool canPartition(vector<int>& nums) {
        dp.assign(nums.size(), vector<int> (20001, -1));
        return solve(nums, 0, 0, 0);
    }
};
