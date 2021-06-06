#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+2;
bool vis[N];
vector<int> adj[N];
vector<int>components;
int nodes = 0;

int getComp(int src){
    vis[src] = 1;
    nodes++;
    for(auto x: adj[src]){
        if(!vis[x]) getComp(x);
    }
    return nodes;
}

int main() {
    int n, m; cin>>n>>m;
    vector<int> indeg(n, 0);
    for(int i=0;i<m;i++){
        int x,y; cin>>x>>y;
        adj[x].push_back(y);
        // adj[y].push_back(x);
    }
    
    bool cycle = 0;
    vector<bool> st(N,0);
    vector<int>v;
    for(int i=0;i<n;i++){
        if(!vis[i]) components.push_back(getComp(i));
        nodes = 0;
    }
    
    for(auto x:components){
        cout<<x<<" ";
    }
    
    
	return 0;
}
