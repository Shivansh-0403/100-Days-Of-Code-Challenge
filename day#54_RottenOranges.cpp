class Solution {
public:
    // int solve(int i, int j, vector<vector<int>>& grid, map<pair<int, int>, bool> mp){
    //     // if (i >= grid.size() || )

    //     if (mp[{i,j}]){
    //         return 0;
    //     }
    //     cout<<i<<" "<<j<<endl;
    //     mp[{i, j}] = true;
    //     int ans = INT_MAX;
    //     if (i-1 >= 0){
    //         if (grid[i-1][j] == 1){
    //             ans = min(ans, solve(i-1, j, grid, mp));
    //         }
    //     }
    //     if (i+1 < grid.size()){
    //         if (grid[i+1][j] == 1){
    //             ans = min(ans, solve(i+1, j, grid, mp));
    //         }
    //     }
    //     if (j-1 >= 0){
    //         if (grid[i][j-1] == 1){
    //             ans = min(ans, solve(i, j-1, grid, mp));
    //         }
    //     }
    //     if (j+1 < grid[0].size()){
    //         if (grid[i][j+1] == 1){
    //             ans = min(ans, solve(i, j+1, grid, mp));
    //         }
    //     }

    //     if (ans == INT_MAX){
    //         return 1;
    //     }
    //     else {
    //         return ans+1;
    //     }
    // }
    int orangesRotting(vector<vector<int>>& grid) {
        // dfs try
        // 2 wala node, -> ek node pe aage jao aate waqt 1 add kar do

        
        
        
        // solve using bfs, a, mpdjacent ko rot karna hai, 
        // ek node ke adjacent nodes ya connected nodes ek second mein rotten ho jayenge

        queue<vector<int>> q;
        int x = -1, y = -1;
        map<pair<int, int>, bool> mp;
        for (int i=0; i<grid.size(); i++){
            bool flag = false;
            for (int j=0; j<grid[i].size(); j++){
                if (grid[i][j] == 2){
                    q.push({i,j});
                    x = i;
                    y = j;
                    flag = true;
                    // break;
                }
            }
            // if (flag){
            //     break;
            // }
        }

        // if (x == -1 && y == -1){
        //     return -1;
        // }
        // else {
        //     return solve(x, y, grid, mp);
        // }

        q.push({-1, -1});
        int count = 0;
        while (!q.empty()){
            vector<int> v = q.front();
            q.pop();
            bool flag = false;

            if (v[0] == -1 && v[1] == -1){
                if (!q.empty()){
                    q.push({-1, -1});
                    count++;
                }
            }
            else {
                cout<<v[0]<<" "<<v[1]<<endl;
                if (v[0]-1 >= 0){
                    if (grid[v[0]-1][v[1]] == 1){
                        q.push({v[0]-1, v[1]});
                        grid[v[0]-1][v[1]] = 2;
                        // flag = true;
                        // cout<<v[0]-1<<" "<<v[1]<<" , ";
                    }
                }
                if (v[0]+1 < grid.size()){
                    if (grid[v[0]+1][v[1]] == 1){
                        q.push({v[0]+1, v[1]});
                        grid[v[0]+1][v[1]] = 2;
                        // flag = true;
                        // cout<<v[0]+1<<" "<<v[1]<<" , ";
                    }
                }
                if (v[1]-1 >= 0){
                    if (grid[v[0]][v[1]-1] == 1){
                        q.push({v[0], v[1]-1});
                        grid[v[0]][v[1]-1] = 2;
                        // flag = true;
                        // cout<<v[0]<<" "<<v[1]-1<<" , ";
                    }
                }
                if (v[1]+1 < grid[0].size()){
                    if (grid[v[0]][v[1]+1] == 1){
                        q.push({v[0], v[1]+1});
                        grid[v[0]][v[1]+1] = 2;
                        // flag = true;
                        // cout<<v[0]<<" "<<v[1]+1<<" , ";
                    }
                }
            }
            // if (flag) count++;
            // cout<<endl;
        }

        for (int i=0; i<grid.size(); i++){
            for (int j=0; j<grid[i].size(); j++){
                if (grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return count;
    }
};
