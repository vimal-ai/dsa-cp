#include <bits/stdc++.h>
using namespace std;


int main() {
	
	int n,m; cin>>n>>m;
	vector<vector<int>>v;
	
	for(int i=0;i<m;i++){
	    int x,y,w; cin>>x>>y>>w;
	    v.push_back({x,y,w});
	}
	int src; cin>>src;
	vector<int> dist(n, 1e7);
	dist[src] = 0;
	for(int e=0;e<n-1;e++){
	    for(auto i:v){
	        dist[i[1]] = min(dist[i[1]], i[2]+dist[i[0]]);
	    }
	}
	for(auto i:dist) cout<<i<<" ";
	return 0;
}
