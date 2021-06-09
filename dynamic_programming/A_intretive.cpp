#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> memo = vector<vector<int>>(1002,vector<int>(1002));

int main() {
    int wt[] = {10,20,30};
    int val[] = {60, 200, 120};
    int n=3;
    int w=50;
    
    for(int i=0;i<1002;i++){
        memo[0][i] = 0;
        memo[i][0] = 0;
    }  
    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            int profit = memo[i-1][j];
            if(wt[i-1] <= j) profit = max(profit, val[i-1] + memo[i-1][j-wt[i-1]]);
            memo[i][j] = profit;
        }
    }cout<<memo[n][w];
    
    return 0;
}
