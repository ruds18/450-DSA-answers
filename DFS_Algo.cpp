#include <bits/stdc++.h> 
#include <unordered_map>
#include <set>


void dfs(int node , vector<bool>&visited, vector<int>&ans,unordered_map<int, set<int>> &adjList ){
    visited[node] = true;
    ans.push_back(node);
    for(auto i:adjList[node]){
        if(!visited[i]){
            dfs(i,visited, ans, adjList);
        }
    }
}

vector<vector<int>> depthFirstSearch(int vertex, int E, vector<vector<int>> &edges)
{
    unordered_map<int, set<int>>adjList;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        adjList[u].insert(v);
        adjList[v].insert(u);
    }
    vector<bool>visited(vertex);
    vector<vector<int>> ans;
    for(int i=0; i<vertex; i++){
        if(!visited[i]){
            vector<int>component;
            dfs(i, visited, component, adjList);
            ans.push_back(component);
        }
    }
    return ans;
}