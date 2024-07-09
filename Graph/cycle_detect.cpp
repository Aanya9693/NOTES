#include<bits/stdc++.h>
using namespace std;

// - - - - - - - IS CYCLE EXIST - - - - - - 

bool detect_bfs(int start, int n, vector<int>adj[]){
    int vis[n]={start};
    vis[start]=1;
    queue<pair<int, int>>q;
    
    //node, came from(parent)
    q.push({start, -1});
    
    while(!q.empty()){
        int node=q.front().first;
        int parent=q.front().second;
        q.pop();
        
        for(auto it:adj[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push({it, node});
            }else if(parent != it){
            	return true;
            }
        }
    }
    return false;
}

void dfs(int node, int vis[], vector<int>adj[], vector<int>& ansdfs){
    vis[node]=1;
    ansdfs.push_back(node);
    
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it, vis, adj, ansdfs);
            // vis[it]=1;
        }
    }
}

int main(){
    //no. of node;
    int n=6;
    // array of vectors, [{}, {}, {}, ...];
    vector<int>adj[n];
    adj[0].push_back(1);
    adj[0].push_back(2); //
    adj[1].push_back(0);
    adj[1].push_back(3); //
    adj[2].push_back(0);
    adj[2].push_back(4); //
    adj[3].push_back(1); 
    adj[3].push_back(5); //
    adj[4].push_back(2); //
    adj[5].push_back(3);
    adj[5].push_back(4); //
    
    //-----running bfs
    bool ans = detect_bfs(0, n, adj);
    
    // ----Printing the result
    cout << "Cycle using BFS Traversal: ";
    cout <<ans;
    cout<<endl;
    //----running dfs
    // int vis[n]={0};
    // vector<int>ansdfs;
    // dfs(0, vis, adj, ansdfs);
    
    // cout << "DFS Traversal: ";
    // for (int i : ansdfs) {
    //     cout << i << " ";
    // }
    return 0;
}

