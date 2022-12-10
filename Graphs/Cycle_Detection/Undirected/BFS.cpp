bool isCyclicBFS(int node ,unordered_map<int, bool> &visited ,unordered_map<int, set<int>> &adjList){
 queue<int>q;
    unordered_map<int, int>parent;
  q.push(node);
    visited[node] = true;
    // source node
    parent[node] = -1;
    
    // neighbour check
    while(!q.empty()){
        int front = q.front();
        q.pop();
        
        for(auto i: adjList[front]){
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
                parent[i] = front;
            }else if(visited[i] && i != parent[front]){
                return true;
            }
        }
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int, set<int>>adjList;
    unordered_map<int, bool>visited;
  
    for(int i=0 ; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        // Undirected graph
        adjList[u].insert(v);
        adjList[v].insert(u);
    }
    
    //bfs call
    
    for(int i=0 ;i<n;i++){
        if(!visited[i]){
            bool ans = isCyclicBFS(i , visited , adjList);
            if(ans) return "Yes";
        }
    }
    return "No";
}