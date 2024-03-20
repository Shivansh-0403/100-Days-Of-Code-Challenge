class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> ms;

        for (int i=0; i<s.length(); i++){
            ms[s[i]]++;
        }

        string str = "";
        for (int i=0; i<order.length(); i++){
            string temp(ms[order[i]], order[i]);
            str += temp;
            ms[order[i]] = 0;
        }

        // cout<<endl<<str<<endl;
        for (auto i:ms){
            if (i.second > 0){
                string temp(i.second, i.first);
                str += temp;
            }
        }
        return str;
    }
};
