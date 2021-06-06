#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+2;
bool vis[N];
vector<int> adj[N];

int main() {
    int n, m; cin>>n>>m;
    
    for(int i=0;i<m;i++){
        int x,y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    queue<int>q;
    q.push(1);
    vis[1] = 1;
    while(!q.empty()){
        int top = q.front();
        q.pop();
        cout<<top<<" ";
        
        for(auto x: adj[top]){
            if(vis[x]==0){
                q.push(x);
                vis[x] = 1;
            }
        }

    }
    
	return 0;
}
