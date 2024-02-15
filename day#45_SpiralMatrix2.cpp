class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int> (n, 0));
        int rowStart = 0;
        int colStart = 0;
        int rowEnd = n-1;
        int colEnd = n-1;

        int num = 1;
        
        while (rowStart<=rowEnd && colStart<=colEnd){
            for (int i=colStart; i<=colEnd; i++){
                ans[rowStart][i] = num;
                num++;
            }
            rowStart++;

            for (int i=rowStart; i<=rowEnd; i++){
                ans[i][colEnd] = num;
                num++;
            }
            colEnd--;

            for (int i=colEnd; i>=colStart; i--){
                ans[rowEnd][i] = num;
                num++;
            }
            rowEnd--;

            for (int i=rowEnd; i>=rowStart; i--){
                ans[i][colStart] = num;
                num++;
            }
            colStart++;
        }

        return ans;
    }
};
