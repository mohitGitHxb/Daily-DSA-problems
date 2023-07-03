#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dirs[5] = {-1, 0, 1, 0, -1};
    int n;

    bool invalid(int r, int c) {
        return r < 0 || c < 0 || r == n || c == n;
    }

    void dfs(vector<vector<int>>& grid, int row, int col, vector<vector<int>>& visited) {
        if(invalid(row, col) || !grid[row][col] || visited[row][col]) {
            return;
        }

        visited[row][col] = 1;

        for(int i = 0; i < 4; i++) {
            int nrow = row + dirs[i];
            int ncol = col + dirs[i + 1];
            dfs(grid, nrow, ncol, visited);
        }
    }

    int bfs(vector<vector<int>>& grid, vector<vector<int>>& visited) {
        int res = 0;
        queue<pair<int, int>> q;

        for(int i = 0 ; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(visited[i][j]) {
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()) {
            int size = q.size();

            for(int i = 0; i < size; i++) {
                auto [r, c] = q.front();
                q.pop();

                for(int k = 0; k < 4; k++) {
                    int nrow = r + dirs[k];
                    int ncol = c + dirs[k + 1];

                    if(invalid(nrow, ncol) || visited[nrow][ncol]) {
                        continue;
                    }

                    if(grid[nrow][ncol]) {
                        return res;
                    }

                    q.push({nrow, ncol});
                    visited[nrow][ncol] = 1;
                }
            }
            res++;
        }

        return res;
    }

    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        vector<vector<int>> visited(n, vector<int> (n, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j]) {
                    dfs(grid, i, j, visited);
                    return bfs(grid, visited);
                }
            }
        }

        return -1;
    }
};
