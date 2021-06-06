#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+2;
bool vis[N];
vector<int> adj[N];

bool isCycle(int src, int parent){
    vis[src] =  1;
    for(auto x: adj[src]){
        if(x!=parent){
            if(vis[x]) return true;
            return isCycle(x, src);
        } 
    }
    return false;
}

int main() {
    int n, m; cin>>n>>m;
    vector<int> indeg(n, 0);
    for(int i=0;i<m;i++){
        int x,y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    bool cycle = 0;
    
    for(int i=0;i<n;i++){
        if(!vis[i] and isCycle(i,-1)) cycle = true;
    }
    if(cycle) cout<<"Cycle is present";
    else cout<<"Cycle is not present";
    
	return 0;
}
