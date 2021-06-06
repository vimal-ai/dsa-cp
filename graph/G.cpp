#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+2;
bool vis[N];
vector<int> adj[N];
vector<int> color(N, -1);
bool bp=1;

void bipartite(int src, int parent, bool curr){
    // cout<<src<<" "<<curr<<"->";
    if(color[src]==-1){
        color[src] = curr;
    }else if(color[src] != curr){
        bp=0;
        return;
    };
    if(vis[src]) return;
    vis[src] = 1;
    for(auto x: adj[src]){
        bipartite(x, src, !curr);
    }
}

int main() {
    int n, m; cin>>n>>m;
    vector<int> indeg(n, 0);
    for(int i=0;i<m;i++){
        int x,y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    for(int i=0;i<n;i++){
        if(!vis[i]) bipartite(i, -1, 1);
    }
    cout<<bp;
	return 0;
}
