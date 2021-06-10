#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> memo = vector<vector<int>>(1002,vector<int>(1002));

   int lcs(int x, int y, string s1, string s2){
    
        for(int i=0;i<=x;i++) memo[i][0] = 0;
        for(int i=0;i<=y;i++) memo[0][i] = 0;
        
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                if(s1[i-1] == s2[j-1]) memo[i][j] = 1+memo[i-1][j-1];
                else memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
            }
        }
        return memo[x][y];
        
    }

int main() {
	
	int A = 6, B = 6;
    string str1 = "ABCDGH";
    string str2 = "AEDFHR";
	
	cout<<lcs(A, B, str1, str2);
	
	return 0;
}
