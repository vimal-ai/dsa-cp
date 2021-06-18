#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+2;
bool vis[N];
vector<int> adj[N];


bool isCycle(int src, vector<bool>st){
    st[src] = 1;
    if(!vis[src]){
        vis[src]=1;
        
        for(auto x: adj[src]){
	    if(st[x]) return true;
            if(!vis[x] and isCycle(x, st)) return true;
        } 
    }
    st[src] = 0;
    return false;
}

int main() {
    int n, m; cin>>n>>m;
    vector<int> indeg(n, 0);
    for(int i=0;i<m;i++){
        int x,y; cin>>x>>y;
        adj[x].push_back(y);
    }
    
    bool cycle = 0;
    vector<bool> st(N,0);
    for(int i=0;i<n;i++){
        if(!vis[i] and isCycle(i, st)) cycle = true;
    }
    
    if(cycle) cout<<"Cycle is present";
    else cout<<"Cycle is not present";
    
	return 0;
}
