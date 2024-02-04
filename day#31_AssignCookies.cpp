class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int count = 0;
        int itg = 0;
        int its = 0;
        while (itg < g.size() && its < s.size()){
            if (g[itg] <= s[its]){
                count++;
                its++;
                itg++;
            }
            else {
                its++;
            }
        }

        return count;
    }
};
