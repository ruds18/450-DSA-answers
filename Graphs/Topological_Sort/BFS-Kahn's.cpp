#include <bits/stdc++.h> 
#include <unordered_map>
#include <queue>
#include <list>

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // BFS - Kahn's Algorithm
    unordered_map<int, list<int>>adjList;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        adjList[u].push_back(v);
    }
    
    vector<int>ans;
    vector<int>indegree(v);
    
    for(auto i:adjList){
        for(auto j:i.second){
            indegree[j]++;
        }
    }
    queue<int>q;
    // Push zero Indegree 
    for(int i=0 ;i<v;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    
    // Do BFS
    while(!q.empty()){
        int front  = q.front();
        q.pop();
        ans.push_back(front);
        
        for(auto i:adjList[front]){
            indegree[i]--;
            
            if(indegree[i] ==0) q.push(i);
        }
    }
        return ans;

}