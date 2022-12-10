bool isCyclicDFS(int node,int parent ,unordered_map<int, bool> &visited ,unordered_map<int, set<int>> &adjList){
    visited[node] = true;
    
    for(auto i:adjList[node]){
        if(!visited[i]){
           bool result = isCyclicDFS(i, node, visited, adjList);
             
            if(result) return true;
        }else{
            if(i != parent){
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