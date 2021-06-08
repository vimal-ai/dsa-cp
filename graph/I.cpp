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
    bool cycle =false;
	initialize(n);
	for(int i=0;i<m;i++){
	    int x,y; cin>>x>>y;
	    
	    int u = find_set(x);
	    int v = find_set(y);
	    
	    if(u==v) cycle = true;
	    else union_set(x,y);
	}
	
	cout<<cycle<<endl;
	
	return 0;
}
