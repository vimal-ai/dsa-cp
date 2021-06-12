#include <bits/stdc++.h>
using namespace std;

vector<vector<bool>> memo = vector<vector<bool>>(1002, vector<bool>(1002));

int main() {
	
	int arr[] ={20,19,18,20,16};
	int n=5;
	
	int range = 0;
	for(int i=0;i<n;i++) range+=arr[i];
	
	for(int i=0;i<=range;i++) memo[0][i] = false;
	for(int i=0;i<=n;i++) memo[i][0] = true;
	
	for(int i=1;i<=n;i++){
	    for(int j=1;j<=range;j++){
	        memo[i][j] = memo[i-1][j];
	        if(arr[i-1]<=j) memo[i][j] = memo[i-1][j] || memo[i-1][j-arr[i-1]];
	    }
	}
	
	int s1=0;
	int i=range/2;
	while(!s1){
	    if(memo[n][i]){
	        s1=i;
	        break;
	    } i--;
    }
	cout<<range-(2*s1);
	return 0;
}
