#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> memo = vector<vector<int>> (1002, vector<int>(1002));

int minOperations(string str1, string str2) {
	    int n=str1.length(), m=str2.length();
	    for(int i=0;i<=n;i++) memo[i][0] = 0;
	    for(int j=0;j<=m;j++) memo[0][j] = 0;
	    
	    for(int i=1;i<=n;i++){
	        for(int j=1;j<=m;j++){
	            if(str1[i-1]==str2[j-1]){
	                memo[i][j] = memo[i-1][j-1]+1;
	            }else{
	                memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
	            }
	        }
	    }
	    return n+m-(2*memo[n][m]);
} 

int main() {
	
	string s1,s2; cin>>s1>>s2;
	cout<<minOperations(s1,s2);
	
	return 0;
}
