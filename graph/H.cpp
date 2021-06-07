#include<bits/stdc++.h>
using namespace std;

vector<int> v(1e3+5);
vector<int> size(1e3+5);

void initializze(int n){
    for(int i = 1; i <= n; i++){
        v[i] = i;
        size[i] = 1;
    }
}

int root(int i){
    while(i != v[i]){
        v[i] = v[v[i]];
        i = v[i];
    }
    return i;
}

void wu(int x, int y){
    int rootX = root(x);
    int rootY = root(y);

    if(size[rootX] < size[rootY]){
        v[rootX] = v[rootY];
        size[rootY] += size[rootX];
    }else{
        v[rootY] = v[rootX];
        size[rootX] += size[rootY];
    }

}
