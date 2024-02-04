class Solution {
public:
    int solve(vector<int> nums, int idx, int curr, vector<int>& dp){
        if (idx == nums.size()-1){
            dp[idx] = 0;
            return 0;
        }

        int count = 0;
        for (int it=idx+1; it<nums.size(); it++){
            if (nums[it] > curr){
                if (dp[it] != -1){
                    count = max(count, dp[it]+1);
                    continue;
                }
                count = max(count, solve(nums, it, nums[it], dp)+1);
            }
        }
        dp[idx] = count;
        return count;
    }
    int lengthOfLIS(vector<int>& nums) {
        int ans = 0;
        vector<int> dp(nums.size(), -1);
        for (int i=0; i<nums.size(); i++){
            ans = max(ans, solve(nums, i, nums[i], dp)+1);
        }
        return ans;
    }
};
