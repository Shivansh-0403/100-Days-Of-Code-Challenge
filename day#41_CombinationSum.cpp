class Solution {
public:
    void solve (vector<int> arr, int target, vector<vector<int>>& vec, int index, int sum, vector<int>& v){
        if (index == arr.size()){
            return ;
        }
        if (sum == target){
            vec.push_back(v);
            return ;
        }
        if (sum > target){
            return ;
        }

        for (int i=0; i<arr.size(); i++){
            sum += arr[i];
            v.push_back(arr[i]);
            solve (arr, target, vec, index+1, sum, v);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> vec;
        int index = 0;
        int sum = 0;
        vector<int> v;
        solve (candidates, target, vec, index, sum, v);

        return vec;
    }
};
