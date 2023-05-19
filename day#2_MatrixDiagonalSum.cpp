class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        
        int diagonalSum = 0;
        for (int i=0;i<mat.size();i++){
            diagonalSum += mat[i][i];
            diagonalSum += mat[i][mat.size()-1-i];
        }
        
        if (mat.size() % 2 != 0){
            diagonalSum -= mat[(mat.size()/2)][(mat.size()/2)];
        }

        return diagonalSum;
        
    }
};
