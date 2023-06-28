https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?page=1&category[]=Graph&curated[]=7&sortBy=submissions

T.C.  - O(no. of vertices + edges)
S.C. - O(no. of vertices)


 bool bfsSol(int src, vector<int> adj[], vector<bool> visited){
        unordered_map<int, int> parent;
     
        queue<int> q;
        q.push(src);
        visited[src] = true;
        parent[src] = -1;
        
        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(auto nbr : adj[front]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr] = true;
                    parent[nbr] = front;
                }
                 else if(visited[nbr] && nbr != parent[front]){
                    return true;
                }
                
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited(V, 0);
        
        for(int i =0; i<V; i++){
            if(!visited[i]){
                bool ans = bfsSol(i, adj, visited);
                if(ans){
                    return true;
                }
            }
        }
        return false;
    }



Explaination:

The isCycle function takes the number of vertices V and the adjacency list adj as input. It initializes a vector visited to keep track of visited vertices and iterates through all vertices. For each unvisited vertex, it calls the bfsSol function to perform BFS and check for a cycle. If a cycle is found, the function returns true. If no cycle is found after processing all vertices, the function returns false.

In bfsSol it creates an unordered map parent to store the parent of each visited vertex during BFS. A queue q is initialized with the source vertex src.
The source vertex is marked as visited by setting visited[src] = true.
The parent of the source vertex is set to -1 in the parent map.
While the queue is not empty, the function dequeues a vertex front from the queue.
It iterates over all the neighbors nbr of the dequeued vertex front in the adjacency list. If a neighbor nbr has not been visited, it is enqueued into the queue, marked as visited, and its parent is set to front in the parent map.If a neighbor nbr has been visited and it is not the parent of the current vertex front, it means there is a back edge and a cycle is detected. In this case, the function returns true.
If no cycle is found during the BFS, the function returns false.
