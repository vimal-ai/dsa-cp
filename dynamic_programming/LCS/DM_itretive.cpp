#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> memo = vector<vector<int>> (1002, vector<int>(1002));
    
int minimumNumberOfDeletions(string S) { 
        string s2 = S;
        reverse(s2.begin(), s2.end());
        int n=S.length();
        
        for(int i=0;i<=n;i++){
            memo[i][0] = 0; memo[0][i] = 0;  
        } 
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(S[i-1]==s2[j-1]){
                    memo[i][j] = memo[i-1][j-1]+1;
                }else{
                    memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
                }
            }
        }
        return n-memo[n][n];
        
} 

int main() {
	
	string a; cin>>a;

	cout<<minimumNumberOfDeletions(a);
	
	return 0;
}
