#include <bits/stdc++.h> 
#include <unordered_map>
#include <stack>
#include <list>

void dfs(int node ,unordered_map<int, list<int>> &adjList,stack<int> &st, 
          unordered_map<int, bool>&vis){
    vis[node] = true;
    for(auto i:adjList[node]){
        if(!vis[i]){
            dfs(i,adjList, st,vis);
        }
    }
    st.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // DFS
    unordered_map<int, list<int>>adjList;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        adjList[u].push_back(v);
    }
    vector<int>ans;
    unordered_map<int, bool>vis;
    stack<int>st;
    
    for(int i =0 ;i<v ; i++){
        if(!vis[i]){
            dfs(i, adjList, st, vis);
        }
    }
    
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}