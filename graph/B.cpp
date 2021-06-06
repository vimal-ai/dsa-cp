#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+2;
bool vis[N];
vector<int> adj[N];

void dfs(int node){
    
    // preorder
    vis[node] = 1;
    cout<<node<<" ";
    
    // inorder
    for(auto x: adj[node]){
        if(!vis[x]) dfs(x);
    }
    
    // postorder
}

int main() {
    int n, m; cin>>n>>m;
    
    for(int i=0;i<m;i++){
        int x,y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    dfs(1);
    
	return 0;
}
