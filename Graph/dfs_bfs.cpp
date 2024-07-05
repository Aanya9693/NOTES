#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define ll long long


vector<int>bfs(int n, vector<int>adj[]){
    int vis[n]={0};
    vis[0]=1;
    queue<int>q;
    q.push(0);
    vector<int>bfs;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        bfs.push_back(node);
        for(auto it:adj[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push(it);
            }
        }
    }
    return bfs;
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
    
    //running bfs
    vector<int> result = bfs(n, adj);
    
    // Printing the result
    cout << "BFS Traversal: ";
    for (int i : result) {
        cout << i << " ";
    }
    cout<<endl;
    //running dfs
    int vis[n]={0};
    vector<int>ansdfs;
    dfs(0, vis, adj, ansdfs);
    
    cout << "DFS Traversal: ";
    for (int i : ansdfs) {
        cout << i << " ";
    }
    return 0;
}
