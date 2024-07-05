#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define ll long long



bool isBipartite_dfs(int node, int col, vector<int>adj[], int color[]){
    color[node]=col;
    
    for(auto it:adj[node]){
        if(color[it]==-1){
            if(isBipartite_dfs(it, !col, adj, color)==false){
                return false;
            }
        }else if(color[it]==color[node]){
            return false;
        }
    }
    return true;
}

bool isBipartite_bfs(int start, int n, vector<int>adj[], int color[]){
    queue<int>q;
    q.push(start);
    
    // vector<int>color(n, -1);
    color[start]=0;
    
    while(!q.empty()){
        int node=q.front();
        q.pop();
        
        for(auto it:adj[node]){
            if(color[it]==-1){
                color[it] = !color[node];
                q.push(it);
            }else if(color[it]==color[node]){
                return false;
            }
        }
    }
    return true;
    
}


int main(){
    //no. of node;
    int n=6;
    // array of vectors, [{}, {}, {}, ...];
    vector<int>adj[n];
    
   // Bipartite graph example
    // adj[0].push_back(1);
    // adj[1].push_back(0);
    // adj[1].push_back(2);
    // adj[2].push_back(1);
    // adj[2].push_back(3);
    // adj[3].push_back(2);
    // adj[3].push_back(4);
    // adj[4].push_back(3);
    // adj[4].push_back(5);
    // adj[5].push_back(4);
    
    // Non-bipartite graph example
    adj[0].push_back(1);
    adj[0].push_back(2);
    
    adj[1].push_back(0);
    adj[1].push_back(2);
    
    adj[2].push_back(0);
    adj[2].push_back(1);
    adj[2].push_back(3);
    
    adj[3].push_back(2);
    adj[3].push_back(4);
    
    adj[4].push_back(3);
    adj[4].push_back(5);
    
    adj[5].push_back(4);
    
    //-----------running bfs
    
    cout << "Is Bipartite using BFS Traversal: ";
    int color[n];
    for(int i=0; i<n; i++)color[i]=-1;
    bool ans=true;
    for(int i=0; i<n; i++){
        if(color[i]==-1){
            if(isBipartite_bfs(i, n, adj, color)==false){
                ans = false;
                break;
            }
        }
    }    
    
    cout<<ans<<endl;

    
   cout << "Is Bipartite using DFS Traversal: ";
    // int color[n];
    for(int i=0; i<n; i++)color[i]=-1;
    bool ans_DFS=true;
    for(int i=0; i<n; i++){
        if(color[i]==-1){
            if(isBipartite_dfs(i, 0, adj, color)==false){
                ans_DFS = false;
                break;
            }
        }
    }    
    
    cout<<ans_DFS<<endl;
    return 0;
}
