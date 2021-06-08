#include <bits/stdc++.h>
using namespace std;

vector<int> v(1e3+5);
vector<int> size(1e3+5);

void initialize(int n){
    for(int i=0;i<n;i++){
        v[i] = i;
        size[i] = 1;
    }
}

int find_set(int a){
    while(a!=v[a]){
        v[a] = v[v[a]];
        a = v[a];
    }
    return a;
}

void union_set(int a, int b){
    a = find_set(a);
    b = find_set(b);
    
    if(a!=b){
        if(size[a] < size[b]) swap(a, b);
        v[b] = v[a];
        size[a] += size[b];
    }
    
}

int main() {
	
	int n,m; cin>>n>>m;
    initialize(n);
    
    vector<vector<int>> edges;
    for(int i=0;i<m;i++){
        int u, v, w; cin>>u>>v>>w;
        edges.push_back({w,u,v});
    }
	sort(edges.begin(), edges.end());
	
	int cost = 0;
	for(auto i:edges){
	    int x = find_set(i[1]);
	    int y = find_set(i[2]);
	    if(x!=y){
	        cout<<x<<" "<<y<<endl;
	        cost += i[0];
	        union_set(i[1],i[2]);
	    }
	}cout<<cost;
	
	return 0;
}
