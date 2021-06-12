#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> memo = vector<vector<int>> (1002,vector<int>(1002));

string lcs(string &a, string &b, int n ,int m){
    
    for(int i=0;i<=n;i++) memo[i][0] = 0;
    for(int i=0;i<=m;i++) memo[0][i] = 0;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1] == b[j-1]){
                memo[i][j] = memo[i-1][j-1] + 1;
            }else{
                memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
            }
        }
    }
    string s;
    int i=n, j=m;
    while(i>0 && j>0){
        if(a[i-1]==b[j-1]){
            s.push_back(a[i-1]);
            i--; j--;
        }else{
            if(memo[i-1][j]>memo[i][j-1]) i--;
            else j--;
        }
    }
    reverse(s.begin(), s.end());
    return s;
    
}

int main() {
	
	string s1,s2; cin>>s1>>s2;
	int n=s1.length(), m=s2.length();
	string c = lcs(s1, s2, n, m);

	cout<<c;
	return 0;
}
