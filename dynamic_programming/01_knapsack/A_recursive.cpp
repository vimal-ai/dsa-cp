#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>memo(1e3, vector<int>(1e3, -1));

int knapsack(int weight[], int value[], int n, int w){
    
    if(n==0||w==0) return 0;
    
    if(memo[n][w] != -1) return memo[n][w];
    
    int profit;
    if(weight[n-1] > w){
        profit = knapsack(weight, value, n-1, w);
    }else{
        int profit1 = knapsack(weight, value, n-1, w);
        int profit2 = value[n-1] + knapsack(weight, value, n-1, w-weight[n-1]);
        profit = max(profit1, profit2);
    }
    memo[n][w] = profit;
    return profit;
}

int main() {
	int n,w; cin>>n>>w;
	int weight[n], value[n];
	
	for(int i=0;i<n;i++) cin>>weight[i];
	for(int i=0;i<n;i++) cin>>value[i];
    
	cout<<knapsack(weight, value, n, w);
	return 0;
}
