/*
coin change porblem :  minimum number of coin to make a given value

https://www.geeksforgeeks.org/find-minimum-number-of-coins-that-make-a-change/
*/


#include <bits/stdc++.h>
using namespace std;

    vector<vector<int>> memo = vector<vector<int>> (1002, vector<int>(1002));
    
    // v = value , M = length of array 
	int minCoins(int coins[], int M, int V) 
	{
	    for(int i=0;i<=V;i++) memo[0][i] = 1e7+5;
	    for(int i=0;i<=M;i++) memo[i][0] = 0;
	    for(int i=1;i<=V;i++) memo[1][i] = (i%coins[0])?1e7+5:(i/coins[0]);
	    
	    for(int i=2;i<=M;i++){
	        for(int j=1;j<=V;j++){
	            memo[i][j] = memo[i-1][j];
	            if(coins[i-1] <= j) memo[i][j] = min(memo[i][j],1+ memo[i][j-coins[i-1]]);
	        }
	    }
        if(memo[M][V]>1e7) return -1;
	    return memo[M][V];
	} 

int main() {
	
	int V = 11, M = 4,coins[] = {9, 6, 5, 1};
	cout<<minCoins(coins, M, V);
	return 0;
}
