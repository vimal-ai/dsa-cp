/*
matrix chain multiplication 
https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1#
*/

#include <bits/stdc++.h>
using namespace std;

    vector<vector<int>> memo = vector<vector<int>>(102, vector<int>(502, -1));
    
    int solve(int arr[], int i, int j){
        if(i>=j) return 0;
        
        if(memo[i][j]!=-1) return memo[i][j];
        
        int ans = INT_MAX;
        for(int k=i;k<j;k++){
            if(memo[i][k] == -1) memo[i][k] = solve(arr, i, k);
            if(memo[k+1][j] == -1) memo[k+1][j] = solve(arr, k+1, j);
            int temp = memo[i][k] + memo[k+1][j] + (arr[i-1] * arr[k] * arr[j]);
            ans = min(temp, ans);
        }
        return memo[i][j] = ans;
    }

int main() {
	int n; cin>>n;
	int arr[n];
	
	for(int i=0;i<n;i++) cin>>arr[i];
	
	cout<<solve(arr, 1, n-1);
	
	return 0;
}
