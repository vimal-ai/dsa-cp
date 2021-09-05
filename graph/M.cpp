#include <bits/stdc++.h>
using namespace std;

#define ff          first
#define ss          second
#define pb          push_back
#define pii         pair<int, int>
#define vi          vector<int>
#define vvi         vector<vector<int>>
#define mii         map<int, int>
#define mk          make_pair
#define pqb         priority_queue<int>
#define pqs         priority_queue<int, vi, greater<int>>
#define w(t)        int t; cin>>t; while(t--)

vector<vector<pair<int,int>>>adj;
vector<bool>vis;
vector<int>dis;
const int inf = 1e7;


int main() {
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m; cin>>n>>m;
    adj = vector<vector<pair<int,int>>>(n);
    vis = vector<bool>(n, 0);
    dis = vector<int>(n);

    for(int i=0;i<m;i++){
        int a, b, w; cin>>a>>b>>w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    int src; cin>>src;
    
    for(int i=0;i<n;i++)dis[i] = inf;
    dis[src] = 0;

    
    priority_queue<pii, vector<pii>, greater<pii>> mh;
    mh.push({0, src});

    // waight, node
    while(!mh.empty()){
        int w = mh.top().ff;
        int n = mh.top().ss;
        mh.pop();
        for(auto i:adj[n]){
            if(dis[i.ff]> i.ss+w){
                dis[i.ff] = i.ss+w;
                mh.push({dis[i.ff], i.ff});
            }
        }
    }

    for(auto i:dis) cout<<i<<' ';

	return 0;
}
