/*
Coin Change maximum number of way to make a Change for n cent

https://practice.geeksforgeeks.org/problems/coin-change2448/1#

*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<long long int>> memo = vector<vector<long long int>> (1002, vector<long long int>(1002));

    // n = target , m = length of array
    long long int count( int S[], int m, int n )
    {
        for(int i=0;i<=n;i++) memo[0][i] = 0;
        for(int i=0;i<=m;i++) memo[i][0] = 1;
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                memo[i][j] = memo[i-1][j];
                if(S[i-1] <= j) memo[i][j] += memo[i][j-S[i-1]];
            }
        }
        return memo[m][n];
    }

int main() {
	
	int n = 10 , m = 4;
    int S[] ={2,5,3,6};
    
    cout<<count(S, m, n);
	
	return 0;
}
