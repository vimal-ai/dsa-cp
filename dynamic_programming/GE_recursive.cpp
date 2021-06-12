/*
palindromic partitioning 
https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1#
*/

#include <bits/stdc++.h>
using namespace std;

    vector<vector<int>> memo = vector<vector<int>>(502, vector<int>(502, -1));
    
    bool isPalindrome(string &s, int i, int j){
        for(int k=i;k<=j;k++){
            if(s[k]!=s[j-k+i]) return false;
        }return true;
    }
    
    int solve(string &s, int i, int j){
        if(i>=j) return 0;
        
        if(memo[i][j]!=-1) return memo[i][j];
        
        if(isPalindrome(s, i, j)) return 0;
        
        int ans=INT_MAX;
        for(int k=i;k<j;k++){
            if(memo[i][k] == -1) memo[i][k] = solve(s, i, k);
            if(memo[k+1][j] == -1) memo[k+1][j] = solve(s, k+1, j);
            int temp = memo[i][k] + memo[k+1][j] + 1;
            ans = min(ans, temp);
        }
        return memo[i][j] = ans;
    }

int main() {
	
	string s; cin>>s;
	
	cout<<solve(s, 0, s.length()-1);
	
	
	return 0;
}
