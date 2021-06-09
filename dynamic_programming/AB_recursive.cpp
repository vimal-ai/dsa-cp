#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> memo = vector<vector<int>>(1002,vector<int>(1002,-1));

bool subsetSum(int arr[], int n, int sum){
    if(sum == 0) return true;
    else if(n==0) return false;
    
    if(memo[n][sum] != -1) return memo[n][sum];
    
    int ans = subsetSum(arr, n-1, sum);
    if(arr[n-1] <= sum) ans = ans || subsetSum(arr, n-1, sum-arr[n-1]);
    return memo[n][sum] = ans;
}

int main() {
    
    int arr[] = {2,5,7,8,10};
    int n=5;
    int sum = 11;
    cout<<subsetSum(arr, n, sum)<<endl;
    
	return 0;
}
