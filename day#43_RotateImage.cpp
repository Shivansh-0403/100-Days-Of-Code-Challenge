class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> v;
        vector<int> vec;
        for (int j=0; j<matrix.size(); j++){
            for (int i=matrix.size()-1; i>=0; i--){
                vec.push_back(matrix[i][j]);
            }
            v.push_back(vec);
            vec.clear();
        }

        matrix = v;
    }
};
