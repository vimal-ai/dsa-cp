#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> memo = vector<vector<int>>(1002,vector<int>(1002, -1));

int lcs(int x, int y, string &s1, string &s2){
    if(x==0||y==0) return 0;
    if(memo[x][y] != -1) return memo[x][y];
    if(s1[x-1] == s2[y-1]){
        return memo[x][y] = 1+lcs(x-1, y-1, s1, s2);
    }else{
        return memo[x][y] = max(lcs(x-1,y,s1,s2), lcs(x,y-1,s1,s2));
    }
    
}
 
    }

int main() {
	
	int A = 6, B = 6;
    string str1 = "ABCDGH";
    string str2 = "AEDFHR";
	
	cout<<lcs(A, B, str1, str2);
	
	return 0;
}
