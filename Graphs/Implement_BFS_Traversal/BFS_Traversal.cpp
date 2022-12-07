#include <bits/stdc++.h> 
#include <unordered_map>
#include <set>
#include <queue>
void bfs(int node , vector<bool>&visited, vector<int>&ans,unordered_map<int, set<int>> &adjList ){
     queue<int>q;
    q.push(node);
    visited[node] = true;
    
    while(!q.empty()){
        int front  = q.front();
        q.pop();
        
        ans.push_back(front);

        for(auto i: adjList[front]){
            if(!visited[i]){
                visited[i]=true;
                q.push(i);
            }
        }
    }
}


vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int, set<int>>adjList;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;
        
        // Undirected graph
        adjList[u].insert(v);
        adjList[v].insert(u);
    }
    vector<bool>visited(vertex);
    vector<int> ans;
    for(int i=0; i<vertex; i++){
        if(!visited[i]){
            bfs(i, visited, ans, adjList);
        }
    }
    return ans;
}