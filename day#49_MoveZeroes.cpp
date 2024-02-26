class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        // reverse(nums.begin(), nums.end());
        // int iter = 0;
        // for (int i=0;i<nums.size();i++){
        //     if (nums[i]!=0){
                
        //     }
        // }

        int i = 0;
        while (i<nums.size()){
            if (nums[i] != 0){
                i++;
                continue;
            }
            else {
                for (int j=i; j<nums.size()-1; j++){
                    swap(nums[j], nums[j+1]);
                }
                i++;
            }
        }

        // vector<int> nonzeroes;
        // int count = 0;
        // for (int i=0; i<nums.size(); i++){
        //     if (nums[i] == 0){
        //         count++;
        //     }
        //     else {
        //         nonzeroes.push_back(nums[i]);
        //     }
        // }
        // for (int i=0; i<count; i++){
        //     nonzeroes.push_back(0);
        // }

        // nums = nonzeroes;
        // return;
    }
};
