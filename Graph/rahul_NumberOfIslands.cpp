#include <bits/stdc++.h>
using namespace std;

/* https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1?page=1&category[]=Graph&curated[]=7&sortBy=submissions


TC O(nm)
SC O(nm) */
void bfs(map<pair<int, int>, bool> &visited, int row, int col, vector<vector<char>> &grid)
{
    queue<pair<int, int>> q;
    // initial steps
    q.push({row, col});
    visited[{row, col}] = true;

    while (!q.empty())
    {
        pair<int, int> fNode = q.front();
        q.pop();
        int x = fNode.first;
        int y = fNode.second;

        // i can move in 4 directions
        int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
        int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
        for (int i = 0; i < 8; i++)
        {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if (newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size() &&
                !visited[{newX, newY}] && grid[newX][newY] == '1')
            {
                q.push({newX, newY});
                visited[{newX, newY}] = true;
            }
        }
    }
}
int numIslands(vector<vector<char>> &grid)
{

    map<pair<int, int>, bool> visited;
    int count = 0;

    for (int row = 0; row < grid.size(); row++)
    {
        int n = grid[row].size();
        for (int col = 0; col < n; col++)
        {
            if (!visited[{row, col}] && grid[row][col] == '1')
            {
                bfs(visited, row, col, grid);
                count++;
            }
        }
    }
    return count;
}

/* The numIslands function takes a grid as input and initializes a map visited to keep track of visited cells.
It iterates through each cell in the grid. If a cell is not visited and contains '1' (indicating land), it calls the bfs function to explore the connected land cells starting from that position.
After calling bfs, it increments the count of islands since a new island has been found.
Finally, the function returns the total count of islands in the grid.

The bfs function performs a BFS starting from a given row and column in the grid. It uses a queue to explore neighboring cells and marks them as visited in a map. Here's how it works:

It initializes a queue q and inserts the starting position (row, col) into the queue.
The starting position is marked as visited in the visited map.
While the queue is not empty, the function dequeues a position (x, y) from the queue.
It defines arrays dx and dy to represent the possible movements in four directions (up, right, down, left) and diagonals.
It iterates through the directions and calculates the new positions (newX, newY) based on the current position (x, y) and the movement.
If the new position is within the grid boundaries, not visited, and contains '1' (indicating land), it is enqueued into the queue and marked as visited in the visited map.
The process continues until the queue becomes empty, exploring all the connected land cells. */

int main(int argc, char **argv)
{
    return 0;
}