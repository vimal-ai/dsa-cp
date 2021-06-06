#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+2;
bool vis[N];
vector<int> adj[N];


int main() {
    int n, m; cin>>n>>m;
    vector<int> indeg(n, 0);
    for(int i=0;i<m;i++){
        int x,y; cin>>x>>y;
        adj[x].push_back(y);
        indeg[y]++;
    }
    
    queue<int>pq;
    for(int i=0;i<n;i++){
        if(!indeg[i]) pq.push(i);
    }
    
    while(!pq.empty()){
        int top = pq.front();
        pq.pop();
        cout<<top<<" ";
        for(auto x:adj[top]){
            indeg[x]--;
            if(!indeg[x]) pq.push(x);
        }
    }
    
	return 0;
}
