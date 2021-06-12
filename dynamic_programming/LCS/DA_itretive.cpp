#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> memo = vector<vector<int>> (1002,vector<int>(1002));

    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        int count = 0;
        for(int i=0;i<=n;i++) memo[i][0] = 0;
        for(int i=0;i<=m;i++) memo[0][i] = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(S1[i-1]==S2[j-1]){
                    memo[i][j] = memo[i-1][j-1]+1;
                    count = max(count, memo[i][j]);
                }else{
                    memo[i][j] = 0;
                }
            }
        }return count;
    }

int main() {

    string str1 = "GeeksforGeeks";
    string str2 = "GeeksQuiz";
	int A = str1.length(), B = str2.length();
	cout<<longestCommonSubstr(str1, str2, A, B)<<endl;
	
	return 0;
}
