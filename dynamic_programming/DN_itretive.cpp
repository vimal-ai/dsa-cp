/*
minimum number of deletion in a string to make it palindrome

https://practice.geeksforgeeks.org/problems/form-a-palindrome1455/1

*/

#include <bits/stdc++.h>
using namespace std;
    
vector<vector<int>> memo = vector<vector<int>>(1002, vector<int>(1002));
    
int countMin(string str){
    
    string s = str; 
    int n=s.length();
    reverse(s.begin(), s.end());
    
    for(int i=0;i<=n;i++){
        memo[i][0]=0;
        memo[0][i]=0;
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(s[i-1]==str[j-1]){
                memo[i][j] = memo[i-1][j-1]+1;
            }else{
                memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
            }
        }
    }return n-memo[n][n];
        
}

int main() {
	
	string a; cin>>a;

	cout<<countMin(a);
	
	return 0;
}
