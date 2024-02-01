class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int> v(temp.size(), 0);
        stack<int> st;      // Store index

        for (int i=temp.size()-1; i>=0; i--){
            if (!st.empty() && temp[st.top()] > temp[i]){
                v[i] = st.top()-i;
                st.push(i);
            }
            else {
                while (!st.empty() && temp[st.top()] <= temp[i]){
                    st.pop();
                }

                if (st.empty()){
                    v[i] = 0;
                }
                else {
                    v[i] = st.top()-i;
                }

                st.push(i);
            }
        }

        return v;
    }
};
