#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> memo = vector<vector<int>> (1002, vector<int>(1e5+2));

int main() {
    
    int arr[] = {1,1,2,3};
    int n = 4;
    int diff = 1;
    int sum=0;
    for(int i=0;i<n;i++) sum+=arr[i];
    
    int target = (sum + diff)/2;
    
    for(int i=0;i<=target;i++) memo[0][i] = 0;
    for(int i=0;i<=n;i++) memo[i][0] = 1;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=target;j++){
            memo[i][j] = memo[i-1][j];
            if(arr[i-1]<=j) memo[i][j] = memo[i-1][j] + memo[i-1][j-arr[i-1]];
        }
    }
    cout<<memo[n][target];
    
    
	return 0;
}
