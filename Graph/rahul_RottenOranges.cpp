https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1



TC O(nm)
SC O(nm)

int orangesRotting(vector<vector<int>>& grid) {
        
        queue<pair<pair<int,int> , int > > q;
        vector<vector<int>> arr = grid;
        int count = 0;
        int ansTime = 0;
        //insert all rotten oranges in queue
        for(int row=0; row<grid.size(); row++) {
            for(int col=0; col<grid[row].size(); col++ ) {
                if(grid[row][col] ==2) {
                    //rotten orange found
                    pair<int,int> coordinate = make_pair(row, col);
                    q.push({coordinate,0});
                }
            }
        }

        while(!q.empty()) {
            pair<pair<int,int> , int > fNode = q.front();
            q.pop();
            int x = fNode.first.first;
            int y = fNode.first.second;
            int time = fNode.second;

            int dx[] = {-1,0,1,0};
            int dy[] = {0,1,0,-1};
            for(int i=0; i<4; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];

                if(newX >=0 && newX < arr.size() && newY >=0 && newY < arr[0].size() &&
                 arr[newX][newY] == 1) {
                     pair<int,int> newCoordinates = make_pair(newX, newY);
                     ansTime = max(ansTime, time+1);
                     q.push({newCoordinates, time + 1});
                     //mark rotten
                     arr[newX][newY] = 2;
                 }
            }


        }

        //chec for fresh orange
        for(int i=0;i<arr.size(); i++) {
            for(int j=0;j<arr[0].size();j++) {
                if(arr[i][j] == 1) {
                    return -1;
                }
            }
        }
       return ansTime;

    }


Explaination

initializes a queue q to store the coordinates of rotten oranges and their corresponding time.
It creates a copy of the input grid called arr to track the state of the oranges during the simulation.
It initializes count to 0 and ansTime to 0. count is used to keep track of the total number of rotten oranges, and ansTime stores the final answer.
It iterates through the grid and finds all the initially rotten oranges (marked as 2) and inserts their coordinates and time (0) into the queue.
While the queue is not empty, it dequeues a pair consisting of the coordinates and time of a rotten orange.
It extracts the x and y coordinates and the time from the dequeued pair.
It defines arrays dx and dy to represent the possible movements in four directions (up, right, down, left).
It iterates through the directions and calculates the new coordinates (newX, newY) based on the current coordinates (x, y) and the movement.
If the new coordinates are within the grid boundaries and there is a fresh orange (marked as 1), it marks it as rotten (2), updates ansTime to the maximum of the current time+1 and the previous ansTime, and enqueues the new coordinates and the updated time into the queue.
After processing all the neighbors of a rotten orange, the simulation moves to the next orange in the queue.
Once the BFS simulation completes, it checks if there are any remaining fresh oranges in the grid. If so, it returns -1, indicating that not all oranges can become rotten.
Otherwise, it returns the value of ansTime, which represents the minimum time required for all oranges to become rotten.
