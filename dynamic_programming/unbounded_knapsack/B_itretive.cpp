#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> memo = vector<vector<int>> (1005, vector<int>(1005));

int knapSack(int N, int W, int val[], int wt[])
{
    
    for(int i=0;i<=N;i++){
        memo[i][0] = 0;
        memo[0][i] = 0;
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=W;j++){
            memo[i][j] = memo[i-1][j];
            if(wt[i-1] <= j) memo[i][j] = max(memo[i][j], val[i-1] + memo[i][j-wt[i-1]]);
        }
    }return memo[N][W];
    
}

int main() {
	
	int N = 4, W = 8;
    int val[] = {1, 4, 5, 7};
    int wt[] = {1, 3, 4, 5};
	
	cout<<knapSack(N ,W, val, wt);
	
	return 0;
}
