class Solution {
public:
    int trap(vector<int>& nums) {
        stack<int> st;
        vector<int> next;

        for (int i=nums.size()-1; i>=0; i--){
            if (st.empty()){
                next.push_back(-1);
                st.push(i);
            }

            else if (!st.empty() && nums[st.top()] >= nums[i]){
                next.push_back(st.top());
                st.push(i);
            }

            else {
                while (!st.empty() && nums[st.top()] < nums[i]){
                    st.pop();
                }

                if (st.empty()){
                    next.push_back(-1);
                }
                else {
                    next.push_back(st.top());
                }

                st.push(i);
            }
        }
        reverse(next.begin(), next.end());


        st = stack<int> ();
        vector<int> prev;

        for (int i=0; i<nums.size(); i++){
            if (st.empty()){
                prev.push_back(-1);
                st.push(i);
            }

            else if (!st.empty() && nums[st.top()] >= nums[i]){
                prev.push_back(st.top());
                st.push(i);
            }

            else {
                while (!st.empty() && nums[st.top()] < nums[i]){
                    st.pop();
                }

                if (st.empty()){
                    prev.push_back(-1);
                }
                else {
                    prev.push_back(st.top());
                }

                st.push(i);
            }
        }

        int it = 0;
        int ans = 0;
        while (it < nums.size()){
            if (next[it] == -1){
                break;
            }
            else {
                int jt = it+1;
                int sum = 0;
                for (jt; jt<next[it]; jt++){
                    sum += nums[it] - nums[jt];
                }
                ans += sum;
                it = jt-1;
                it++;
            }
        }

        for (int i=nums.size()-1; i>it; i--){
            int sum = 0;
            int j = i;
            while (j > prev[i]){
                sum += nums[i] - nums[j];
                j--;
            }
            i = j+1;
            ans += sum;
        }

        return ans;
    }
};
