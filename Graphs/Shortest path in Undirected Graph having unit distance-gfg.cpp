class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
       unordered_map<int, list<int>>adjList;
       for(int i=0; i<edges.size(); i++){
           int u = edges[i][0];
           int v = edges[i][1];
           
           adjList[u].push_back(v);
           adjList[v].push_back(u);
       }
       
       vector<bool>vis(N, false);
       vector<int>dist(N,-1);
       queue<pair<int, int>>q;
       
     
       int steps =0;
       
      q.push({src,steps});
      vis[src] =true;
      dist[src] = steps;
      
      while(!q.empty()){
      int front= q.front().first;
      steps = q.front().second+1;
      dist[front] = steps-1;
      q.pop();
      
      for(auto i:adjList[front]){
          if(!vis[i]){
              vis[i] = true;
             q.push({i, steps});
          }
      }
      
    }
          return dist;
    }
};