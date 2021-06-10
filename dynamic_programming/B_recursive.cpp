#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> memo = vector<vector<int>> (1005, vector<int>(1005, -1));

int knapSack(int N, int W, int val[], int wt[])
    {
        if(N == 0 || W == 0) return 0;
        
        if(memo[N][W] != -1) return memo[N][W];
        
        int profit = knapSack(N-1, W, val, wt);
        if(wt[N-1] <= W) profit = max(profit, val[N-1] + knapSack(N, W-wt[N-1], val, wt));
        
        return memo[N][W] = profit;
    }

int main() {
	
	int N = 4, W = 8;
    int val[] = {1, 4, 5, 7};
    int wt[] = {1, 3, 4, 5};
	
	cout<<knapSack(N ,W, val, wt);
	
	return 0;
}
