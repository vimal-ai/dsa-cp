/*
Maximize The Cut Segments / rod cutting porblem

https://practice.geeksforgeeks.org/problems/cutted-segments1642/1#

*/


#include <bits/stdc++.h>
using namespace std;

    vector<vector<int>> memo =  vector<vector<int>>(4, vector<int>(10005));
    
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        int arr[3] = {x, y, z};
        
        for(int i=0;i<=n;i++) memo[0][i] = -1e5;
        for(int i=0;i<=3;i++) memo[i][0] = 0;
        
        for(int i=1;i<=3;i++){
            for(int j=1;j<=n;j++){
                memo[i][j] = memo[i-1][j];
                if(arr[i-1]<=j) memo[i][j] = max(memo[i][j], 1 + memo[i][j-arr[i-1]]);
            }
        }
        return max(memo[3][n], 0);
    }

int main() {
	
	int N = 7;
    int x=5, y= 5, z= 2;
	
	cout<<maximizeTheCuts(N ,x, y, z);
	
	return 0;
}
