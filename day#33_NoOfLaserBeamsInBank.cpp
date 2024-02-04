class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0;
        int prev = 0;
        int curr = 0;
        for (int i=0; i<bank.size(); i++){
            curr = 0;
            for (int j=0; j<bank[i].length(); j++){
                if (bank[i][j] == '1'){
                    curr++;
                }
            }
            cout<<prev<<" "<<curr<<endl;
            if (curr != 0){
                ans += (prev*curr);
                prev = curr;
            }
            if (prev == 0){
                prev = curr;
            }
        }
        return ans;
    }
};
