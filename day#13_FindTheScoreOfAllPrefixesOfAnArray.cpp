class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        long long sum = 0;
        long long mx = INT_MIN;
        vector<long long> ans;
        long long temp = -1;

        for (int i=0;i<nums.size();i++){
            // mx = max(mx, nums[i]);
            if (nums[i] > mx){
                mx = nums[i];
            }
            temp = nums[i] + mx;
            sum += temp;
            ans.push_back(sum);
        }

        return ans;
    }
};
