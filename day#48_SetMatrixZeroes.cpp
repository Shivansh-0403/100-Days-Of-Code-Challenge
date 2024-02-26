class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        for (int i=0; i<matrix.size(); i++){
            for (int j=0; j<matrix[0].size(); j++){
                if (matrix[i][j] == 0){
                    for (int x=0; x<matrix.size(); x++){
                        if (matrix[x][j] == 0) continue;
                        matrix[x][j] = INT_MAX-7;
                    }
                    for (int x=0; x<matrix[0].size(); x++){
                        if (matrix[i][x] == 0) continue;
                        matrix[i][x] = INT_MAX-7;
                    }
                    matrix[i][j]=0;
                }
            }
        }
        for (int i=0; i<matrix.size(); i++){
            for (int j=0; j<matrix[0].size(); j++){
                if (matrix[i][j] == INT_MAX-7){
                    matrix[i][j] = 0;
                }
            }
        }


      // Approach 2
      // map<int, bool> row;
      //   map<int, bool> col;

      //   for (int i=0; i<matrix.size(); i++){
      //       row[i] = false;
      //       for (int j=0; j<matrix[0].size(); j++){
      //           if (matrix[i][j] == 0){
      //               row[i] = true;
      //               col[j] = true;
      //           }
      //       }
      //   }

      //   for (int i=0; i<matrix.size(); i++){
      //       if (row[i] == true){
      //           for (int j=0; j<matrix[0].size(); j++){
      //               matrix[i][j] = 0;
      //           }
      //       }
      //       // else {

      //       // }
      //   }
      //   for (int i=0; i<matrix[0].size(); i++){
      //       if (col.find(i) != col.end()){
      //           for (int j=0; j<matrix.size(); j++){
      //               matrix[j][i] = 0;
      //           }
      //       }
      //   }

        return ;
    }
};
