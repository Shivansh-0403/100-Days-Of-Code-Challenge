class Solution {
public:
    vector<bool> vis;
    vector<vector<int>> res;
    vector<int> v;
    void solve(vector<int>& nums, int target, int idx)
    {
        if (target == 0){
            res.push_back(v);
            return ;
        }
        if (idx >= nums.size()){
            return ;
        }
        for (int i=idx; i<nums.size(); i++){
            if (vis[i] == 1){
                continue;
            }
            if (target < nums[i]){
                break;
            }
            if (target-nums[i] < 0){
                break;
            }
            if (i > idx && nums[i] == nums[i-1]){
                // very important
                continue;
            }
            v.push_back(nums[i]);
            vis[i] = 1;
            solve(nums, target-nums[i], i+1);
            v.pop_back();
            vis[i] = 0;
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        sort(candidates.begin(), candidates.end());

        vis.assign(candidates.size(), 0);
        solve(candidates, target, 0);

        return res;
    }
};
