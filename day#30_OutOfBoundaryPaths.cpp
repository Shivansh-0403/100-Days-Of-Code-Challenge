class Solution {
public:
    int solve(int m, int n, int maxMoves, int startRow, int startColumn, 
                int& ans, map<pair<pair<int, int>, int>, int>& dp){
        
        if (maxMoves < 0){
            return 0;
        }
        if (startRow >= m || startColumn >= n || startRow < 0 || startColumn < 0){
            return 1;
        }

        if (dp.find({{startRow, startColumn}, maxMoves}) != dp.end()){
            return dp[{{startRow, startColumn}, maxMoves}];
        }

        int count = 0;
        count = (count + solve(m, n, maxMoves-1, startRow+1, startColumn, ans, dp)) % 1000000007;
        
        count = (count + solve(m, n, maxMoves-1, startRow-1, startColumn, ans, dp)) % 1000000007;
        
        count = (count + solve(m, n, maxMoves-1, startRow, startColumn+1, ans, dp)) % 1000000007;
        
        count = (count + solve(m, n, maxMoves-1, startRow, startColumn-1, ans, dp)) % 1000000007;

        dp[{{startRow, startColumn}, maxMoves}] = count;
        return count;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int ans = 0;

        map < pair < pair < int, int>, int>, int> dp;
        return solve(m, n, maxMove, startRow, startColumn, ans, dp);
    }
};
