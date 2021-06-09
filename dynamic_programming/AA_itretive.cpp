#include <bits/stdc++.h>
using namespace std;

vector<vector<bool>> memo = vector<vector<bool>>(1002,vector<bool>(1002));

int main() {
    
    int arr[] = {2,5,7,8,10};
    int n=5;
    int sum = 11;
//     cout<<subsetSum(arr, n, sum)<<endl;
    
    for(int i=0;i<=sum;i++) memo[0][i] = false;
    for(int i=0;i<=n;i++) memo[i][i] = false;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            int ans = memo[i-1][j];
            if(arr[i-1]<=j) ans = ans || memo[i-1][j-arr[i-1]];
            memo[i][j] = ans;
        }
    }cout<<memo[n][sum];
    
	return 0;
}
