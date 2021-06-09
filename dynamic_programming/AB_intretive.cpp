#include <bits/stdc++.h>
using namespace std;

vector<vector<bool>> memo = vector<vector<bool>>(1002, vector<bool>(1e5+2));

bool dp(int arr[], int n, int sum){
    
    for(int i=0;i<=sum;i++) memo[0][i] = false;
    for(int i=0;i<=n;i++) memo[i][0] = true;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            int ans = memo[i-1][j];
            if(arr[i-1]<=j) ans = ans || memo[i-1][j-arr[i-1]];
            memo[i][j] = ans;
        }
    }
    return memo[n][sum];
}

bool equalPartition(int N, int arr[]){
    
    int sum = 0;
    for(int i=0;i<N;i++) sum+=arr[i];
    
    if(sum%2) return 0;
    
    // return subsetSum(arr, N, sum/2);
    return dp(arr, N, sum/2);
}


int main() {
	int arr[] = {1,5,11,5};
	int n = 4;
	cout<<equalPartition(n, arr);
	
	
	return 0;
}

