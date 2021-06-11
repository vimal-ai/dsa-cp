#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> memo = vector<vector<int>> (502,vector<int>(502));
	
	int LongestRepeatingSubsequence(string str){
		    string s = str;
		    int n=str.length();
		    
		    for(int i=0;i<=n;i++){
		        memo[i][0] = 0;
		        memo[0][i] = 0;
		    }
		    
		    for(int i=1;i<=n;i++){
		        for(int j=1;j<=n;j++){
		            if(i!=j && str[i-1]==str[j-1]){
		                memo[i][j] = memo[i-1][j-1]+1;
		            }else{
		                memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
		            }
		        }
		    }return memo[n][n];
	}

int main() {
	
	string s; cin>>s;
	cout<<LongestRepeatingSubsequence(s);
	
	
	return 0;
}
