class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<int> m(nums.size()+1, 0);
        int count = 0;
        for (int i=0; i<nums.size(); i++){
            m[nums[i]]++;
            count++;
        }

        vector<vector<int>> ans;
        
        while (count > 0){
            vector<int> v;

            for (int i=0; i<m.size(); i++){
                if (m[i] != 0){
                    v.push_back(i);
                    m[i]--;
                    count--;
                }
            }

            ans.push_back(v);
        }
        return ans;
    }
};
