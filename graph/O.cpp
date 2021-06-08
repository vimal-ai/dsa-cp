#include <bits/stdc++.h>
using namespace std;


int main() {
	
	int n,m; cin>>n>>m;
	vector<vector<int>>v(n);
	
	for(int i=0;i<n;i++){
	    vector<int>temp(n);
	    for(int j=0;j<n;j++)temp[j]=1e7;
	    v[i]=temp;
	}
	
	for(int i=0;i<m;i++){
	    int x,y,w; cin>>x>>y>>w;
	    v[x][y] = w;
	   // v[y][x] = w;
	}
	vector<vector<int>> dist = v;
	
	for(int k=0;k<n;k++){
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
	        }
	    }
	}
	
	for(int i=0;i<n;i++){
	    for(int j=0;j<n;j++){
	      if(dist[i][j]!=1e7) cout<<dist[i][j]<<" ";
	      else cout<<-1<<" ";
	    } 
	    cout<<endl;
	}
	
	
	return 0;
}
