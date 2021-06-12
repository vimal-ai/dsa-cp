#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> memo = vector<vector<int>>(1002, vector<int>(1e5+2, -1));

bool subsetSum(int arr[], int n, int sum){
    
    if(sum==0) return true;
    else if(n==0) return false;
    
    if(memo[n][sum] != -1) return memo[n][sum];
    
    bool ans = subsetSum(arr, n-1, sum);
    if(arr[n-1] <= sum) ans = ans || subsetSum(arr, n-1, sum-arr[n-1]);
    return memo[n][sum] = ans;
    
}

bool equalPartition(int N, int arr[]){
    
    int sum = 0;
    for(int i=0;i<N;i++) sum+=arr[i];
    
    if(sum%2) return 0;
    
    return subsetSum(arr, N, sum/2);
//     return dp(arr, N, sum/2);
}


int main() {
	int arr[] = {1,5,11,5};
	int n = 4;
	cout<<equalPartition(n, arr);
	
	
	return 0;
}

